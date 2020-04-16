# $FreeBSD$

PORTNAME=	kImageAnnotator
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.1
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Tool for annotating images

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libkColorPicker.so:graphics/kcolorpicker

USES=		cmake localbase qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	ksnip
USE_QT=		core \
		buildtools_build qmake_build

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_EXAMPLE

.include <bsd.port.mk>
