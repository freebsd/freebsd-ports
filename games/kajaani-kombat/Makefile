# Created by: nemysis@gmx.ch
# $FreeBSD$

PORTNAME=	kajaani-kombat
PORTVERSION=	0.7
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://kombat.kajaani.net/dl/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Funny multiplayer game... and much more

LICENSE=	GPLv2

LIB_DEPENDS=	freetype:${PORTSDIR}/print/freetype2

USE_SDL=	sdl image mixer net ttf
USE_GMAKE=	yes
ALL_TARGET=	client server
USE_ICONV=	yes
MAKE_JOBS_SAFE=	yes

PORTDOCS=	AUTHORS ChangeLog README

MAN6=		${PORTNAME}.6

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Kajaani Kombat" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} 's|-O||g; s|-Wall $$(DEBUG)|${CXXFLAGS} &|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-server ${DATADIR}
	@(cd ${WRKSRC} && ${INSTALL_DATA} *.png *.ogg *.ttf ${DATADIR})
	${LN} -sf ${DATADIR}/logo.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

	${INSTALL_MAN} ${WRKSRC}/${MAN6} ${MAN6PREFIX}/man/man6

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
