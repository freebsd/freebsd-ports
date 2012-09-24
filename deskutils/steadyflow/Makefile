# $FreeBSD$
#

PORTNAME=	steadyflow
PORTVERSION=	0.1.7
PORTREVISION=	3
CATEGORIES=	deskutils
MASTER_SITES=	http://launchpad.net/${PORTNAME}/trunk/${PORTVERSION}/+download/ \
		https://launchpadlibrarian.net/72208624/

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Simple download manager

LICENSE=	GPLv3

LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		gee:${PORTSDIR}/devel/libgee \
		notify:${PORTSDIR}/devel/libnotify \
		unique-1:${PORTSDIR}/x11-toolkits/unique
BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala

USE_CMAKE=	yes
GLIB_SCHEMAS=	net.launchpad.steadyflow.gschema.xml
USE_GNOME=	desktopfileutils glib20 gtk20
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
USE_PKGCONFIG=	build
CMAKE_ARGS=	-DCOMPILE_GSETTINGS_ON_INSTALL:BOOL=ON \
		-DWANT_AYATANA:BOOL=OFF

MAN1=	steadyflow.1

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
