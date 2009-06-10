# New ports collection makefile for: qlandkartegt
# Date created:                1 Jun 2009
# Whom:                        Mykola Dzham <freebsd@levsha.org.ua>
#
# $FreeBSD$
#

PORTNAME=	qlandkartegt
PORTVERSION=	0.12.0
CATEGORIES=	astro
MASTER_SITES=	SF

MAINTAINER=	freebsd@levsha.org.ua
COMMENT=	The ultimate outdoor aficionado's tool

LIB_DEPENDS=	gdal:${PORTSDIR}/graphics/gdal \
		proj.5:${PORTSDIR}/graphics/proj

USE_CMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib moc_build uic_build rcc_build qmake_build opengl linguist

MAN1=		qlandkartegt.1

.include <bsd.port.mk>
