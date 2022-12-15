PORTNAME=	snmalloc
DISTVERSION?=	0.6.1.g20221223
CATEGORIES=	devel

MAINTAINER=	nfilardo@microsoft.com
COMMENT=	High-performance memory allocator
WWW=		https://github.com/microsoft/snmalloc

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++17-lang

PLIST_SUB=	PKGNAMESUFFIX=${PKGNAMESUFFIX}

USE_GITHUB=	yes
GH_ACCOUNT?=	microsoft
GH_PROJECT?=	snmalloc
GH_TAGNAME?=	4e88b426219163c1fc1626bc9733e1f423cc741e
CMAKE_ARGS+=	-DCMAKE_INSTALL_LIBDIR:STRING=lib/snmalloc${PKGNAMESUFFIX}

CXXFLAGS+=	-DNDEBUG
CMAKE_OFF+=	BUILD_TESTING

.include <bsd.port.mk>
