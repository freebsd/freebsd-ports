PORTNAME=	agar
DISTVERSION=	1.7.1
CATEGORIES=	devel
MASTER_SITES=	http://stable.hypertriton.com/agar/

MAINTAINER=	vedge@hypertriton.com
COMMENT=	Cross-platform GUI toolkit
WWW=		https://libagar.org/

LICENSE=		BSD2CLAUSE OFL11
LICENSE_COMB=		multi
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/LICENSE
LICENSE_FILE_OFL11=	${WRKSRC}/OFL.txt

LIB_DEPENDS=	libpng.so:graphics/png \
		libfreetype.so:print/freetype2

USES=		libtool localbase pathfix perl5 pkgconfig jpeg gl
USE_GL=		gl glu
USE_LDCONFIG=	yes
USE_PERL5=	build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-jpeg=${LOCALBASE} \
		--with-png=${LOCALBASE} \
		--with-freetype=${LOCALBASE} \
		--with-gl=${LOCALBASE} \
		--with-glu=${LOCALBASE} \
		--enable-au \
		--enable-sg \
		--enable-map \
		--enable-network
.if defined(MACHINE_CPU) && (${MACHINE_CPU:Msse} == "sse" || ${MACHINE_CPU:Mamd64} == "amd64")
CONFIGURE_ARGS+=--with-sse \
		--with-sse-inline
.else
CONFIGURE_ARGS+=--without-sse
.endif

OPTIONS_DEFINE=		DEBUG FONTCONFIG PORTAUDIO SNDFILE THREADS X11 XINERAMA
OPTIONS_DEFAULT=	FONTCONFIG SDL2 THREADS X11 XINERAMA
OPTIONS_RADIO=		SDL
OPTIONS_RADIO_SDL=	SDL1 SDL2
OPTIONS_SUB=		yes

PORTAUDIO_DESC=	Portaudio support in Agar AU library
SDL1_DESC=	SDL 1.2 support in Agar GUI library
SDL2_DESC=	SDL 2.0 support in Agar GUI library
SNDFILE_DESC=	Audio file support in Agar AU library

DEBUG_CONFIGURE_ENABLE=	debug

FONTCONFIG_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig
FONTCONFIG_CONFIGURE_WITH=fontconfig

PORTAUDIO_IMPLIES=	THREADS
PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_CONFIGURE_WITH=portaudio

SDL1_USES=		sdl
SDL1_USE=		SDL=sdl
SDL1_CONFIGURE_WITH=	sdl

SDL2_USES=		sdl
SDL2_USE=		SDL=sdl2
SDL2_CONFIGURE_WITH=	sdl2

SNDFILE_IMPLIES=	THREADS
SNDFILE_LIB_DEPENDS=	libsndfile.so:audio/libsndfile
SNDFILE_CONFIGURE_ON=	--with-sndfile=${LOCALBASE}
SNDFILE_CONFIGURE_OFF=	--without-sndfile

THREADS_CONFIGURE_ENABLE=threads

X11_USES=		xorg
X11_USE=		XORG=x11,xext
X11_CONFIGURE_ON=	--with-x=${LOCALBASE} --with-glx
X11_CONFIGURE_OFF=	--without-x --without-glx

XINERAMA_IMPLIES=	X11
XINERAMA_USE=		XORG=xinerama
XINERAMA_CONFIGURE_WITH=xinerama

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libag_*.so

.include <bsd.port.mk>
