PORTNAME=	jwt-cpp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	kiwi@FreeBSD.org
COMMENT=	C++ library for jwt
WWW=		https://thalhammer.github.io/jwt-cpp/

LICENSE=	MIT

BUILD_DEPENDS=	nlohmann-json>=3.11:devel/nlohmann-json \
		jsoncpp>=1.9:devel/jsoncpp

USES=		cmake pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	Thalhammer

CMAKE_ARGS+=	-DJWT_CMAKE_FILES_INSTALL_DIR=${PREFIX}/lib/cmake/jwt-cpp

CMAKE_ON=	JWT_ENABLE_COVERAGE \
		JWT_ENABLE_FUZZING \
		JWT_EXTERNAL_NLOHMANN_JSON

CMAKE_OFF=	JWT_BUILD_EXAMPLES \
		JWT_BUILD_TESTS \
		JWT_BUILD_DOCS \
		JWT_EXTERNAL_PICOJSON

.include <bsd.port.mk>
