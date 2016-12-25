# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	dolphin-emu
PORTVERSION=	5.0
PORTREVISION=	3
CATEGORIES=	emulators

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Gamecube and Wii Emulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

# Notes on dependencies:
# - keep enet from Externals as Dolphin's version diverges
# - xxhash and SOIL are not (yet?) in ports and built from Externals
# - skip ALSA (emulated), ao (buggy) and bluez support
LIB_DEPENDS=	libpulse.so:audio/pulseaudio \
		libavcodec.so:multimedia/ffmpeg \
		libavformat.so:multimedia/ffmpeg \
		libswscale.so:multimedia/ffmpeg \
		libavutil.so:multimedia/ffmpeg \
		libportaudio.so:audio/portaudio \
 		liblzo2.so:archivers/lzo2 \
 		libpng.so:graphics/png \
 		libSoundTouch.so:audio/soundtouch \
 		libsfml-system.so:devel/sfml \
		libminiupnpc.so:net/miniupnpc \
 		libmbedtls.so:security/mbedtls \
		libcurl.so:ftp/curl \
		libgtest.so:devel/googletest

USE_GITHUB=	yes
GH_PROJECT=	dolphin

USE_GL=		gl glew glu
USE_GNOME=	atk cairo glib20 gdkpixbuf2 gtk20 pango
USE_SDL=	sdl2
USE_WX=		3.0+
USE_XORG=	ice sm x11 xext xi xrandr

USES=		cmake compiler:c++11-lib iconv openal pkgconfig

CMAKE_ARGS+=	-DTRY_X11:BOOL=ON \
		-DUSE_UPNP:BOOL=ON \
		-DDISABLE_WX:BOOL=OFF \
		-DUSE_SHARED_GTEST:BOOL=ON \
		-DENABLE_PCH:BOOL=OFF \
		-DCMAKE_REQUIRED_INCLUDES:PATH="${LOCALBASE}/include" \
		-DCMAKE_REQUIRED_FLAGS:STRING="-L${LOCALBASE}/lib" \
		-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=ON

# XXX Bypass git check (and set a dummy -unused- revision)
CMAKE_ARGS+=	-DDOLPHIN_WC_BRANCH:STRING="stable" \
		-DDOLPHIN_WC_REVISION:STRING="1"

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
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
