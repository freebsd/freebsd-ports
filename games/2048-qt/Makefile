# $FreeBSD$

PORTNAME=	2048-qt
PORTVERSION=	0.1.5
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	GH

MAINTAINER=	swills@FreeBSD.org
COMMENT=	2048 game implemented in QT

USE_GITHUB=	yes
GH_ACCOUNT=	xiaoyong
GH_PROJECT=	2048-Qt

USES=		gmake pkgconfig qmake tar:bzip2
USE_QT5=	core gui network widgets qml quick buildtools_build quickcontrols

PLIST_FILES=	bin/2048-qt ${DESKTOPDIR}/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.png

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/2048-qt ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/icons/256x256/apps/2048-qt.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
