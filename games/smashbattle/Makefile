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

USE_ZIP=	yes
EXTRACT_AFTER_ARGS=	-d ${WRKDIR}/${DISTNAME}
USES=		gmake
USE_SDL=	sdl image mixer
USE_DOS2UNIX=	*.cpp *.h *.ini Makefile
ALL_TARGET=	battle

NO_STAGE=	yes
pre-extract:
	@${MKDIR} ${WRKDIR}/${DISTNAME}

SUB_FILES=	${PORTNAME}

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} \
		-e 's|CC=|CC?=|' \
		-e 's|CFLAGS=-c -Wall|CFLAGS += $$(shell sdl-config --cflags) -c -Wall|' \
		-e 's|LDFLAGS=-lSDL -lSDL_mixer -lz -lstdc++|LDFLAGS += $$(shell $${SDL_CONFIG} --libs) -lSDL -lSDL_mixer -lz -lstdc++ -lm|' \
			${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/usr/share/games/smashbattle/gfx/SB.png|${PORTNAME}|' \
		-e 's|/usr/local/bin/smashbattle|${PORTNAME}|' \
		${WRKSRC}/linux/*.desktop

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "gfx music sfx stage" ${DATADIR})
	${INSTALL_PROGRAM} ${WRKSRC}/battle ${DATADIR}/${PORTNAME}
	${LN} -sf ${DATADIR}/gfx/SB.png ${PREFIX}/share/pixmaps/${PORTNAME}.png
#	${INSTALL_DATA} ${WRKSRC}/linux/*.desktop ${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/linux/*.desktop ${DESKTOPDIR}

.include <bsd.port.mk>
