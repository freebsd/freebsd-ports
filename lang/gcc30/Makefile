# ex:ts=8 
# Ports collection makefile for:	egcs 
# Date created:				9 Jan 1998
# Whom:					John Polstra <jdp@polstra.com>
#
# $FreeBSD$
#

PORTNAME=	gcc30
PORTVERSION=	3.0.3
PORTREVISION=	0
CATEGORIES=	lang java
MASTER_SITES=	ftp://egcs.cygnus.com/pub/egcs/releases/gcc-${GCC_REV}/  \
		${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	gcc/releases/gcc-${GCC_REV}
DISTFILES=	gcc-core-${GCC_REV}${EXTRACT_SUFX} \
		gcc-g++-${GCC_REV}${EXTRACT_SUFX} \
		gcc-g77-${GCC_REV}${EXTRACT_SUFX} \
		gcc-java-${GCC_REV}${EXTRACT_SUFX} \
		gcc-objc-${GCC_REV}${EXTRACT_SUFX}

MAINTAINER=	obrien@FreeBSD.org

USE_BZIP2=	yes

LATEST_LINK=	gcc30

PATCH_WRKSRC=	${SRCDIR}
CONFIGURE_SCRIPT=	../${SRCDIR:C/${WRKDIR}//}/configure

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-freebsdaout${OSREL}
.endif

GCC_REV=	${PORTVERSION:C/\.0$//}
SRCDIR=		${WRKDIR}/gcc-${GCC_REV}
WRKSRC=		${WRKDIR}/build
TARGLIB=	${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_REV}
PLIST_SUB=	GCC_REV=${GCC_REV} GNU_HOST=${CONFIGURE_TARGET}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BISON=	yes
CONFIGURE_ARGS=	--disable-nls --with-gnu-as --with-gnu-ld \
		--with-gxx-include-dir=${TARGLIB}/include/g++
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
.if defined(WANT_SHAREDLIBS)
CONFIGURE_ARGS+= --enable-shared
.else
CONFIGURE_ARGS+= --disable-shared
.endif
.if defined(WANT_THREADS_SUPPORT)
CONFIGURE_ARGS+= --enable-threads
#	?is this an ObjC only thing?
CONFIGURE_ARGS+= --enable-threads=posix
.endif
ALL_TARGET=	bootstrap
MAN1=		cpp30.1 g++30.1 g77-30.1 gcc30.1 gcov30.1

pre-fetch:
	@${ECHO} "Making GCC ${DISTNAME:S/^gcc-//} for ${OPSYS} ${OSREL} ${PORTOBJFORMAT}	target ${ARCH}-portbld-freebsd${OSREL}"

pre-configure:
	@# Keep from running `autoconf' and `autoheader' since we modified
	@# configure.in by patching it.
	@touch ${SRCDIR}/gcc/configure
	@touch ${SRCDIR}/gcc/cstamp-h.in
	@${MKDIR} ${CONFIGURE_WRKSRC}
	@${RM} -f ${SRCDIR}/gcc/*/*.info*

pre-build:
	cd ${SRCDIR} ; contrib/gcc_update --touch

pre-install:
	${MKDIR} ${PREFIX}/info

post-install:
	@${RM} -f ${PREFIX}/bin/c++ ${PREFIX}/bin/${CONFIGURE_TARGET}-c++
	@${MV} -f ${PREFIX}/bin/c++filt ${PREFIX}/bin/g++filt
	@(for prog in ${PREFIX}/bin/gcc ${PREFIX}/bin/g++ \
		${PREFIX}/bin/g++filt ${PREFIX}/bin/g77 ${PREFIX}/bin/gcov \
		${PREFIX}/bin/${CONFIGURE_TARGET}-gcc \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_REV}/cc1 \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_REV}/cc1obj \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_REV}/cc1plus \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_REV}/cpp0 \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_REV}/collect2 \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_REV}/f771 ; \
	do \
		strip $$prog ; \
	done )
.for file in gcc g++ cpp g++filt gcov ${CONFIGURE_TARGET}-gcc ${CONFIGURE_TARGET}-g++
	${MV} -f ${PREFIX}/bin/${file} ${PREFIX}/bin/${file}30
	-( test -e ${PREFIX}/man/man1/${file}.1 \
		&& ${MV} -f ${PREFIX}/man/man1/${file}.1 \
		${PREFIX}/man/man1/${file}30.1 )
.endfor
.for file in g77
	${MV} -f ${PREFIX}/bin/${file} ${PREFIX}/bin/${file}-30
	${MV} -f ${PREFIX}/man/man1/${file}.1 ${PREFIX}/man/man1/${file}-30.1
.endfor
	${MV} -f ${PREFIX}/bin/gccbug ${PREFIX}/bin/gccbug-${PORTVERSION:C/\.0$//}
	# These 3 libraries are moved from PREFIX/lib to avoid conflicts
	# 	with the stock compiler.
	${MV} -f ${PREFIX}/lib/libiberty.a ${TARGLIB}
	${MV} -f ${PREFIX}/lib/libstdc++.* ${PREFIX}/lib/libsupc++.* ${TARGLIB}
	-${MV} -f ${PREFIX}/lib/ieee ${TARGLIB}
#.if defined(WANT_SHAREDLIBS)
#	${MV} -f ${PREFIX}/lib/libstdc++.so* ${TARGLIB}
#.endif
.for info in cpp cppinternals g77 gcc gcj
	install-info ${PREFIX}/info/${info}.info ${PREFIX}/info/dir
.endfor
	cd ${PREFIX} ;\
	    find ${TARGLIB:S/^${PREFIX}\///} -type f -o -type l	\
	    	>${WRKDIR}/PLIST.gcc-lib
	cd ${PREFIX} ;\
	    find ${TARGLIB:S/^${PREFIX}\///} -type d \
	    	| sort -r | ${SED} -e 's/^/@dirrm /g' >>${WRKDIR}/PLIST.gcc-lib
	(${ECHO} "@unexec rmdir %D/lib/gcc-lib/${CONFIGURE_TARGET} 2>&1 || true" ; ${ECHO} "@unexec rmdir %D/lib/gcc-lib 2>&1 || true") >> ${WRKDIR}/PLIST.gcc-lib
	${ECHO} "r ${TMPPLIST}"			> ${WRKDIR}/ex.script
	${ECHO} "/Insert PLIST.gcc-lib"		>> ${WRKDIR}/ex.script
	${ECHO} "d"				>> ${WRKDIR}/ex.script
	${ECHO} "r ${WRKDIR}/PLIST.gcc-lib"	>> ${WRKDIR}/ex.script
	${ECHO} "x!"				>> ${WRKDIR}/ex.script
	${CP} -p ${TMPPLIST} ${TMPPLIST}.pre-gcc-lib
	cd ${WRKDIR} ; ex < ex.script

.include <bsd.port.post.mk>
