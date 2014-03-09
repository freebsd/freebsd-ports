# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gcc47-aux
PORTVERSION=	${SNAPSHOT}
PORTREVISION=	4
CATEGORIES=	lang
MASTER_SITES=	http://downloads.dragonlace.net/src/:boot \
		${MASTER_SITE_GCC}
MASTER_SITE_SUBDIR=	releases/gcc-${GCC_VERSION}
DISTFILES=	gcc-${GCC_VERSION}.tar.bz2

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Version of GCC ${GCC_BRANCH} with full Ada support

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

.include "${.CURDIR}/Makefile.common"

LANGS=			c
APPLY_DIFFS=		core
INTENDED_COMPILER=	NATIVE
BOOTSTRAP_COMPILER=	NOT_REQUIRED
BOOTSTRAP_TRIPLET=	NOT_SET
FULL_GNATGCC=		NOT_SET
OS_LABEL4VERS=		[${OPSYS}]
GARCH=			${ARCH:S/amd64/x86_64/}
NO_LICENSES_INSTALL=	yes
NO_MTREE=		yes

OPTIONS_DEFINE=	ADA CXX FORT OBJC STATIC TESTSUITE NLS
OPTIONS_DEFAULT=	ADA CXX FORT OBJC
NO_OPTIONS_SORT=	yes

