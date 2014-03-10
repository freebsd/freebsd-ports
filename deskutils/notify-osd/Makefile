# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	notify-osd
PORTVERSION=	0.9.29
PORTREVISION=	5
CATEGORIES=	deskutils
MASTER_SITES=	http://launchpadlibrarian.net/43419242/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	On-screen-display notification agent using libnotify

LICENSE=	GPLv3

CONFLICTS=	xfce4-notification-daemon-[0-9]*

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libnotify.so:${PORTSDIR}/devel/libnotify
RUN_DEPENDS=	dbus-daemon:${PORTSDIR}/devel/dbus

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
USE_GNOME=	libwnck gconf2
USE_GCC=	yes

.include <bsd.port.mk>
