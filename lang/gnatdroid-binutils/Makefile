# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=		binutils
PORTVERSION=		2.21.1
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	binutils/releases
PKGNAMEPREFIX=		gnatdroid-

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Infrastructure for C/Ada Android cross-compiler

BUILD_DEPENDS=	gnatdroid-sysroot>=9:${PORTSDIR}/lang/gnatdroid-sysroot \
		${LOCALBASE}/lib/libgmp.so:${PORTSDIR}/math/gmp \
		${LOCALBASE}/lib/libmpfr.so:${PORTSDIR}/math/mpfr
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gmake
USE_BZIP2=	YES
HAS_CONFIGURE=	YES
NO_MTREE=	YES

WRKSRC=			${WRKDIR}/binutils-${PORTVERSION}
PREFIX=			${LOCALBASE}/android9
BRANCH1=		ARMv5
BRANCH2=		ARMv7
BR1_PREFIX=		${PREFIX}/${BRANCH1}
BR2_PREFIX=		${PREFIX}/${BRANCH2}
ARMTARGET=		arm-android-eabi
PLIST_SUB+=		TARGET="${ARMTARGET}"
PLIST_SUB+=		BRANCH1="${BRANCH1}"
PLIST_SUB+=		BRANCH2="${BRANCH2}"

CONFIGURE_ARGS+=	--target=${ARMTARGET}
CONFIGURE_ARGS+=	--prefix=${BR1_PREFIX}
CONFIGURE_ARGS+=	--with-sysroot=${PREFIX}
CONFIGURE_ARGS+=	--with-gmp=${LOCALBASE}
CONFIGURE_ARGS+=	--with-mpfr=${LOCALBASE}
CONFIGURE_ARGS+=	--disable-werror
CONFIGURE_ARGS+=	--disable-nls

post-install:
	${MKDIR} ${STAGEDIR}${BR2_PREFIX}
	(cd ${STAGEDIR}${BR1_PREFIX} && ${COPYTREE_BIN} \* \
		${STAGEDIR}${BR2_PREFIX})

.include <bsd.port.mk>
