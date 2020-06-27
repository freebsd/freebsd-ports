# $FreeBSD$

PORTNAME=	kImageAnnotator
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.1
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library for image-annotation tools

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libkColorPicker.so:graphics/kcolorpicker

USES=		cmake localbase compiler:c++11-lang qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	ksnip
USE_QT=		core svg \
		buildtools_build linguisttools_build qmake_build

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_EXAMPLE

PLIST_SUB=	SHLIB_VER=${DISTVERSION}

.include <bsd.port.mk>
