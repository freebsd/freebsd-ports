PORTNAME=	agar
PORTVERSION=	1.5.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://stable.hypertriton.com/agar/

MAINTAINER=	vedge@hypertriton.com
COMMENT=	Cross-platform GUI toolkit

LICENSE=	BSD2CLAUSE

BROKEN_FreeBSD_12_powerpc64=	fails to compile: cpuinfo.c:289: error: 'IllegalInsn' undeclared (first use in this function)
BROKEN_FreeBSD_13_powerpc64=	fails to compile: include/agar/core/byteswap.h:46:8: error: unsupported inline asm: input with type 'int' matching output with type 'u_int16_t' (aka 'unsigned short')

USES=		libtool pathfix perl5 pkgconfig jpeg
USE_PERL5=	build
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DEBUG FONTCONFIG GUI NETWORK PORTAUDIO SDL SNDFILE X11 XINERAMA
OPTIONS_DEFAULT=FONTCONFIG GUI NETWORK PORTAUDIO SDL SNDFILE X11 XINERAMA
OPTIONS_SUB=	yes

NETWORK_DESC=	Network support in AG_Net(3)

DEBUG_CONFIGURE_ENABLE=	debug
NETWORK_CONFIGURE_ENABLE=network

PORTAUDIO_CONFIGURE_ENABLE=au
PORTAUDIO_CONFIGURE_ON=	--with-portaudio=${LOCALBASE}
PORTAUDIO_CONFIGURE_OFF=--without-portaudio
PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_IMPLIES=	SNDFILE

SNDFILE_CONFIGURE_ON=	--with-sndfile=${LOCALBASE}
SNDFILE_CONFIGURE_OFF=	--without-sndfile
SNDFILE_LIB_DEPENDS=	libsndfile.so:audio/libsndfile
SNDFILE_IMPLIES=	PORTAUDIO

GUI_CONFIGURE_ENABLE=	gui

GUI_CONFIGURE_ON=	--with-jpeg=${LOCALBASE} \
			--with-png=${LOCALBASE} \
			--with-freetype=${LOCALBASE}

GUI_LIB_DEPENDS=	libpng.so:graphics/png \
			libfreetype.so:print/freetype2

FONTCONFIG_CONFIGURE_WITH=fontconfig
FONTCONFIG_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig
FONTCONFIG_IMPLIES=	GUI

X11_USES=		gl xorg
X11_USE=		GL=gl XORG=x11,xext
X11_CONFIGURE_ON=	--with-x=${LOCALBASE} --with-glx
X11_CONFIGURE_OFF=	--without-x --without-glx
X11_IMPLIES=		GUI

XINERAMA_USE=		XORG=xinerama
XINERAMA_CONFIGURE_WITH=xinerama
XINERAMA_IMPLIES=	X11

SDL_USES=		gl sdl
SDL_USE=		SDL=sdl GL=gl
SDL_CONFIGURE_WITH=	sdl
SDL_IMPLIES=		GUI

.if defined(MACHINE_CPU) && (${MACHINE_CPU:Msse} == "sse" || ${MACHINE_CPU:Mamd64} == "amd64")
CONFIGURE_ARGS+=	--with-sse \
			--with-sse-inline
PLIST_SUB+=		SSE=""
.else
CONFIGURE_ARGS+=	--without-sse
PLIST_SUB+=		SSE="@comment "
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libag_*.so.*

post-patch-GUI-off:
	@${REINPLACE_CMD} -e 's|^LIBS=.*|LIBS=|' ${WRKSRC}/au/Makefile
	@${REINPLACE_CMD} -e 's|^LIBS=.*|LIBS=|' ${WRKSRC}/math/Makefile

.include <bsd.port.mk>
