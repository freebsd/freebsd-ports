# New ports collection makefile for:	easypaint
# Date created:		2012-01-06
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	easypaint
PORTVERSION=	0.6.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://qt-apps.org/CONTENT/content-files/
DISTNAME=	140877-easyPaint

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Easy graphic editing program

LICENSE=	GPLv3

USE_QT4=	gui xml qmake_build uic_build moc_build rcc_build
QPROFILE=	easyPaint
WRKSRC=		${WRKDIR}/${QPROFILE}

DESKTOP_ENTRIES="easyPaint" "${COMMENT}" "" "easypaint" \
		"Graphics;2DGraphics;RasterGraphics;" "true"

PLIST_FILES=	bin/${PORTNAME}

do-configure:
	cd ${WRKSRC} && ${QMAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${QPROFILE} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
