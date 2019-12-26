# $FreeBSD$

PORTNAME=	nomacs
PORTVERSION=	3.6.1
PORTREVISION=	9
CATEGORIES=	graphics

MAINTAINER=	bsd@tuxproject.de
COMMENT=	Small, fast, and free image viewer

LICENSE=	GPLv3

LIB_DEPENDS=	libexiv2.so:graphics/exiv2 \
		libsysinfo.so:devel/libsysinfo \
		libopencv_highgui.so:graphics/opencv \
		libopencv_core.so:graphics/opencv-core \
		liblcms2.so:graphics/lcms2 \
		libtbb.so:devel/tbb

USES=		cmake compiler:c++11-lang desktop-file-utils dos2unix \
		pkgconfig qt:5 tar:bzip2
USE_QT=		concurrent core gui network printsupport svg widgets \
		buildtools_build linguisttools_build qmake_build

DOS2UNIX_REGEX=	.*\.(cpp|h|txt)

OPTIONS_DEFINE=	RAW TIFF
OPTIONS_DEFAULT=	RAW TIFF

RAW_LIB_DEPENDS=	libraw.so:graphics/libraw
RAW_CMAKE_BOOL=		ENABLE_RAW

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_CMAKE_BOOL=		ENABLE_TIFF

USE_GITHUB=	yes
WRKSRC_SUBDIR=	ImageLounge

.include <bsd.port.mk>
