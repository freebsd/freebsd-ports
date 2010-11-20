# New ports collection makefile for:	notification-daemon
# Date created:				2005-08-06
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#   $MCom: ports/deskutils/notification-daemon/Makefile,v 1.6 2010/06/28 22:16:41 kwm Exp $
#

PORTNAME=	notification-daemon
PORTVERSION=	0.5.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Send small notifications to your desktop

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		canberra-gtk.0:${PORTSDIR}/audio/libcanberra \
		notify.1:${PORTSDIR}/devel/libnotify

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget intlhack gconf2 libwnck
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_XORG=	x11 xt sm ice xext
USE_GSTREAMER=	good
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-dbus-services=${PREFIX}/share/dbus-1/services
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	notification-daemon.schemas

CONFLICTS=	xfce4-notification-daemon-[0-9]* xfce4-notifyd-[0-9]*

.include <bsd.port.mk>
