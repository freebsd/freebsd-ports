PORTNAME=	rocksndiamonds
DISTVERSION=	4.4.0.5
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.artsoft.org/RELEASES/unix/${PORTNAME}/
EXTRACT_SUFX=	-linux.tar.gz

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Colorful Boulderdash'n'Emerald Mine'n'Sokoban'n'Stuff
WWW=		https://www.artsoft.org/${PORTNAME}/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake gnome iconv sdl
USE_SDL=	image2 mixer2 net2 sdl2
MAKE_ARGS=	BASE_PATH="${DATADIR}" \
		CC="${CC}" \
		MAKE="${MAKE_CMD}" \
		OPTIONS="${CFLAGS}" \
		RO_GAME_DIR="${DATADIR}" \
		RW_GAME_DIR="/var/games/${PORTNAME}" \
		X11_PATH="${LOCALBASE}"

DESKTOP_ENTRIES=	"Rocks'n'Diamonds" \
			"Arcade game" \
			"${PORTNAME}" \
			"${PORTNAME}" \
			"Game;ArcadeGame;" \
			""

SUB_FILES=	pkg-message
PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/rocksndiamonds.png
PORTDATA=	graphics levels music sounds
PORTDOCS=	CREDITS ChangeLog docs/elements

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} \
		-e 's|sdl2-config|$${SDL2_CONFIG}|g' ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} \
		-e 's|machine/joystick.h|sys/joystick.h|' \
		${WRKSRC}/src/libgame/joystick.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/build-projects/android/app/src/main/res/mipmap-xxhdpi/ic_launcher.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDATA}" ${STAGEDIR}${DATADIR})

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
