PORTNAME=	kImageAnnotator
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.2
CATEGORIES=	graphics kde
PKGNAMESUFFIX=	-qt6

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library for image-annotation tools
WWW=		https://github.com/ksnip/kImageAnnotator

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libkColorPicker-Qt6.so:graphics/kcolorpicker

USES=		cmake localbase compiler:c++17-lang gl qt:6 xorg
USE_GITHUB=	yes
GH_ACCOUNT=	ksnip
USE_GL=		opengl
USE_QT=		base svg \
		tools:build
USE_XORG=	x11

CMAKE_ON=	BUILD_SHARED_LIBS BUILD_WITH_QT6
CMAKE_OFF=	BUILD_EXAMPLE

PLIST_SUB=	SHLIB_VER=${DISTVERSION} \
		SHLIB_VER_MAJ=${DISTVERSION:R:R}

.include <bsd.port.mk>
