# $FreeBSD$

PORTNAME=	imageformats
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	graphics
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt plugins for additional image formats

LIB_DEPENDS=	libjasper.so:graphics/jasper \
		libmng.so:graphics/libmng \
		libtiff.so:graphics/tiff \
		libwebp.so:graphics/webp

USE_QT5=	core gui buildtools_build
QT_DIST=	${PORTNAME}
USES=		qmake

.include <bsd.port.mk>
