# Created by: Johannes Jost Meixner <xmj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	linux-${USE_LINUX}
PORTVERSION=	6.8
CATEGORIES=	emulators linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Meta-port for all things CentOS ${LINUX_DIST_VER}

USES=	metaport

# base
USE_LINUX=	c6

# non-base

RUN_DEPENDS+=	linux-${USE_LINUX}-libasyncns>0:dns/linux-c6-libasyncns \
		linux-${USE_LINUX}-tk85>0:x11-toolkits/linux-c6-tk85 \
		linux-${USE_LINUX}-gtk2>0:x11-toolkits/linux-c6-gtk2 \
		linux-${USE_LINUX}-hicolor-icon-theme>0:x11-themes/linux-c6-hicolor-icon-theme \
		linux-${USE_LINUX}-qt47-x11>0:x11-toolkits/linux-c6-qt47-x11 \
		linux-${USE_LINUX}-pango>0:x11-toolkits/linux-c6-pango \
		linux-${USE_LINUX}-openmotif>0:x11-toolkits/linux-c6-openmotif \
		linux-${USE_LINUX}-atk>0:accessibility/linux-c6-atk \
		linux-${USE_LINUX}-sqlite>0:databases/linux-c6-sqlite3 \
		linux-${USE_LINUX}-tcl85>0:lang/linux-c6-tcl85 \
		linux-${USE_LINUX}-nspr>0:devel/linux-c6-nspr \
		linux-${USE_LINUX}-libsigc++20>0:devel/linux-c6-libsigc++20 \
		linux-${USE_LINUX}-sdl>0:devel/linux-c6-sdl12 \
		linux-${USE_LINUX}-libpciaccess>0:devel/linux-c6-libpciaccess \
		linux-${USE_LINUX}-libglade2>0:devel/linux-c6-libglade2 \
		linux-${USE_LINUX}-devtools>0:devel/linux-c6-devtools \
		linux-${USE_LINUX}-dbus-libs>0:devel/linux-c6-dbus-libs \
		linux-${USE_LINUX}-qt47>0:devel/linux-c6-qt47 \
		linux-${USE_LINUX}-dbus-glib>0:devel/linux-c6-dbus-glib \
		linux-${USE_LINUX}-ncurses-base>0:devel/linux-c6-ncurses-base \
		linux-${USE_LINUX}-xorg-libs>0:x11/linux-c6-xorg-libs \
		linux-${USE_LINUX}-fontconfig>0:x11-fonts/linux-c6-fontconfig \
		linux-${USE_LINUX}-cups-libs>0:print/linux-c6-cups-libs \
		linux-${USE_LINUX}-flac>0:audio/linux-c6-flac \
		linux-${USE_LINUX}-alsa-utils>0:audio/linux-c6-alsa-utils \
		linux-${USE_LINUX}-alsa-lib>0:audio/linux-c6-alsa-lib \
		linux-${USE_LINUX}-libaudiofile>0:audio/linux-c6-libaudiofile \
		linux-${USE_LINUX}-esound>0:audio/linux-c6-esound \
		linux-${USE_LINUX}-alsa-plugins-oss>0:audio/linux-c6-alsa-plugins-oss \
		linux-${USE_LINUX}-sdl_mixer>0:audio/linux-c6-sdl_mixer \
		linux-${USE_LINUX}-alsa-plugins-pulseaudio>0:audio/linux-c6-alsa-plugins-pulseaudio \
		linux-${USE_LINUX}-libsndfile>0:audio/linux-c6-libsndfile \
		linux-${USE_LINUX}-libogg>0:audio/linux-c6-libogg \
		linux-${USE_LINUX}-arts>0:audio/linux-c6-arts \
		linux-${USE_LINUX}-pulseaudio-utils>0:audio/linux-c6-pulseaudio-utils \
		linux-${USE_LINUX}-pulseaudio-libs>0:audio/linux-c6-pulseaudio-libs \
		linux-${USE_LINUX}-mikmod>0:audio/linux-c6-mikmod \
		linux-${USE_LINUX}-openal-soft>0:audio/linux-c6-openal-soft \
		linux-${USE_LINUX}-libvorbis>0:audio/linux-c6-libvorbis \
		linux-${USE_LINUX}-nas-libs>0:audio/linux-c6-nas-libs \
		linux-${USE_LINUX}-libtheora>0:multimedia/linux-c6-libtheora \
		linux-${USE_LINUX}-libv4l>0:multimedia/linux-c6-libv4l \
		linux-${USE_LINUX}-qt47-webkit>0:www/linux-c6-qt47-webkit \
		linux-${USE_LINUX}-flashplugin>0:www/linux-c6-flashplugin11 \
		linux-${USE_LINUX}-cyrus-sasl2>0:security/linux-c6-cyrus-sasl2 \
		linux-${USE_LINUX}-libssh2>0:security/linux-c6-libssh2 \
		linux-${USE_LINUX}-openssl-compat>0:security/linux-c6-openssl-compat \
		linux-${USE_LINUX}-openssl>0:security/linux-c6-openssl \
		linux-${USE_LINUX}-gnutls>0:security/linux-c6-gnutls \
		linux-${USE_LINUX}-libgcrypt>0:security/linux-c6-libgcrypt \
		linux-${USE_LINUX}-nss>0:security/linux-c6-nss \
		linux-${USE_LINUX}-libtasn1>0:security/linux-c6-libtasn1 \
		linux-${USE_LINUX}-libgpg-error>0:security/linux-c6-libgpg-error \
		linux-${USE_LINUX}-curl>0:ftp/linux-c6-curl \
		linux-${USE_LINUX}-tcp_wrappers-libs>0:net/linux-c6-tcp_wrappers-libs \
		linux-${USE_LINUX}-openldap>0:net/linux-c6-openldap \
		linux-${USE_LINUX}-avahi-libs>0:net/linux-c6-avahi-libs \
		linux-${USE_LINUX}-expat>0:textproc/linux-c6-expat \
		linux-${USE_LINUX}-aspell>0:textproc/linux-c6-aspell \
		linux-${USE_LINUX}-libxml2>0:textproc/linux-c6-libxml2 \
		linux-${USE_LINUX}-sdl_image>0:graphics/linux-c6-sdl_image \
		linux-${USE_LINUX}-sdl_ttf>0:graphics/linux-c6-sdl_ttf \
		linux-${USE_LINUX}-png>0:graphics/linux-c6-png \
		linux-${USE_LINUX}-tiff>0:graphics/linux-c6-tiff \
		linux-${USE_LINUX}-jpeg>0:graphics/linux-c6-jpeg \
		linux-${USE_LINUX}-glx-utils>0:graphics/linux-c6-glx-utils \
		linux-${USE_LINUX}-gdk-pixbuf2>0:graphics/linux-c6-gdk-pixbuf2 \
		linux-${USE_LINUX}-cairo>0:graphics/linux-c6-cairo

OPTIONS_DEFINE=	NVIDIA_GL

NVIDIA_GL_RUN_DEPENDS=	${LINUXBASE}/usr/lib/libGL.so.1:x11/nvidia-driver \
			linux-${USE_LINUX}-libGLU>0:graphics/linux-c6-libGLU
NVIDIA_GL_RUN_DEPENDS_OFF=	linux-${USE_LINUX}-dri>0:graphics/linux-c6-dri

.include <bsd.port.mk>
