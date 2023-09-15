#
# !!!NOTE!!! Update of x11-toolkits/gtk30 (specially >= 3.20.x) must be
# accompanied by PORTREVISION bumps of this port.
# Support of GTK is checked at compile time and themes directories too.

PORTNAME=	xfce4-notifyd
PORTVERSION=	0.8.2
PORTREVISION=	2
CATEGORIES=	deskutils xfce
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Visually-appealing notification daemon for Xfce
WWW=		https://gitlab.xfce.org/apps/xfce4-notifyd

LICENSE=	GPLv3

BUILD_DEPENDS=	xdt-csource:devel/xfce4-dev-tools
LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz \
		libnotify.so:devel/libnotify

USES=		compiler:c11 gettext-tools gmake gnome libtool pkgconfig \
		sqlite tar:bzip2 xfce xorg
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 intltool
USE_XFCE=	libutil panel
USE_XORG=	ice sm x11

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	CANBERRA NLS
OPTIONS_SUB=	yes

CANBERRA_DESC=	Sound (audio) support via canberra

CANBERRA_LIB_DEPENDS=		libcanberra.so:audio/libcanberra \
				libcanberra-gtk3.so:audio/libcanberra-gtk3
CANBERRA_CONFIGURE_ENABLE=	canberra

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
