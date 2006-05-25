# New ports collection makefile for:	notification-daemon
# Date created:				2005-08-06
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=	notification-daemon
PORTVERSION=	0.3.4
PORTREVISION=	2
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://www.galago-project.org/files/releases/source/notification-daemon/

MAINTAINER=	andreas@syndrom23.de
COMMENT=	Send small notifications to your desktop

LIB_DEPENDS=	dbus-1.2:${PORTSDIR}/devel/dbus \
		sexy:${PORTSDIR}/x11-toolkits/libsexy \
		popt.0:${PORTSDIR}/devel/popt

USE_GNOME=	gnomehack gnometarget intlhack gconf2 libwnck
USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
GCONF_SCHEMAS=	notification-daemon.schemas
CONFIGURE_ARGS=	--with-dbus-services=${PREFIX}/share/dbus-1/services
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
