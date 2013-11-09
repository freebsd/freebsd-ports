# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	armv7
PORTVERSION=	${SNAPSHOT}
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GCC}
MASTER_SITE_SUBDIR=	releases/gcc-${GCC_VERSION}
PKGNAMEPREFIX=	gnatdroid-
DISTNAME=	arm-gnat-${PORTVERSION}
DISTFILES=	gcc-core-${GCC_VERSION}.tar.bz2 \
		gcc-ada-${GCC_VERSION}.tar.bz2 \
		gcc-testsuite-${GCC_VERSION}.tar.bz2

MAINTAINER=	marino@FreeBSD.org
COMMENT=	C/Ada cross-compiler, target: Android ARMv7

LICENSE=	GPLv3

BUILD_DEPENDS=	gnatdroid-sysroot>=9:${PORTSDIR}/lang/gnatdroid-sysroot \
		gnatdroid-binutils>=2.21:${PORTSDIR}/lang/gnatdroid-binutils \
		gnat-aux>=20110325:${PORTSDIR}/lang/gnat-aux
RUN_DEPENDS:=	gnatdroid-sysroot>=9:${PORTSDIR}/lang/gnatdroid-sysroot \
		gnatdroid-binutils>=2.21:${PORTSDIR}/lang/gnatdroid-binutils

NO_LICENSES_INSTALL= yes

.include "${.CURDIR}/../gnat-aux/Makefile.common"

LANGS=		c ada
APPLY_DIFFS=	core ada ada-testsuite gcc-testsuite
NO_MTREE=	YES

# Disable C++ until arm.cc/no-rtti issue resolved for libsupc++

OPTIONS_DEFINE=		FORT OBJC #CXX
OPTIONS_DEFAULT=
OPTIONS_SUB=		yes
CXX_DESC=		Also build c++ language
FORT_DESC=		Also build Fortran language
OBJC_DESC=		Also build Objective-C language

DROID_TARGET=		arm-android-eabi
DROID_ARCH=		armv7-a
ARMVERSION=		ARMv7
FPU=			neon
WRKSRC=			${WRKDIR}/gcc-${GCC_VERSION}
BUILD_WRKSRC=		${WRKDIR}/build
PATCHDIR=		${.CURDIR}/../gnat-aux/files
CFG_SCRIPT=		${WRKSRC}/configure
REVFILE=		${WRKSRC}/gcc/REVISION
SRPREFIX=		${LOCALBASE}/android9
PREFIX=			${SRPREFIX}/${ARMVERSION}
FULL_GNATGCC=		${LOCALBASE}/bin/gnatgcc
INSTALLDIRS=		lib libexec share
INSTALLDIRS+=		${DROID_TARGET}/lib
PLIST_SUB+=		TARGET="${DROID_TARGET}"
PLIST_SUB+=		GCCVERS="${GCC_VERSION}"
SUB_FILES=		pkg-message
SUB_LIST=		TARGET="${DROID_TARGET}"

ADA_CONFIGURE_ENV=	CC=${FULL_GNATGCC}
ALL_TARGET=		all

.include <bsd.port.pre.mk>

.if ${ARCH:S/amd64/x86_64/} == x86_64
OS_LABEL4VERS=	"[${OPSYS}64 x Android ${ARMVERSION}]"
.else
OS_LABEL4VERS=	"[${OPSYS}32 x Android ${ARMVERSION}]"
.endif

###########
##  C++  ##
###########

.if ${PORT_OPTIONS:MCXX}
LANGS+=		c++
APPLY_DIFFS+=	cxx cxx-testsuite
DISTFILES+=	gcc-g++-${GCC_VERSION}.tar.bz2
INSTALLDIRS+=	include/c++/${GCC_VERSION}
.endif

###############
##  Fortran  ##
###############

.if ${PORT_OPTIONS:MFORT}
LANGS+=		fortran
APPLY_DIFFS+=	fortran
DISTFILES+=	gcc-fortran-${GCC_VERSION}.tar.bz2
.endif

###################
##  Objective-C  ##
###################

