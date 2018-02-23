# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	easypaint
PORTVERSION=	0.6.0
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://qt-apps.org/CONTENT/content-files/
DISTNAME=	140877-easyPaint

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easy graphic editing program

LICENSE=	GPLv3

USES=		qmake
USE_QT4=	gui xml uic_build moc_build rcc_build
QPROFILE=	easyPaint
WRKSRC=		${WRKDIR}/${QPROFILE}

DESKTOP_ENTRIES="easyPaint" "${COMMENT}" "easypaint" "easypaint" \
		"Graphics;2DGraphics;RasterGraphics;" "true"

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${QPROFILE} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/icons/program/paint.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
