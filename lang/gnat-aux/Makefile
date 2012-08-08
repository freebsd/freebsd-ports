# New ports collection makefile for:  gnat-aux
# Date created:                       2010-12-16
# Whom:                               John Marino <draco@marino.st>
#
# $FreeBSD$
#

PORTNAME=	gnat-aux
PORTVERSION=	${SNAPSHOT}
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://downloads.dragonlace.net/src/:boot \
		http://dragonlace.mirrors.ada.cx/src/:boot \
		${MASTER_SITE_GCC}
MASTER_SITE_SUBDIR=	releases/gcc-${GCC_VERSION}
DISTFILES=	gcc-core-${GCC_VERSION}.tar.bz2

MAINTAINER=	draco@marino.st
COMMENT=	GNAT Ada compiler based on GCC ${GCC_BRANCH}

.include "${.CURDIR}/Makefile.common"

LANGS=			c
APPLY_DIFFS=		core
INTENDED_COMPILER=	NATIVE
BOOTSTRAP_COMPILER=	NOT_REQUIRED
BOOTSTRAP_TRIPLET=	NOT_SET
FULL_GNATGCC=		NOT_SET

OPTIONS=	ADA    "Build Ada language" on
OPTIONS+=	CXX    "Build C++ language" on
OPTIONS+=	FORT   "Build Fortran language" on
OPTIONS+=	OBJC   "Build Objective-C language" on
OPTIONS+=	TS_ADA "Enable Ada testsuite" off
OPTIONS+=	TS_CXX "Enable C++ testsuite" off
OPTIONS+=	TS_FOR "Enable Fortran testsuite" off
OPTIONS+=	TS_OBC "Enable Objective-C testsuite" off
OPTIONS+=	TS_GCC "Enable GCC testsuite" off

.include <bsd.port.pre.mk>
.include <bsd.port.options.mk>

.if ${ARCH} == "amd64"
BLD_TARGET=		x86_64-aux-freebsd${OSREL}
OS_LABEL4VERS=		[FreeBSD64]
BOOTSTRAP_TRIPLET=	x86_64-bootstrap-freebsd8.1/4.6.0
BOOTSTRAP_COMPILER=	gnat-bootstrap.x86_64.freebsd.tar.bz2
.else
BLD_TARGET=		i386-aux-freebsd${OSREL}
OS_LABEL4VERS=		[FreeBSD]
BOOTSTRAP_TRIPLET=	i386-bootstrap-freebsd8.0/4.6.0
BOOTSTRAP_COMPILER=	gnat-bootstrap.i386.freebsd.tar.bz2
.endif
PLIST_SUB=		GNU_HOST=${BLD_TARGET}
PLIST_SUB+=		GCC_VER=${GCC_VERSION}

WRKSRC=			${WRKDIR}/gcc-${GCC_VERSION}
BUILDDIR=		${WRKDIR}/build
CFG_SCRIPT=		${WRKSRC}/configure
REVFILE=		${WRKSRC}/gcc/REVISION
BOOTSTRAP_PREFIX=	${WRKDIR}/bootstrap
PKG_PREFIX=		${PREFIX}
LPATH=			lib/gcc/${BLD_TARGET}/${GCC_VERSION}
LEPATH=			libexec/gcc/${BLD_TARGET}/${GCC_VERSION}
USE_LDCONFIG=		${PREFIX}/lib/gcc
MAN1=			gnatcpp.1 gnatgcc.1 gnatgcov.1
MAN1PREFIX=		${PREFIX}/share
MAN7PREFIX=		${PREFIX}/share
NO_MANCOMPRESS=		yes

# If we find gnatgcc and friends in standard location, then we'll use this
# compiler instead of downloading the bootstrap.
.if exists (${PREFIX}/bin/gnatgcc)
.if exists (${PREFIX}/bin/gnatbind)
.if exists (${PREFIX}/bin/gnatlink)
.if exists (${PREFIX}/bin/gnatmake)
FULL_GNATGCC=${PREFIX}/bin/gnatgcc
FULL_PATH=/sbin:/bin:/usr/sbin:/usr/bin:${PREFIX}/bin
.endif
.endif
.endif
.endif

# If FULL_GNATGCC is not set, we'll request the bootstrap compiler
.if ${FULL_GNATGCC} == "NOT_SET"
INTENDED_COMPILER=BOOTSTRAP
FULL_GNATGCC=${BOOTSTRAP_PREFIX}/bin/gnatgcc
FULL_PATH=${BOOTSTRAP_PREFIX}/bin:/sbin:/bin:/usr/sbin:/usr/bin:${PREFIX}/bin
DISTFILES+=	${BOOTSTRAP_COMPILER}:boot
.endif

###########
##  Ada  ##
###########

