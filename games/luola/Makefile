# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	luola
PORTVERSION=	1.3.0
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	http://www.luolamies.org/software/luola/ \
		http://mirror.amdmi3.ru/distfiles/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		stdlevels-5.2${EXTRACT_SUFX} \
		nostalgia-1.1${EXTRACT_SUFX}
DIST_SUBDIR=	luola

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Multiplayer Cave-flying game

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl image ttf

CONFIGURE_ARGS=	--program-prefix=''

OPTIONS_DEFINE=	SDL_GFX SOUND
SDL_GFX_DESC=	Nicer graphics

OPTIONS_DEFAULT=	SDL_GFX SOUND

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSDL_GFX}
USE_SDL+=	gfx
.else
CONFIGURE_ARGS+=	--disable-sdl-gfx
.endif

.if ${PORT_OPTIONS:MSOUND}
CONFIGURE_ARGS+=	--enable-sound
USE_SDL+=	mixer
.endif

post-patch:
	@${REINPLACE_CMD} -e '/LIBS=.*-lSDL_/ s|\(SDL_[a-z]*\)|\1 `sdl-config --libs`|' ${WRKSRC}/configure

post-install:
	@${INSTALL_DATA} ${WRKDIR}/*.lev ${WRKDIR}/*.png ${DATADIR}/levels
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in README FAQ
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
