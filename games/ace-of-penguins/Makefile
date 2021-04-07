PORTNAME=	ace-of-penguins
PORTVERSION=	1.4
CATEGORIES=	games
MASTER_SITES=	http://www.delorie.com/store/ace/
DISTNAME=	ace-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Set of Unix/X solitaire games

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=ace-
USES=		gmake libtool localbase:ldflags xorg
USE_XORG=	x11 xpm
INSTALL_TARGET=	install-strip

PORTDOCS=	*

GAMES=		"canfield:Solitaire game:CardGame" \
		"freecell:Solitaire game:CardGame" \
		"golf:Solitaire game:CardGame" \
		"mastermind:Logic game:LogicGame" \
		"merlin:Classical logic game:LogicGame" \
		"minesweeper:Logic game:LogicGame" \
		"pegged:Solitaire game:LogicGame" \
		"penguins:Solitaire game:CardGame" \
		"solitaire:Solitaire game:CardGame" \
		"spider:Solitaire game:CardGame" \
		"taipedit:Layout editor for taipei game:CardGame" \
		"taipei:Mahjong solitaire game:BoardGame" \
		"thornq:Solitaire game:CardGame" \


.for game in ${GAMES}
DESKTOP_ENTRIES+= \
		"Ace of Penguins: ${game:C/^([^:]*):([^:]*):([^:]*)$$/\1/:C/\"//g}" \
		"${game:C/^([^:]*):([^:]*):([^:]*)$$/\2/:C/\"//g}" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.gif" \
		"ace-${game:C/^([^:]*):([^:]*):([^:]*)$$/\1/:C/\"//g}" \
		"Game;${game:C/^([^:]*):([^:]*):([^:]*)$$/\3/:C/\"//g};" \
		""
.endfor

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/as.gif ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.gif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in AUTHORS ChangeLog NEWS README docs/*.gif docs/*.html
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
