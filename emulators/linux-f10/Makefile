# Created by: Johannes Jost Meixner <xmj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	linux-f10
PORTVERSION=	0.2
CATEGORIES=	emulators linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Meta-port for all things Fedora ${LINUX_DIST_VER}

USES=	metaport

# base
USE_LINUX=	f10

# non-base

RUN_DEPENDS+=	linux-f10-libasyncns>0:${PORTSDIR}/dns/linux-f10-libasyncns \
		linux-f10-gtk2>0:${PORTSDIR}/x11-toolkits/linux-f10-gtk2 \
		linux-f10-tk85>0:${PORTSDIR}/x11-toolkits/linux-f10-tk85 \
		linux-f10-qt45>0:${PORTSDIR}/x11-toolkits/linux-f10-qt45 \
		linux-f10-openmotif>0:${PORTSDIR}/x11-toolkits/linux-f10-openmotif \
		linux-f10-pango>0:${PORTSDIR}/x11-toolkits/linux-f10-pango \
		linux-f10-blt>0:${PORTSDIR}/x11-toolkits/linux-f10-blt \
		linux-f10-atk>0:${PORTSDIR}/accessibility/linux-f10-atk \
		linux-f10-sqlite3>0:${PORTSDIR}/databases/linux-f10-sqlite3 \
		linux-f10-procps>0:${PORTSDIR}/sysutils/linux-f10-procps \
		linux-f10-tcl85>0:${PORTSDIR}/lang/linux-f10-tcl85 \
		linux-f10-libg2c>0:${PORTSDIR}/lang/linux-f10-libg2c \
		linux-f10-sdl>0:${PORTSDIR}/devel/linux-f10-sdl12 \
		linux-f10-libglade2>0:${PORTSDIR}/devel/linux-f10-libglade2 \
		linux-f10-allegro>0:${PORTSDIR}/devel/linux-f10-allegro \
		linux-f10-devtools>0:${PORTSDIR}/devel/linux-f10-devtools \
		linux-f10-dbus-libs>0:${PORTSDIR}/devel/linux-f10-dbus-libs \
		linux-f10-nspr>0:${PORTSDIR}/devel/linux-f10-nspr \
		linux-f10-dbus-glib>0:${PORTSDIR}/devel/linux-f10-dbus-glib \
		linux-f10-libsigc++20>0:${PORTSDIR}/devel/linux-f10-libsigc++20 \
		linux-f10-ncurses-base>0:${PORTSDIR}/devel/linux-f10-ncurses-base \
		linux_base-f10>0:${PORTSDIR}/emulators/linux_base-f10 \
		linux-f10-xorg-libs>0:${PORTSDIR}/x11/linux-f10-xorg-libs \
		linux-f10-fontconfig>0:${PORTSDIR}/x11-fonts/linux-f10-fontconfig \
		linux-f10-cups-libs>0:${PORTSDIR}/print/linux-f10-cups-libs \
		linux-f10-nas-libs>0:${PORTSDIR}/audio/linux-f10-nas-libs \
		linux-f10-openal-soft>0:${PORTSDIR}/audio/linux-f10-openal-soft \
		linux-f10-esound>0:${PORTSDIR}/audio/linux-f10-esound \
		linux-f10-sdl_mixer>0:${PORTSDIR}/audio/linux-f10-sdl_mixer \
		linux-f10-pulseaudio-libs>0:${PORTSDIR}/audio/linux-f10-pulseaudio-libs \
		linux-f10-libogg>0:${PORTSDIR}/audio/linux-f10-libogg \
		linux-f10-libvorbis>0:${PORTSDIR}/audio/linux-f10-libvorbis \
		linux-f10-freealut>0:${PORTSDIR}/audio/linux-f10-freealut \
		linux-f10-arts>0:${PORTSDIR}/audio/linux-f10-arts \
		linux-f10-mikmod>0:${PORTSDIR}/audio/linux-f10-mikmod \
		linux-f10-openal>0:${PORTSDIR}/audio/linux-f10-openal \
		linux-f10-alsa-plugins-oss>0:${PORTSDIR}/audio/linux-f10-alsa-plugins-oss \
		linux-f10-libaudiofile>0:${PORTSDIR}/audio/linux-f10-libaudiofile \
		linux-f10-alsa-lib>0:${PORTSDIR}/audio/linux-f10-alsa-lib \
		linux-f10-libv4l>0:${PORTSDIR}/multimedia/linux-f10-libv4l \
		linux-f10-libtheora>0:${PORTSDIR}/multimedia/linux-f10-libtheora \
		linux-f10-flashplugin>0:${PORTSDIR}/www/linux-f10-flashplugin11 \
		linux-f10-nss>0:${PORTSDIR}/security/linux-f10-nss \
		linux-f10-libtasn1>0:${PORTSDIR}/security/linux-f10-libtasn1 \
		linux-f10-libgcrypt>0:${PORTSDIR}/security/linux-f10-libgcrypt \
		linux-f10-libgpg-error>0:${PORTSDIR}/security/linux-f10-libgpg-error \
		linux-f10-cyrus-sasl2>0:${PORTSDIR}/security/linux-f10-cyrus-sasl2 \
		linux-f10-gnutls>0:${PORTSDIR}/security/linux-f10-gnutls \
		linux-f10-openssl>0:${PORTSDIR}/security/linux-f10-openssl \
		linux-f10-libssh2>0:${PORTSDIR}/security/linux-f10-libssh2 \
		linux-f10-hicolor-icon-theme>0:${PORTSDIR}/x11-themes/linux-f10-hicolor-icon-theme \
		linux-f10-qtcurve-gtk2>0:${PORTSDIR}/x11-themes/linux-f10-qtcurve-gtk2 \
		linux-f10-curl>0:${PORTSDIR}/ftp/linux-f10-curl \
		linux-f10-nss_ldap>0:${PORTSDIR}/net/linux-f10-nss_ldap \
		linux-f10-openldap>0:${PORTSDIR}/net/linux-f10-openldap \
		linux-f10-expat>0:${PORTSDIR}/textproc/linux-f10-expat \
		linux-f10-libxml2>0:${PORTSDIR}/textproc/linux-f10-libxml2 \
		linux-f10-scim-libs>0:${PORTSDIR}/textproc/linux-f10-scim-libs \
		linux-f10-aspell>0:${PORTSDIR}/textproc/linux-f10-aspell \
		linux-f10-scim-gtk>0:${PORTSDIR}/textproc/linux-f10-scim-gtk \
		linux-f10-ucl>0:${PORTSDIR}/archivers/linux-f10-ucl \
		linux-f10-upx>0:${PORTSDIR}/archivers/linux-f10-upx \
		linux-f10-gdk-pixbuf>0:${PORTSDIR}/graphics/linux-f10-gdk-pixbuf \
		linux-f10-png>0:${PORTSDIR}/graphics/linux-f10-png \
		linux-f10-sdl_ttf>0:${PORTSDIR}/graphics/linux-f10-sdl_ttf \
		linux-f10-jpeg>0:${PORTSDIR}/graphics/linux-f10-jpeg \
		linux-f10-tiff>0:${PORTSDIR}/graphics/linux-f10-tiff \
		linux-f10-imlib>0:${PORTSDIR}/graphics/linux-f10-imlib \
		linux-f10-ungif>0:${PORTSDIR}/graphics/linux-f10-ungif \
		linux-f10-libmng>0:${PORTSDIR}/graphics/linux-f10-libmng \
		linux-f10-sdl_image>0:${PORTSDIR}/graphics/linux-f10-sdl_image \
		linux-f10-glew>0:${PORTSDIR}/graphics/linux-f10-glew \
		linux-f10-cairo>0:${PORTSDIR}/graphics/linux-f10-cairo
# don't pull in graphics/linux-f10-libGLU -- conflicts with graphics/linux-f10-dri

OPTIONS_DEFINE=	NVIDIA_GL

NVIDIA_GL_RUN_DEPENDS=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver
NVIDIA_GL_RUN_DEPENDS_OFF=	linux-f10-dri>0:${PORTSDIR}/graphics/linux-f10-dri

.include <bsd.port.mk>