.if defined(WITH_ADA)
LANGS+=		ada
APPLY_DIFFS+=	ada
DISTFILES+=	gcc-ada-${GCC_VERSION}.tar.bz2
PLIST_SUB+=	ADA=""
.else
PLIST_SUB+=	ADA="@comment "
.endif

###########
##  C++  ##
###########

.if defined(WITH_CXX)
LANGS+=		c++
APPLY_DIFFS+=	cxx
DISTFILES+=	gcc-g++-${GCC_VERSION}.tar.bz2
MAN1+=		gnatg++.1
LCXXPATH=	include/c++/${GCC_VERSION}
LSHRPATH=	share/gcc-${GCC_VERSION}
PLIST_SUB+=	CXX=""
.else
PLIST_SUB+=	CXX="@comment "
.endif

###############
##  Fortran  ##
###############

.if defined(WITH_FORT)
LANGS+=		fortran
APPLY_DIFFS+=	fortran
DISTFILES+=	gcc-fortran-${GCC_VERSION}.tar.bz2
MAN1+=		gnatgfortran.1
QUADOPT=	--enable-libquadmath
PLIST_SUB+=	FRT=""
.else
QUADOPT=	--disable-libquadmath
PLIST_SUB+=	FRT="@comment "
.endif

###################
##  Objective-C  ##
###################

.if defined(WITH_OBJC)
LANGS+=		objc
DISTFILES+=	gcc-objc-${GCC_VERSION}.tar.bz2
.endif

##################
##  Testsuites  ##
##################

.if defined(WITH_TS_ADA) \
 || defined(WITH_TS_CXX) \
 || defined(WITH_TS_FOR) \
 || defined(WITH_TS_OBC) \
 || defined(WITH_TS_GCC)
BUILD_DEPENDS=	dejagnu>=1.4:${PORTSDIR}/misc/dejagnu
DISTFILES+=	gcc-testsuite-${GCC_VERSION}.tar.bz2
.if defined(WITH_TS_ADA)
APPLY_DIFFS+=	ada-testsuite
.endif
.if defined(WITH_TS_CXX)
APPLY_DIFFS+=	cxx-testsuite
.endif
.if defined(WITH_TS_GCC)
APPLY_DIFFS+=	gcc-testsuite
.endif
.endif

# for port maintenance, uncomment to invoke "make makesum"
# DISTFILES=${PORTNAME}-${SNAPSHOT}.tar.bz2 \
#   gnat-aux-460.i386.freebsd.tar.bz2 \
#   gnat-aux-460.x86_64.freebsd.tar.bz2

# Establish Ada-aware compiler for use
ADA_CONFIGURE_ENV=	CC=${FULL_GNATGCC}
ADA_CONFIGURE_ENV+=	PATH=${FULL_PATH}
ADA_CONFIGURE_ENV+=	CONFIG_SHELL=${SH}
ADA_MAKE_ENV=		PATH=${FULL_PATH}
ADA_MAKE_ENV+=		LD_LIBRARY_PATH=${BUILDDIR}/gcc

# The standard configuration options
CONFIGURE_ARGS=		--enable-languages=${LANGS:Q}
CONFIGURE_ARGS+=	--build=${BLD_TARGET}
CONFIGURE_ARGS+=	--program-prefix=gnat
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-system-zlib
CONFIGURE_ARGS+=	--with-gmp=${PKG_PREFIX}
CONFIGURE_ARGS+=	--with-mpfr=${PKG_PREFIX}
CONFIGURE_ARGS+=	--with-mpc=${PKG_PREFIX}
CONFIGURE_ARGS+=	--with-libiconv-prefix=${PKG_PREFIX}
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-threads=posix
CONFIGURE_ARGS+=	--disable-bootstrap
CONFIGURE_ARGS+=	${QUADOPT}
CONFIGURE_ARGS+=	--disable-libmudflap
CONFIGURE_ARGS+=	--disable-libgomp
CONFIGURE_ARGS+=	--disable-libssp
CONFIGURE_ARGS+=	--disable-nls

post-extract:
	# Personalize GNAT for each different machine
	@${ECHO} "-=> GNAT AUX ${OS_LABEL4VERS}" > ${REVFILE}

	# Create new directories in preparation of applying diff files
.if defined(WITH_CXX)
	${MKDIR} ${WRKSRC}/libstdc++-v3/config/locale/dragonfly
	${MKDIR} ${WRKSRC}/libstdc++-v3/config/os/bsd/dragonfly
.endif

	# Apply required composite diff files
.for suffix in ${APPLY_DIFFS}
	@${ECHO} "Applying composite patch diff-${suffix}"
	@${PATCH} -d ${WRKSRC} -s -E < ${FILESDIR}/diff-${suffix}
.endfor

