# ex:ts=8
# Ports collection makefile for:	egcs
# Date created:				9 Jan 1998
# Whom:					John Polstra <jdp@polstra.com>
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	3.2.3
PORTREVISION=	1
CATEGORIES=	lang java
MASTER_SITES=	${MASTER_SITE_GCC} \
		http://web.inter.NL.net/hcc/Haj.Ten.Brugge/:bc
MASTER_SITE_SUBDIR=	releases/gcc-${PORTVERSION}
DISTFILES=	gcc-core-${PORTVERSION}${EXTRACT_SUFX} \
		gcc-testsuite-${PORTVERSION}${EXTRACT_SUFX} \
		gcc-g++-${PORTVERSION}${EXTRACT_SUFX} \
		gcc-g77-${PORTVERSION}${EXTRACT_SUFX} \
		gcc-java-${PORTVERSION}${EXTRACT_SUFX} \
		gcc-objc-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER?=	dinoex@FreeBSD.org
COMMENT?=	GNU Compiler Collection 3.2.3

LATEST_LINK?=	gcc32${PKGNAMESUFFIX}

USE_BZIP2=	yes

PATCH_WRKSRC=	${SRCDIR}
CONFIGURE_SCRIPT=	../${SRCDIR:C/${WRKDIR}//}/configure
# Do not require GCC 3.2 to compile -- or we have an infinite loop on RELENG_4.
USE_GCC=	X
NOMANCOMPRESS=	yes	# too hard to deal with differences on 5-cur and releng4

ONLY_FOR_ARCHS=	i386 alpha sparc64

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "aout"
CONFIGURE_TARGET=	${ARCH}-portbld-freebsdaout${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
.endif

GCC_REV=	${PORTVERSION:C/\.0$//}
SRCDIR=		${WRKDIR}/gcc-${GCC_REV}
WRKSRC=		${WRKDIR}/build
TARGLIB=	${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_REV}
PLIST_SUB=	GCC_REV=${GCC_REV} GNU_HOST=${CONFIGURE_TARGET}  \
		PORTVERSION=${PORTVERSION}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--disable-nls \
		--with-gxx-include-dir=${TARGLIB}/include/g++-v3
#CONFIGURE_ARGS+=	--program-suffix=32
CONFIGURE_ARGS+=	--with-system-zlib --includedir=${TARGLIB}/include/Java
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
.if defined(WANT_SHAREDLIBS)
CONFIGURE_ARGS+=	--enable-shared
INSTALLS_SHLIB=		yes
LDCONFIG_DIRS=	%%PREFIX%%/lib ${TARGLIB}
EXTRA_SHLIB=	libgcc_s
.else
CONFIGURE_ARGS+=	--disable-shared
.endif
.if defined(WANT_THREADS_SUPPORT)
CONFIGURE_ARGS+=	--enable-threads
#	?is this an ObjC only thing?
CONFIGURE_ARGS+=	--enable-threads=posix
.endif
ALL_TARGET=	bootstrap
MAN1=		cpp32.1 g++32.1 g77-32.1 gcc32.1 gcov32.1 \
		gcj32.1 gcjh32.1 gij.1 rmic.1 rmiregistry.1 \
		jcf-dump32.1 jv-scan32.1 jv-convert.1
MAN7=		fsf-funding.7 gfdl.7 gpl.7

pre-configure:
	cd ${SRCDIR} ; contrib/gcc_update --touch
	@${RM} -f ${SRCDIR}/gcc/*/*.info*
	@${MKDIR} ${CONFIGURE_WRKSRC}

post-build:
	@echo "Consider running 'make check' before 'make install',"
	@echo "especially if you have not built port on -STABLE or -CURRENT."
	@echo "This suggestion assumes that you have dejagnu port installed."

check: build
	cd ${WRKSRC}; export RUNTESTFLAGS='--target_board ''unix{-pthread}'''; ${GMAKE} -sk check

pre-install:
	${MKDIR} ${PREFIX}/info

post-install:
	@${RM} -f ${PREFIX}/bin/c++ ${PREFIX}/bin/${CONFIGURE_TARGET}-c++
	@${MV} -f ${PREFIX}/bin/c++filt ${PREFIX}/bin/g++filt
	@(for prog in ${PREFIX}/bin/gcc ${PREFIX}/bin/g++ \
		${PREFIX}/bin/g++filt ${PREFIX}/bin/g77 ${PREFIX}/bin/gcov \
		${PREFIX}/bin/${CONFIGURE_TARGET}-gcc \
		${TARGLIB}/cpp0 ${TARGLIB}/collect2 ${TARGLIB}/f771 ; \
	do \
		${STRIP_CMD} $$prog ; \
	done )
.for file in gcc g++ cpp g++filt gcov ${CONFIGURE_TARGET}-gcc ${CONFIGURE_TARGET}-g++ gcj gcjh jv-scan jcf-dump jar grepjar
	${MV} -f ${PREFIX}/bin/${file} ${PREFIX}/bin/${file}32
	( ${TEST} ! -e ${PREFIX}/man/man1/${file}.1 \
		|| ${MV} -f ${PREFIX}/man/man1/${file}.1 \
		${PREFIX}/man/man1/${file}32.1 )
.endfor
.for file in g77
	${MV} -f ${PREFIX}/bin/${file} ${PREFIX}/bin/${file}-32
	( ${TEST} ! -e ${PREFIX}/man/man1/${file}.1 \
		|| ${MV} -f ${PREFIX}/man/man1/${file}.1 \
		${PREFIX}/man/man1/${file}-32.1 )
.endfor
	${MV} -f ${PREFIX}/bin/gccbug ${PREFIX}/bin/gccbug-${PORTVERSION}
	# These 3 libraries are moved from PREFIX/lib to avoid conflicts
	# 	with the stock compiler.
.for file in libstdc++ libsupc++ libg2c libfrtbegin libobjc ${EXTRA_SHLIB}
	${MV} -f ${PREFIX}/lib/${file}.* ${TARGLIB}
.endfor
	-${MV} -f ${PREFIX}/lib/ieee ${TARGLIB}
	# Java
	-${MV} -f ${PREFIX}/lib/libgcj.* ${TARGLIB}
	${RM} -f ${PREFIX}/lib/libiberty.a
	${RM} -f ${TARGLIB}/*.la
.for info in cpp cppinternals g77 gcc gcj
	install-info ${PREFIX}/info/${info}.info ${PREFIX}/info/dir
.endfor
# I am sick and tired of the anonyance that man pages can only be generated if
# perl 5.6 is installed.  This is becoming a royal PITA on non-5-CURRENT systems
.for mp in ${_MANPAGES}
	( ${TEST} -e ${mp} && ${TOUCH} ${TOUCH_FLAGS} ${mp} )
.endfor
	cd ${PREFIX} ;\
	    ${FIND} ${TARGLIB:S/^${PREFIX}\///} -type f -o -type l	\
	    	>${WRKDIR}/PLIST.gcc-lib
	cd ${PREFIX} ;\
	    ${FIND} ${TARGLIB:S/^${PREFIX}\///} -type d \
	    	| ${SORT} -r | ${SED} -e 's/^/@dirrm /g' \
		>>${WRKDIR}/PLIST.gcc-lib
	(${ECHO_CMD} "@unexec rmdir %D/lib/gcc-lib/${CONFIGURE_TARGET} 2>&1 || true" ; ${ECHO_CMD} "@unexec rmdir %D/lib/gcc-lib 2>&1 || true") >> ${WRKDIR}/PLIST.gcc-lib
	${ECHO_CMD} "r ${TMPPLIST}"		> ${WRKDIR}/ex.script
	${ECHO_CMD} "/Insert PLIST.gcc-lib"	>> ${WRKDIR}/ex.script
	${ECHO_CMD} "d"				>> ${WRKDIR}/ex.script
	${ECHO_CMD} "r ${WRKDIR}/PLIST.gcc-lib"	>> ${WRKDIR}/ex.script
	${ECHO_CMD} "x!"			>> ${WRKDIR}/ex.script
	${CP} -p ${TMPPLIST} ${TMPPLIST}.pre-gcc-lib
	cd ${WRKDIR} ; ex < ex.script
.if ${ARCH} != "sparc64" && ${ARCH} != ia64
	# libgcj is built on all platforms except sparc64 and ia64.
	${CAT} ${MASTERDIR}/pkg-plist.libgcj >> ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
