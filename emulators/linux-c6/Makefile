# Created by: Johannes Jost Meixner <xmj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	linux-c6
PORTVERSION=	${LINUX_DIST_VER}
PORTREVISION=	2
CATEGORIES=	emulators linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Meta-port for all things CentOS ${LINUX_DIST_VER}

RUN_DEPENDS=	linux-c6-libasyncns>0:dns/linux-c6-libasyncns \
		linux-c6-tk85>0:x11-toolkits/linux-c6-tk85 \
		linux-c6-gtk2>0:x11-toolkits/linux-c6-gtk2 \
		linux-c6-hicolor-icon-theme>0:x11-themes/linux-c6-hicolor-icon-theme \
		linux-c6-qt47-x11>0:x11-toolkits/linux-c6-qt47-x11 \
		linux-c6-pango>0:x11-toolkits/linux-c6-pango \
		linux-c6-openmotif>0:x11-toolkits/linux-c6-openmotif \
		linux-c6-atk>0:accessibility/linux-c6-atk \
		linux-c6-sqlite>0:databases/linux-c6-sqlite3 \
		linux-c6-tcl85>0:lang/linux-c6-tcl85 \
		linux-c6-nspr>0:devel/linux-c6-nspr \
		linux-c6-libsigc++20>0:devel/linux-c6-libsigc++20 \
		linux-c6-sdl>0:devel/linux-c6-sdl12 \
		linux-c6-libpciaccess>0:devel/linux-c6-libpciaccess \
		linux-c6-libglade2>0:devel/linux-c6-libglade2 \
		linux-c6-devtools>0:devel/linux-c6-devtools \
		linux-c6-dbus-libs>0:devel/linux-c6-dbus-libs \
		linux-c6-qt47>0:devel/linux-c6-qt47 \
		linux-c6-dbus-glib>0:devel/linux-c6-dbus-glib \
		linux-c6-ncurses-base>0:devel/linux-c6-ncurses-base \
		linux-c6-xorg-libs>0:x11/linux-c6-xorg-libs \
		linux-c6-fontconfig>0:x11-fonts/linux-c6-fontconfig \
		linux-c6-cups-libs>0:print/linux-c6-cups-libs \
		linux-c6-flac>0:audio/linux-c6-flac \
		linux-c6-alsa-utils>0:audio/linux-c6-alsa-utils \
		linux-c6-alsa-lib>0:audio/linux-c6-alsa-lib \
		linux-c6-libaudiofile>0:audio/linux-c6-libaudiofile \
		linux-c6-esound>0:audio/linux-c6-esound \
		linux-c6-alsa-plugins-oss>0:audio/linux-c6-alsa-plugins-oss \
		linux-c6-sdl_mixer>0:audio/linux-c6-sdl_mixer \
		linux-c6-alsa-plugins-pulseaudio>0:audio/linux-c6-alsa-plugins-pulseaudio \
		linux-c6-libsndfile>0:audio/linux-c6-libsndfile \
		linux-c6-libogg>0:audio/linux-c6-libogg \
		linux-c6-arts>0:audio/linux-c6-arts \
		linux-c6-pulseaudio-utils>0:audio/linux-c6-pulseaudio-utils \
		linux-c6-pulseaudio-libs>0:audio/linux-c6-pulseaudio-libs \
		linux-c6-mikmod>0:audio/linux-c6-mikmod \
		linux-c6-openal-soft>0:audio/linux-c6-openal-soft \
		linux-c6-libvorbis>0:audio/linux-c6-libvorbis \
		linux-c6-nas-libs>0:audio/linux-c6-nas-libs \
		linux-c6-libtheora>0:multimedia/linux-c6-libtheora \
		linux-c6-libv4l>0:multimedia/linux-c6-libv4l \
		linux-c6-qt47-webkit>0:www/linux-c6-qt47-webkit \
		linux-c6-flashplugin>0:www/linux-c6-flashplugin24 \
		linux-c6-cyrus-sasl2>0:security/linux-c6-cyrus-sasl2 \
		linux-c6-libssh2>0:security/linux-c6-libssh2 \
		linux-c6-openssl-compat>0:security/linux-c6-openssl-compat \
		linux-c6-openssl>0:security/linux-c6-openssl \
		linux-c6-gnutls>0:security/linux-c6-gnutls \
		linux-c6-libgcrypt>0:security/linux-c6-libgcrypt \
		linux-c6-nss>0:security/linux-c6-nss \
		linux-c6-libtasn1>0:security/linux-c6-libtasn1 \
		linux-c6-libgpg-error>0:security/linux-c6-libgpg-error \
		linux-c6-curl>0:ftp/linux-c6-curl \
		linux-c6-tcp_wrappers-libs>0:net/linux-c6-tcp_wrappers-libs \
		linux-c6-openldap>0:net/linux-c6-openldap \
		linux-c6-avahi-libs>0:net/linux-c6-avahi-libs \
		linux-c6-expat>0:textproc/linux-c6-expat \
		linux-c6-aspell>0:textproc/linux-c6-aspell \
		linux-c6-libxml2>0:textproc/linux-c6-libxml2 \
		linux-c6-dri>0:graphics/linux-c6-dri \
		linux-c6-sdl_image>0:graphics/linux-c6-sdl_image \
		linux-c6-sdl_ttf>0:graphics/linux-c6-sdl_ttf \
		linux-c6-png>0:graphics/linux-c6-png \
		linux-c6-tiff>0:graphics/linux-c6-tiff \
		linux-c6-jpeg>0:graphics/linux-c6-jpeg \
		linux-c6-glx-utils>0:graphics/linux-c6-glx-utils \
		linux-c6-gdk-pixbuf2>0:graphics/linux-c6-gdk-pixbuf2 \
		linux-c6-cairo>0:graphics/linux-c6-cairo

USES=		linux:c6 metaport

.include <bsd.port.mk>