.if ${INTENDED_COMPILER} == "BOOTSTRAP"
	${MKDIR} ${BOOTSTRAP_PREFIX}
	${MV} ${BOOTSTRAP_PREFIX}/../bin ${BOOTSTRAP_PREFIX}
	${MV} ${BOOTSTRAP_PREFIX}/../lib ${BOOTSTRAP_PREFIX}
	${MV} ${BOOTSTRAP_PREFIX}/../libexec ${BOOTSTRAP_PREFIX}

	# Bootstrap compiler has statically linked z, gmp, mpc, mpfr and iconv
	# The only shared lib is libc.so.7, so it should work for a long time.

.if ${OSVERSION} > 900000
	# Since June 7, bootstrap compiler's include-fixed headers have been
	# incompatible with FreeBSD 9.0-CURRENT
	${RM} -rf ${BOOTSTRAP_PREFIX}/lib/gcc/${BOOTSTRAP_TRIPLET}/include-fixed
.endif
.endif

do-configure:
	${MKDIR} ${BUILDDIR}
	cd ${BUILDDIR} && ${SETENV} ${ADA_CONFIGURE_ENV} \
	${CFG_SCRIPT} ${CONFIGURE_ARGS}

do-build:
	cd ${BUILDDIR} && ${SETENV} ${ADA_MAKE_ENV} ${GMAKE} ${_MAKE_JOBS} all

test: build
.if defined(WITH_ADA) && defined(WITH_TS_ADA)
	cd ${BUILDDIR} && ${SETENV} ${ADA_MAKE_ENV} ${GMAKE} -sk check-ada
.endif
.if defined(WITH_FORT) && defined(WITH_TS_FOR)
	cd ${BUILDDIR} && ${SETENV} ${ADA_MAKE_ENV} ${GMAKE} -sk check-fortran
.endif
.if defined(WITH_OBJC) && defined(WITH_TS_OBC)
	cd ${BUILDDIR} && ${SETENV} ${ADA_MAKE_ENV} ${GMAKE} -sk check-objc
.endif
.if defined(WITH_CXX) && defined(WITH_TS_CXX)
	# libstdc++ testsuite will break every time, TRUE used to force continuation
	cd ${BUILDDIR} && ${SETENV} ${ADA_MAKE_ENV} ${GMAKE} -sk check-c++ || true
.endif
.if defined(WITH_TS_GCC)
	cd ${BUILDDIR} && ${SETENV} ${ADA_MAKE_ENV} ${GMAKE} -sk check-c
.endif

do-install:
	cd ${BUILDDIR} && ${SETENV} ${ADA_MAKE_ENV} ${GMAKE} install-strip DESTDIR=${DESTDIR}

post-install:
	${RM} -f ${WRKDIR}/PLIST.lib
.for d in ${LPATH} ${LEPATH} ${LCXXPATH} ${LSHRPATH}
	cd ${PREFIX} ; ${FIND} $d \( -type f -or -type l \) | ${SORT} >> ${WRKDIR}/PLIST.lib
	cd ${PREFIX} ; ${FIND} $d  -type d | ${SORT} -r | \
	   ${SED} -e 's/^/@dirrm /g' >> ${WRKDIR}/PLIST.lib
.endfor
	${ECHO_CMD} "@unexec ${RMDIR} %D/lib/gcc/${BLD_TARGET}     2>/dev/null || true" >> ${WRKDIR}/PLIST.lib
	${ECHO_CMD} "@unexec ${RMDIR} %D/lib/gcc                   2>/dev/null || true" >> ${WRKDIR}/PLIST.lib
	${ECHO_CMD} "@unexec ${RMDIR} %D/libexec/gcc/${BLD_TARGET} 2>/dev/null || true" >> ${WRKDIR}/PLIST.lib
	${ECHO_CMD} "@unexec ${RMDIR} %D/libexec/gcc               2>/dev/null || true" >> ${WRKDIR}/PLIST.lib
	${ECHO_CMD} "@unexec ${RMDIR} %D/include/c++               2>/dev/null || true" >> ${WRKDIR}/PLIST.lib

	cd ${WRKDIR}; ${SED} -i -e "/PLIST.lib/ r PLIST.lib" ${TMPPLIST}
.if ${OSVERSION} > 900000
	@${ECHO_MSG} "===================================================================="
	@${ECHO_MSG} " NOTICE REGARDING ADA TASKING ON FREEBSD 9.0:"
	@${ECHO_MSG} " Due to a bug in the FreeBSD 9.0 threading library, an exiting task"
	@${ECHO_MSG} " panics with the message: 'thread exits with resources held!'."
	@${ECHO_MSG} " This behavior breaks Ada tasking.  These are two solutions:"
	@${ECHO_MSG} " 1) Upgrade to FreeBSD 9.1 or higher"
	@${ECHO_MSG} " 2) Patch and rebuild thread library as described in"
	@${ECHO_MSG} "    http://www.dragonlace.net/posts/F9_Fix/"
	@${ECHO_MSG} "===================================================================="
.endif

.include <bsd.port.post.mk>
