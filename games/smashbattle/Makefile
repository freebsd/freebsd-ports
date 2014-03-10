# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	smashbattle
PORTVERSION=	110224
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/beta-${PORTVERSION}
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	8-bit style platform battle game

WRKSRC=		${WRKDIR}/${DISTNAME}/battle/Battle

EXTRACT_AFTER_ARGS=	-d ${WRKDIR}/${DISTNAME}
USES=		dos2unix gmake zip:infozip
DOS2UNIX_FILES=	*.cpp *.h Makefile
USE_SDL=	sdl image mixer
ALL_TARGET=	battle

pre-extract:
	@${MKDIR} ${WRKDIR}/${DISTNAME}

SUB_FILES=	${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|CC=|CC?=|; \
		s|CFLAGS=-c -Wall|CFLAGS += $$(shell sdl-config --cflags) -c -Wall|; \
		s|LDFLAGS=-lSDL -lSDL_mixer -lz -lstdc++|LDFLAGS += $$(shell $${SDL_CONFIG} --libs) -lSDL -lSDL_mixer -lz -lstdc++ -lm|' \
			${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/usr/share/games/smashbattle/gfx/SB.png|${PORTNAME}|; \
		s|/usr/local/bin/smashbattle|${PORTNAME}|' \
		${WRKSRC}/linux/*.desktop

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
.for d in gfx music sfx stage
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/battle ${STAGEDIR}${DATADIR}/${PORTNAME}
	${LN} -sf ${DATADIR}/gfx/SB.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
	${INSTALL_DATA} ${WRKSRC}/linux/*.desktop ${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
