PORTNAME=	linux-rl9
PORTVERSION=	${LINUX_DIST_VER}
CATEGORIES=	emulators linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Meta-port for all things Rocky Linux ${LINUX_DIST_VER}
WWW=		https://rockylinux.org

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	linux-rl9-gnupg2>=0:security/linux-rl9-gnupg \
		linux-rl9-pulseaudio-utils>0:audio/linux-rl9-pulseaudio-utils \
		linux-rl9-wget>=0:ftp/linux-rl9-wget

USES=		linux:rl9 metaport
USE_LINUX=	alsalib alsa-lib-devel alsa-plugins-oss alsa-plugins-pulseaudio \
		at-spi2-atk at-spi2-core atk avahi-libs brotli \
		ca-certificates cairo cairo-gobject cups-libs curl cyrus-sasl2 \
		dbuslibs dri elfutils-libelf elfutils-libs expat \
		ffmpeg-libs flac fontconfig freetype fribidi gdkpixbuf2 gnutls \
		graphite2 gsm gstreamer1 gstreamer1-libav gtk3 harfbuzz icu jasper \
		jbigkit jpeg libassuan libasyncns libdrm libevent libidn2 libpsl \
		libepoxy libgcrypt libglvnd libgpg-error libnghttp2 \
		libogg libpciaccess libproxy librsvg2 libsndfile libsoup \
		libtasn1 libthai libtheora libtracker-sparql \
		libunistring libusb libv4l libva libvdpau libvorbis libvpx libxkbcommon libxml2 \
		llvm lz4 nettle nspr nss openal-soft ocl-icd openjpeg openldap opus orc \
		p11-kit pango pixman png pulseaudio-libs python3 sqlite3 \
		strace systemd-libs tiff vulkan wayland webp xorglibs

.include <bsd.port.options.mk>

.include <bsd.port.mk>
