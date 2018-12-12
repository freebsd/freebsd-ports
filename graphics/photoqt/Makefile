# $FreeBSD$

PORTNAME=	photoqt
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6
PORTREVISION=	3
CATEGORIES=	graphics

MAINTAINER=	melanhit@gmail.com
COMMENT=	Simple, powerful and good looking QT5 image viewer

LICENSE=	GPLv2

USES=		cmake:outsource compiler:c++11-lib desktop-file-utils \
		localbase:ldflags qt:5
USE_QT=		core declarative graphicaleffects gui multimedia network \
		quickcontrols sql svg widgets xml \
		buildtools_build linguisttools_build qmake_build

USE_GITHUB=	yes
GH_ACCOUNT=	luspi

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