ADA_DESC=		Build Ada language
CXX_DESC=		Build C++ language
FORT_DESC=		Build Fortran language
OBJC_DESC=		Build Objective-C language
STATIC_DESC=		Build with no shared libraries other than libc
TESTSUITE_DESC=		Activate test support

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
.  if ${OSVERSION} < 900000
USE_BINUTILS=		yes
EXTRA_CONFIG+=		--with-as=${LOCALBASE}/bin/as
EXTRA_CONFIG+=		--with-ld=${LOCALBASE}/bin/ld
RUN_DEPENDS+=		${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils
.  endif
.  if ${GARCH} == x86_64
OS_LABEL4VERS=		[FreeBSD64]
BOOTSTRAP_TRIPLET=	x86_64-bootstrap-freebsd8.1/4.6.0
.  else
BOOTSTRAP_TRIPLET=	i386-bootstrap-freebsd8.0/4.6.0
.  endif
.endif
.if ${OPSYS} == DragonFly
.  if ${GARCH} == x86_64
OS_LABEL4VERS=		[DragonFly64]
BOOTSTRAP_TRIPLET=	x86_64-bootstrap-dragonfly2.8/4.6.0
.  else
BOOTSTRAP_TRIPLET=	i386-bootstrap-dragonfly2.8/4.6.0
.  endif
.endif
BLD_TARGET=		${GARCH}-aux-${OPSYS:L}${OSREL}
BOOTSTRAP_COMPILER=	gnat-bootstrap.${GARCH}.${OPSYS:L}.tar.bz2

WRKSRC=			${WRKDIR}/gcc-${GCC_VERSION}
BUILDDIR=		${WRKDIR}/build
CFG_SCRIPT=		${WRKSRC}/configure
REVFILE=		${WRKSRC}/gcc/REVISION
BOOTSTRAP_PREFIX=	${WRKDIR}/bootstrap
PKG_PREFIX=		${PREFIX}/${PORTNAME}
STICONV=		${PREFIX}/lib/libiconv.a
STINTL=			\$${top_builddir}/../intl/libintl.a
AWKMANPAGE=		'{if ($$0 ~ /^man\/man[1-9]\/.+[1-9]$$/) print $$0 ".gz"; else print $$0}'

# If we find gnatmake and friends in a standard location, then we'll use this
# compiler instead of downloading the bootstrap.
.if exists (${LOCALBASE}/${PORTNAME}/bin/ada)
.if exists (${LOCALBASE}/${PORTNAME}/bin/gnatbind)
.if exists (${LOCALBASE}/${PORTNAME}/bin/gnatlink)
.if exists (${LOCALBASE}/${PORTNAME}/bin/gnatmake)
FULL_GNATGCC=${LOCALBASE}/${PORTNAME}/bin/ada
FULL_PATH=/sbin:/bin:/usr/sbin:/usr/bin:${PREFIX}/${PORTNAME}/bin:${PREFIX}/bin
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
.if ${OPSYS} == DragonFly && ${DFLYVERSION} > 300500
BUILD_DEPENDS+=	${LOCALBASE}/lib/compat/libc.so.7:${PORTSDIR}/misc/compat34x
.endif
.endif

# for port maintenance, invoke "make makesum PLUS_BOOTSTRAPS=1"
.if defined(PLUS_BOOTSTRAPS)
DISTFILES=gcc-${GCC_VERSION}.tar.bz2 \
   gnat-bootstrap.i386.dragonfly.tar.bz2:boot \
   gnat-bootstrap.x86_64.dragonfly.tar.bz2:boot \
   gnat-bootstrap.i386.freebsd.tar.bz2:boot \
   gnat-bootstrap.x86_64.freebsd.tar.bz2:boot
.endif

###########
##  Ada  ##
###########

.if ${PORT_OPTIONS:MADA}
LANGS+=		ada
APPLY_DIFFS+=	ada
.endif

###########
##  C++  ##
###########

.if ${PORT_OPTIONS:MCXX}
LANGS+=		c++
APPLY_DIFFS+=	cxx
.endif

###############
##  Fortran  ##
###############

.if ${PORT_OPTIONS:MFORT}
LANGS+=		fortran
APPLY_DIFFS+=	fortran
EXTRA_CONFIG+=	--enable-libquadmath
.else
EXTRA_CONFIG+=	--disable-libquadmath
.endif

###################
##  Objective-C  ##
###################

.if ${PORT_OPTIONS:MOBJC}
LANGS+=		objc
.endif

#########################
##  Testsuite Support  ##
#########################

.if ${PORT_OPTIONS:MTESTSUITE}
BUILD_DEPENDS+=	dejagnu>=1.4:${PORTSDIR}/misc/dejagnu
APPLY_DIFFS+=	ada-testsuite
APPLY_DIFFS+=	fortran-testsuite
APPLY_DIFFS+=	cxx-testsuite
APPLY_DIFFS+=	gcc-testsuite
.endif

#################################
##  NATIONAL LANGUAGE SUPPORT  ##
#################################

.if ${PORT_OPTIONS:MNLS}
USES+=	gettext:build
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
ADA_CONFIG_ARGS+=	${ICONV_CONFIGURE_ARG}
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
.if ${PORT_OPTIONS:MCXX}
	${MKDIR} ${WRKSRC}/libstdc++-v3/config/locale/dragonfly
	${MKDIR} ${WRKSRC}/libstdc++-v3/config/os/bsd/dragonfly
.endif

	# Apply required composite diff files
.for suffix in ${APPLY_DIFFS}
	@${ECHO} "Applying composite patch diff-${suffix}"
	@${PATCH} -d ${WRKSRC} -s -E < ${FILESDIR}/diff-${suffix}
.endfor

	# Update LINK_SPEC to add gcc47-aux lib runpath in every binary
	@${ECHO} "Configuring LINK_SPEC runpath"
	@${REINPLACE_CMD} -e 's;\@PREFIX\@;${PREFIX};' \
	  ${WRKSRC}/gcc/config/dragonfly.h \
	  ${WRKSRC}/gcc/config/i386/freebsd64.h \
	  ${WRKSRC}/gcc/config/i386/freebsd.h

.if ${PORT_OPTIONS:MSTATIC}
	@${ECHO} "Reconfiguring GCC Makefile to build compiler statically"
	@${PATCH} -d ${WRKSRC} -s -E < ${FILESDIR}/diff-static-version
.if ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's;\@LIBINTL\@;${STINTL} ${STICONV};' \
	  ${WRKSRC}/intl/config.intl.in
	@${REINPLACE_CMD} -e 's;\@LIBICONV\@;;' \
	  ${WRKSRC}/gcc/Makefile.in \
	  ${WRKSRC}/libcpp/Makefile.in \
	  ${WRKSRC}/gcc/ada/gcc-interface/Makefile.in
.else
	@${REINPLACE_CMD} -e 's;\@LIBICONV\@;${STICONV};' \
	  ${WRKSRC}/gcc/Makefile.in \
	  ${WRKSRC}/libcpp/Makefile.in \
	  ${WRKSRC}/gcc/ada/gcc-interface/Makefile.in
.endif
.endif

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
	${CFG_SCRIPT} ${ADA_CONFIG_ARGS}

do-build:
	cd ${BUILDDIR} && ${SETENV} ${ADA_MAKE_ENV} ${GMAKE} -j${MAKE_JOBS_NUMBER} all

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
	cd ${BUILDDIR} && ${SETENV} ${ADA_MAKE_ENV} ${GMAKE} install-strip DESTDIR=${STAGEDIR}

post-install:
	${MV} ${STAGEDIR}${PKG_PREFIX}/share/man ${STAGEDIR}/${PKG_PREFIX}
	cd ${STAGEDIR}${PKG_PREFIX}; ${FIND} * -type d -empty | \
	   ${SORT} -dr | ${XARGS} ${RMDIR}
	cd ${STAGEDIR}${PREFIX}; ${FIND} ${PORTNAME} \( -type f -or -type l \) | \
	   ${AWK} ${AWKMANPAGE} | ${SORT} >> ${TMPPLIST}
	cd ${STAGEDIR}${PREFIX}; ${FIND} ${PORTNAME} -type d | ${SORT} -r | \
	   ${SED} -E -e 's/^/@dirrm /g' >> ${TMPPLIST}

.include <bsd.port.mk>
