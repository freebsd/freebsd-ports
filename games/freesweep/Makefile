PORTNAME=	freesweep
PORTVERSION=	1.0.2
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	fuz@fuz.su
COMMENT=	Minesweeper-style game for text-mode terminals

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	rwestlund

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-prefsdir=${DATADIR} \
		--with-scoresdir=/var/games

ALL_TARGET=	${PORTNAME}
MAKE_ARGS=	VERSION='"${PORTVERSION}"'

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/freesweep ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}/var/games
	${TOUCH} ${STAGEDIR}/var/games/sweeptimes.sample
	${INSTALL_DATA} ${WRKSRC}/sweeprc ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/freesweep.6 ${STAGEDIR}${PREFIX}/man/man6

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
