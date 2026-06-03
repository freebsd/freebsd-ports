PORTNAME=	giada
DISTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Hardcore loop machine
WWW=		https://www.giadamusic.com/ \
		https://github.com/monocasual/giada

BROKEN_FreeBSD_14=		fails to find clang-scan-deps

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libatk-1.0.so:accessibility/at-spi2-core \
		libcurl.so:ftp/curl \
		libdbus-1.so:devel/dbus \
		libfmt.so:devel/libfmt \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libjack.so:audio/jack \
		libpng16.so:graphics/png \
		libpulse.so:audio/pulseaudio \
		librtmidi.so:audio/rtmidi \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile \
		libwayland-client.so:graphics/wayland \
		libwebkit2gtk-4.0.so:www/webkit2-gtk@40 \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++17-lang gettext-runtime gl gnome jpeg localbase pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	monocasual
GH_TUPLE=	cameron314:concurrentqueue:6dd38b8:concurrentqueue/src/deps/concurrentqueue \
		fltk:fltk:a9b1113:fltk/src/deps/fltk \
		juce-framework:JUCE:29396c2:juce/src/deps/juce \
		monocasual:geompp:b6c6740:geompp/src/deps/geompp \
		monocasual:mcl-atomic-swapper:4aa864c:mclatomicswapper/src/deps/mcl-atomic-swapper \
		monocasual:mcl-audio-buffer:e6b00c8:mclaudiobuffer/src/deps/mcl-audio-buffer \
		monocasual:mcl-utils:77a740e:mclutils/src/deps/mcl-utils \
		monocasual:rtaudio:0f18dfd:rtaudio/src/deps/rtaudio
USE_GNOME=	cairo gdkpixbuf glib20 gtk30 pango
USE_GL=		egl
USE_XORG=	ice sm x11 xcursor xext xfixes xft xinerama xpm xrender

CMAKE_ON=	CMAKE_SKIP_RPATH

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
