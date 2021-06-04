# Created by: Andrey Zakhvatov

PORTNAME=	mirrormagic
PORTVERSION=	2.0.2
PORTREVISION=	21
CATEGORIES=	games
MASTER_SITES=	http://www.artsoft.org/RELEASES/unix/mirrormagic/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Arcade style game with stereo sound for X Window System

LICENSE=	GPLv2

USES=		gmake
MAKE_ARGS=	CC="${CC}" MAKE="${MAKE_CMD}" OPTIONS="${CFLAGS}" \
		RO_GAME_DIR="${DATADIR}" RW_GAME_DIR="${DATADIR}/scores" \
		X11_PATH="${LOCALBASE}"
USE_GCC=	yes # doesn't start otherwise (UB?)

PORTDATA=	*
PORTDOCS=	*

DESKTOP_ENTRIES="Mirror Magic" \
		"" \
		"" \
		"${PORTNAME}" \
		"Game;LogicGame;" \
		""

OPTIONS_DEFINE=	SDL DOCS
OPTIONS_DEFAULT=SDL

SDL_USES=		sdl
SDL_USE=		SDL=image,mixer,sdl
SDL_ALL_TARGET=		sdl
SDL_USES_OFF=		xorg
SDL_USE_OFF=		XORG=x11,xt
SDL_ALL_TARGET_OFF=	x11

post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|$$(SDL_CONFIG)|g' \
		${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's|machine/soundcard.h|sys/soundcard.h|' \
		${WRKSRC}/src/libgame/sound.h
	@${REINPLACE_CMD} -e 's|machine/joystick.h|sys/joystick.h|' \
		${WRKSRC}/src/tools.c
	@${REINPLACE_CMD} -e 's|inline||' ${WRKSRC}/src/libgame/*.[ch]

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mirrormagic ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "graphics levels music scores sounds" \
		${STAGEDIR}${DATADIR}
	${RMDIR} ${STAGEDIR}${DATADIR}/scores
	${LN} -s /var/games/${PORTNAME} ${STAGEDIR}${DATADIR}/scores
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in CHANGES CREDITS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor
	${MKDIR} ${STAGEDIR}/var/games/${PORTNAME}

.include <bsd.port.mk>
