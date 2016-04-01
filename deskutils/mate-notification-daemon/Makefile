# Created by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$

PORTNAME=	mate-notification-daemon
PORTVERSION=	1.12.1
CATEGORIES=	deskutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Send small notifications to your desktop

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libcanberra-gtk.so:audio/libcanberra \
		libnotify.so:devel/libnotify

PORTSCOUT=	limitw:1,even

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_XORG=	x11
USE_GNOME=	glib20 gtk20 librsvg2 intlhack libwnck
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-dbus-services=${PREFIX}/share/dbus-1/services \
		--disable-static \
		--with-gtk=2.0
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.NotificationDaemon.gschema.xml

.include <bsd.port.mk>
