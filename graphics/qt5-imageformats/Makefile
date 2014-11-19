# $FreeBSD$

PORTNAME=	imageformats
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	graphics
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt plugins for additional image formats

LIB_DEPENDS=	libjasper.so:${PORTSDIR}/graphics/jasper \
		libmng.so:${PORTSDIR}/graphics/libmng \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libwebp.so:${PORTSDIR}/graphics/webp

USE_QT5=	core gui buildtools_build
QT_DIST=	${PORTNAME}
USES=		qmake

.include <bsd.port.mk>
