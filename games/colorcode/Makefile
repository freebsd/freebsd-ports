# $FreeBSD$

PORTNAME=	colorcode
PORTVERSION=	0.7.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://colorcode.laebisch.com/download/
DISTNAME=	ColorCode-${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Advanced MasterMind game and solver

USE_QT4=	gui moc_build qmake_build rcc_build uic_build
USES=		qmake
WRKSRC=		${WRKDIR}/ColorCode-${PORTVERSION}

DESKTOP_ENTRIES=	"ColorCode" "${COMMENT}" \
			"${PREFIX}/share/pixmaps/colorcode.png" "colorcode" \
			"LogicGame;Game;Qt;" false

PLIST_FILES=	bin/colorcode \
		share/pixmaps/colorcode.png

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/colorcode ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA}	${WRKSRC}/img/cc64.png	${STAGEDIR}${PREFIX}/share/pixmaps/colorcode.png

.include <bsd.port.mk>
