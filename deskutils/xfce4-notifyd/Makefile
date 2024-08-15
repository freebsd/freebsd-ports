#
# !!!NOTE!!! Update of x11-toolkits/gtk30 (specially >= 3.20.x) must be
# accompanied by PORTREVISION bumps of this port.
# Support of GTK is checked at compile time and themes directories too.

PORTNAME=	xfce4-notifyd
PORTVERSION=	0.9.6
CATEGORIES=	deskutils xfce
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Visually-appealing notification daemon for Xfce
WWW=		https://gitlab.xfce.org/apps/xfce4-notifyd

LICENSE=	GPLv3

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz \
		libnotify.so:devel/libnotify

USES=		compiler:c11 gettext-tools gmake gnome libtool pkgconfig \
		sqlite tar:bzip2 xfce xorg
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 intltool
USE_XFCE=	libmenu panel xfconf
USE_XORG=	ice sm x11

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--disable-systemd
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS SOUND
OPTIONS_SUB=	yes

SOUND_DESC=	Sound (audio) support via canberra

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

SOUND_LIB_DEPENDS=	libcanberra-gtk3.so:audio/libcanberra-gtk3 \
			libcanberra.so:audio/libcanberra
SOUND_CONFIGURE_ENABLE=	sound

.include <bsd.port.mk>
