# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	dolphin-emu
DISTVERSION=	5.0-rc
PORTREVISION=	2
CATEGORIES=	emulators

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Gamecube and Wii Emulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

# Notes on dependencies:
# - keep enet from externals as Dolphin's version diverges
# - xxhash and SOIL are not (yet) in ports
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		liblzo2.so:archivers/lzo2 \
		libpng.so:graphics/png \
		libSoundTouch.so:audio/soundtouch \
		libmbedtls.so.9:security/polarssl13 \
		libsfml-system.so:devel/sfml

USE_GITHUB=	yes
GH_PROJECT=	dolphin

USE_SDL=	sdl2
USE_XORG=	ice x11 xext xi xrandr
USE_WX=		3.0+
USE_GL=		gl glew glu

USES=		cmake compiler:c++11-lib dos2unix iconv openal pkgconfig tar:tgz
DOS2UNIX_REGEX=	.*\.(h|c|cpp)

# Disable ALSA (emulated) and ao (buggy)
CMAKE_ARGS+=	-DTRY_X11:BOOL=ON \
		-DDISABLE_WX:BOOL=OFF \
		-DENABLE_QT:BOOL=OFF \
		-DENABLE_PCH:BOOL=OFF \
		-DENABLE_SDL:BOOL=ON \
		-DDISABLE_ALSA:BOOL=ON \
		-DDISABLE_AO:BOOL=ON \
		-DDISABLE_BLUEZ:BOOL=ON \
		-DDISABLE_OPENAL:BOOL=OFF \
		-DCMAKE_REQUIRED_INCLUDES:PATH="${LOCALBASE}/include" \
		-DCMAKE_REQUIRED_FLAGS:STRING="-L${LOCALBASE}/lib" \
		-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=ON

# XXX Bypass git check (and set a dummy -unused- revision)
CMAKE_ARGS+=	-DDOLPHIN_WC_BRANCH:STRING="stable" \
		-DDOLPHIN_WC_REVISION:STRING="1"

OPTIONS_DEFINE=	PULSEAUDIO PORTAUDIO DEBUG FRAMEDUMPS UPNP NLS
OPTIONS_DEFAULT=	PORTAUDIO FRAMEDUMPS UPNP
OPTIONS_SUB=	yes
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_ON=	-DDISABLE_PULSEAUDIO:BOOL=OFF
PULSEAUDIO_CMAKE_OFF=	-DDISABLE_PULSEAUDIO:BOOL=ON
PORTAUDIO_DESC=	Enable PortAudio (mic) support
PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_CMAKE_ON=	-DDISABLE_PORTAUDIO:BOOL=OFF
PORTAUDIO_CMAKE_OFF=	-DDISABLE_PORTAUDIO:BOOL=ON
DEBUG_MAKE_ENV=	VERBOSE=yes
DEBUG_CMAKE_ON=	-DFASTLOG:BOOL=ON
DEBUG_CMAKE_OFF=	-DFASTLOG:BOOL=OFF
FRAMEDUMPS_DESC=	Encode framedumps in AVI format
FRAMEDUMPS_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
			libavformat.so:multimedia/ffmpeg \
			libswscale.so:multimedia/ffmpeg \
			libavutil.so:multimedia/ffmpeg
FRAMEDUMPS_CMAKE_ON=	-DENCODE_FRAMEDUMPS:BOOL=ON
FRAMEDUMPS_CMAKE_OFF=	-DENCODE_FRAMEDUMPS:BOOL=OFF
UPNP_LIB_DEPENDS=	libminiupnpc.so:net/miniupnpc
UPNP_CMAKE_ON=	-DUSE_UPNP:BOOL=ON
UPNP_CMAKE_OFF=	-DUSE_UPNP:BOOL=OFF
NLS_USES=	gettext
NLS_CMAKE_ON=	-DDISABLE_NLS:BOOL=OFF
NLS_CMAKE_OFF=	-DDISABLE_NLS:BOOL=ON

.include <bsd.port.pre.mk>

# JIT-enabled binaries are amd64 only
.if ${ARCH} != "amd64"
CMAKE_ARGS+=	-DENABLE_GENERIC:BOOL=ON
.endif

# When building with GCC, needs GCC 4.9+
.if ${COMPILER_TYPE} == gcc && ${COMPILER_VERSION} < 49
USE_GCC=	yes
# Enable std::stoul()
CXXFLAGS+=	-D_GLIBCXX_USE_C99
# Enable log2f(), exp2f() and roundf()
CXXFLAGS+=	-D_GLIBCXX_USE_C99_MATH_TR1
# Turn on extra long double versions of math functions, needed for cmath
CXXFLAGS+=	-D__ISO_C_VISIBLE=1999 -D_DECLARE_C99_LDBL_MATH
.endif

.include <bsd.port.post.mk>
