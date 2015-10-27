# Created by: Muhammad Moinur Rahman <bofh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qmapshack
PORTVERSION=	1.3.1
CATEGORIES=	astro
MASTER_SITES=	https://bitbucket.org/maproom/qmapshack/downloads/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Ultimate outdoor aficionado's tool

LICENSE=	GPLv3

LIB_DEPENDS=	libgdal.so:${PORTSDIR}/graphics/gdal \
		libroutino.so:${PORTSDIR}/astro/routino

USES=		cmake desktop-file-utils
USE_QT5=	buildtools linguisttools qmake script sql webkit widgets xml

.include <bsd.port.mk>
