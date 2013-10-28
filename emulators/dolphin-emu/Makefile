# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	dolphin-emu
PORTVERSION=	4.0.0
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://contribs.martymac.org/FreeBSD-ports/distfiles/ \
		LOCAL/martymac
EXTRACT_SUFX=	.tgz

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Gamecube and Wii Emulator

LICENSE=	GPLv2

LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		liblzo2.so:${PORTSDIR}/archivers/lzo2 \
		libSoundTouch.so:${PORTSDIR}/audio/soundtouch \
		libsfml-network.so:${PORTSDIR}/devel/sfml \
		libpolarssl.so:${PORTSDIR}/security/polarssl

USE_SDL=	sdl
USE_OPENAL=	yes
USE_XORG=	ice xext x11 xrandr xi
USE_WX=		2.9+
WX_UNICODE=	yes
USE_GL=	gl glew glu

USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*\.(h|c|cpp)

USE_GCC=	yes

USES=		cmake pkgconfig iconv
CMAKE_BUILD_TYPE=	Release
# Disable ALSA (emulated) and ao (buggy)
CMAKE_ARGS+=	-DOPENMP:BOOL=OFF \
		-DDISABLE_ALSA:BOOL=ON \
		-DDISABLE_AO:BOOL=ON \
		-DDISABLE_BLUEZ:BOOL=ON \
		-DUSE_X11:BOOL=ON \
		-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=ON

OPTIONS_DEFINE=	PULSEAUDIO PORTAUDIO DEBUG FRAMEDUMPS UPNP
PORTAUDIO_DESC=	Enable PortAudio (mic) support
FRAMEDUMPS_DESC=	Encode framedumps in AVI format
OPTIONS_DEFAULT=	PORTAUDIO FRAMEDUMPS UPNP

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CMAKE_ARGS+=	-DDISABLE_NLS:BOOL=ON
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MDEBUG}
CMAKE_ARGS+=	-DFASTLOG:BOOL=ON
INSTALL_TARGET=	install
CFLAGS+=	-g
CXXFLAGS+=	-g
MAKE_ENV+=	VERBOSE=yes
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	libpulse.so:${PORTSDIR}/audio/pulseaudio
.else
CMAKE_ARGS+=	-DDISABLE_PULSEAUDIO:BOOL=ON
.endif

.if ${PORT_OPTIONS:MPORTAUDIO}
LIB_DEPENDS+=	libportaudio.so.2:${PORTSDIR}/audio/portaudio2
.else
CMAKE_ARGS+=	-DDISABLE_PORTAUDIO:BOOL=ON
.endif

.if ${PORT_OPTIONS:MFRAMEDUMPS}
CMAKE_ARGS+=	-DENCODE_FRAMEDUMPS:BOOL=ON
LIB_DEPENDS+=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg \
		libavformat.so:${PORTSDIR}/multimedia/ffmpeg \
		libswscale.so:${PORTSDIR}/multimedia/ffmpeg \
		libavutil.so:${PORTSDIR}/multimedia/ffmpeg
.else
CMAKE_ARGS+=	-DENCODE_FRAMEDUMPS:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MUPNP}
CMAKE_ARGS+=	-DUSE_UPNP:BOOL=ON
LIB_DEPENDS+=	libminiupnpc.so:${PORTSDIR}/net/miniupnpc
.else
CMAKE_ARGS+=	-DUSE_UPNP:BOOL=OFF
.endif

.include <bsd.port.pre.mk>

.if !empty(ICONV_LIB)
CMAKE_ARGS+=	-DUSE_ICONV:BOOL=ON
.else
CMAKE_ARGS+=	-DUSE_ICONV:BOOL=OFF
.endif

.include <bsd.port.post.mk>
