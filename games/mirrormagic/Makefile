# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	mirrormagic
PORTVERSION=	2.0.2
PORTREVISION=	13
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
USE_GCC=	any # doesn't start otherwise (UB?)

PORTDATA=	*
PORTDOCS=	*

SCOREDIR=	/var/games/${PORTNAME}

SUB_FILES=	pkg-deinstall pkg-install
SUB_LIST=	SCOREDIR="${SCOREDIR}"

DESKTOP_ENTRIES="Mirror Magic" \
		"" \
		"" \
		"${PORTNAME}" \
		"Game;LogicGame;" \
		""

OPTIONS_DEFINE=	SDL
OPTIONS_DEFAULT=SDL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSDL}
USE_SDL=	image mixer sdl
ALL_TARGET=	sdl
.else
USE_XORG=	x11
ALL_TARGET=	x11
.endif

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
	${LN} -s ${SCOREDIR} ${STAGEDIR}${DATADIR}/scores
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in CHANGES CREDITS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
