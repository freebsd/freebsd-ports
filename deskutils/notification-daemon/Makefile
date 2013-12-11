# Created by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$
#   $MCom: ports/deskutils/notification-daemon/Makefile,v 1.11 2011/06/11 19:51:12 mezz Exp $

PORTNAME=	notification-daemon
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Send small notifications to your desktop

LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus \
		libcanberra-gtk3.so:${PORTSDIR}/audio/libcanberra-gtk3

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack gtk30
USES=		gettext gmake pkgconfig
USE_XORG=	x11
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-dbus-services=${PREFIX}/share/dbus-1/services
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFLICTS=	xfce4-notification-daemon-[0-9]* xfce4-notifyd-[0-9]*

NO_STAGE=	yes
.include <bsd.port.mk>
