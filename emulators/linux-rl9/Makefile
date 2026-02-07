PORTNAME=	linux-rl9
PORTVERSION=	${LINUX_DIST_VER}
CATEGORIES=	emulators linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Meta-port for all things Rocky Linux ${LINUX_DIST_VER}
WWW=		https://rockylinux.org

LICENSE=	BSD2CLAUSE

USES=		linux:rl9 metaport
USE_LINUX=	alsalib alsa-lib-devel alsa-plugins-oss alsa-plugins-pulseaudio \
		at-spi2-atk at-spi2-core atk avahi-libs \
		ca-certificates cairo cairo-gobject cups-libs curl cyrus-sasl2 \
		dbuslibs devtools dri elfutils-libelf elfutils-libs expat \
		ffmpeg-libs flac fontconfig freetype fribidi gdkpixbuf2 gnupg gnutls \
		graphite2 gsm gstreamer1 gstreamer1-libav gtk2 gtk3 harfbuzz icu \
		imageformats-libs libassuan libasyncns libdrm libepoxy libevent \
		libgcrypt libglvnd libgpg-error libksba libnghttp2 libogg \
		libpciaccess librsvg2 libsecret libsigc++20 \
		libsndfile libssh libstemmer libtasn1 libthai libtheora libtool-ltdl \
		libtracker-sparql libusb libv4l libva libvdpau \
		libvorbis libvpx libxkbcommon libxml2 libxslt llvm \
		lz4 nettle npth nspr nss ocl-icd openal-soft openldap opus orc \
		p11-kit pango pixman pulseaudio-libs pulseaudio-utils python3 \
		qt3d qtbase qtconnectivity qtdeclarative qtgraphicaleffects qtimageformats \
		qtmultimedia qtquickcontrols qtscript qtsensors qtserialbus qtserialport \
		qtsvg qttools qtwayland qtwebchannel qtwebsockets qtx11extras qtxmlpatterns \
		sdl12 sdl12-extralibs sdl20 sdl20-extralibs \
		sqlite3 strace systemd-libs tcp_wrappers-libs vulkan \
		wayland wget xcb-util xorglibs

.include <bsd.port.options.mk>

.include <bsd.port.mk>
