# New ports collection makefile for:	dolphin-emu
# Date created:		2011-10-03
# Whom:			Ganael Laplanche <ganael.laplanche@martymac.org>
#
# $FreeBSD$
#

PORTNAME=	dolphin-emu
PORTVERSION=	3.0.r${REVDATE}
CATEGORIES=	emulators
MASTER_SITES=	http://contribs.martymac.org/FreeBSD-ports/distfiles/ \
		LOCAL/martymac
PKGNAMESUFFIX=	-devel
EXTRACT_SUFX=	.tgz

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Gamecube and Wii Emulator

LICENSE=	GPLv2

LIB_DEPENDS=	avformat.1:${PORTSDIR}/multimedia/ffmpeg \
		execinfo.1:${PORTSDIR}/devel/libexecinfo \
		freetype.9:${PORTSDIR}/print/freetype2 \
		lzo2.2:${PORTSDIR}/archivers/lzo2 \
		sfml-network.1:${PORTSDIR}/devel/sfml

REVDATE=	20110912

USE_GNOME=	pkgconfig gnomelibs
USE_SDL=	sdl
USE_OPENAL=	yes
USE_XORG=	ice xext x11 xrandr
USE_WX=	2.8
USE_GL=	gl glew glu

USE_CMAKE=	yes
CMAKE_BUILD_TYPE=	Release
# Disable ao (seems buggy) and ALSA (emulated)
CMAKE_ARGS+=	-DDISABLE_AO:BOOL=ON \
		-DDISABLE_ALSA:BOOL=ON \
		-DDISABLE_BLUEZ:BOOL=ON

## Un-comment the following to build with debug symbols
#INSTALL_TARGET=	install
#CFLAGS+=	-ggdb
#MAKE_ENV+=	VERBOSE=yes

SUB_FILES=	pkg-message
SUB_LIST+=	MAINTAINER=${MAINTAINER}

OPTIONS=	PULSEAUDIO "Build PulseAudio sound backend" off \
		PORTAUDIO "Enable portaudio (mic) support" on

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CMAKE_ARGS+=	-DDISABLE_NLS:BOOL=ON
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.pre.mk>

# XXX Needs spawn.h header to build
.if ${OSVERSION} < 800041
BROKEN=	requires FreeBSD 8.0 or newer
.endif

.if defined(WITH_PULSEAUDIO)
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
.else
CMAKE_ARGS+=	-DDISABLE_PULSEAUDIO:BOOL=ON
.endif

.if !defined(WITHOUT_PORTAUDIO)
LIB_DEPENDS+=	portaudio.2:${PORTSDIR}/audio/portaudio2
.else
CMAKE_ARGS+=	-DDISABLE_PORTAUDIO:BOOL=ON
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
