PORTNAME=	linux-rl9
PORTVERSION=	${LINUX_DIST_VER}
CATEGORIES=	emulators linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Meta-port for all things Rocky Linux ${LINUX_DIST_VER}
WWW=		https://rockylinux.org

LICENSE=	BSD2CLAUSE

USES=		linux:rl9 metaport
USE_LINUX=	alsalib alsa-lib-devel alsa-plugins-oss alsa-plugins-pulseaudio \
		at-spi2-atk at-spi2-core atk avahi-libs brotli \
		ca-certificates cairo cairo-gobject cups-libs curl cyrus-sasl2 \
		dbuslibs devtools dri elfutils-libelf elfutils-libs expat \
		ffmpeg-libs flac fontconfig freetype fribidi gdkpixbuf2 gnupg gnutls \
		graphite2 gsm gstreamer1 gstreamer1-libav gtk2 gtk3 harfbuzz icu \
		jasper jbigkit jpeg libassuan libasyncns libdrm libepoxy libevent \
		libgcrypt libgfortran libglvnd libgpg-error libidn2 libnghttp2 libogg \
		libpciaccess libproxy libpsl librsvg2 libsecret libsigc++20 libsigsegv \
		libsndfile libsoup libtasn1 libthai libtheora libtool-ltdl \
		libtracker-sparql libunistring libusb libv4l libva libvdpau \
		libvorbis libvpx libxcrypt libxkbcommon libxml2 libxslt llvm \
		lz4 nettle nspr nss ocl-icd openal-soft openjpeg openldap opus orc \
		p11-kit pango pixman png pulseaudio-libs pulseaudio-utils python3 \
		qt3d qtbase qtconnectivity qtdeclarative qtgraphicaleffects qtimageformats \
		qtmultimedia qtquickcontrols qtscript qtsensors qtserialbus qtserialport \
		qtsvg qttools qtwayland qtwebchannel qtwebsockets qtx11extras qtxmlpatterns \
		sqlite3 strace systemd-libs tcp_wrappers-libs tiff vulkan \
		wayland webp wget xcb-util xorglibs

.include <bsd.port.options.mk>

.include <bsd.port.mk>
