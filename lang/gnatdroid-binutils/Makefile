# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=		binutils
PORTVERSION=		2.24
PORTREVISION=		2
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	binutils/releases
PKGNAMEPREFIX=		gnatdroid-

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Infrastructure for C/Ada Android cross-compiler

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

BUILD_DEPENDS=	gnatdroid-sysroot=19:${PORTSDIR}/lang/gnatdroid-sysroot \
		${LOCALBASE}/lib/libgmp.so:${PORTSDIR}/math/gmp \
		${LOCALBASE}/lib/libmpfr.so:${PORTSDIR}/math/mpfr
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gmake tar:bzip2
HAS_CONFIGURE=	yes
NO_MTREE=	yes

NO_LICENSES_INSTALL= yes

WRKSRC=			${WRKDIR}/binutils-${PORTVERSION}
PREFIX=			${LOCALBASE}/android19
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
#	Move the unwanted documentation out of the stage directory
	${MV} ${STAGEDIR}${BR1_PREFIX}/share ${WRKDIR}
	${MKDIR} ${STAGEDIR}${BR2_PREFIX}
	(cd ${STAGEDIR}${BR1_PREFIX} && ${COPYTREE_BIN} \* \
		${STAGEDIR}${BR2_PREFIX})

.include <bsd.port.mk>
