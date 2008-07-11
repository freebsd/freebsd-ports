# New ports collection makefile for:	chromium
# Date created:				17 Dec, 2003
# Whom:					Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	chromium
PORTVERSION=	0.9.13.2
CATEGORIES=	games
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	chromium-bsu

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	An arcade-style, top-scrolling space shooter

LIB_DEPENDS=	glpng.1:${PORTSDIR}/graphics/glpng \
		ftgl.2:${PORTSDIR}/graphics/ftgl \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig

GNU_CONFIGURE=	yes
USE_GL=		gl glu
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PORTDOCS=	*

MAN6=		chromium.6

OPTIONS=	SDL_MIXER "Use SDL_mixer instead of openal for audio" off \
		GLUT	"Use GLUT instead of SDL for video" off

.include <bsd.port.pre.mk>

.if defined(WITH_GLUT)
USE_GL+=	glut
CONFIGURE_ARGS+=--disable-sdl
.else
USE_SDL+=	sdl
CONFIGURE_ARGS+=--disable-glut
.endif

.if defined(WITH_SDL_MIXER)
USE_SDL+=	mixer
CONFIGURE_ARGS+=--disable-openal
.else
LIB_DEPENDS+=	openal.0:${PORTSDIR}/audio/openal \
		alut.1:${PORTSDIR}/audio/freealut
CONFIGURE_ARGS+=--disable-sdlmixer
.endif

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/SUBDIRS/ s|doc||' ${WRKSRC}/data/Makefile.in
.endif
	@${REINPLACE_CMD} -e '/^bindir=.*games/ d; /^datadir=.*games/ d' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
