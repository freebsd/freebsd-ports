# Created by: Johannes Jost Meixner <xmj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	linux-f10
PORTVERSION=	0.1
CATEGORIES=	emulators linux
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Meta-port for all things Fedora ${LINUX_DIST_VER}

NO_BUILD=	yes
NO_MTREE=	yes
NO_INSTALL=	yes

# base
USE_LINUX=	f10

# non-base

RUN_DEPENDS+=	dns/linux-f10-libasyncns>0:${PORTSDIR}/dns/linux-f10-libasyncns \
		x11-toolkits/linux-f10-gtk2>0:${PORTSDIR}/x11-toolkits/linux-f10-gtk2 \
		x11-toolkits/linux-f10-tk85>0:${PORTSDIR}/x11-toolkits/linux-f10-tk85 \
		x11-toolkits/linux-f10-qt45>0:${PORTSDIR}/x11-toolkits/linux-f10-qt45 \
		x11-toolkits/linux-f10-openmotif>0:${PORTSDIR}/x11-toolkits/linux-f10-openmotif \
		x11-toolkits/linux-f10-pango>0:${PORTSDIR}/x11-toolkits/linux-f10-pango \
		x11-toolkits/linux-f10-blt>0:${PORTSDIR}/x11-toolkits/linux-f10-blt \
		accessibility/linux-f10-atk>0:${PORTSDIR}/accessibility/linux-f10-atk \
		databases/linux-f10-sqlite3>0:${PORTSDIR}/databases/linux-f10-sqlite3 \
		sysutils/linux-f10-procps>0:${PORTSDIR}/sysutils/linux-f10-procps \
		lang/linux-f10-tcl85>0:${PORTSDIR}/lang/linux-f10-tcl85 \
		lang/linux-f10-libg2c>0:${PORTSDIR}/lang/linux-f10-libg2c \
		devel/linux-f10-sdl12>0:${PORTSDIR}/devel/linux-f10-sdl12 \
		devel/linux-f10-libglade2>0:${PORTSDIR}/devel/linux-f10-libglade2 \
		devel/linux-f10-allegro>0:${PORTSDIR}/devel/linux-f10-allegro \
		devel/linux-f10-devtools>0:${PORTSDIR}/devel/linux-f10-devtools \
		devel/linux-f10-dbus-libs>0:${PORTSDIR}/devel/linux-f10-dbus-libs \
		devel/linux-f10-nspr>0:${PORTSDIR}/devel/linux-f10-nspr \
		devel/linux-f10-dbus-glib>0:${PORTSDIR}/devel/linux-f10-dbus-glib \
		devel/linux-f10-libsigc++20>0:${PORTSDIR}/devel/linux-f10-libsigc++20 \
		devel/linux-f10-ncurses-base>0:${PORTSDIR}/devel/linux-f10-ncurses-base \
		emulators/linux_base-f10>0:${PORTSDIR}/emulators/linux_base-f10 \
		x11/linux-f10-xorg-libs>0:${PORTSDIR}/x11/linux-f10-xorg-libs \
		x11-fonts/linux-f10-fontconfig>0:${PORTSDIR}/x11-fonts/linux-f10-fontconfig \
		print/linux-f10-cups-libs>0:${PORTSDIR}/print/linux-f10-cups-libs \
		audio/linux-f10-nas-libs>0:${PORTSDIR}/audio/linux-f10-nas-libs \
		audio/linux-f10-openal-soft>0:${PORTSDIR}/audio/linux-f10-openal-soft \
		audio/linux-f10-esound>0:${PORTSDIR}/audio/linux-f10-esound \
		audio/linux-f10-sdl_mixer>0:${PORTSDIR}/audio/linux-f10-sdl_mixer \
		audio/linux-f10-pulseaudio-libs>0:${PORTSDIR}/audio/linux-f10-pulseaudio-libs \
		audio/linux-f10-libogg>0:${PORTSDIR}/audio/linux-f10-libogg \
		audio/linux-f10-libvorbis>0:${PORTSDIR}/audio/linux-f10-libvorbis \
		audio/linux-f10-freealut>0:${PORTSDIR}/audio/linux-f10-freealut \
		audio/linux-f10-arts>0:${PORTSDIR}/audio/linux-f10-arts \
		audio/linux-f10-mikmod>0:${PORTSDIR}/audio/linux-f10-mikmod \
		audio/linux-f10-openal>0:${PORTSDIR}/audio/linux-f10-openal \
		audio/linux-f10-alsa-plugins-oss>0:${PORTSDIR}/audio/linux-f10-alsa-plugins-oss \
		audio/linux-f10-libaudiofile>0:${PORTSDIR}/audio/linux-f10-libaudiofile \
		audio/linux-f10-alsa-lib>0:${PORTSDIR}/audio/linux-f10-alsa-lib \
		multimedia/linux-f10-libv4l>0:${PORTSDIR}/multimedia/linux-f10-libv4l \
		multimedia/linux-f10-libtheora>0:${PORTSDIR}/multimedia/linux-f10-libtheora \
		www/linux-f10-flashplugin11>0:${PORTSDIR}/www/linux-f10-flashplugin11 \
		security/linux-f10-nss>0:${PORTSDIR}/security/linux-f10-nss \
		security/linux-f10-libtasn1>0:${PORTSDIR}/security/linux-f10-libtasn1 \
		security/linux-f10-libgcrypt>0:${PORTSDIR}/security/linux-f10-libgcrypt \
		security/linux-f10-libgpg-error>0:${PORTSDIR}/security/linux-f10-libgpg-error \
		security/linux-f10-cyrus-sasl2>0:${PORTSDIR}/security/linux-f10-cyrus-sasl2 \
		security/linux-f10-gnutls>0:${PORTSDIR}/security/linux-f10-gnutls \
		security/linux-f10-openssl>0:${PORTSDIR}/security/linux-f10-openssl \
		security/linux-f10-libssh2>0:${PORTSDIR}/security/linux-f10-libssh2 \
		x11-themes/linux-f10-hicolor-icon-theme>0:${PORTSDIR}/x11-themes/linux-f10-hicolor-icon-theme \
		x11-themes/linux-f10-qtcurve-gtk2>0:${PORTSDIR}/x11-themes/linux-f10-qtcurve-gtk2 \
		ftp/linux-f10-curl>0:${PORTSDIR}/ftp/linux-f10-curl \
		net/linux-f10-nss_ldap>0:${PORTSDIR}/net/linux-f10-nss_ldap \
		net/linux-f10-openldap>0:${PORTSDIR}/net/linux-f10-openldap \
		textproc/linux-f10-expat>0:${PORTSDIR}/textproc/linux-f10-expat \
		textproc/linux-f10-libxml2>0:${PORTSDIR}/textproc/linux-f10-libxml2 \
		textproc/linux-f10-scim-libs>0:${PORTSDIR}/textproc/linux-f10-scim-libs \
		textproc/linux-f10-aspell>0:${PORTSDIR}/textproc/linux-f10-aspell \
		textproc/linux-f10-scim-gtk>0:${PORTSDIR}/textproc/linux-f10-scim-gtk \
		archivers/linux-f10-ucl>0:${PORTSDIR}/archivers/linux-f10-ucl \
		archivers/linux-f10-upx>0:${PORTSDIR}/archivers/linux-f10-upx \
		graphics/linux-f10-gdk-pixbuf>0:${PORTSDIR}/graphics/linux-f10-gdk-pixbuf \
		graphics/linux-f10-png>0:${PORTSDIR}/graphics/linux-f10-png \
		graphics/linux-f10-sdl_ttf>0:${PORTSDIR}/graphics/linux-f10-sdl_ttf \
		graphics/linux-f10-jpeg>0:${PORTSDIR}/graphics/linux-f10-jpeg \
		graphics/linux-f10-tiff>0:${PORTSDIR}/graphics/linux-f10-tiff \
		graphics/linux-f10-dri>0:${PORTSDIR}/graphics/linux-f10-dri \
		graphics/linux-f10-imlib>0:${PORTSDIR}/graphics/linux-f10-imlib \
		graphics/linux-f10-ungif>0:${PORTSDIR}/graphics/linux-f10-ungif \
		graphics/linux-f10-libmng>0:${PORTSDIR}/graphics/linux-f10-libmng \
		graphics/linux-f10-sdl_image>0:${PORTSDIR}/graphics/linux-f10-sdl_image \
		graphics/linux-f10-glew>0:${PORTSDIR}/graphics/linux-f10-glew \
		graphics/linux-f10-cairo>0:${PORTSDIR}/graphics/linux-f10-cairo
# don't pull in graphics/linux-f10-libGLU -- conflicts with graphics/linux-f10-dri

.include <bsd.port.mk>
