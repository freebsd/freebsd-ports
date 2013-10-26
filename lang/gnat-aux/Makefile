# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnat-aux
PORTVERSION=	${SNAPSHOT}
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://downloads.dragonlace.net/src/:boot \
		${MASTER_SITE_GCC}
MASTER_SITE_SUBDIR=	releases/gcc-${GCC_VERSION}
DISTFILES=	gcc-core-${GCC_VERSION}.tar.bz2

MAINTAINER=	marino@FreeBSD.org
COMMENT=	GNAT Ada compiler based on GCC ${GCC_BRANCH}

NO_STAGE=	yes
.include "${.CURDIR}/Makefile.common"

LANGS=			c
APPLY_DIFFS=		core
INTENDED_COMPILER=	NATIVE
BOOTSTRAP_COMPILER=	NOT_REQUIRED
BOOTSTRAP_TRIPLET=	NOT_SET
FULL_GNATGCC=		NOT_SET
GARCH=			${ARCH:S/amd64/x86_64/}
OS_LABEL4VERS=		[${OPSYS}${GARCH:C,^.*(64),\1,}]

OPTIONS_DEFINE=		ADA CXX FORT OBJC TESTSUITE
OPTIONS_DEFAULT=	ADA CXX FORT OBJC
NO_OPTIONS_SORT=	yes

ADA_DESC=		Build Ada language
CXX_DESC=		Build C++ language
FORT_DESC=		Build Fortran language
OBJC_DESC=		Build Objective-C language
TESTSUITE_DESC=		Activate test support

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
.  if ${GARCH} == x86_64
BOOTSTRAP_TRIPLET=	x86_64-bootstrap-freebsd8.1/4.6.0
.  else
BOOTSTRAP_TRIPLET=	i386-bootstrap-freebsd8.0/4.6.0
.  endif
.endif
.if ${OPSYS} == DragonFly
BOOTSTRAP_TRIPLET=	${GARCH}-bootstrap-dragonfly2.8/4.6.0
.endif
BLD_TARGET=		${GARCH}-aux-${OPSYS:L}${OSREL}
BOOTSTRAP_COMPILER=	gnat-bootstrap.${GARCH}.${OPSYS:L}.tar.bz2

WRKSRC=			${WRKDIR}/gcc-${GCC_VERSION}
BUILDDIR=		${WRKDIR}/build
CFG_SCRIPT=		${WRKSRC}/configure
REVFILE=		${WRKSRC}/gcc/REVISION
BOOTSTRAP_PREFIX=	${WRKDIR}/bootstrap
DESTINY=		${WRKDIR}/destdir
PKG_PREFIX=		${PREFIX}
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
.if ${FULL_GNATGCC} == NOT_SET
INTENDED_COMPILER=BOOTSTRAP
FULL_GNATGCC=${BOOTSTRAP_PREFIX}/bin/gnatgcc
FULL_PATH=${BOOTSTRAP_PREFIX}/bin:/sbin:/bin:/usr/sbin:/usr/bin:${PREFIX}/bin
DISTFILES+=	${BOOTSTRAP_COMPILER}:boot
.endif

###########
##  Ada  ##
###########

.if ${PORT_OPTIONS:MADA}
LANGS+=		ada
APPLY_DIFFS+=	ada
DISTFILES+=	gcc-ada-${GCC_VERSION}.tar.bz2
.endif

###########
##  C++  ##
###########

.if ${PORT_OPTIONS:MCXX}
LANGS+=		c++
APPLY_DIFFS+=	cxx
DISTFILES+=	gcc-g++-${GCC_VERSION}.tar.bz2
MAN1+=		gnatg++.1
.endif

###############
##  Fortran  ##
###############

.if ${PORT_OPTIONS:MFORT}
LANGS+=		fortran
APPLY_DIFFS+=	fortran
DISTFILES+=	gcc-fortran-${GCC_VERSION}.tar.bz2
MAN1+=		gnatgfortran.1
QUADOPT=	--enable-libquadmath
.else
QUADOPT=	--disable-libquadmath
.endif

###################
##  Objective-C  ##
###################

.if ${PORT_OPTIONS:MOBJC}
LANGS+=		objc
DISTFILES+=	gcc-objc-${GCC_VERSION}.tar.bz2
.endif

##################
##  Testsuites  ##
##################

.if ${PORT_OPTIONS:MTESTSUITE}
BUILD_DEPENDS=	dejagnu>=1.4:${PORTSDIR}/misc/dejagnu
DISTFILES+=	gcc-testsuite-${GCC_VERSION}.tar.bz2
APPLY_DIFFS+=	ada-testsuite
APPLY_DIFFS+=	cxx-testsuite
APPLY_DIFFS+=	fortran-testsuite
APPLY_DIFFS+=	gcc-testsuite
.endif

# for port maintenance, uncomment to invoke "make makesum PLUS_BOOTSTRAPS=1"
.if defined(PLUS_BOOTSTRAPS)
DISTFILES= \
	gcc-core-${GCC_VERSION}.tar.bz2\
	gcc-ada-${GCC_VERSION}.tar.bz2 \
	gcc-g++-${GCC_VERSION}.tar.bz2 \
	gcc-fortran-${GCC_VERSION}.tar.bz2 \
	gcc-objc-${GCC_VERSION}.tar.bz2 \
	gcc-testsuite-${GCC_VERSION}.tar.bz2 \
	gnat-bootstrap.x86_64.dragonfly.tar.bz2:boot \
	gnat-bootstrap.i386.dragonfly.tar.bz2:boot \
	gnat-bootstrap.x86_64.freebsd.tar.bz2:boot \
	gnat-bootstrap.i386.freebsd.tar.bz2:boot
