# Created by: Piotr Kubaj
# $FreeBSD$

PORTNAME=	linux-c7
PORTVERSION=	${LINUX_DIST_VER}
PORTREVISION=	2
CATEGORIES=	emulators linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Meta-port for all things CentOS ${LINUX_DIST_VER}

RUN_DEPENDS=	linux-c7-libasyncns>0:dns/linux-c7-libasyncns \
		linux-c7-tk85>0:x11-toolkits/linux-c7-tk85 \
		linux-c7-gtk2>0:x11-toolkits/linux-c7-gtk2 \
		linux-c7-hicolor-icon-theme>0:x11-themes/linux-c7-hicolor-icon-theme \
		linux-c7-qt-x11>0:x11-toolkits/linux-c7-qt-x11 \
		linux-c7-pango>0:x11-toolkits/linux-c7-pango \
		linux-c7-openmotif>0:x11-toolkits/linux-c7-openmotif \
		linux-c7-atk>0:accessibility/linux-c7-atk \
		linux-c7-sqlite>0:databases/linux-c7-sqlite3 \
		linux-c7-tcl85>0:lang/linux-c7-tcl85 \
		linux-c7-nspr>0:devel/linux-c7-nspr \
		linux-c7-libsigc++20>0:devel/linux-c7-libsigc++20 \
		linux-c7-sdl>0:devel/linux-c7-sdl12 \
		linux-c7-libpciaccess>0:devel/linux-c7-libpciaccess \
		linux-c7-libglade2>0:devel/linux-c7-libglade2 \
		linux-c7-devtools>0:devel/linux-c7-devtools \
		linux-c7-dbus-libs>0:devel/linux-c7-dbus-libs \
		linux-c7-qt>0:devel/linux-c7-qt \
		linux-c7-dbus-glib>0:devel/linux-c7-dbus-glib \
		linux-c7-ncurses-base>0:devel/linux-c7-ncurses-base \
		linux-c7-xorg-libs>0:x11/linux-c7-xorg-libs \
		linux-c7-fontconfig>0:x11-fonts/linux-c7-fontconfig \
		linux-c7-cups-libs>0:print/linux-c7-cups-libs \
		linux-c7-flac>0:audio/linux-c7-flac \
		linux-c7-alsa-utils>0:audio/linux-c7-alsa-utils \
		linux-c7-alsa-lib>0:audio/linux-c7-alsa-lib \
		linux-c7-audiofile>0:audio/linux-c7-audiofile \
		linux-c7-alsa-plugins-oss>0:audio/linux-c7-alsa-plugins-oss \
		linux-c7-alsa-plugins-pulseaudio>0:audio/linux-c7-alsa-plugins-pulseaudio \
		linux-c7-libsndfile>0:audio/linux-c7-libsndfile \
		linux-c7-libogg>0:audio/linux-c7-libogg \
		linux-c7-pulseaudio-utils>0:audio/linux-c7-pulseaudio-utils \
		linux-c7-pulseaudio-libs>0:audio/linux-c7-pulseaudio-libs \
		linux-c7-libvorbis>0:audio/linux-c7-libvorbis \
		linux-c7-libtheora>0:multimedia/linux-c7-libtheora \
		linux-c7-libv4l>0:multimedia/linux-c7-libv4l \
		linux-c7-cyrus-sasl2>0:security/linux-c7-cyrus-sasl2 \
		linux-c7-libssh2>0:security/linux-c7-libssh2 \
		linux-c7-openssl-compat>0:security/linux-c7-openssl-compat \
		linux-c7-openssl>0:security/linux-c7-openssl \
		linux-c7-gnutls>0:security/linux-c7-gnutls \
		linux-c7-libgcrypt>0:security/linux-c7-libgcrypt \
		linux-c7-nss>0:security/linux-c7-nss \
		linux-c7-libtasn1>0:security/linux-c7-libtasn1 \
		linux-c7-libgpg-error>0:security/linux-c7-libgpg-error \
		linux-c7-curl>0:ftp/linux-c7-curl \
		linux-c7-tcp_wrappers-libs>0:net/linux-c7-tcp_wrappers-libs \
		linux-c7-openldap>0:net/linux-c7-openldap \
		linux-c7-avahi-libs>0:net/linux-c7-avahi-libs \
		linux-c7-expat>0:textproc/linux-c7-expat \
		linux-c7-aspell>0:textproc/linux-c7-aspell \
		linux-c7-libxml2>0:textproc/linux-c7-libxml2 \
		linux-c7-dri>0:graphics/linux-c7-dri \
		linux-c7-png>0:graphics/linux-c7-png \
		linux-c7-tiff>0:graphics/linux-c7-tiff \
		linux-c7-jpeg>0:graphics/linux-c7-jpeg \
		linux-c7-glx-utils>0:graphics/linux-c7-glx-utils \
		linux-c7-gdk-pixbuf2>0:graphics/linux-c7-gdk-pixbuf2 \
		linux-c7-cairo>0:graphics/linux-c7-cairo \
		linux-c7-pixman>0:x11/linux-c7-pixman \
		linux-c7-jasper>0:graphics/linux-c7-jasper

USES=		linux:c7 metaport

.include <bsd.port.pre.mk>

.if ${LINUX_ARCH} == x86_64
RUN_DEPENDS+=	linux-c7-sdl_image>0:graphics/linux-c7-sdl_image \
		linux-c7-esound>0:audio/linux-c7-esound \
		linux-c7-openal-soft>0:audio/linux-c7-openal-soft \
		linux-c7-sdl20>0:devel/linux-c7-sdl20 \
		linux-c7-sdl_mixer>0:audio/linux-c7-sdl_mixer \
		linux-c7-sdl_ttf>0:graphics/linux-c7-sdl_ttf \
		linux-c7-qtwebkit>0:www/linux-c7-qtwebkit
.endif

.include <bsd.port.post.mk>
