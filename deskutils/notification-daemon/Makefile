# Created by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$

PORTNAME=	notification-daemon
PORTVERSION=	3.20.0
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Send small notifications to your desktop

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libdbus-1.so:devel/dbus

USES=		gettext gmake gnome localbase pathfix pkgconfig tar:xz xorg
USE_GNOME=	cairo gnomeprefix gtk30
INSTALLS_ICONS=	yes
USE_XORG=	x11
GNU_CONFIGURE=	yes

PORTSCOUT=	limitw:1,even

SUB_FILES=	org.freedesktop.Notifications.service

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/dbus-1/services
	${INSTALL_DATA} ${WRKDIR}/org.freedesktop.Notifications.service \
		${STAGEDIR}${PREFIX}/share/dbus-1/services

.include <bsd.port.mk>
