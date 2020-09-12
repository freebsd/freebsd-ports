# $FreeBSD$

PORTNAME=	kImageAnnotator
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library for image-annotation tools

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libkColorPicker.so:graphics/kcolorpicker

USES=		cmake localbase compiler:c++11-lang qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	ksnip
USE_QT=		core gui svg widgets \
		buildtools_build linguisttools_build qmake_build
USE_XORG=	x11

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_EXAMPLE

PLIST_SUB=	SHLIB_VER=${DISTVERSION}

.include <bsd.port.mk>
