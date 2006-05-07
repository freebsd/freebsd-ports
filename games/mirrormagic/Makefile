# New ports collection makefile for:	mirrormagic
# Date created:				1 April 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	mirrormagic
PORTVERSION=	2.0.2
CATEGORIES=	games
MASTER_SITES=	http://www.artsoft.org/RELEASES/unix/mirrormagic/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An arcade style game with stereo sound for X Window System

USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" MAKE="${GMAKE}" OPTIONS="${CFLAGS}" \
		RO_GAME_DIR="${DATADIR}" RW_GAME_DIR="${DATADIR}/scores" \
		X11_PATH="${X11BASE}"

.if defined(WITH_SDL)
USE_SDL=	image mixer sdl
ALL_TARGET=	sdl
.else
USE_XLIB=	yes
ALL_TARGET=	x11
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|$$(SDL_CONFIG)|g' \
		${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's|machine/soundcard.h|sys/soundcard.h|' \
		${WRKSRC}/src/libgame/sound.h
	@${REINPLACE_CMD} -e 's|machine/joystick.h|sys/joystick.h|' \
		${WRKSRC}/src/tools.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mirrormagic ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${TAR} -C ${WRKSRC} -cf - graphics levels music scores sounds | \
		${TAR} -C ${DATADIR} -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}
	@${CHMOD} 777 ${DATADIR}/scores
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in CHANGES CREDITS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
