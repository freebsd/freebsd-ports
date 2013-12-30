# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	kajaani-kombat
PORTVERSION=	0.7
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://kombat.kajaani.net/dl/

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Funny multiplayer game... and much more

LICENSE=	GPLv2

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2

USES=		gmake iconv
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
.for d in *.png *.ogg *.ttf
	@(cd ${WRKSRC} && ${INSTALL_DATA} ${d} ${STAGEDIR}${DATADIR})
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-server ${STAGEDIR}${DATADIR}
	${LN} -sf ${DATADIR}/logo.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.6 ${STAGEDIR}${MAN6PREFIX}/man/man6/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
