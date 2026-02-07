PORTNAME=	ossim
DISTVERSION=	2.12.0
PORTREVISION=	3
CATEGORIES=	graphics geography
MASTER_SITES=	https://github.com/ossimlabs/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Powerful suite of geospatial libraries and applications
WWW=		https://github.com/ossimlabs/ossim

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfreetype.so:print/freetype2 \
		libgeos.so:graphics/geos \
		libgeotiff.so:graphics/libgeotiff \
		libjsoncpp.so:devel/jsoncpp \
		libtiff.so:graphics/tiff \
		libproj.so:graphics/proj

USES=		cmake compiler:c++17-lang jpeg sqlite
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_OSSIM_APPS \
		BUILD_OSSIM_ID_SUPPORT
CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_Git
CMAKE_ARGS=	-DBUILD_LIBRARY_DIR:STRING=lib \
		-DLIBSUFFIX:STRING="" \
		-DINSTALL_ARCHIVE_DIR:STRING=lib \
		-DINSTALL_LIBRARY_DIR:STRING=lib \
		-DOSSIM_INCLUDE_DIR:STRING=${WRKSRC}/include

OPTIONS_DEFINE=	TEST
OPTIONS_SUB=	yes

TEST_CMAKE_BOOL=       BUILD_OSSIM_TESTS

.include <bsd.port.mk>
