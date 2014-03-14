# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gcc-aux
PORTVERSION=	${SNAPSHOT}
CATEGORIES=	lang
MASTER_SITES=	http://downloads.dragonlace.net/src/:boot \
		LOCAL/marino:boot ${MASTER_SITE_GCC}
MASTER_SITE_SUBDIR= ${MS_SUBDIR}
DISTFILES=	${IDENTIFICATION}.tar.bz2

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Version of GCC ${GCC_BRANCH} with full Ada support

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

.include "${.CURDIR}/Makefile.common"

LANGS=			c c++ ada
APPLY_DIFFS=		core cxx ada
INTENDED_COMPILER=	NATIVE
GARCH=			${ARCH:S/amd64/x86_64/}
BOOTSTRAP_COMPILER=	gnat-bootstrap.${GARCH}.${OPSYS:L}.tar.bz2
BLD_TARGET=		${GARCH}-aux-${OPSYS:L}${OSREL}
FULL_GNATGCC=		NOT_SET
OS_LABEL4VERS=		[${OPSYS}${GARCH:M*64:S/amd_//:S/x86_//}]

OPTIONS_GROUP=		Standard Bootstrap
OPTIONS_GROUP_Standard= FORT OBJC NLS TESTSUITE STATIC
OPTIONS_GROUP_Bootstrap=BOOTSTRAP
OPTIONS_DEFAULT=	FORT OBJC
NO_OPTIONS_SORT=	yes

FORT_DESC=		Fortran language support
OBJC_DESC=		Objective-C language support
TESTSUITE_DESC=		Activate test support
STATIC_DESC=		Link compilers and drivers statically
BOOTSTRAP_DESC=		Create bootstrap compiler (overrides other options)

# The BOOTSTRAP option overrides all the others.  "make stage" will build a 
# static compiler that supports C, C++, and Ada languages and then create
# a new distfile in $WRKDIR/newbsd with the name following the pattern:
# ada-bootstrap.$ARCH.$OPSYS.XY.tar.bz2.  There is no need to "make install"

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
.  if ${OSVERSION} < 900000
BOOTSTRAP_COMPILER=	ada-bootstrap.${GARCH}.freebsd.84.tar.bz2
.  else
BOOTSTRAP_COMPILER=	ada-bootstrap.${GARCH}.freebsd.100B.tar.bz2
.  endif
.endif
.if ${OPSYS} == DragonFly
BOOTSTRAP_COMPILER=	ada-bootstrap.${GARCH}.dragonfly.36A.tar.bz2
.endif

WRKSRC=			${WRKDIR}/${IDENTIFICATION}
BUILDDIR=		${WRKDIR}/build
NEWBSDIR=		${WRKDIR}/newbs/bootstrap
CFG_SCRIPT=		${WRKSRC}/configure
REVFILE=		${WRKSRC}/gcc/REVISION
BOOTSTRAP_PREFIX=	${WRKDIR}/bootstrap
PKG_PREFIX=		${PREFIX}/${PORTNAME}
MANPREFIX=		${PREFIX}/${PORTNAME}/share
BSFILENAME=		ada-bootstrap.${GARCH}.${OPSYS:L}.${OSREL:S/.//}.tar.bz2

# If we find gnatmake and friends in a standard location, then we'll use this
# compiler instead of downloading the bootstrap.
.if exists (${LOCALBASE}/${PORTNAME}/bin/ada)
.if exists (${LOCALBASE}/${PORTNAME}/bin/gnatbind)
.if exists (${LOCALBASE}/${PORTNAME}/bin/gnatlink)
.if exists (${LOCALBASE}/${PORTNAME}/bin/gnatmake)
FULL_GNATGCC=${LOCALBASE}/${PORTNAME}/bin/ada
FULL_GNATGXX=${LOCALBASE}/${PORTNAME}/bin/g++
FULL_PATH=/sbin:/bin:/usr/sbin:/usr/bin:${PREFIX}/${PORTNAME}/bin:${PREFIX}/bin
.endif
.endif
.endif
.endif

# If FULL_GNATGCC is not set, we'll request the bootstrap compiler
.if ${FULL_GNATGCC} == NOT_SET
INTENDED_COMPILER=BOOTSTRAP
FULL_GNATGCC=${BOOTSTRAP_PREFIX}/bin/gcc
FULL_GNATGXX=${BOOTSTRAP_PREFIX}/bin/g++
FULL_PATH=${BOOTSTRAP_PREFIX}/bin:/sbin:/bin:/usr/sbin:/usr/bin:${PREFIX}/bin
DISTFILES+=	${BOOTSTRAP_COMPILER}:boot
.endif

# for port maintenance, invoke "make makesum PLUS_BOOTSTRAPS=1"
.if defined(PLUS_BOOTSTRAPS)
DISTFILES= \
   ${IDENTIFICATION}.tar.bz2 \
   ada-bootstrap.i386.dragonfly.36A.tar.bz2:boot \
   ada-bootstrap.i386.freebsd.84.tar.bz2:boot \
   ada-bootstrap.i386.freebsd.100B.tar.bz2:boot \
   ada-bootstrap.x86_64.dragonfly.36A.tar.bz2:boot \
   ada-bootstrap.x86_64.freebsd.84.tar.bz2:boot \
   ada-bootstrap.x86_64.freebsd.100B.tar.bz2:boot
.endif

.if ${PORT_OPTIONS:MFORT} && !${PORT_OPTIONS:MBOOTSTRAP}
LANGS+=		fortran
APPLY_DIFFS+=	fortran
EXTRA_CONFIG+=	--enable-libquadmath
.else
EXTRA_CONFIG+=	--disable-libquadmath
.endif

.if ${PORT_OPTIONS:MOBJC} && !${PORT_OPTIONS:MBOOTSTRAP}
LANGS+=		objc
.endif

.if ${PORT_OPTIONS:MTESTSUITE} && !${PORT_OPTIONS:MBOOTSTRAP}
BUILD_DEPENDS+=	dejagnu>=1.4:${PORTSDIR}/misc/dejagnu
APPLY_DIFFS+=	ada-testsuite
APPLY_DIFFS+=	fortran-testsuite
APPLY_DIFFS+=	cxx-testsuite
APPLY_DIFFS+=	gcc-testsuite
.endif

.if ${PORT_OPTIONS:MNLS} && !${PORT_OPTIONS:MBOOTSTRAP}
USES+=	gettext:build
EXTRA_CONFIG+=	--enable-nls
.else
EXTRA_CONFIG+=	--disable-nls
.endif

.if ${PORT_OPTIONS:MSTATIC} && !${PORT_OPTIONS:MBOOTSTRAP}
EXTRA_CONFIG+=		--with-stage1-ldflags=-static
.endif

.if ${PORT_OPTIONS:MBOOTSTRAP}
EXTRA_CONFIG+=		--disable-shared --disable-lto
EXTRA_CONFIG+=		--with-boot-ldflags=-static
.else
EXTRA_CONFIG+=		--disable-bootstrap
.endif

# Establish Ada-aware compiler for use
ADA_CONFIGURE_ENV+=	CC=${FULL_GNATGCC}
ADA_CONFIGURE_ENV+=	CXX=${FULL_GNATGXX}
ADA_CONFIGURE_ENV+=	PATH=${FULL_PATH}
ADA_MAKE_ENV+=		PATH=${FULL_PATH}
ADA_MAKE_ENV+=		LD_LIBRARY_PATH=${BUILDDIR}/gcc

# The standard configuration options
ADA_CONFIG_ARGS=	--enable-languages=${LANGS:Q}
ADA_CONFIG_ARGS+=	--build=${BLD_TARGET}
ADA_CONFIG_ARGS+=	--prefix=${PKG_PREFIX:Q}
ADA_CONFIG_ARGS+=	--with-system-zlib
ADA_CONFIG_ARGS+=	--with-gmp=${PREFIX}
ADA_CONFIG_ARGS+=	--with-mpfr=${PREFIX}
ADA_CONFIG_ARGS+=	--with-mpc=${PREFIX}
ADA_CONFIG_ARGS+=	${ICONV_CONFIGURE_ARG}
ADA_CONFIG_ARGS+=	--enable-shared
ADA_CONFIG_ARGS+=	--enable-threads=posix
ADA_CONFIG_ARGS+=	--disable-libmudflap
ADA_CONFIG_ARGS+=	--disable-libgomp
ADA_CONFIG_ARGS+=	--disable-libssp
ADA_CONFIG_ARGS+=	${EXTRA_CONFIG}

post-extract:
	# Personalize GNAT for each different machine
	@${ECHO} "-=> GNAT AUX ${OS_LABEL4VERS}" > ${REVFILE}
	# Create new directories in preparation of applying diff files
	${MKDIR} ${WRKSRC}/libstdc++-v3/config/locale/dragonfly
	${MKDIR} ${WRKSRC}/libstdc++-v3/config/os/bsd/dragonfly
	# Apply required composite diff files
.for suffix in ${APPLY_DIFFS}
	@${ECHO} "Applying composite patch diff-${suffix}"
	@${PATCH} -d ${WRKSRC} -s -E < ${FILESDIR}/diff-${suffix}
.endfor
.if ${PORT_OPTIONS:MSTATIC} || ${PORT_OPTIONS:MBOOTSTRAP}
	# Ensure GNAT tools are built statically
	${REINPLACE_CMD} -e 's/^GCC_LINK_FLAGS=.*/GCC_LINK_FLAGS=-static/' \
	  ${WRKSRC}/gcc/ada/gcc-interface/Makefile.in
.endif
.if ${PORT_OPTIONS:MBOOTSTRAP} && ${OPSYS} == FreeBSD
	# FreeBSD 8 linker doesn't understand --hash-style, so do not
	# allow the bootstrap to use it.
	${REINPLACE_CMD} -e 's|" ELF_HASH_STYLE "||' \
	  ${WRKSRC}/gcc/config/i386/freebsd64.h \
	  ${WRKSRC}/gcc/config/i386/freebsd.h
.endif
	# Update LINK_SPEC to add gcc-aux lib runpath in every binary
	@${ECHO} "Configuring LINK_SPEC runpath"
	@${REINPLACE_CMD} -e 's;\@PREFIX\@;${PREFIX};' \
	  ${WRKSRC}/gcc/config/dragonfly.h \
	  ${WRKSRC}/gcc/config/i386/freebsd64.h \
	  ${WRKSRC}/gcc/config/i386/freebsd.h

do-configure:
	${MKDIR} ${BUILDDIR}
	cd ${BUILDDIR} && ${SETENV} ${ADA_CONFIGURE_ENV} \
		${CFG_SCRIPT} ${ADA_CONFIG_ARGS}

do-build:
	cd ${BUILDDIR} && ${SETENV} ${ADA_MAKE_ENV} \
		${MAKE_CMD} -j${MAKE_JOBS_NUMBER} ${MAKE_ARGS} all

.if ${PORT_OPTIONS:MTESTSUITE} && !${PORT_OPTIONS:MBOOTSTRAP}
test: build test-ada test-fortran test-objc test-cxx test-c

test-ada:
	cd ${BUILDDIR} && ${SETENV} ${ADA_MAKE_ENV} \
		${MAKE_CMD} -sk check-ada

test-cxx:
	# libstdc++ testsuite will break every time, for TRUE to continue
	cd ${BUILDDIR} && ${SETENV} ${ADA_MAKE_ENV} \
		${MAKE_CMD} -sk check-c++ || true

test-c:
	cd ${BUILDDIR} && ${SETENV} ${ADA_MAKE_ENV} \
		${MAKE_CMD} -sk check-c

test-fortran:
.  if ${PORT_OPTIONS:MFORT}
	cd ${BUILDDIR} && ${SETENV} ${ADA_MAKE_ENV} \
		${MAKE_CMD} -sk check-fortran
.  endif

test-objc:
.  if ${PORT_OPTIONS:MOBJC}
	cd ${BUILDDIR} && ${SETENV} ${ADA_MAKE_ENV} \
		${MAKE_CMD} -sk check-objc
.  endif
.endif

do-install:
	cd ${BUILDDIR} && ${SETENV} ${ADA_MAKE_ENV} \
		${MAKE_CMD} install-strip ${MAKE_ARGS}
	${RM} -rf ${STAGEDIR}${PKG_PREFIX}/share/info

post-install:
	cd ${STAGEDIR}${PKG_PREFIX}; ${FIND} * -type d -empty | \
	   ${SORT} -dr | ${XARGS} ${RMDIR}
	cd ${STAGEDIR}${PREFIX}; \
	   ${FIND} ${PORTNAME} \( -type f -or -type l \) | \
	   ${SORT} | ${SED} -e 's/\/man\/man[1578]\/.*[1578]$$/&.gz/' \
	    >> ${TMPPLIST}
	cd ${STAGEDIR}${PREFIX}; ${FIND} ${PORTNAME} -type d | ${SORT} -r | \
	   ${SED} -e '/^share/d' -e 's/^/@dirrm /g' >> ${TMPPLIST}

.if ${PORT_OPTIONS:MBOOTSTRAP}
post-stage:
	${MKDIR} ${NEWBSDIR}
	${CP} -a ${STAGEDIR}${PKG_PREFIX}/bin ${NEWBSDIR}/
	${CP} -a ${STAGEDIR}${PKG_PREFIX}/lib ${NEWBSDIR}/
	${CP} -a ${STAGEDIR}${PKG_PREFIX}/include ${NEWBSDIR}/
	${CP} -a ${STAGEDIR}${PKG_PREFIX}/libexec ${NEWBSDIR}/
	${RM} ${NEWBSDIR}/bin/${GARCH}*
	${RM} -rf ${NEWBSDIR}/lib/gcc/${BLD_TARGET}/${GCC_VERSION}/include-fixed
	(cd ${NEWBSDIR}/.. ; ${TAR} -cyf ${BSFILENAME} bootstrap)
.endif

.include <bsd.port.mk>