.if ${PORT_OPTIONS:MOBJC}
LANGS+=		objc
DISTFILES+=	gcc-objc-${GCC_VERSION}.tar.bz2
.endif

CONFIGURE_ARGS=		--enable-languages=${LANGS:Q}
CONFIGURE_ARGS+=	--target=${DROID_TARGET}
CONFIGURE_ARGS+=	--program-prefix=${DROID_TARGET}-
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-arch=${DROID_ARCH}
CONFIGURE_ARGS+=	--with-system-zlib
CONFIGURE_ARGS+=	--with-gmp=${LOCALBASE}
CONFIGURE_ARGS+=	--with-mpfr=${LOCALBASE}
CONFIGURE_ARGS+=	--with-mpc=${LOCALBASE}
CONFIGURE_ARGS+=	${ICONV_CONFIGURE_ARG}
CONFIGURE_ARGS+=	--with-sysroot=${SRPREFIX}
CONFIGURE_ARGS+=	--with-float=soft
CONFIGURE_ARGS+=	--with-fpu=${FPU}
CONFIGURE_ARGS+=	--enable-target-optspace
CONFIGURE_ARGS+=	--enable-threads=posix
CONFIGURE_ARGS+=	--disable-bootstrap
CONFIGURE_ARGS+=	--disable-shared
CONFIGURE_ARGS+=	--disable-libssp
CONFIGURE_ARGS+=	--disable-libgomp
CONFIGURE_ARGS+=	--disable-libmudflap
CONFIGURE_ARGS+=	--disable-libquadmath
CONFIGURE_ARGS+=	--disable-sjlj-exceptions
CONFIGURE_ARGS+=	--disable-tls
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
	@${PATCH} -d ${WRKSRC} -s -E < ${PATCHDIR}/diff-${suffix}
.endfor

do-configure:
	${MKDIR} ${BUILD_WRKSRC}
	cd ${BUILD_WRKSRC} && ${SETENV} ${ADA_CONFIGURE_ENV} \
	${CFG_SCRIPT} ${CONFIGURE_ARGS}

pre-install:
	# The "native tools" won't install unless a directory exists
	${MKDIR} ${STAGEDIR}${PREFIX}/${DROID_TARGET}/bin 

do-install:
	cd ${BUILD_WRKSRC} && ${GMAKE} install-strip DESTDIR=${STAGEDIR}
	${MV} ${STAGEDIR}${PREFIX}/bin/${DROID_TARGET}-gcc \
	   ${STAGEDIR}${PREFIX}/bin/${DROID_TARGET}-gnatgcc
	${MV} ${STAGEDIR}${PREFIX}/${DROID_TARGET}/bin/gcc \
	   ${STAGEDIR}${PREFIX}/${DROID_TARGET}/bin/gnatgcc
.if ${PORT_OPTIONS:MFORT}
	${MV} ${STAGEDIR}${PREFIX}/bin/${DROID_TARGET}-gfortran \
	   ${STAGEDIR}${PREFIX}/bin/${DROID_TARGET}-gnatgfortran
	${MV} ${STAGEDIR}${PREFIX}/${DROID_TARGET}/bin/gfortran \
	   ${STAGEDIR}${PREFIX}/${DROID_TARGET}/bin/gnatgfortran
.endif

post-install:
.for d in ${INSTALLDIRS}
	cd ${STAGEDIR}${PREFIX}; ${FIND} $d \( -type f -or -type l \) | \
		${SORT} >> ${TMPPLIST}
.endfor
.for loop in A B
	cd ${STAGEDIR}${PREFIX}; ${FIND} * -type d -empty | \
		${SORT} -dr | ${XARGS} ${RMDIR}
.endfor
	cd ${STAGEDIR}${PREFIX}; ${FIND} * -type d | ${SORT} -dr | \
	   ${SED} -e '/^bin$$/d' \
	   -e '/^${DROID_TARGET}\/bin$$/d' \
	   -e '/^${DROID_TARGET}\/lib$$/d' \
	   -e '/^${DROID_TARGET}$$/d' \
	   -e 's/^/@dirrm /g' >> ${TMPPLIST}

.include <bsd.port.post.mk>
