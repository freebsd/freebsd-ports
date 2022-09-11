PORTNAME=	kImageAnnotator
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library for image-annotation tools
WWW=		https://github.com/ksnip/kImageAnnotator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libkColorPicker.so:graphics/kcolorpicker

USES=		cmake localbase compiler:c++11-lang qt:5 xorg
USE_GITHUB=	yes
GH_ACCOUNT=	ksnip
USE_QT=		core gui svg widgets \
		buildtools:build linguisttools:build qmake:build
USE_XORG=	x11

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_EXAMPLE

PLIST_SUB=	SHLIB_VER=${DISTVERSION}

.include <bsd.port.mk>
