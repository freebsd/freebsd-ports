PORTNAME=	CRoaring
DISTVERSIONPREFIX=	v
DISTVERSION=	5.2.0
CATEGORIES=	devel

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Roaring bitmaps in C (and C++), with SIMD
WWW=		http://roaringbitmap.org/ \
		https://github.com/RoaringBitmap/CRoaring

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/cmocka.h:sysutils/cmocka

USES=		pkgconfig cmake:testing
USE_GITHUB=	yes
GH_ACCOUNT=	RoaringBitmap

USE_LDCONFIG=	yes

CMAKE_OFF=	ROARING_USE_CPM ${CMAKE_OFF_${ARCH}}
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS_armv7=	-DROARING_DISABLE_NEON:BOOL=TRUE
CMAKE_ARGS+=	${CMAKE_ARGS_${ARCH}}

PLIST_SUB=	DISTVERSION=${DISTVERSION}

.include <bsd.port.mk>
