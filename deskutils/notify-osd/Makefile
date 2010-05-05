# New ports collection makefile for:	notify-osd
# Date created:				05 May 2010
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	notify-osd
PORTVERSION=	0.9.29
CATEGORIES=	deskutils
MASTER_SITES=	http://launchpadlibrarian.net/43419242/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	On-screen-display notification agent using libnotify

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		notify.1:${PORTSDIR}/devel/libnotify
RUN_DEPENDS=	dbus-daemon:${PORTSDIR}/devel/dbus

GNU_CONFIGURE=	yes
USE_GNOME=	libwnck gconf2
USE_GMAKE=	yes
USE_GCC=	4.4+

.include <bsd.port.mk>
