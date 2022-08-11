PORTNAME=	binutils
PORTVERSION=	2.27
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	SOURCEWARE/binutils/releases
PKGNAMEPREFIX?=	gnatdroid-

MAINTAINER?=	jamie@catflap.org
COMMENT?=	Infrastructure for C/Ada Android cross-compiler (ARMv7)

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

BUILD_DEPENDS=	${SYSROOT}>0:lang/${SYSROOT} \
		${LOCALBASE}/lib/libgmp.so:math/gmp \
		${LOCALBASE}/lib/libmpfr.so:math/mpfr
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		cpe gmake tar:bzip2
CPE_VENDOR=	gnu
HAS_CONFIGURE=	yes
NO_MTREE=	yes

NO_LICENSES_INSTALL=	yes

WRKSRC=			${WRKDIR}/binutils-${PORTVERSION}
PREFIX?=		${LOCALBASE}/android
SRPREFIX?=		${PREFIX}
BRANCH2?=		ARMv7
BR2_PREFIX=		${PREFIX}/${BRANCH2}
XCCTARGET?=		arm-aux-linux-androideabi
SYSROOT?=		gnatdroid-sysroot
PLIST_SUB+=		TARGET="${XCCTARGET}"
PLIST_SUB+=		BRANCH2="${BRANCH2}"

CONFIGURE_ARGS+=	--target=${XCCTARGET}
CONFIGURE_ARGS+=	--prefix=${BR2_PREFIX}
CONFIGURE_ARGS+=	--with-sysroot=${SRPREFIX}
CONFIGURE_ARGS+=	--with-gmp=${LOCALBASE}
CONFIGURE_ARGS+=	--with-mpfr=${LOCALBASE}
CONFIGURE_ARGS+=	--disable-werror
CONFIGURE_ARGS+=	--disable-nls

post-install:
#	Move the unwanted documentation out of the stage directory
	${MV} ${STAGEDIR}${BR2_PREFIX}/share ${WRKDIR}

.include <bsd.port.mk>
