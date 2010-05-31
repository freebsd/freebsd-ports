# New ports collection makefile for:	cairo-dock
# Date created:		2010-03-18
# Whom:			Ivan Klymenko <fidaj@ukr.net>
#
# $FreeBSD$
#

PORTNAME=	cairo-dock
DISTVERSION=	2.1.0
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	BERLIOS

MAINTAINER=	fidaj@ukr.net
COMMENT=	Cairo-Dock is a light and eye-candy dock

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		gtkglext-x11-1.0.0:${PORTSDIR}/x11-toolkits/gtkglext

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig glib20 gtk20 librsvg2 libxml2
USE_LDCONFIG=	yes
USE_XORG=	xrender

.include <bsd.port.mk>
