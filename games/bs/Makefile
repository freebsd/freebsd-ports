# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	bs
PORTVERSION=	2.9
CATEGORIES=	games
MASTER_SITES=	http://www.catb.org/~esr/bs/

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Battleships solitaire game with a color interface

LICENSE=	BSD

USES=		gmake
MAKE_ARGS=	CC="${CC}"
ALL_TARGET=	# empty

PLIST_FILES=	bin/bs \
		man/man6/bs.6.gz \
		share/pixmaps/battleship.png

PORTDOCS=	NEWS README

OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="Battleships" "${COMMENT}" "battleship" \
		"xterm -e ${PORTNAME}" "Game;ArcadeGame;" false

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/battleship.png ${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.6 ${STAGEDIR}${MAN6PREFIX}/man/man6/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
