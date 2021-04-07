PORTNAME=	cpprestsdk
PORTVERSION=	2.10.16
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	projects@phess.net
COMMENT=	Microsoft C++ REST SDK

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../license.txt

BUILD_DEPENDS=	${LOCALBASE}/include/websocketpp/client.hpp:devel/websocketpp
LIB_DEPENDS=	libboost_system.so:devel/boost-libs

USES=		cmake compiler:c++11-lang pkgconfig ssl
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	Microsoft
WRKSRC_SUBDIR=	Release
CMAKE_OFF=	BUILD_SAMPLES BUILD_TESTS

CXXFLAGS+=	-Wno-c11-extensions

OPTIONS_DEFINE=	BROTLI

BROTLI_LIB_DEPENDS=	libbrotlidec.so:archivers/brotli
BROTLI_CMAKE_ON=	-DCPPREST_EXCLUDE_BROTLI:BOOL=OFF

.include <bsd.port.mk>
