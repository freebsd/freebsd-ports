PORTNAME=	CRoaring
DISTVERSIONPREFIX=	v
DISTVERSION=	5.2.2
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

CMAKE_OFF=	ROARING_USE_CPM
CMAKE_ON=	BUILD_SHARED_LIBS

PLIST_SUB=	DISTVERSION=${DISTVERSION}

.include <bsd.port.mk>
