PORTNAME=	sdl3
DISTVERSIONPREFIX=	release-
DISTVERSION=	3.2.18
CATEGORIES=	devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Cross-platform multimedia development API (version 3 preview)
WWW=		https://www.libsdl.org/ \
		https://github.com/libsdl-org/SDL

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake iconv localbase pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	libsdl-org
GH_PROJECT=	SDL
CMAKE_OFF=	SDL_RPATH SDL_DEPS_SHARED
CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_Git
USE_LDCONFIG=	yes

PLIST_SUB=	LIBVERSION=${DISTVERSION:C/[0-9]+/0/1}

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=		CSD DBUS FCITX HIDAPI IBUS JOYSTICK \
			SAMPLERATE UDEV
OPTIONS_GROUP=		AUDIO VIDEO
OPTIONS_GROUP_AUDIO=	ALSA JACK OSS PIPEWIRE PULSEAUDIO SNDIO
OPTIONS_GROUP_VIDEO=	KMSDRM OPENGL OPENGLES VULKAN \
			WAYLAND X11
OPTIONS_DEFAULT=	HIDAPI JOYSTICK KMSDRM OPENGL OPENGLES \
			OSS VULKAN WAYLAND X11
OPTIONS_DEFINE_powerpc=	ALTIVEC
OPTIONS_DEFINE_powerpc64=	ALTIVEC
OPTIONS_DEFAULT_powerpc=	ALTIVEC
OPTIONS_DEFAULT_powerpc64=	ALTIVEC
OPTIONS_SUB=		yes

AUDIO_DESC=		Audio drivers
VIDEO_DESC=		Video drivers

CSD_DESC=		Client-side decorations for Wayland via libdecor
FCITX_DESC=		fcitx support
HIDAPI_DESC=		Use HIDAPI for low level joystick drivers
IBUS_DESC=		IBus support
JOYSTICK_DESC=		Joystick and haptic support
KMSDRM_DESC=		KMSDRM display support
OPENGLES_DESC=		OpenGL ES rendering support
UDEV_DESC=		Use udev for input device detection
VULKAN_DESC=		Vulkan rendering support

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=	SDL_ALSA
ALSA_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_ALSA

ALTIVEC_CMAKE_BOOL=	SDL_ALTIVEC

CSD_LIB_DEPENDS=	libdecor-0.so:x11-toolkits/libdecor
CSD_CMAKE_BOOL=		SDL_WAYLAND_LIBDECOR
CSD_IMPLIES=		WAYLAND

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_CMAKE_BOOL=	SDL_DBUS

FCITX_LIB_DEPENDS=	libfcitx-config.so:chinese/fcitx
FCITX_IMPLIES=		DBUS

HIDAPI_CMAKE_BOOL=	SDL_HIDAPI
HIDAPI_IMPLIES=		JOYSTICK

IBUS_LIB_DEPENDS=	libibus-1.0.so:textproc/ibus
IBUS_CMAKE_BOOL=	SDL_IBUS
IBUS_IMPLIES=		DBUS

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CMAKE_BOOL=	SDL_JACK

JOYSTICK_BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto
JOYSTICK_LIB_DEPENDS=	libinotify.so:devel/libinotify
JOYSTICK_CMAKE_BOOL=	SDL_HIDAPI_JOYSTICK SDL_HIDAPI_LIBUSB SDL_VIRTUAL_JOYSTICK

KMSDRM_USES=		gl
KMSDRM_USE=		GL=gbm
KMSDRM_CMAKE_BOOL=	SDL_KMSDRM

OPENGL_USES=		gl
OPENGL_USE=		GL=opengl
OPENGL_CMAKE_BOOL=	SDL_OPENGL

OPENGLES_USES=		gl
OPENGLES_USE=		GL=egl,glesv1,glesv2
OPENGLES_CMAKE_BOOL=	SDL_OPENGLES

OSS_CMAKE_BOOL=		SDL_OSS

PIPEWIRE_LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire
PIPEWIRE_CMAKE_BOOL=	SDL_PIPEWIRE

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	SDL_PULSEAUDIO

SAMPLERATE_LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate
SAMPLERATE_CMAKE_BOOL=	SDL_LIBSAMPLERATE
SAMPLERATE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_SampleRate

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CMAKE_BOOL=	SDL_SNDIO

UDEV_BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto
UDEV_LIB_DEPENDS=	libudev.so:devel/libudev-devd
UDEV_CMAKE_BOOL=	SDL_LIBUDEV

VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader
VULKAN_CMAKE_BOOL=	SDL_VULKAN SDL_RENDER_VULKAN

WAYLAND_BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols \
			${LOCALBASE}/include/linux/input.h:devel/evdev-proto
WAYLAND_LIB_DEPENDS=	libwayland-egl.so:graphics/wayland \
			libxkbcommon.so:x11/libxkbcommon
WAYLAND_CMAKE_BOOL=	SDL_WAYLAND
WAYLAND_IMPLIES=	OPENGLES

X11_USES=		xorg
X11_USE=		XORG=x11,xcursor,xext,xi,xfixes,xrandr,xrender,xscrnsaver
X11_CMAKE_BOOL=		SDL_X11

.include <bsd.port.options.mk>

# Similar to x11/pixman
.if ${ARCH} == "armv6" || ${ARCH} == "armv7"
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:devel/binutils
CFLAGS+=	-B${LOCALBASE}/bin -no-integrated-as
.endif

.if !${PORT_OPTIONS:MX11} && !${PORT_OPTIONS:MWAYLAND}
CMAKE_ON+=	SDL_UNIX_CONSOLE_BUILD
.endif

post-patch-FCITX-off:
	@${REINPLACE_CMD} -e 's|HAVE_FCITX TRUE|HAVE_FCITX FALSE|g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
