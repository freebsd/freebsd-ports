# $FreeBSD$

PORTNAME=	nomacs
PORTVERSION=	3.14.2
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	vidar@karlsen.tech
COMMENT=	Small, fast, and free image viewer

LICENSE=	GPLv3

LIB_DEPENDS=	libexiv2.so:graphics/exiv2 \
		libopencv_highgui.so:graphics/opencv \
		libopencv_core.so:graphics/opencv-core \
		liblcms2.so:graphics/lcms2 \
		libquazip5.so:archivers/quazip

USES=		cmake compiler:c++11-lang desktop-file-utils \
		dos2unix pkgconfig qt:5
USE_QT=		concurrent core gui network printsupport svg widgets \
		buildtools_build linguisttools_build qmake_build
DOS2UNIX_FILES=	ImageLounge/plugins/PaintPlugin/src/DkPaintPlugin.cpp \
		ImageLounge/src/DkGui/DkWidgets.cpp

USE_LDCONFIG=	yes

USE_GITHUB=	yes

CMAKE_ARGS=		-DUSE_SYSTEM_QUAZIP=ON
CMAKE_SOURCE_PATH=	${WRKSRC}/ImageLounge

OPTIONS_DEFINE=		RAW TIFF TRANSLATIONS PLUGINS
OPTIONS_DEFAULT=	RAW TIFF TRANSLATIONS PLUGINS
OPTIONS_SUB=		yes

RAW_LIB_DEPENDS=	libraw.so:graphics/libraw
RAW_CMAKE_BOOL=		ENABLE_RAW

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_CMAKE_BOOL=	ENABLE_TIFF

TRANSLATIONS_CMAKE_BOOL=	ENABLE_TRANSLATIONS
TRANSLATIONS_DESC=		Install translations

PLUGINS_GH_TUPLE=	nomacs:nomacs-plugins:3.14:plugins/ImageLounge/plugins
PLUGINS_CMAKE_ON=	ENABLE_PLUGINS

.include <bsd.port.mk>
