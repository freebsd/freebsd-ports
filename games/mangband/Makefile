# Created by: driedfruit
# $FreeBSD$

PORTNAME=	mangband
PORTVERSION=	1.5.3
CATEGORIES=	games
MASTER_SITES=	http://mangband.org/download/

MAINTAINER=	flambard@mangband.org
COMMENT=	Free online multiplayer real-time roguelike game

LICENSE=	GPLv2

ALL_TARGET=	mangclient mangband
GNU_CONFIGURE=	yes
USES=		dos2unix ncurses

MAKE_ARGS=	"DATADIR=${DATADIR}"

OPTIONS_DEFINE=	GCU X11 SDL EXAMPLES
OPTIONS_DEFAULT=	GCU X11 SDL
GCU_DESC=	Display module GCU (curses)
X11_DESC=	Display module X11
SDL_DESC=	Display module SDL

GCU_CONFIGURE_WITH=	gcu

X11_LIB_DEPENDS=	libX11.so:x11/libX11
X11_CONFIGURE_WITH=	x11

SDL_LIB_DEPENDS=	libX11.so:x11/libX11
SDL_CONFIGURE_WITH=	sdl
SDL_USES=		sdl

# Only relevant when OPTION SDL is on
USE_SDL=		sdl

PORTEXAMPLES=	*

SUB_FILES=	pkg-message

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mangband ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/mangclient ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/mangband.cfg ${STAGEDIR}${PREFIX}/etc/mangband.cfg.sample
	@echo "# FreeBSD Hacks" >> ${STAGEDIR}${PREFIX}/etc/mangband.cfg.sample
	@echo "EDIT_DIR = \"${DATADIR}/edit\"" >> ${STAGEDIR}${PREFIX}/etc/mangband.cfg.sample
	@echo "SAVE_DIR = \"${DATADIR}/save\"" >> ${STAGEDIR}${PREFIX}/etc/mangband.cfg.sample
	@echo "DATA_DIR = \"${DATADIR}/data\"" >> ${STAGEDIR}${PREFIX}/etc/mangband.cfg.sample
	@find ${WRKDIR}/${DISTNAME}/lib -name Makefile.am -exec ${RM} {} +
	@(cd ${WRKDIR}/${DISTNAME}/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@echo "[MAngband]" >> ${STAGEDIR}${EXAMPLESDIR}/mangrc
	@echo "LibDir ${DATADIR}/" >> ${STAGEDIR}${EXAMPLESDIR}/mangrc

.include <bsd.port.mk>
