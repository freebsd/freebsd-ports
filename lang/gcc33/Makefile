# ex:ts=8
# Ports collection makefile for:	egcs
# Date created:				9 Jan 1998
# Whom:					John Polstra <jdp@polstra.com>
#
# $FreeBSD$
#

SNAPDATE=

PORTNAME=	gcc
PORTVERSION=	3.3.2
PORTREVISION=	${SNAPDATE:S/-//g}
CATEGORIES=	lang java
VERSIONSTRING=	3.3.2
MASTER_SITES=	${MASTER_SITE_GCC} \
		http://web.inter.NL.net/hcc/Haj.Ten.Brugge/:bc
MASTER_SITE_SUBDIR=	releases/gcc-${VERSIONSTRING}
DISTFILES=	\
		gcc-core-${VERSIONSTRING}${EXTRACT_SUFX} \
		gcc-g++-${VERSIONSTRING}${EXTRACT_SUFX} \
		gcc-g77-${VERSIONSTRING}${EXTRACT_SUFX} \
		gcc-java-${VERSIONSTRING}${EXTRACT_SUFX} \
		gcc-objc-${VERSIONSTRING}${EXTRACT_SUFX} \
		gcc-testsuite-${VERSIONSTRING}${EXTRACT_SUFX}

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	GNU Compiler Collection 3.3

.if defined (WITH_BOUNDSCHECKING)
# Fetch another file, but don't extract it.  Also add another patchfile.
BCPATCH=	bounds-checking-gcc-3.3.1-1.00.patch.bz2
DISTFILES+=	${BCPATCH}:bc
EXTRACT_ONLY=	${DISTFILES:S/${BCPATCH}:bc//}
EXTRA_PATCHES=	${FILESDIR}/opt.patch-bc
.endif

LATEST_LINK?=	gcc33${PKGNAMESUFFIX}

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_PERL5_BUILD=yes

PATCH_WRKSRC=	${SRCDIR}
CONFIGURE_SCRIPT=	../${SRCDIR:C/${WRKDIR}//}/configure
NOMANCOMPRESS=	yes	# too hard to deal with differences on 5-cur and releng4

.include <bsd.port.pre.mk>

CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}

GCC_VER=	${PORTVERSION:C/\.0$//}
SRCDIR=		${WRKDIR}/gcc-${VERSIONSTRING}
WRKSRC=		${WRKDIR}/build
TARGLIB=	${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_VER}
GCJINC=		${PREFIX}/include/gcj
GNUINC=		${PREFIX}/include/gnu
JAVAINC=	${PREFIX}/include/java
JAVAINC2=	${PREFIX}/include/javax
PLIST_SUB=	GCC_VER=${GCC_VER} GNU_HOST=${CONFIGURE_TARGET}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BISON=	yes
CONFIGURE_ARGS=	--disable-nls \
		--with-gxx-include-dir=${TARGLIB}/include/c++/${GCC_REV}
#CONFIGURE_ARGS+=	--program-suffix=33
#	Java
CONFIGURE_ARGS+=	--with-system-zlib #--includedir=${TARGLIB}/include/Java -libdir=${TARGLIB}
MAKE_ARGS+=	MAKEINFOFLAGS="--no-split"
.if defined(WANT_SHAREDLIBS)
CONFIGURE_ARGS+=	--enable-shared
INSTALLS_SHLIB=	yes
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
MAN1=		cpp33.1 g++33.1 g77-33.1 gcc33.1 gcov33.1 \
		gcj33.1 gcjh33.1 gij33.1 grepjar33.1 jar33.1 \
		jcf-dump33.1 jv-scan33.1 jv-convert33.1 \
		rmic33.1 rmiregistry33.1
MAN7=		fsf-funding.7 gfdl.7 gpl.7
INFO=		cpp cppinternals g77 gcc gccint gcj fastjar

pre-everything::
	@${ECHO_MSG} "Making GCC ${DISTNAME:S/^gcc-//} for ${OPSYS} ${OSREL} ${PORTOBJFORMAT}	target ${CONFIGURE_TARGET}"
.if !defined(WITH_BOUNDSCHECKING)
	@${ECHO_MSG} "You can enable fine-grained bounds-checking support for compiled C programs"
	@${ECHO_MSG} "by defining WITH_BOUNDSCHECKING.  Compile and link with \"-fbounds-checking\""
	@${ECHO_MSG} "to use."
.endif

.if defined(WITH_BOUNDSCHECKING)
# Extract bounds-checking patch, removing the ada parts of the patch with sed.
pre-patch:
	cd ${_DISTDIR} ; \
	${BZCAT} ${BCPATCH} | \
		${SED} -e '/^--- .*ada/,/^diff/d' | \
		${SED} -e '/^--- .*parse.h/,/^diff/d' | \
		${PATCH} -d ${PATCH_WRKSRC} -E -p1 --quiet
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|\(const char version_string.*\)";|\1 [FreeBSD]";|' \
	    ${SRCDIR}/gcc/version.c

pre-configure:
	cd ${SRCDIR} ; contrib/gcc_update --touch
	@${RM} -f ${SRCDIR}/gcc/*/*.info*
	@${MKDIR} ${CONFIGURE_WRKSRC}

post-build:
	@echo "Consider running 'make check' before 'make install',"
	@echo "especially if you have not built port on -STABLE or -CURRENT."
	@echo "This assumes that you have the dejagnu port installed."

check: build
	cd ${WRKSRC}; export RUNTESTFLAGS='--target_board ''unix{-pthread}'''; ${GMAKE} -sk check

pre-install:
	${MKDIR} ${PREFIX}/info

post-install:
	@${RM} -f ${PREFIX}/bin/c++ ${PREFIX}/bin/${CONFIGURE_TARGET}-c++
	@(for prog in \
		${TARGLIB}/cc1 ${TARGLIB}/cc1obj ${TARGLIB}/cc1plus \
		${TARGLIB}/collect2 ${TARGLIB}/f771 ; \
	do \
		${STRIP_CMD} $$prog ; \
	done )
.for f in gcc g++ cpp gcov ${CONFIGURE_TARGET}-gcc ${CONFIGURE_TARGET}-g++ gcj gcjh gij jv-scan jcf-dump jv-convert jar grepjar rmic rmiregistry
	${STRIP_CMD} ${PREFIX}/bin/${f}
	${MV} -f ${PREFIX}/bin/${f} ${PREFIX}/bin/${f}33
	( ${TEST} ! -e ${PREFIX}/man/man1/${f}.1 \
		|| ${MV} -f ${PREFIX}/man/man1/${f}.1 \
		${PREFIX}/man/man1/${f}33.1 )
.endfor
.for f in g77
	${MV} -f ${PREFIX}/bin/${f} ${PREFIX}/bin/${f}-33
	( ${TEST} ! -e ${PREFIX}/man/man1/${f}.1 \
		|| ${MV} -f ${PREFIX}/man/man1/${f}.1 \
		${PREFIX}/man/man1/${f}-33.1 )
.endfor
	${MV} -f ${PREFIX}/bin/gccbug ${PREFIX}/bin/gccbug-${PORTVERSION}
	# These 3 libraries are moved from PREFIX/lib to avoid conflicts
	# 	with the stock compiler.
.for f in libstdc++ libsupc++ libg2c libfrtbegin libobjc ${EXTRA_SHLIB}
	${MV} -f ${PREFIX}/lib/${f}.* ${TARGLIB}
.endfor
	-${MV} -f ${PREFIX}/lib/ieee ${TARGLIB}
	# Java
	-${MV} -f ${PREFIX}/lib/libgcj.* ${TARGLIB}
	${RM} -f ${PREFIX}/lib/libiberty.a
	${RM} -f ${TARGLIB}/*.la
.for info in cpp cppinternals g77 gcc gccint gcj fastjar
	install-info ${PREFIX}/info/${info}.info ${PREFIX}/info/dir
.endfor
# I am sick and tired of the anonyance that man pages can only be generated if
# perl 5.6 is installed.  This is becoming a royal PITA on non-5-CURRENT systems
	for mp in ${_MANPAGES} ; do \
	    ${TEST} -e $${mp} || ${TOUCH} ${TOUCH_FLAGS} $${mp} ;\
	    done
	cd ${PREFIX} ;\
	    ${FIND} ${TARGLIB:S/^${PREFIX}\///} -type f -o -type l	\
	    	>${WRKDIR}/PLIST.gcc-lib
	cd ${PREFIX} ;\
	    ${FIND} ${TARGLIB:S/^${PREFIX}\///} -type d \
	    	| sort -r | ${SED} -e 's/^/@dirrm /g' >>${WRKDIR}/PLIST.gcc-lib
	(${ECHO_CMD} "@unexec rmdir %D/lib/gcc-lib/${CONFIGURE_TARGET} 2>&1 || true" ; ${ECHO_CMD} "@unexec rmdir %D/lib/gcc-lib 2>&1 || true") >> ${WRKDIR}/PLIST.gcc-lib
	cd ${PREFIX} ;\
	    ${FIND} ${GCJINC:S/^${PREFIX}\///} -type f -o -type l	\
	    	>${WRKDIR}/PLIST.gcj-inc
	cd ${PREFIX} ;\
	    ${FIND} ${GNUINC:S/^${PREFIX}\///} -type f -o -type l	\
	    	>>${WRKDIR}/PLIST.gcj-inc
	cd ${PREFIX} ;\
	    ${FIND} ${JAVAINC:S/^${PREFIX}\///} -type f -o -type l	\
	    	>>${WRKDIR}/PLIST.gcj-inc
	cd ${PREFIX} ;\
	    ${FIND} ${JAVAINC2:S/^${PREFIX}\///} -type f -o -type l	\
	    	>>${WRKDIR}/PLIST.gcj-inc
	cd ${PREFIX} ;\
	    ${FIND} ${GCJINC:S/^${PREFIX}\///} -type d \
	    	| sort -r | ${SED} -e 's/^/@dirrm /g' >>${WRKDIR}/PLIST.gcj-inc
	cd ${PREFIX} ;\
	    ${FIND} ${GNUINC:S/^${PREFIX}\///} -type d \
	    	| sort -r | ${SED} -e 's/^/@dirrm /g' >>${WRKDIR}/PLIST.gcj-inc
	cd ${PREFIX} ;\
	    ${FIND} ${JAVAINC:S/^${PREFIX}\///} -type d \
	    	| sort -r | ${SED} -e 's/^/@dirrm /g' >>${WRKDIR}/PLIST.gcj-inc
	cd ${PREFIX} ;\
	    ${FIND} ${JAVAINC2:S/^${PREFIX}\///} -type d \
	    	| sort -r | ${SED} -e 's/^/@dirrm /g' >>${WRKDIR}/PLIST.gcj-inc
	${ECHO_CMD} "r ${TMPPLIST}"		> ${WRKDIR}/ex.script
	${ECHO_CMD} "/Insert PLIST.gcc-lib"	>> ${WRKDIR}/ex.script
	${ECHO_CMD} "d"				>> ${WRKDIR}/ex.script
	${ECHO_CMD} "r ${WRKDIR}/PLIST.gcc-lib"	>> ${WRKDIR}/ex.script
	${ECHO_CMD} "/Insert PLIST.gcj-inc"	>> ${WRKDIR}/ex.script
	${ECHO_CMD} "d"				>> ${WRKDIR}/ex.script
	${ECHO_CMD} "r ${WRKDIR}/PLIST.gcj-inc"	>> ${WRKDIR}/ex.script
	${ECHO_CMD} "x!"			>> ${WRKDIR}/ex.script
	${CP} -p ${TMPPLIST} ${TMPPLIST}.pre-gcc-lib
	cd ${WRKDIR} ; ex < ex.script

cklatest:
.for SITE in ftp://gcc.gnu.org/pub/gcc/snapshots/                                   ftp://mirrors.rcn.net/mirrors/sources.redhat.com/gcc/snapshots/
	@-ncftpls ${SITE} | ${GREP} LATEST
.endfor

.include <bsd.port.post.mk>
