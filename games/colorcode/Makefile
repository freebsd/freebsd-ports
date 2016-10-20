# $FreeBSD$

PORTNAME=	colorcode
PORTVERSION=	0.8.5
CATEGORIES=	games
MASTER_SITES=	http://colorcode.laebisch.com/download/
DISTNAME=	ColorCode-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced MasterMind game and solver

USE_QT5=	gui widgets buildtools_build
USES=		qmake
WRKSRC=		${WRKDIR}/ColorCode-${PORTVERSION}

DESKTOP_ENTRIES=	ColorCode "" \
			colorcode colorcode \
			"LogicGame;Game;Qt;" true

PLIST_FILES=	bin/colorcode \
		share/pixmaps/colorcode.png

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/colorcode ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA}	${WRKSRC}/img/cc64.png	${STAGEDIR}${PREFIX}/share/pixmaps/colorcode.png

.include <bsd.port.mk>
