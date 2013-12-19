# Created by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$
#   $MCom: ports/trunk/deskutils/notification-daemon/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	notification-daemon
PORTVERSION=	0.7.6
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Send small notifications to your desktop

LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus \
		libcanberra-gtk3.so:${PORTSDIR}/audio/libcanberra-gtk3

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus \
		libcanberra-gtk3.so:${PORTSDIR}/audio/libcanberra-gtk3

NO_STAGE=	yes
USE_XZ=		yes
USE_GNOME=	gnomeprefix intlhack gtk30
USES=		gettext gmake pathfix pkgconfig
USE_XORG=	x11
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-dbus-services=${PREFIX}/share/dbus-1/services
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFLICTS=	xfce4-notification-daemon-[0-9]* xfce4-notifyd-[0-9]*

.include <bsd.port.mk>
