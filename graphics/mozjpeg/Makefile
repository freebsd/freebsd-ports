# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	mozjpeg
PORTVERSION=	4.0.3
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Improved JPEG encoder by Mozilla

LICENSE=	BSD3CLAUSE

BROKEN_mips64=	does not configure: error: SIMD support cannot be enabled
BROKEN_sparc64=	does not configure: error: SIMD support cannot be enabled

BUILD_DEPENDS=	nasm>=2.10,1:devel/nasm
LIB_DEPENDS=	libpng.so:graphics/png

USES=		cmake

CMAKE_OFF=	REQUIRE_SIMD WITH_12BIT WITH_ARITH_DEC WITH_ARITH_ENC WITH_JAVA WITH_JPEG7
CMAKE_ON=	ENABLE_SHARED ENABLE_STATIC FORCE_INLINE PNG_SUPPORTED WITH_JPEG8 WITH_MEM_SRCDST WITH_SIMD WITH_TURBOJPEG
USE_LDCONFIG=	yes

GH_ACCOUNT=	mozilla
USE_GITHUB=	yes

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
