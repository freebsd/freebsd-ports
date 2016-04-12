# Created by: Muhammad Moinur Rahman <bofh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qmapshack
PORTVERSION=	1.3.1
CATEGORIES=	astro
MASTER_SITES=	https://bitbucket.org/maproom/qmapshack/downloads/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Ultimate outdoor aficionado's tool

LICENSE=	GPLv3

BROKEN=		unfetchable

LIB_DEPENDS=	libgdal.so:graphics/gdal \
		libroutino.so:astro/routino

USES=		cmake desktop-file-utils
USE_QT5=	buildtools linguisttools qmake script sql webkit widgets xml

.include <bsd.port.mk>
