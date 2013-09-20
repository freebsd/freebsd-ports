# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	mirrormagic
PORTVERSION=	2.0.2
PORTREVISION=	11
CATEGORIES=	games
MASTER_SITES=	http://www.artsoft.org/RELEASES/unix/mirrormagic/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Arcade style game with stereo sound for X Window System

LICENSE=	GPLv2

USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" MAKE="${GMAKE}" OPTIONS="${CFLAGS}" \
		RO_GAME_DIR="${DATADIR}" RW_GAME_DIR="${DATADIR}/scores" \
		X11_PATH="${LOCALBASE}"
WANT_SDL=	yes

OPTIONS_DEFINE=	SDL
OPTIONS_DEFAULT=	SDL

NO_STAGE=	yes
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
	${INSTALL_PROGRAM} ${WRKSRC}/mirrormagic ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${TAR} -C ${WRKSRC} -cf - graphics levels music scores sounds | \
		${TAR} -C ${DATADIR} -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}
	@${CHMOD} 777 ${DATADIR}/scores
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in CHANGES CREDITS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
