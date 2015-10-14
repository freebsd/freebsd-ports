# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	dolphin-emu
PORTVERSION=	4.0.2
PORTREVISION=	4
CATEGORIES=	emulators

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Gamecube and Wii Emulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		liblzo2.so:${PORTSDIR}/archivers/lzo2 \
		libSoundTouch.so:${PORTSDIR}/audio/soundtouch \
		libpolarssl.so.5:${PORTSDIR}/security/polarssl

USE_GITHUB=	yes
GH_PROJECT=	dolphin

USE_SDL=	sdl
USE_XORG=	ice xext x11 xrandr xi
USE_WX=		3.0+
WX_UNICODE=	yes
USE_GL=		gl glew glu

USES=		dos2unix cmake iconv openal pkgconfig tar:tgz compiler:c++11-lib
DOS2UNIX_REGEX=	.*\.(h|c|cpp)

NOT_FOR_ARCHS=	armv6

# Disable ALSA (emulated) and ao (buggy)
CMAKE_ARGS+=	-DOPENMP:BOOL=OFF \
		-DDISABLE_ALSA:BOOL=ON \
		-DDISABLE_AO:BOOL=ON \
		-DDISABLE_BLUEZ:BOOL=ON \
		-DUSE_X11:BOOL=ON \
		-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=ON

OPTIONS_DEFINE=	PULSEAUDIO PORTAUDIO DEBUG FRAMEDUMPS UPNP NLS
OPTIONS_DEFAULT=	PORTAUDIO FRAMEDUMPS UPNP NLS
OPTIONS_SUB=	yes
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:${PORTSDIR}/audio/pulseaudio
PULSEAUDIO_CMAKE_ON=	-DDISABLE_PULSEAUDIO:BOOL=OFF
PULSEAUDIO_CMAKE_OFF=	-DDISABLE_PULSEAUDIO:BOOL=ON
PORTAUDIO_DESC=	Enable PortAudio (mic) support
PORTAUDIO_LIB_DEPENDS=	libportaudio.so:${PORTSDIR}/audio/portaudio
PORTAUDIO_CMAKE_ON=	-DDISABLE_PORTAUDIO:BOOL=OFF
PORTAUDIO_CMAKE_OFF=	-DDISABLE_PORTAUDIO:BOOL=ON
DEBUG_MAKE_ENV=	VERBOSE=yes
DEBUG_CMAKE_ON=	-DFASTLOG:BOOL=ON
DEBUG_CMAKE_OFF=	-DFASTLOG:BOOL=OFF
FRAMEDUMPS_DESC=	Encode framedumps in AVI format
FRAMEDUMPS_LIB_DEPENDS=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg \
			libavformat.so:${PORTSDIR}/multimedia/ffmpeg \
			libswscale.so:${PORTSDIR}/multimedia/ffmpeg \
			libavutil.so:${PORTSDIR}/multimedia/ffmpeg
FRAMEDUMPS_CMAKE_ON=	-DENCODE_FRAMEDUMPS:BOOL=ON
FRAMEDUMPS_CMAKE_OFF=	-DENCODE_FRAMEDUMPS:BOOL=OFF
UPNP_LIB_DEPENDS=	libminiupnpc.so:${PORTSDIR}/net/miniupnpc
UPNP_CMAKE_ON=	-DUSE_UPNP:BOOL=ON
UPNP_CMAKE_OFF=	-DUSE_UPNP:BOOL=OFF
NLS_USES=	gettext
NLS_CMAKE_ON=	-DDISABLE_NLS:BOOL=OFF
NLS_CMAKE_OFF=	-DDISABLE_NLS:BOOL=ON

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 900000
BROKEN=		does not build: absence of xlocale.h
.endif

# XXX Temporary workaround for ports/184540
.if ${PORT_OPTIONS:MDEBUG}
INSTALL_TARGET=	install
.endif

.if !empty(ICONV_LIB)
CMAKE_ARGS+=	-DICONV_LINK:BOOL=ON
.else
CMAKE_ARGS+=	-DICONV_LINK:BOOL=OFF
.endif

.include <bsd.port.post.mk>
