# New ports collection makefile for:	gnatdroid-armv7
# Date created:				2011-07-20
# Whom:					John Marino <draco@marino>
#
# $FreeBSD$
#

PORTNAME=	armv7
PORTVERSION=	20110627
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://downloads.dragonlace.net/src/ \
		http://dragonlace.mirrors.ada.cx/src/
PKGNAMEPREFIX=	gnatdroid-
DISTNAME=	arm-gnat-${PORTVERSION}

MAINTAINER=	draco@marino.st
COMMENT=	C/Ada cross-compiler, target: Android ARMv7

BUILD_DEPENDS=	gnatdroid-sysroot>=9:${PORTSDIR}/lang/gnatdroid-sysroot \
		gnatdroid-binutils>=2.21:${PORTSDIR}/lang/gnatdroid-binutils \
		${LOCALBASE}/lib/libgmp.so:${PORTSDIR}/math/gmp \
		${LOCALBASE}/lib/libmpfr.so:${PORTSDIR}/math/mpfr \
		${LOCALBASE}/lib/libmpc.so:${PORTSDIR}/math/mpc
RUN_DEPENDS:=	${BUILD_DEPENDS}
BUILD_DEPENDS+=	gnat-aux>=20110325:${PORTSDIR}/lang/gnat-aux

USE_BZIP2=	YES
USE_GMAKE=	YES
HAS_CONFIGURE=	YES
USE_ICONV=	YES
USE_BISON=	build
ALL_TARGET=	default
NO_MTREE=	YES
MAKE_JOBS_SAFE=	YES

DROID_TARGET=		arm-android-eabi
DROID_ARCH=		armv7-a
ARMVERSION=		ARMv7
FPU=			neon
GCC_BRANCH=		4.6
GCC_VERSION=		4.6.1
WRKSRC=			${WRKDIR}/gcc-${GCC_BRANCH}-${PORTVERSION}
BUILDDIR=		${WRKDIR}/build
CFG_SCRIPT=		${WRKSRC}/configure
REVFILE=		${WRKSRC}/gcc/REVISION
SRPREFIX=		${LOCALBASE}/android9
PREFIX=			${SRPREFIX}/${ARMVERSION}
FULL_GNATGCC=		${LOCALBASE}/bin/gnatgcc
PLIST_SUB+=		TARGET="${DROID_TARGET}"
PLIST_SUB+=		GCCVERS="${GCC_VERSION}"

ADA_CONFIGURE_ENV=	CC=${FULL_GNATGCC}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
OS_LABEL4VERS=	"[FreeBSD64 x Android ${ARMVERSION}]"
.else
OS_LABEL4VERS=	"[FreeBSD32 x Android ${ARMVERSION}]"
.endif

CONFIGURE_ARGS=		--enable-languages=c,ada
CONFIGURE_ARGS+=	--target=${DROID_TARGET}
CONFIGURE_ARGS+=	--program-prefix=${DROID_TARGET}-
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-arch=${DROID_ARCH}
CONFIGURE_ARGS+=	--with-system-zlib
CONFIGURE_ARGS+=	--with-gmp=${LOCALBASE}
CONFIGURE_ARGS+=	--with-mpfr=${LOCALBASE}
CONFIGURE_ARGS+=	--with-mpc=${LOCALBASE}
CONFIGURE_ARGS+=	--with-libiconv-prefix=${LOCALBASE}
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
CONFIGURE_ARGS+=	--disable-libstdcxx-pch
CONFIGURE_ARGS+=	--disable-tls
CONFIGURE_ARGS+=	--disable-nls

post-extract:
	# Personalize GNAT for each different machine
	@${ECHO} "-=> GNAT AUX ${OS_LABEL4VERS}" > ${REVFILE}

do-configure:
	${MKDIR} ${BUILDDIR}
	cd ${BUILDDIR} && ${SETENV} ${ADA_CONFIGURE_ENV} \
	${CFG_SCRIPT} ${CONFIGURE_ARGS}

do-build:
	cd ${BUILDDIR} && ${GMAKE} ${_MAKE_JOBS} all

do-install:
	cd ${BUILDDIR} && ${GMAKE} install-strip DESTDIR=${DESTDIR}
	${MV} ${PREFIX}/bin/${DROID_TARGET}-gcc \
	   ${PREFIX}/bin/${DROID_TARGET}-gnatgcc
	${MV} ${PREFIX}/${DROID_TARGET}/bin/gcc \
	   ${PREFIX}/${DROID_TARGET}/bin/gnatgcc

post-install:
.for d in lib/gcc libexec/gcc share
	cd ${PREFIX}; ${FIND} $d \( -type f -or -type l \) | ${SORT} >> ${TMPPLIST}
	cd ${PREFIX}; ${FIND} $d -type d | ${SORT} -dr | \
	   ${SED} -e 's/^/@dirrm /g' >> ${TMPPLIST}
.endfor
	@${ECHO} "@dirrm include" >> ${TMPPLIST}
	@${ECHO} "@dirrm libexec" >> ${TMPPLIST}
	@${ECHO} "@dirrm lib" >> ${TMPPLIST}

	@${ECHO} "============================================================"
	@${ECHO} "  Add to path: ${PREFIX}/bin"
	@${ECHO} "  All binaries have prefix of ${DROID_TARGET}-"
	@${ECHO} "  e.g. ${DROID_TARGET}-gnatgcc"
	@${ECHO} "       ${DROID_TARGET}-gnatmake"
	@${ECHO} "============================================================"

.include <bsd.port.post.mk>
