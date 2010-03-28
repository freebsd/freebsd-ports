# New ports collection makefile for:	zint
# Date created:		2010-03-13
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	zint
PORTVERSION=	2.3.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Zint Barcode Generator

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png

USE_CMAKE=	yes
CMAKE_USE_PTHREAD=	yes
USE_LDCONFIG=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui xml qmake_build uic_build moc_build rcc_build designer

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
