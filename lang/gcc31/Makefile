# ex:ts=8 
# Ports collection makefile for:	egcs 
# Date created:				9 Jan 1998
# Whom:					John Polstra <jdp@polstra.com>
#
# $FreeBSD$
#

SNAPDATE=	2002-09-09
SNAPVER=	${SNAPDATE:S/-//g}

PORTNAME=	gcc
PORTVERSION=	3.1.1
PORTREVISION=	1
PORTREVISION=	${SNAPVER}
CATEGORIES=	lang java
MASTER_SITES=	${MASTER_SITE_GCC}
MASTER_SITE_SUBDIR=	releases/gcc-${GCC_REV}
DISTFILES=	gcc-core-${PORTVERSION}${EXTRACT_SUFX} \
		gcc-g++-${PORTVERSION}${EXTRACT_SUFX} \
		gcc-g77-${PORTVERSION}${EXTRACT_SUFX} \
		gcc-java-${PORTVERSION}${EXTRACT_SUFX} \
		gcc-objc-${PORTVERSION}${EXTRACT_SUFX}

PATCH_SITES=	ftp://relay.nuxi.com/obrien/
PATCHFILES=	port_gcc31_${SNAPDATE}.diff

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU Compiler Collection 3.1 (inprogress version)

NOT_FOR_ARCHS=	amd64 ia64
NO_CDROM=	'dated material'
LATEST_LINK=	gcc31

USE_BZIP2=	yes

PATCH_WRKSRC=	${SRCDIR}
CONFIGURE_SCRIPT=	../${SRCDIR:C/${WRKDIR}//}/configure

.ifdef USE_GCC
.error You have `USE_GCC' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

# do not require Gcc 3.1 to compile -- or we have an infinate loop on RELENG_4.
USE_GCC=	X
NOMANCOMPRESS=	yes	# to hard to deal with differences on 5-cur and releng4

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "aout"
CONFIGURE_TARGET=	${ARCH}-portbld-freebsdaout${OSREL}
.else
CONFIGURE_TARGET?=	${ARCH}-portbld-freebsd${OSREL}
.endif

GCC_REV=	${PORTVERSION:C/\.0$//}
#SRCDIR=		${WRKDIR}/gcc-${GCC_REV}
SRCDIR=		${WRKDIR}/gcc-${PORTVERSION}
WRKSRC=		${WRKDIR}/build
TARGLIB=	${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_REV}
PLIST_SUB=	GCC_REV=${GCC_REV} GNU_HOST=${CONFIGURE_TARGET}  \
		SNAPVER=${PORTVERSION}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BISON=	yes
CONFIGURE_ARGS=	--disable-nls --with-gnu-as --with-gnu-ld \
		--with-gxx-include-dir=${TARGLIB}/include/g++-v3
#CONFIGURE_ARGS+=	--program-suffix=31
#	Java
CONFIGURE_ARGS+=	--with-system-zlib --includedir=${TARGLIB}/include/Java
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
MAN1=		cpp31.1 g++31.1 g77-31.1 gcc31.1 gcov31.1 \
		gcj31.1 gcjh31.1 gij.1 \
		jcf-dump31.1 jv-scan31.1 jv-convert.1
MAN7=		fsf-funding.7 gfdl.7 gpl.7

pre-everything::
	@${ECHO_MSG} "Making GCC ${DISTNAME:S/^gcc-//} for ${OPSYS} ${OSREL} ${PORTOBJFORMAT}	target ${CONFIGURE_TARGET}"

pre-configure:
	@# Keep from running `autoconf' and `autoheader' since we modified
	@# configure.in by patching it.
	@${TOUCH} ${SRCDIR}/gcc/configure
	@${TOUCH} ${SRCDIR}/gcc/cstamp-h.in
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
		${TARGLIB}/cc1 ${TARGLIB}/cc1obj ${TARGLIB}/cc1plus \
		${TARGLIB}/cpp0 ${TARGLIB}/collect2 ${TARGLIB}/f771 ; \
	do \
		${STRIP_CMD} $$prog ; \
	done )
.for file in gcc g++ cpp g++filt gcov ${CONFIGURE_TARGET}-gcc ${CONFIGURE_TARGET}-g++ gcj gcjh jv-scan jcf-dump jar grepjar
	${MV} -f ${PREFIX}/bin/${file} ${PREFIX}/bin/${file}31
	( ${TEST} ! -e ${PREFIX}/man/man1/${file}.1 \
		|| ${MV} -f ${PREFIX}/man/man1/${file}.1 \
		${PREFIX}/man/man1/${file}31.1 )
.endfor
.for file in g77
	${MV} -f ${PREFIX}/bin/${file} ${PREFIX}/bin/${file}-31
	( ${TEST} ! -e ${PREFIX}/man/man1/${file}.1 \
		|| ${MV} -f ${PREFIX}/man/man1/${file}.1 \
		${PREFIX}/man/man1/${file}-31.1 )
.endfor
	${MV} -f ${PREFIX}/bin/gccbug ${PREFIX}/bin/gccbug-${PORTVERSION}
	# These 3 libraries are moved from PREFIX/lib to avoid conflicts
	# 	with the stock compiler.
.for file in libstdc++ libsupc++ libg2c libfrtbegin libobjc
	${MV} -f ${PREFIX}/lib/${file}.* ${TARGLIB}
.endfor
	-${MV} -f ${PREFIX}/lib/ieee ${TARGLIB}
	# Java
	cd ${PREFIX}/lib ; ${MV} -f libgcj.* ${TARGLIB}
	${RM} -f ${PREFIX}/lib/libiberty.a
	${RM} -f ${TARGLIB}/*.la
# I am sick and tired of this .info shit, makeinfo --no-split isn't working
	@cd ${PREFIX}/info ; ${RM} -f cpp.* cppinternals.* g77.* gcc.* gccint.* gcj.*
#.for info in cpp cppinternals g77 gcc gcj
#	install-info ${PREFIX}/info/${info}.info ${PREFIX}/info/dir
#.endfor
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

cklatest:
.for SITE in ftp://gcc.gnu.org/pub/gcc/snapshots/                                   ftp://mirrors.rcn.net/mirrors/sources.redhat.com/gcc/snapshots/	
	@-ncftpls ${SITE} | grep LATEST
.endfor

.include <bsd.port.post.mk>
