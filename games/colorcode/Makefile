# $FreeBSD$

PORTNAME=	colorcode
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://colorcode.laebisch.com/download/
DISTNAME=	ColorCode-${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Advanced MasterMind game and solver

USE_QT4=	gui moc_build qmake_build rcc_build uic_build
HAS_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/ColorCode-${PORTVERSION}

DESKTOP_ENTRIES=	"ColorCode" "${COMMENT}" \
			"${PREFIX}/share/pixmaps/colorcode.png" "colorcode" \
			"LogicGame;Game;Qt;" false

PLIST_FILES=	bin/colorcode \
		share/pixmaps/colorcode.png

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKEFLAGS} ${QMAKE_ARGS}

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/colorcode ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA}	${WRKSRC}/img/cc64.png	${PREFIX}/share/pixmaps/colorcode.png

.include <bsd.port.mk>
