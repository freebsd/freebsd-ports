PORTNAME=	seabattle
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1
CATEGORIES=	games

MAINTAINER=	fuz@fuz.su
COMMENT=	Curses based battleship type game

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	deater

OPTIONS_DEFINE=	DOCS ALSA
OPTIONS_DEFAULT=	ALSA
ALSA_RUN_DEPENDS=	aplay:audio/alsa-utils

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/seabattle ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/seabattle
	${INSTALL_DATA} ${WRKSRC}/share/seabattle/*.au ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.historical ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
