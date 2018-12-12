# $FreeBSD$

PORTNAME=	imageformats
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	1
CATEGORIES=	graphics
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt plugins for additional image formats

LIB_DEPENDS=	libjasper.so:graphics/jasper \
		libmng.so:graphics/libmng \
		libtiff.so:graphics/tiff \
		libwebp.so:graphics/webp

USE_QT=		core gui buildtools_build
USES=		compiler:c++11-lang localbase qmake qt-dist:5,imageformats

.include <bsd.port.mk>
