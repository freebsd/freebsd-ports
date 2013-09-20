# $FreeBSD$

PORTNAME=	chessx
PORTVERSION=	0.9.6
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./-/g}

MAINTAINER=	yamagi@yamagi.org
COMMENT=	Qt4 chess database application

LICENSE=	GPLv2 # (or later)

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_QT4=	corelib gui svg xml network moc_build qmake_build rcc_build uic_build
MAKE_JOBS_SAVE=	yes

OPTIONS_DEFINE=	STOCKFISH CRAFTY
STOCKFISH_DESC=	Build with Stockfish Chess Engine
CRAFTY_DESC=	Build with Crafty Chess Application
OPTIONS_DEFAULT=STOCKFISH CRAFTY

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSTOCKFISH}
RUN_DEPENDS+=	stockfish:${PORTSDIR}/games/stockfish
.endif

.if ${PORT_OPTIONS:MCRAFTY}
RUN_DEPENDS+=	crafty:${PORTSDIR}/games/crafty
.endif

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

DESKTOP_ENTRIES="ChessX" "" "${PREFIX}/share/pixmaps/${PORTNAME}.png" \
				"${PORTNAME}" "Game;BoardGame;" true

do-configure:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKEFLAGS})

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} release/${PORTNAME} ${PREFIX}/bin)
	(cd ${WRKSRC}/data/images && ${INSTALL_DATA} chessx.png \
		${PREFIX}/share/pixmaps/${PORTNAME}.png)

.include <bsd.port.mk>