.endif

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
CONFIGURE_ARGS+=	${ICONV_CONFIGURE_ARG}
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
.if ${PORT_OPTIONS:MCXX}
	${MKDIR} ${WRKSRC}/libstdc++-v3/config/locale/dragonfly
	${MKDIR} ${WRKSRC}/libstdc++-v3/config/os/bsd/dragonfly
.endif

	# Apply required composite diff files
.for suffix in ${APPLY_DIFFS}
	@${ECHO} "Applying composite patch diff-${suffix}"
	@${PATCH} -d ${WRKSRC} -s -E < ${FILESDIR}/diff-${suffix}
.endfor

.if ${INTENDED_COMPILER} == BOOTSTRAP
	${MKDIR} ${BOOTSTRAP_PREFIX}
	${MV} ${BOOTSTRAP_PREFIX}/../bin ${BOOTSTRAP_PREFIX}
	${MV} ${BOOTSTRAP_PREFIX}/../lib ${BOOTSTRAP_PREFIX}
	${MV} ${BOOTSTRAP_PREFIX}/../libexec ${BOOTSTRAP_PREFIX}

	# Bootstrap compiler has statically linked z, gmp, mpc, mpfr and iconv
	# The only shared lib is libc.so.7, so it should work for a long time.

	${RM} -rf ${BOOTSTRAP_PREFIX}/lib/gcc/${BOOTSTRAP_TRIPLET}/include-fixed
.endif

do-configure:
	${MKDIR} ${BUILDDIR}
	cd ${BUILDDIR} && ${SETENV} ${ADA_CONFIGURE_ENV} \
	${CFG_SCRIPT} ${CONFIGURE_ARGS}

do-build:
	cd ${BUILDDIR} && ${SETENV} ${ADA_MAKE_ENV} ${GMAKE} ${_MAKE_JOBS} all

test: build test-ada test-fortran test-objc test-cxx test-c

test-ada:
.if ${PORT_OPTIONS:MADA} && ${PORT_OPTIONS:MTESTSUITE}
	cd ${BUILDDIR} && ${SETENV} ${ADA_MAKE_ENV} ${GMAKE} -sk check-ada
.endif

test-fortran:
.if ${PORT_OPTIONS:MFORT} && ${PORT_OPTIONS:MTESTSUITE}
	cd ${BUILDDIR} && ${SETENV} ${ADA_MAKE_ENV} ${GMAKE} -sk check-fortran
.endif

test-objc:
.if ${PORT_OPTIONS:MOBJC} && ${PORT_OPTIONS:MTESTSUITE}
	cd ${BUILDDIR} && ${SETENV} ${ADA_MAKE_ENV} ${GMAKE} -sk check-objc
.endif

test-cxx:
.if ${PORT_OPTIONS:MCXX} && ${PORT_OPTIONS:MTESTSUITE}
	# libstdc++ testsuite will break every time, TRUE used to force continuation
	cd ${BUILDDIR} && ${SETENV} ${ADA_MAKE_ENV} ${GMAKE} -sk check-c++ || true
.endif

test-c:
.if ${PORT_OPTIONS:MTESTSUITE}
	cd ${BUILDDIR} && ${SETENV} ${ADA_MAKE_ENV} ${GMAKE} -sk check-c
.endif

do-install:
	cd ${BUILDDIR} && ${SETENV} ${ADA_MAKE_ENV} ${GMAKE} install-strip DESTDIR=${DESTINY}
	${RM} ${DESTINY}${PREFIX}/lib/libiberty.a
	${CP} -pR ${DESTINY}${PREFIX}/ ${PREFIX}/

post-install:
	${RM} -f ${WRKDIR}/PLIST.all
	${RM} -rf ${DESTINY}/man
	${MV} ${DESTINY}${PREFIX}/share/man ${DESTINY}/
	cd ${DESTINY}; ${FIND} man -type d \
	   -exec ${MKDIR} ${DESTINY}${PREFIX}/share/{} \;
	cd ${DESTINY}${PREFIX}; ${FIND} * \( -type f -or -type l \) | \
	   ${SORT} >> ${WRKDIR}/PLIST.all
	cd ${DESTINY}${PREFIX}; ${FIND} * -type d | ${SORT} -r | \
	   ${SED} -E '/^(bin|sbin|lib|libexec|share)$$/d' | \
	   ${SED} -e 's/^/@dirrm /g' >> ${WRKDIR}/PLIST.all

	cd ${WRKDIR}; ${SED} -i -e "/PLIST.all/ r PLIST.all" ${TMPPLIST}
.if ${OPSYS} == FreeBSD
.  if ${OSVERSION} > 900000 && ${OSVERSION} < 900507
	@${ECHO_MSG} "===================================================================="
	@${ECHO_MSG} " NOTICE REGARDING ADA TASKING ON FREEBSD 9.0:"
	@${ECHO_MSG} " Due to a bug in the FreeBSD 9.0 threading library, an exiting task"
	@${ECHO_MSG} " panics with the message: 'thread exits with resources held!'."
	@${ECHO_MSG} " This behavior breaks Ada tasking.  These are two solutions:"
	@${ECHO_MSG} " 1) Upgrade to FreeBSD 9.1 or higher"
	@${ECHO_MSG} " 2) Patch and rebuild thread library as described in"
	@${ECHO_MSG} "    http://www.dragonlace.net/posts/F9_Fix/"
	@${ECHO_MSG} "===================================================================="
.  endif
.endif

.include <bsd.port.mk>
