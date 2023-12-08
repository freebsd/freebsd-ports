PORTNAME=	photoqt
DISTVERSIONPREFIX=	v
DISTVERSION=	3.4
CATEGORIES=	graphics

MAINTAINER=	melanhit@gmail.com
COMMENT=	Simple, powerful and good looking QT5 image viewer
WWW=		https://photoqt.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreeimage.so:graphics/freeimage \
		libIL.so:graphics/devil \
		libmpv.so:multimedia/mpv \
		libpoppler.so:graphics/poppler \
		libpoppler-qt5.so:graphics/poppler-qt5 \
		libpugixml.so:textproc/pugixml

USES=		cmake compiler:c++11-lib desktop-file-utils \
		kde:5 libarchive localbase:ldflags magick:7 qt:5
USE_QT=		concurrent core dbus declarative graphicaleffects gui multimedia \
		printsupport network quickcontrols sql svg widgets xml \
		buildtools:build concurrent:build linguisttools:build qmake:build
USE_KDE=	ecm:build

USE_GITHUB=	yes
GH_ACCOUNT=	luspi

CMAKE_OFF=	CHROMECAST # requires the chromecast Python module

OPTIONS_DEFINE=	EXIV2 RAW GM
OPTIONS_DEFAULT=EXIV2

EXIV2_CMAKE_BOOL=	EXIV2
EXIV2_DESC=		Metadata editing
EXIV2_LIB_DEPENDS=	libexiv2.so:graphics/exiv2

RAW_CMAKE_BOOL=		RAW
RAW_DESC=		Raw image support
RAW_LIB_DEPENDS=	libraw.so:graphics/libraw

GM_CMAKE_BOOL=		GM
GM_DESC=		GraphicsMagick image processing
GM_LIB_DEPENDS=		libGraphicsMagick.so:graphics/GraphicsMagick

.include <bsd.port.mk>
