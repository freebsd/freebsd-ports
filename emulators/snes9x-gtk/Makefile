PORTNAME=	snes9x
DISTVERSION=	1.61
CATEGORIES=	emulators
PKGNAMESUFFIX=	-gtk

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
		libpng.so:graphics/png

USES=		compiler:c++17-lang desktop-file-utils gettext \
		gnome localbase:ldflags meson pkgconfig sdl xorg
USE_GITHUB=	yes
GH_ACCOUNT=	snes9xgit
GH_TUPLE=	KhronosGroup:glslang:bcf6a24:glslang/../shaders/glslang \
		KhronosGroup:SPIRV-Cross:1458bae:spirv/../shaders/SPIRV-Cross
USE_GNOME=	gdkpixbuf2 gtkmm30
USE_SDL=	sdl2
USE_XORG=	x11 xrandr xext

PATCH_WRKSRC=	${WRKSRC}/..
WRKSRC_SUBDIR=	gtk

OPTIONS_MULTI=		SOUND
OPTIONS_MULTI_SOUND=	ALSA OSS PORTAUDIO PULSEAUDIO
OPTIONS_DEFINE=		DEBUGGER NLS WAYLAND XVIDEO
OPTIONS_DEFAULT=	OSS WAYLAND XVIDEO
OPTIONS_SUB=		yes

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_MESON_TRUE=	alsa

DEBUGGER_DESC=		Snes9X debugger
DEBUGGER_MESON_TRUE=	debugger

OSS_MESON_TRUE=		oss

PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_MESON_TRUE=	portaudio

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_MESON_TRUE=	pulseaudio

WAYLAND_CATEGORIES=	wayland
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
WAYLAND_MESON_TRUE=	wayland

XVIDEO_USE=		XORG=xv

.include <bsd.port.mk>
