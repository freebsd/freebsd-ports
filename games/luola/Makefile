# New ports collection makefile for:	luola
# Date created:		20 Jan 2006
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	luola
PORTVERSION=	1.3.0
PORTREVISION=	3
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

OPTIONS=	SDL_GFX	"Enable sdl_gfx for nicer graphics" on \
		SOUND "Enable sound" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_SDL_GFX)
CONFIGURE_ARGS+=	--disable-sdl-gfx
.else
USE_SDL+=	gfx
.endif

.if !defined(WITHOUT_SOUND)
CONFIGURE_ARGS+=	--enable-sound
USE_SDL+=	mixer
.endif

post-patch:
	@${REINPLACE_CMD} -e '/LIBS=.*-lSDL_/ s|\(SDL_[a-z]*\)|\1 `sdl-config --libs`|' ${WRKSRC}/configure

post-install:
	@${INSTALL_DATA} ${WRKDIR}/*.lev ${WRKDIR}/*.png ${DATADIR}/levels
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in README FAQ
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
