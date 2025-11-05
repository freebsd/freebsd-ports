PORTNAME=	proj
DISTVERSION=	9.7.0
PORTEPOCH=	1
CATEGORIES=	graphics geography
MASTER_SITES=	https://github.com/OSGeo/PROJ/releases/download/${DISTVERSION}/ \
		https://download.osgeo.org/proj/

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Cartographic Projections library
WWW=		https://github.com/OSGeo/PROJ

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	nlohmann-json>=3:devel/nlohmann-json
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libtiff.so:graphics/tiff
TEST_DEPENDS=	googletest>0:devel/googletest
#RUN_DEPENDS=	proj-data>=0:graphics/proj-data

USES=		compiler:c++17-lang cmake:testing cpe pathfix pkgconfig sqlite
CPE_VENDOR=	proj_project
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_TESTING
CMAKE_TESTING_OFF=	TESTING_USE_NETWORK
CMAKE_TESTING_ON=	BUILD_TESTING \
			USE_EXTERNAL_GTEST

PLIST_SUB=	DISTVERSION=${DISTVERSION}

.include <bsd.port.mk>
