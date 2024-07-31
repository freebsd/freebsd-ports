PORTNAME=	snes9x
DISTVERSION=	1.63
CATEGORIES=	emulators
PKGNAMESUFFIX=	-gtk

PATCH_SITES=	https://github.com/snes9xgit/snes9x/commit/
PATCHFILES=	bff02194a797b44f7d0082c4594a2c8c0381bb1b.patch:-p1

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Super Nintendo Entertainment System (SNES) Emulator
WWW=		https://github.com/snes9xgit/snes9x

# Commercial users must seek permission from copyright holders.
LICENSE=	Snes9x
LICENSE_NAME=	Snes9x License
LICENSE_FILE=	${WRKSRC}/../LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

LIB_DEPENDS=	libminizip.so:archivers/minizip \
		libepoxy.so:graphics/libepoxy \
		libpng.so:graphics/png \
		libharfbuzz.so:print/harfbuzz

USES=		cmake compiler:c++17-lang desktop-file-utils gettext \
		gnome localbase:ldflags pkgconfig sdl xorg
USE_GITHUB=	yes
GH_ACCOUNT=	snes9xgit
GH_TUPLE=	KhronosGroup:SPIRV-Cross:bccaa94:spirv/../external/SPIRV-Cross \
		KhronosGroup:Vulkan-Headers:577baa0:vulkan/../external/vulkan-headers \
		KhronosGroup:glslang:9c7fd1a:glslang/../external/glslang

USE_GNOME=	gdkpixbuf2 gtkmm30
USE_SDL=	sdl2
USE_XORG=	x11 xrandr xext

CMAKE_ARGS=	-DCMAKE_INSTALL_LOCALEDIR:STRING="share/locale"
CMAKE_OFF=	DANGEROUS_HACKS DEBUGGER

PATCH_WRKSRC=	${WRKSRC}/..
WRKSRC_SUBDIR=	gtk

OPTIONS_MULTI=		SOUND
OPTIONS_MULTI_SOUND=	ALSA OSS PORTAUDIO PULSEAUDIO
OPTIONS_DEFINE=		NLS WAYLAND XVIDEO
OPTIONS_DEFAULT=	OSS WAYLAND XVIDEO
OPTIONS_SUB=		yes

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=	USE_ALSA

OSS_CMAKE_BOOL=		USE_OSS

PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_CMAKE_BOOL=	USE_PORTAUDIO

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	USE_PULSEAUDIO

WAYLAND_CATEGORIES=	wayland
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
WAYLAND_CMAKE_BOOL=	USE_WAYLAND

XVIDEO_USE=		XORG=xv
XVIDEO_CMAKE_BOOL=	USE_XV

.include <bsd.port.mk>
