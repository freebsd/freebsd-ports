PORTNAME=	agar
PORTVERSION=	1.7.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://stable.hypertriton.com/agar/

MAINTAINER=	vedge@hypertriton.com
COMMENT=	Cross-platform GUI toolkit
WWW=		https://libagar.org/

LICENSE=		BSD2CLAUSE OFL11
LICENSE_COMB=		multi
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/LICENSE
LICENSE_FILE_OFL11=	${WRKSRC}/OFL.txt

USES=		libtool localbase pathfix perl5 pkgconfig jpeg gl
USE_PERL5=	build
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

OPTIONS_DEFINE=	DEBUG FONTCONFIG PORTAUDIO SDL SDL2 SNDFILE THREADS X11 XINERAMA
OPTIONS_DEFAULT=FONTCONFIG SDL2 THREADS X11 XINERAMA
OPTIONS_SUB=	yes

SDL_DESC=	SDL 1.2 support in Agar GUI library
SDL2_DESC=	SDL 2.0 support in Agar GUI library
PORTAUDIO_DESC=	Portaudio support in Agar AU library
SNDFILE_DESC=	Audio file support in Agar AU library

CONFIGURE_ARGS+=--with-jpeg=${LOCALBASE} \
		--with-png=${LOCALBASE} \
		--with-freetype=${LOCALBASE} \
		--with-gl=${LOCALBASE} \
		--with-glu=${LOCALBASE} \
		--enable-au \
		--enable-sg \
		--enable-map \
		--enable-network

USE_GL=		gl glu

LIB_DEPENDS=	libpng.so:graphics/png \
		libfreetype.so:print/freetype2

.if defined(MACHINE_CPU) && (${MACHINE_CPU:Msse} == "sse" || ${MACHINE_CPU:Mamd64} == "amd64")
CONFIGURE_ARGS+=--with-sse \
		--with-sse-inline
.else
CONFIGURE_ARGS+=--without-sse
.endif

DEBUG_CONFIGURE_ENABLE= debug

FONTCONFIG_CONFIGURE_WITH=fontconfig
FONTCONFIG_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig

PORTAUDIO_CONFIGURE_WITH=portaudio
PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_IMPLIES=	THREADS

SDL_USES=		sdl
SDL_USE=		SDL=sdl
SDL_CONFIGURE_WITH=	sdl
SDL_PREVENTS=		SDL2

SDL2_USES=		sdl
SDL2_USE=		SDL=sdl2
SDL2_CONFIGURE_WITH=	sdl2
SDL2_PREVENTS=		SDL

SNDFILE_CONFIGURE_ON=	--with-sndfile=${LOCALBASE}
SNDFILE_CONFIGURE_OFF=	--without-sndfile
SNDFILE_LIB_DEPENDS=	libsndfile.so:audio/libsndfile
SNDFILE_IMPLIES=	THREADS

THREADS_CONFIGURE_ENABLE=threads

X11_USES=		xorg
X11_USE=		XORG=x11,xext
X11_CONFIGURE_ON=	--with-x=${LOCALBASE} --with-glx
X11_CONFIGURE_OFF=	--without-x --without-glx

XINERAMA_USE=		XORG=xinerama
XINERAMA_CONFIGURE_WITH=xinerama
XINERAMA_IMPLIES=	X11

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libag_*.so.*

.include <bsd.port.mk>
