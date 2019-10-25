# $FreeBSD$

PORTNAME=	ossim
DISTVERSIONPREFIX=	Neptune-
DISTVERSION=	2.10.0
CATEGORIES=	graphics geography

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	Powerful suite of geospatial libraries and applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${LOCALBASE}/bin/git:devel/git
LIB_DEPENDS=	libgeos.so:graphics/geos \
		libgeotiff.so:graphics/libgeotiff \
		libjsoncpp.so:devel/jsoncpp \
		libtiff.so:graphics/tiff \
		libopenjp2.so:graphics/openjpeg \
		libfreetype.so:print/freetype2 \
		libOpenThreads.so:graphics/osg

USES=		cmake compiler:c++11-lang jpeg localbase
USE_GITHUB=	yes
GH_ACCOUNT=	ossimlabs
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_OSSIM_APPS
CMAKE_ARGS=	-DBUILD_LIBRARY_DIR:STRING=lib \
		-DLIBSUFFIX:STRING="" \
		-DINSTALL_ARCHIVE_DIR:STRING=lib \
		-DINSTALL_LIBRARY_DIR:STRING=lib \
		-DOSSIM_INCLUDE_DIR:STRING=${WRKSRC}/include

OPTIONS_DEFINE=	TEST
OPTIONS_SUB=	yes

TEST_CMAKE_BOOL=	BUILD_OSSIM_TESTS

.include <bsd.port.mk>
