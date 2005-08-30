# New ports collection makefile for:	libnotify
# Date created:				2005-08-06
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=	libnotify
PORTVERSION=	0.2.1
CATEGORIES=	devel gnome
MASTER_SITES=	http://www.galago.info/files/releases/source/libnotify/

MAINTAINER=	andreas@syndrom23.de
COMMENT=	A library for desktop notifications

LIB_DEPENDS=	dbus-1.1:${PORTSDIR}/devel/dbus \
		popt.0:${PORTSDIR}/devel/popt

USE_GNOME=	gnomehack gnomeprefix gnometarget intlhack glib20
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
