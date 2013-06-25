# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	dolphin-emu
PORTVERSION=	3.5.r${REVDATE}
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://contribs.martymac.org/FreeBSD-ports/distfiles/ \
		LOCAL/martymac
PKGNAMESUFFIX=	-devel
EXTRACT_SUFX=	.tgz

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Gamecube and Wii Emulator

LICENSE=	GPLv2

LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo \
		freetype:${PORTSDIR}/print/freetype2 \
		lzo2:${PORTSDIR}/archivers/lzo2 \
		sfml-network:${PORTSDIR}/devel/sfml

REVDATE=	20130415

USE_SDL=	sdl
USE_OPENAL=	yes
USE_XORG=	ice xext x11 xrandr
USE_WX=		2.9+
WX_UNICODE=	yes
USE_GL=	gl glew glu

USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*\.(h|c|cpp)

# XXX Has only been tested with clang and gcc
.if ${CC} != "clang" && ${CXX} != "clang++"
USE_GCC=	4.6+
.endif

USES=		cmake pkgconfig iconv
CMAKE_BUILD_TYPE=	Release
# Disable ao (seems buggy) and ALSA (emulated)
CMAKE_ARGS+=	-DDISABLE_AO:BOOL=ON \
		-DDISABLE_ALSA:BOOL=ON \
		-DDISABLE_BLUEZ:BOOL=ON \
		-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=ON

SUB_FILES=	pkg-message
SUB_LIST+=	MAINTAINER=${MAINTAINER}

OPTIONS_DEFINE=	PULSEAUDIO PORTAUDIO DEBUG FRAMEDUMPS
PORTAUDIO_DESC=	Enable PortAudio (mic) support
FRAMEDUMPS_DESC=	Encode framedumps in AVI format
OPTIONS_DEFAULT=	PORTAUDIO FRAMEDUMPS

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
LIB_DEPENDS+=	pulse:${PORTSDIR}/audio/pulseaudio
.else
CMAKE_ARGS+=	-DDISABLE_PULSEAUDIO:BOOL=ON
.endif

.if ${PORT_OPTIONS:MPORTAUDIO}
LIB_DEPENDS+=	portaudio.2:${PORTSDIR}/audio/portaudio2
.else
CMAKE_ARGS+=	-DDISABLE_PORTAUDIO:BOOL=ON
.endif

.if ${PORT_OPTIONS:MFRAMEDUMPS}
CMAKE_ARGS+=	-DENCODE_FRAMEDUMPS:BOOL=ON
LIB_DEPENDS+=	avcodec1:${PORTSDIR}/multimedia/ffmpeg1 \
		avformat1:${PORTSDIR}/multimedia/ffmpeg1 \
		swscale1:${PORTSDIR}/multimedia/ffmpeg1 \
		avutil1:${PORTSDIR}/multimedia/ffmpeg1
.else
CMAKE_ARGS+=	-DENCODE_FRAMEDUMPS:BOOL=OFF
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
