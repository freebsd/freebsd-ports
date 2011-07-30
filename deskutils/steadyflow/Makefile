# New ports collection makefile for: steadyflow
# Date created:		2011-01-28
# Whom:		Olivier Duchateau <duchateau.olivier@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	steadyflow
PORTVERSION=	0.1.7
CATEGORIES=	deskutils
MASTER_SITES=	http://launchpad.net/${PORTNAME}/trunk/${PORTVERSION}/+download/ \
		https://launchpadlibrarian.net/72208624/

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	Simple download manager

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		gee.2:${PORTSDIR}/devel/libgee \
		notify.1:${PORTSDIR}/devel/libnotify \
		unique-1.0.2:${PORTSDIR}/x11-toolkits/unique
BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala

LICENSE=	GPLv3

USE_CMAKE=	yes
GLIB_SCHEMAS=	net.launchpad.steadyflow.gschema.xml
USE_GNOME=	desktopfileutils glib20 gtk20 pkgconfig
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes

CMAKE_ARGS=	-DCOMPILE_GSETTINGS_ON_INSTALL:BOOL=OFF \
		-DWANT_AYATANA:BOOL=OFF

MAN1=	steadyflow.1

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
