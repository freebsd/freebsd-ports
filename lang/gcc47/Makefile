# ex:ts=8
# Ports collection makefile for:	egcs
# Date created:				9 Jan 1998
# Whom:					John Polstra <jdp@polstra.com>
#
# $FreeBSD$
#

SNAPDATE=	2003-11-26
#CVS_DATE=	${SNAPDATE} 18:53:04 EDT

PORTNAME=	gcc
PORTVERSION=	3.4
PORTREVISION=	${SNAPDATE:S/-//g}
CATEGORIES=	lang java
VERSIONSTRING=	${PORTVERSION}-${PORTREVISION}
MASTER_SITES=	${MASTER_SITE_GCC}
MASTER_SITE_SUBDIR=	snapshots/${VERSIONSTRING}
.if !defined(CVS_DATE)
DISTFILES=	\
		gcc-core-${VERSIONSTRING}${EXTRACT_SUFX} \
		gcc-g++-${VERSIONSTRING}${EXTRACT_SUFX} \
		gcc-g77-${VERSIONSTRING}${EXTRACT_SUFX} \
		gcc-java-${VERSIONSTRING}${EXTRACT_SUFX} \
		gcc-objc-${VERSIONSTRING}${EXTRACT_SUFX} \
		gcc-testsuite-${VERSIONSTRING}${EXTRACT_SUFX}
.endif

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	GNU Compiler Collection 3.4

LATEST_LINK?=	gcc34${PKGNAMESUFFIX}

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_PERL5_BUILD=yes

PATCH_WRKSRC=	${SRCDIR}
CONFIGURE_SCRIPT=	../${SRCDIR:C/${WRKDIR}//}/configure
NOMANCOMPRESS=	yes	# too hard to deal with differences on 5-cur and releng4

.include <bsd.port.pre.mk>

BROKEN=		"Building libjava causes an Internal Compiler Error iff built within the ports tree"

CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}

GCC_VER=	${PORTVERSION:C/\.0$//}
SRCDIR=		${WRKDIR}/gcc-${VERSIONSTRING}
WRKSRC=		${WRKDIR}/build
TARGLIB=	${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_VER}
PLIST_SUB=	GCC_VER=${GCC_VER} GNU_HOST=${CONFIGURE_TARGET}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BISON=	yes
CONFIGURE_ARGS=	--disable-nls \
		--with-gxx-include-dir=${TARGLIB}/include/c++/${GCC_REV}
#CONFIGURE_ARGS+=	--program-suffix=34
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
ALL_TARGET=	bootstrap-lean
MAN1=		cpp34.1 g++34.1 g77-34.1 gcc34.1 gcov34.1 \
		gcj34.1 gcjh34.1 gij34.1 grepjar34.1 jar34.1 \
		jcf-dump34.1 jv-scan34.1 jv-convert34.1 \
		rmic34.1 rmiregistry34.1
MAN7=		fsf-funding.7 gfdl.7 gpl.7
INFO=		cpp cppinternals g77 gcc gccint gcj

.if defined(CVS_DATE)
NO_CHECKSUM=	yes
DIST_SUBDIR=	${PKGNAME}
CVS_CMD?=	cvs -z3 -qR
CVSROOT=	:pserver:anoncvs@subversions.gnu.org:/cvsroot/gcc
STAMPFILE=	${DISTDIR}/${DIST_SUBDIR}/.timestamp
do-fetch:
	@if [ ! -e ${STAMPFILE} ] || \
	    [ "X${CVS_DATE}" != "X$$(${CAT} ${STAMPFILE})" ]; then \
		${MKDIR} ${DISTDIR}/${DIST_SUBDIR} && \
		cd ${DISTDIR}/${DIST_SUBDIR} ; \
		unset CVS_RSH CVS_SERVER || ${TRUE} ; \
		${ECHO_MSG} ">> Attempting to CVS checkout from ${CVSROOT}." ;\
		if ${CVS_CMD} -d ${CVSROOT} co -D "${CVS_DATE}" gcc ; \
		then \
			( ${ECHO_CMD} -n "${CVS_DATE}" > ${STAMPFILE} ) ; \
			exit ; \
		fi ; \
		${ECHO_MSG} ">> Couldn't CVS checkout ${PKGNAME}." ; \
		${ECHO_MSG} ">> Please try again later."; \
		exit 1; \
	fi

do-extract:
	${MKDIR} ${SRCDIR}
	cd ${DISTDIR}/${DIST_SUBDIR}/${DIST_SUBDIR ; pax -pe -rwt . ${SRCDIR}
.endif	# CVS_DATE

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

post-install:
	@${RM} -f ${PREFIX}/bin/c++ ${PREFIX}/bin/${CONFIGURE_TARGET}-c++
.for f in gcc g++ cpp gcov ${CONFIGURE_TARGET}-gcc ${CONFIGURE_TARGET}-g++ gcj gcjh gij jv-scan jcf-dump jv-convert jar grepjar rmic rmiregistry
	${STRIP_CMD} ${PREFIX}/bin/${f}
	${MV} -f ${PREFIX}/bin/${f} ${PREFIX}/bin/${f}34
	( ${TEST} ! -e ${PREFIX}/man/man1/${f}.1 \
		|| ${MV} -f ${PREFIX}/man/man1/${f}.1 \
		${PREFIX}/man/man1/${f}34.1 )
.endfor
.for f in g77
	${MV} -f ${PREFIX}/bin/${f} ${PREFIX}/bin/${f}-34
	( ${TEST} ! -e ${PREFIX}/man/man1/${f}.1 \
		|| ${MV} -f ${PREFIX}/man/man1/${f}.1 \
		${PREFIX}/man/man1/${f}-34.1 )
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
.for info in cpp cppinternals g77 gcc gccint gcj
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
	    	| sort -r | ${SED} -e 's/^/@dirrm /g' >>${WRKDIR}/PLIST.gcc-lib
	(${ECHO_CMD} "@unexec rmdir %D/lib/gcc-lib/${CONFIGURE_TARGET} 2>&1 || true" ; ${ECHO_CMD} "@unexec rmdir %D/lib/gcc-lib 2>&1 || true") >> ${WRKDIR}/PLIST.gcc-lib
	# Handle GCJ include files.
	${RM} -f ${WRKDIR}/PLIST.gcj-inc
.for inc in ${PREFIX}/include/gcj ${PREFIX}/include/gnu ${PREFIX}/include/java ${PREFIX}/include/javax
	cd ${PREFIX} ;\
	    ${FIND} ${inc:S/^${PREFIX}\///} -type f -o -type l	\
	    	>>${WRKDIR}/PLIST.gcj-inc ;\
	    ${FIND} ${inc:S/^${PREFIX}\///} -type d \
	    	| sort -r | ${SED} -e 's/^/@dirrm /g' >>${WRKDIR}/PLIST.gcj-inc
.endfor
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
