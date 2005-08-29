# New ports collection makefile for:	notification-daemon
# Date created:				2005-08-06
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=	notification-daemon
PORTVERSION=	0.2.1
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://www.galago.info/files/releases/source/notification-daemon/

MAINTAINER=	andreas@syndrom23.de
COMMENT=	Send small notifications to your desktop

LIB_DEPENDS=	dbus-1.1:${PORTSDIR}/devel/dbus \
		notify.0:${PORTSDIR}/devel/libnotify

USE_GNOME=	gnomehack gnomeprefix gnometarget intlhack gtk20
USE_LIBTOOL_VER=15
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-dbus-services=${PREFIX}/share/dbus-1/services

.include <bsd.port.mk>
