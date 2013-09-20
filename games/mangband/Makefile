# Created by: driedfruit
# $FreeBSD$

PORTNAME=	mangband
PORTVERSION=	1.1.2
CATEGORIES=	games
MASTER_SITES=	http://www.mangband.org/ http://www.mangband.org/download/

MAINTAINER=	flambard@mangband.org
COMMENT=	Free online multiplayer real-time roguelike game

ALL_TARGET=	mangclient mangband
WRKSRC=		${WRKDIR}/${DISTNAME}/src
GNU_CONFIGURE=	yes
USES=		ncurses
USE_GMAKE=	yes

MAKE_ARGS=	"DATADIR=${DATADIR}"

OPTIONS_DEFINE=	GCU X11 SDL
OPTIONS_DEFAULT=	GCU X11 SDL
GCU_DESC=	Display module GCU
X11_DESC=	Display module X11
SDL_DESC=	Display module SDL

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGCU}
CONFIGURE_ARGS+=	--with-gcu
.else
CONFIGURE_ARGS+=	--without-gcu
.endif

.if ${PORT_OPTIONS:MX11}
LIB_DEPENDS+=	X11.6:${PORTSDIR}/x11/libX11
CONFIGURE_ARGS+=	--with-x11
.else
CONFIGURE_ARGS+=	--without-x11
.endif

.if ${PORT_OPTIONS:MSDL}
LIB_DEPENDS+=	SDL-1.2:${PORTSDIR}/devel/sdl12
CONFIGURE_ARGS+=	--with-sdl
.else
CONFIGURE_ARGS+=	--without-sdl
.endif

do-install:
	@${INSTALL_PROGRAM} -o root -g games -m 2550 \
		${WRKSRC}/mangband ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mangclient ${PREFIX}/bin
	@${CP} ${WRKDIR}/${DISTNAME}/mangband.cfg ${PREFIX}/etc

	@echo "# FreeBSD Hacks" >> ${PREFIX}/etc/mangband.cfg
	@echo "EDIT_DIR = \"${DATADIR}/edit\"" >> ${PREFIX}/etc/mangband.cfg
	@echo "SAVE_DIR = \"${DATADIR}/save\"" >> ${PREFIX}/etc/mangband.cfg
	@echo "DATA_DIR = \"${DATADIR}/data\"" >> ${PREFIX}/etc/mangband.cfg

	@${MKDIR} ${EXAMPLESDIR}
	@echo "[MAngband]" >> ${EXAMPLESDIR}/mangrc
	@echo "LibDir ${DATADIR}" >> ${EXAMPLESDIR}/mangrc

	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC}/../lib && ${PAX} -rw * ${DATADIR}
	@${CHMOD} 750 ${DATADIR}/*
	@${CHMOD} 755 ${DATADIR}/user
	@${CHMOD} 755 ${DATADIR}/xtra
	@${CHOWN} -R root:games ${DATADIR}/*
	@${CHOWN} ${SHAREOWN}:${SHAREGRP} ${DATADIR}

.include <bsd.port.mk>
