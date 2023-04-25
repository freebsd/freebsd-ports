PORTNAME=	seabattle
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Curses based battleship type game
WWW=		http://www.deater.net/weave/vmwprod/seabattle.html

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
