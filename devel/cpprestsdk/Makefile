PORTNAME=	cpprestsdk
PORTVERSION=	2.10.19
PORTREVISION=	8
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	sigsegv@radiotube.org
COMMENT=	Microsoft C++ REST SDK
WWW=		https://github.com/Microsoft/cpprestsdk

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../license.txt

DEPRECATED=	Deprecated upstream, does not build with CMake 4
EXPIRATION_DATE=2026-11-30

BUILD_DEPENDS=	${LOCALBASE}/include/websocketpp/client.hpp:devel/websocketpp
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		cmake:testing compiler:c++11-lang pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	Microsoft
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_SAMPLES BUILD_TESTS WERROR
CMAKE_TESTING_ON=	BUILD_TESTS

WRKSRC_SUBDIR=	Release

OPTIONS_DEFINE=	BROTLI

BROTLI_LIB_DEPENDS=	libbrotlidec.so:archivers/brotli
BROTLI_CMAKE_ON=	-DCPPREST_EXCLUDE_BROTLI:BOOL=OFF

.include <bsd.port.mk>
