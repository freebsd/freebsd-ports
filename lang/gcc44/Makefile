# ex:ts=8
# Ports collection makefile for:	egcs
# Date created:				9 Jan 1998
# Whom:					John Polstra <jdp@polstra.com>
#
# $FreeBSD$
#
SNAPDATE=	2004-01-28

PORTNAME=	gcc
PORTVERSION=	3.4.0
PORTREVISION=	${SNAPDATE:S/-//g}
CATEGORIES=	lang java
VERSIONSTRING=	3.4-${PORTREVISION}
MASTER_SITES=	${MASTER_SITE_GCC} \
		http://web.inter.NL.net/hcc/Haj.Ten.Brugge/:bc
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

USE_BISON=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
USE_REINPLACE=	yes
USE_SIZE=	yes

PATCH_WRKSRC=	${SRCDIR}
CONFIGURE_SCRIPT=	../${SRCDIR:C/${WRKDIR}//}/configure
NOMANCOMPRESS=	yes	# too hard to deal with differences on 5-cur and releng4

.include <bsd.port.pre.mk>

.if ${ARCH} == sparc64
BROKEN=	"libgcj is not supported/packaging is broken on this platform"
.endif

CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}

SRCDIR=		${WRKDIR}/gcc-${VERSIONSTRING}
WRKSRC=		${WRKDIR}/build
SUFFIX=		34
TARGLIB=	${PREFIX}/lib/gcc/${CONFIGURE_TARGET}/${PORTVERSION}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls \
		--with-system-zlib \
		--with-libiconv-prefix=${LOCALBASE} \
		--program-suffix=${SUFFIX} \
		--with-gxx-include-dir=${TARGLIB}/include/c++/
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
PLIST_SUB=	GCC_VER=${PORTVERSION} GNU_HOST=${CONFIGURE_TARGET}
MAN1=		cpp${SUFFIX}.1 \
		g++${SUFFIX}.1 \
		g77-${SUFFIX}.1 \
		gcc${SUFFIX}.1 \
		gcov${SUFFIX}.1 \
		gcj${SUFFIX}.1 \
		gcjh${SUFFIX}.1 \
		gij${SUFFIX}.1 \
		grepjar${SUFFIX}.1 \
		jar${SUFFIX}.1 \
		jcf-dump${SUFFIX}.1 \
		jv-scan${SUFFIX}.1 jv-convert${SUFFIX}.1 \
		rmic${SUFFIX}.1 rmiregistry${SUFFIX}.1
MAN7=		fsf-funding.7 gfdl.7 gpl.7
INFO=		cpp cppinternals g77 gcc gccinstall gccint gcj fastjar

pre-everything::
	@${ECHO_MSG} "Making GCC ${DISTNAME:S/^gcc-//} for ${OPSYS} ${OSREL} ${PORTOBJFORMAT}	target ${CONFIGURE_TARGET}"

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
	cd ${DISTDIR}/${DIST_SUBDIR}/${DIST_SUBDIR ; ${PAX} -pe -rwt . ${SRCDIR}
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
.for f in c++ f77 gcc g++ cpp gcov ${CONFIGURE_TARGET}-gcc ${CONFIGURE_TARGET}-g++ gcj gcjh gij jv-scan jcf-dump jv-convert jar grepjar rmic rmiregistry
	# gij and jv-convert, for example, are not built on all platforms.
	if [ -e ${PREFIX}/bin/${f}${SUFFIX} ]; then \
	  ${STRIP_CMD} ${PREFIX}/bin/${f}${SUFFIX}; \
	  ( ${TEST} ! -e ${PREFIX}/man/man1/${f}.1 \
		|| ${MV} -f ${PREFIX}/man/man1/${f}.1 \
		${PREFIX}/man/man1/${f}${SUFFIX}.1 ); \
	fi
.endfor
	${MV} -f ${PREFIX}/bin/g7734 ${PREFIX}/bin/g77-34
	${MV} -f ${PREFIX}/man/man1/g7734.1 ${PREFIX}/man/man1/g77-34.1
	# These libraries are moved from PREFIX/lib to avoid conflicts with
	# the stock compiler.
.for f in libstdc++ libsupc++ libg2c libfrtbegin libobjc ${EXTRA_SHLIB}
	${MV} -f ${PREFIX}/lib/${f}.* ${TARGLIB}
.endfor
	-${MV} -f ${PREFIX}/lib/ieee ${TARGLIB}
	-${MV} -f ${PREFIX}/lib/libgcj.* ${TARGLIB}
	${RM} -f ${PREFIX}/lib/libiberty.a
	${RM} -f ${TARGLIB}/*.la
# I am sick and tired of the anonyance that man pages can only be generated if
# perl 5.6 is installed.  This is becoming a royal PITA on non-5-CURRENT systems
.for mp in ${_MANPAGES}
	( ${TEST} -e ${mp} || ${TOUCH} ${TOUCH_FLAGS} ${mp} )
.endfor
	# Handle target libraries and GCJ include files.
	${RM} -f ${WRKDIR}/PLIST.lib
.for d in ${TARGLIB:S/^${PREFIX}\///} include/gcj include/gnu include/java include/javax
	cd ${PREFIX} ; if [ -d $d ]; then \
	    ${FIND} $d -type f -o -type l >>${WRKDIR}/PLIST.lib ;\
	    ${FIND} $d -type d | ${SORT} -r \
	        | ${SED} -e 's/^/@dirrm /g' >>${WRKDIR}/PLIST.lib ;\
	fi
.endfor
	(${ECHO_CMD} "@unexec rmdir %D/lib/gcc/${CONFIGURE_TARGET} 2>&1 || true" ; ${ECHO_CMD} "@unexec rmdir %D/lib/gcc 2>&1 || true") >> ${WRKDIR}/PLIST.lib
	${ECHO_CMD} "r ${TMPPLIST}"		> ${WRKDIR}/ex.script
	${ECHO_CMD} "/Insert PLIST.lib"		>> ${WRKDIR}/ex.script
	${ECHO_CMD} "d"				>> ${WRKDIR}/ex.script
	${ECHO_CMD} "r ${WRKDIR}/PLIST.lib"	>> ${WRKDIR}/ex.script
	${ECHO_CMD} "x!"			>> ${WRKDIR}/ex.script
	${CP} -p ${TMPPLIST} ${TMPPLIST}.pre
	cd ${WRKDIR} ; ex < ex.script

cklatest:
.for SITE in ftp://gcc.gnu.org/pub/gcc/snapshots/                                   ftp://mirrors.rcn.net/mirrors/sources.redhat.com/gcc/snapshots/
	@-ncftpls ${SITE} | ${GREP} 'LATEST.*3\.4'
.endfor

.include <bsd.port.post.mk>
