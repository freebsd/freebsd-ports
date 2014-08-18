# Created by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$
#   $MCom: ports/trunk/deskutils/notification-daemon/Makefile 19804 2014-08-13 14:55:11Z kwm $

PORTNAME=	notification-daemon
PORTVERSION=	0.7.6
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Send small notifications to your desktop

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus \
		libcanberra-gtk3.so:${PORTSDIR}/audio/libcanberra-gtk3

CONFLICTS=	xfce4-notification-daemon-[0-9]* xfce4-notifyd-[0-9]*

USE_GNOME=	gnomeprefix intlhack gtk30
USES=		gettext gmake pathfix pkgconfig tar:xz
USE_XORG=	x11
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-dbus-services=${PREFIX}/share/dbus-1/services
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
