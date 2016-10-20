# Created by: Igor Pokrovsky <ip@doom.homeunix.org>
# $FreeBSD$

PORTNAME=	glaxium
PORTVERSION=	0.5
PORTREVISION=	16
CATEGORIES=	games
MASTER_SITES=	http://xhosxe.free.fr/glaxium/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenGL based space-ship "shoot-em-up" game

LIB_DEPENDS=	libpng.so:graphics/png

USES=		dos2unix gmake
USE_SDL=	sdl mixer
USE_GL=		glut
GNU_CONFIGURE=	yes
ALL_TARGET=	${PORTNAME}

DOS2UNIX_FILES=	variables.cpp scene.cpp

DESKTOP_ENTRIES=	"Glaxium" \
			"Space-ship \"shoot-em-up\" game" \
			"${DATADIR}/textures/myship.png" \
			"glaxium" \
			"Game;ArcadeGame;" \
			false

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g; \
		 s|/games/glaxium|/glaxium|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|gcc -g -o|$$(CC) -o|g ; \
		 s|/games/glaxium|/glaxium|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|Scratcher:: Scratcher|Scratcher|g' \
		${WRKSRC}/scratcher.hpp
	@${REINPLACE_CMD} -e 's|TankFire::TankFire|TankFire|g' \
		${WRKSRC}/tank.hpp

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
