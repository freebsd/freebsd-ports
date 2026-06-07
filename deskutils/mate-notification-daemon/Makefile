PORTNAME=	mate-notification-daemon
DISTVERSION=	1.28.3
PORTREVISION=	4
CATEGORIES=	deskutils mate
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/v${DISTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Send small notifications to your desktop
WWW=		https://mate-desktop.org/

LICENSE=	GPLv2+ GPLv3+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING

LIB_DEPENDS=	libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libcanberra.so:audio/libcanberra \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libmate-desktop-2.so:x11/mate-desktop \
		libmate-panel-applet-4.so:x11/mate-panel \
		libnotify.so:devel/libnotify

USES=		gettext gmake gnome libtool localbase pkgconfig tar:xz xorg
USE_GITHUB=	nodefault
GH_ACCOUNT=	mate-desktop
USE_XORG=	x11
USE_GNOME=	cairo glib20 gtk30 intlhack librsvg2 libwnck3
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--disable-static \
		--with-dbus-services=${PREFIX}/share/dbus-1/services
INSTALL_TARGET=	install-strip

PORTSCOUT=	site:https://github.com/mate-desktop/mate-notification-daemon/releases/ limitw:1,even

GLIB_SCHEMAS=	org.mate.NotificationDaemon.gschema.xml

.include <bsd.port.mk>
