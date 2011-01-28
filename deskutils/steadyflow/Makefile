# New ports collection makefile for: steadyflow
# Date created:		2011-01-28
# Whom:		Olivier Duchateau <duchateau.olivier@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	steadyflow
PORTVERSION=	0.1.5
CATEGORIES=	deskutils
MASTER_SITES=	http://launchpad.net/${PORTNAME}/trunk/${PORTVERSION}/+download/ \
		https://launchpadlibrarian.net/56276785/

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	Simple download manager

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		gee.2:${PORTSDIR}/devel/libgee \
		notify.1:${PORTSDIR}/devel/libnotify \
		unique-1.0.2:${PORTSDIR}/x11-toolkits/unique
BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala

LICENSE=	GPLv3

USE_CMAKE=	yes
USE_GNOME=	desktopfileutils glib20 gtk20 pkgconfig
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes

CMAKE_ARGS=	-DWANT_GSETTINGS:BOOL=OFF \
		-DWANT_AYATANA:BOOL=OFF

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
