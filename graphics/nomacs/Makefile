PORTNAME=	nomacs
DISTVERSION=	3.22.0
CATEGORIES=	graphics

MAINTAINER=	vidar@karlsen.tech
COMMENT=	Small, fast, and free image viewer
WWW=		https://www.nomacs.org/

LICENSE=	GPLv3

LIB_DEPENDS=	libexiv2.so:graphics/exiv2 \
		liblcms2.so:graphics/lcms2 \
		libopencv_core.so:graphics/opencv \
		libopencv_imgproc.so:graphics/opencv \
		libquazip1-qt6.so:archivers/quazip@qt6

USES=		cmake compiler:c++17-lang cpe desktop-file-utils dos2unix gl \
		kde:6 pkgconfig qt:6
DOS2UNIX_FILES=	ImageLounge/plugins/PaintPlugin/src/DkPaintPlugin.cpp \
		ImageLounge/src/DkGui/DkWidgets.cpp
USE_GITHUB=	yes
USE_GL=		opengl
USE_KDE=	kimageformats
USE_LDCONFIG=	yes
USE_QT=		5compat base imageformats svg tools

CMAKE_ARGS=		-DENABLE_QUAZIP=ON \
			-DUSE_SYSTEM_QUAZIP=ON
CMAKE_SOURCE_PATH=	${WRKSRC}/ImageLounge

PLIST_SUB=	SOVER=${DISTVERSION:R:R} \
		VERSION=${DISTVERSION}

OPTIONS_DEFINE=		NLS PLUGINS RAW TIFF
OPTIONS_DEFAULT=	PLUGINS RAW TIFF
OPTIONS_SUB=		yes

NLS_CMAKE_BOOL=		ENABLE_TRANSLATIONS

PLUGINS_CMAKE_ON=	ENABLE_PLUGINS

RAW_LIB_DEPENDS=	libraw.so:graphics/libraw
RAW_CMAKE_BOOL=		ENABLE_RAW

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_CMAKE_BOOL=	ENABLE_TIFF

.include <bsd.port.mk>
