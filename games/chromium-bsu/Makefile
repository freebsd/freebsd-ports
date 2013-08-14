# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	chromium-bsu
PORTVERSION=	0.9.15.1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Chromium%20B.S.U.%20source%20code/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	An arcade-style, top-scrolling space shooter

LIB_DEPENDS=	glpng:${PORTSDIR}/graphics/glpng \
		ftgl:${PORTSDIR}/graphics/ftgl \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig

GNU_CONFIGURE=	yes
USE_GL=		gl glu
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-glc
INSTALLS_ICONS=	yes

PORTDOCS=	*

MAN6=		chromium-bsu.6

OPTIONS_DEFINE=	SDL_MIXER GLUT NLS DOCS
SDL_MIXER_DESC=	Use SDL_mixer instead of OpenAL for audio
GLUT_DESC=	Use GLUT instead of SDL for video

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGLUT}
USE_GL+=	glut
CONFIGURE_ARGS+=--disable-sdl --disable-sdlimage
.else
USE_SDL+=	sdl image
CONFIGURE_ARGS+=--disable-glut
.endif

.if ${PORT_OPTIONS:MSDL_MIXER}
USE_SDL+=	mixer
CONFIGURE_ARGS+=--disable-openal
.else
USE_OPENAL=	al alut
CONFIGURE_ARGS+=--disable-sdlmixer
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
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
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/doc / d' ${WRKSRC}/data/Makefile.in
.endif

.include <bsd.port.mk>
