PORTNAME=	photoqt
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6
PORTREVISION=	10
CATEGORIES=	graphics

MAINTAINER=	melanhit@gmail.com
COMMENT=	Simple, powerful and good looking QT5 image viewer
WWW=		https://photoqt.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lib desktop-file-utils \
		localbase:ldflags qt:5
USE_QT=		core declarative graphicaleffects gui multimedia network \
		quickcontrols sql svg widgets xml \
		buildtools:build linguisttools:build qmake:build

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

post-patch:
		${REINPLACE_CMD} -e 's,Exiv2::Image::AutoPtr,Exiv2::Image::UniquePtr,g' \
			${WRKSRC}/cplusplus/scripts/getanddostuff/manipulation.cpp \
			${WRKSRC}/cplusplus/scripts/getmetadata.cpp

.include <bsd.port.mk>
