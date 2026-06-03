PORTNAME=	tomenet
DISTVERSION=	4.9.3
CATEGORIES=	games
MASTER_SITES=	https://tomenet.eu/downloads/:DEFAULT \
		https://github.com/${GH_ACCOUNT}/${PORTNAME}/releases/download/v${DISTVERSION}/:DEFAULT
SOUND_VER=	1.0a
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:DEFAULT \
		${PORTNAME}-soundpack-${SOUND_VER}.tar.gz:soundpack

MAINTAINER=	dnpowers@me.com
COMMENT=	Online multiplayer rogue-like role-playing game
WWW=		https://tomenet.eu/

LICENSE=	BSD2CLAUSE CC-BY-2.0 GPLv2
LICENSE_COMB=	multi

USES=		gmake localbase:ldflags ncurses tar:bzip2
USE_GITHUB=	nodefault
GH_ACCOUNT=	TomenetGame
GH_PROJECT=	${PORTNAME}-soundpack:soundpack
GH_TAGNAME=	v${SOUND_VER}

MAKEFILE=	makefile

CFLAGS+=	-DDEFAULT_PATH='\"${DATADIR}/lib/\"'

SUB_FILES=	pkg-message

WRKSRC_SUBDIR=	src

OPTIONS_DEFINE=		DOCS SDL X11
OPTIONS_DEFAULT=	DOCS
OPTIONS_SUB=		yes
SDL_USES=		sdl
SDL_USE=		SDL=mixer2,sdl2
SDL_CFLAGS+=		-DSOUND_SDL -I${LOCALBASE}/include/SDL2
SDL_LDFLAGS+=		-lSDL2 -lSDL2_mixer
X11_USES=		xorg
X11_USE=		XORG=x11
X11_CFLAGS+=		-DUSE_X11
X11_LDFLAGS+=		-lX11
X11_DESKTOP_ENTRIES=	"TomeNET" \
			"" \
			"${PORTNAME}" \
			"tomenet" \
			"Game;RolePlay;" \
			${FALSE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tomenet ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKDIR}/${PORTNAME}-${DISTVERSION} && ${COPYTREE_SHARE} lib ${STAGEDIR}${DATADIR})
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${DISTVERSION}/.tomenetrc ${STAGEDIR}${ETCDIR}/tomenetrc

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${DISTVERSION}/TomeNET-Guide.txt ${STAGEDIR}${DOCSDIR}

post-install-SDL-on:
	(cd ${WRKSRC_soundpack}/sound && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/lib/xtra/sound/)
	${CP} ${STAGEDIR}${DATADIR}/lib/xtra/music/music.cfg.default ${STAGEDIR}${DATADIR}/lib/xtra/music/music.cfg

post-install-X11-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/client/tomenet4.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
