# New ports collection makefile for:  gcc-aux
# Date created:                       2012-07-15
# Whom:                               John Marino <draco@marino.st>
#
# $FreeBSD$
#

PORTNAME=	gcc-aux
PORTVERSION=	${SNAPSHOT}
CATEGORIES=	lang
MASTER_SITES=	http://downloads.dragonlace.net/src/:boot \
		http://dragonlace.mirrors.ada.cx/src/:boot \
		${MASTER_SITE_GCC}
MASTER_SITE_SUBDIR=	releases/gcc-${GCC_VERSION}
DISTFILES=	gcc-${GCC_VERSION}.tar.bz2

MAINTAINER=	draco@marino.st
COMMENT=	Version of GCC ${GCC_BRANCH} with full Ada support

.include "${.CURDIR}/Makefile.common"

LANGS=			c
APPLY_DIFFS=		core
INTENDED_COMPILER=	NATIVE
BOOTSTRAP_COMPILER=	NOT_REQUIRED
BOOTSTRAP_TRIPLET=	NOT_SET
FULL_GNATGCC=		NOT_SET

OPTIONS=	ADA        "Build Ada language" on
OPTIONS+=	CXX        "Build C++ language" on
OPTIONS+=	FORT       "Build Fortran language" on
OPTIONS+=	OBJC       "Build Objective-C language" on
OPTIONS+=	STATIC     "Build with no shared libraries other than libc" off
OPTIONS+=	TESTSUITE  "Activate test support" off
OPTIONS+=	NLS        "Native Language Support" off

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

WRKSRC=			${WRKDIR}/gcc-${GCC_VERSION}
BUILDDIR=		${WRKDIR}/build
CFG_SCRIPT=		${WRKSRC}/configure
REVFILE=		${WRKSRC}/gcc/REVISION
BOOTSTRAP_PREFIX=	${WRKDIR}/bootstrap
DESTINY=		${WRKDIR}/destdir
PKG_PREFIX=		${PREFIX}/${PORTNAME}
STICONV=		${PREFIX}/lib/libiconv.a
STINTL=			\$${top_builddir}/../intl/libintl.a
USE_LDCONFIG=		${PREFIX}/${PORTNAME}/lib ${PREFIX}/${PORTNAME}/lib/gcc
MAN1=			cpp.1 gcc.1 gcov.1
MAN1PREFIX=		${PREFIX}/${PORTNAME}/share
MAN7PREFIX=		${PREFIX}/${PORTNAME}/share
NO_MANCOMPRESS=		yes

# If we find gnatmake and friends in a standard location, then we'll use this
# compiler instead of downloading the bootstrap.
.if exists (${PREFIX}/${PORTNAME}/bin/ada)
.if exists (${PREFIX}/${PORTNAME}/bin/gnatbind)
.if exists (${PREFIX}/${PORTNAME}/bin/gnatlink)
.if exists (${PREFIX}/${PORTNAME}/bin/gnatmake)
FULL_GNATGCC=${PREFIX}/${PORTNAME}/bin/ada
FULL_PATH=/sbin:/bin:/usr/sbin:/usr/bin:${PREFIX}/${PORTNAME}/bin:${PREFIX}/bin
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

# for port maintenance, invoke "make makesum PLUS_BOOTSTRAPS=1"
.if defined(PLUS_BOOTSTRAPS)
DISTFILES=gcc-${GCC_VERSION}.tar.bz2 \
   gnat-bootstrap.i386.freebsd.tar.bz2:boot \
   gnat-bootstrap.x86_64.freebsd.tar.bz2:boot
.endif

###########
##  Ada  ##
###########

.if defined(WITH_ADA)
LANGS+=		ada
APPLY_DIFFS+=	ada
.endif

###########
##  C++  ##
###########

.if defined(WITH_CXX)
LANGS+=		c++
APPLY_DIFFS+=	cxx
MAN1+=		g++.1
.endif

###############
##  Fortran  ##
###############

.if defined(WITH_FORT)
LANGS+=		fortran
APPLY_DIFFS+=	fortran
MAN1+=		gfortran.1
EXTRA_CONFIG+=	--enable-libquadmath
.else
EXTRA_CONFIG+=	--disable-libquadmath
.endif

###################
##  Objective-C  ##
###################

.if defined(WITH_OBJC)
LANGS+=		objc
.endif

#########################
##  Testsuite Support  ##
#########################

.if defined(WITH_TESTSUITE)
BUILD_DEPENDS=	dejagnu>=1.4:${PORTSDIR}/misc/dejagnu
APPLY_DIFFS+=	ada-testsuite
APPLY_DIFFS+=	fortran-testsuite
APPLY_DIFFS+=	cxx-testsuite
APPLY_DIFFS+=	gcc-testsuite
.endif

#################################
##  NATIONAL LANGUAGE SUPPORT  ##
#################################

.if defined(WITH_NLS)
BUILD_DEPENDS=	gettext>=0.18:${PORTSDIR}/devel/gettext
EXTRA_CONFIG+=	--enable-nls
.else
EXTRA_CONFIG+=	--disable-nls
.endif

###############################
##  STATICALLY BUILT OPTION  ##
###############################
#
# The "static" option is handled in the post-extract phase.

