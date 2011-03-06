# New ports collection makefile for:	chromium
# Date created:				17 Dec, 2003
# Whom:					Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	chromium-bsu
PORTVERSION=	0.9.15
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Chromium%20B.S.U.%20source%20code/${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	An arcade-style, top-scrolling space shooter

LIB_DEPENDS=	glpng.1:${PORTSDIR}/graphics/glpng \
		ftgl.2:${PORTSDIR}/graphics/ftgl \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig

GNU_CONFIGURE=	yes
USE_GL=		gl glu
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-glc
MAKE_JOBS_SAFE=	yes

PORTDOCS=	*

MAN6=		chromium-bsu.6

OPTIONS=	SDL_MIXER "Use SDL_mixer instead of openal for audio" off \
		GLUT	"Use GLUT instead of SDL for video" off

.include <bsd.port.pre.mk>

.if defined(WITH_GLUT)
USE_GL+=	glut
CONFIGURE_ARGS+=--disable-sdl --disable-sdlimage
.else
USE_SDL+=	sdl image
CONFIGURE_ARGS+=--disable-glut
.endif

.if defined(WITH_SDL_MIXER)
USE_SDL+=	mixer
CONFIGURE_ARGS+=--disable-openal
.else
USE_OPENAL=	al alut
CONFIGURE_ARGS+=--disable-sdlmixer
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^LIBS =/ s|$$| @INTLLIBS@|' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|\([A-Z][A-Z_]*[A-Z]\)\+="\(.*\)"$$|\1="$$\1 \2"|; \
		s|\([A-Z][A-Z_]*[A-Z]\)\+=\(.*\)$$|\1="$$\1 \2"|' \
		${WRKSRC}/configure
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/doc / d' ${WRKSRC}/data/Makefile.in
.endif

.include <bsd.port.post.mk>
