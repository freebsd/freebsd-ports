# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kajaani-kombat
PORTVERSION=	0.7
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://kombat.kajaani.net/dl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Funny multiplayer game... and much more

BROKEN=		unfetchable

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		gmake iconv ncurses
USE_SDL=	sdl image mixer net ttf
ALL_TARGET=	client server

PORTDOCS=	AUTHORS ChangeLog README
OPTIONS_DEFINE=	DOCS

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Kajaani Kombat" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

post-patch:
	@${REINPLACE_CMD} 's|-O||g; s|-Wall $$(DEBUG)|${CXXFLAGS} &|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for f in *.png *.ogg *.ttf
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-server ${STAGEDIR}${DATADIR}
	${LN} -sf ${DATADIR}/logo.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.6 ${STAGEDIR}${MAN6PREFIX}/man/man6/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
