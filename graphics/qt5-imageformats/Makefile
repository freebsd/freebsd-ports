# $FreeBSD$

PORTNAME=	imageformats
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	2
CATEGORIES=	graphics
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt plugins for additional image formats

LIB_DEPENDS=	libmng.so:${PORTSDIR}/graphics/libmng \
		libtiff.so:${PORTSDIR}/graphics/tiff

USE_QT5=	core gui buildtools_build
QT_DIST=	${PORTNAME}
USES=		qmake

.include <bsd.port.mk>