# Establish Ada-aware compiler for use
ADA_CONFIGURE_ENV=	CC=${FULL_GNATGCC}
ADA_CONFIGURE_ENV+=	PATH=${FULL_PATH}
ADA_MAKE_ENV=		PATH=${FULL_PATH}
ADA_MAKE_ENV+=		ICONVPREFIX=${PREFIX}
ADA_MAKE_ENV+=		LD_LIBRARY_PATH=${BUILDDIR}/gcc

# The standard configuration options
ADA_CONFIG_ARGS=	--enable-languages=${LANGS:Q}
ADA_CONFIG_ARGS+=	--build=${BLD_TARGET}
ADA_CONFIG_ARGS+=	--prefix=${PKG_PREFIX:Q}
ADA_CONFIG_ARGS+=	--with-system-zlib
ADA_CONFIG_ARGS+=	--with-gmp=${PREFIX}
ADA_CONFIG_ARGS+=	--with-mpfr=${PREFIX}
ADA_CONFIG_ARGS+=	--with-mpc=${PREFIX}
ADA_CONFIG_ARGS+=	--with-libiconv-prefix=${PREFIX}
ADA_CONFIG_ARGS+=	--enable-shared
ADA_CONFIG_ARGS+=	--enable-threads=posix
ADA_CONFIG_ARGS+=	--disable-bootstrap
ADA_CONFIG_ARGS+=	--disable-libmudflap
ADA_CONFIG_ARGS+=	--disable-libgomp
ADA_CONFIG_ARGS+=	--disable-libssp
ADA_CONFIG_ARGS+=	${EXTRA_CONFIG}

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

.if defined(WITH_STATIC)
	@${ECHO} "Reconfiguring GCC Makefile to build compiler statically"
	@${PATCH} -d ${WRKSRC} -s -E < ${FILESDIR}/diff-static-version
.if defined(WITH_NLS)
	@${PERL} -pi -e 's;\@LIBINTL\@;${STINTL} ${STICONV};' ${WRKSRC}/intl/config.intl.in
	@${PERL} -pi -e 's;\@LIBICONV\@;;' \
	  ${WRKSRC}/gcc/Makefile.in \
	  ${WRKSRC}/libcpp/Makefile.in \
	  ${WRKSRC}/gcc/ada/gcc-interface/Makefile.in
.else
	@${PERL} -pi -e 's;\@LIBICONV\@;${STICONV};' \
	  ${WRKSRC}/gcc/Makefile.in \
	  ${WRKSRC}/libcpp/Makefile.in \
	  ${WRKSRC}/gcc/ada/gcc-interface/Makefile.in
.endif
.endif

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
	${CFG_SCRIPT} ${ADA_CONFIG_ARGS}

do-build:
	cd ${BUILDDIR} && ${SETENV} ${ADA_MAKE_ENV} ${GMAKE} ${_MAKE_JOBS} all

test: build test-ada test-fortran test-objc test-cxx test-c

test-ada:
.if defined(WITH_ADA) && defined(WITH_TESTSUITE)
	cd ${BUILDDIR} && ${SETENV} ${ADA_MAKE_ENV} ${GMAKE} -sk check-ada
.endif

test-fortran:
.if defined(WITH_FORT) && defined(WITH_TESTSUITE)
	cd ${BUILDDIR} && ${SETENV} ${ADA_MAKE_ENV} ${GMAKE} -sk check-fortran
.endif

test-objc:
.if defined(WITH_OBJC) && defined(WITH_TESTSUITE)
	cd ${BUILDDIR} && ${SETENV} ${ADA_MAKE_ENV} ${GMAKE} -sk check-objc
.endif

test-cxx:
.if defined(WITH_CXX) && defined(WITH_TESTSUITE)
	# libstdc++ testsuite will break every time, TRUE used to force continuation
	cd ${BUILDDIR} && ${SETENV} ${ADA_MAKE_ENV} ${GMAKE} -sk check-c++ || true
.endif

test-c:
.if defined(WITH_TESTSUITE)
	cd ${BUILDDIR} && ${SETENV} ${ADA_MAKE_ENV} ${GMAKE} -sk check-c
.endif

do-install:
	cd ${BUILDDIR} && ${SETENV} ${ADA_MAKE_ENV} ${GMAKE} install-strip DESTDIR=${DESTINY}
	${CP} -pr ${DESTINY}${PREFIX}/ ${PREFIX}/

post-install:
	${RM} -f ${WRKDIR}/PLIST.all
	${RM} -rf ${DESTINY}/man
	${MV} ${DESTINY}${PREFIX}/${PORTNAME}/share/man ${DESTINY}/
	cd ${DESTINY}; ${FIND} man -type d \
	   -exec ${MKDIR} ${DESTINY}${PREFIX}/${PORTNAME}/share/{} \;
	cd ${DESTINY}${PREFIX}; ${FIND} ${PORTNAME} \( -type f -or -type l \) | \
	   ${SORT} >> ${WRKDIR}/PLIST.all
	cd ${DESTINY}${PREFIX}; ${FIND} ${PORTNAME}  -type d | ${SORT} -r | \
	   ${SED} -e 's/^/@dirrm /g' >> ${WRKDIR}/PLIST.all

	cd ${WRKDIR}; ${SED} -i -e "/PLIST.all/ r PLIST.all" ${TMPPLIST}
.if ${OSVERSION} > 900000 && ${OSVERSION} < 900507
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
