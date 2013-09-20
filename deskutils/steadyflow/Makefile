# $FreeBSD$

PORTNAME=	steadyflow
PORTVERSION=	0.2.0
CATEGORIES=	deskutils
MASTER_SITES=	https://launchpadlibrarian.net/109019071/ \
	https://launchpad.net/${PORTNAME}/trunk/${PORTVERSION}/+download/ \
	LOCAL/olivierd

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Simple download manager

LICENSE=	GPLv3

LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		gee:${PORTSDIR}/devel/libgee06 \
		notify:${PORTSDIR}/devel/libnotify \
		unique-1:${PORTSDIR}/x11-toolkits/unique
BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala

USE_XZ=	yes
USES=		cmake pkgconfig gettext
GLIB_SCHEMAS=	net.launchpad.steadyflow.gschema.xml
USE_GNOME=	desktopfileutils glib20 gtk30
INSTALLS_ICONS=	yes
CMAKE_ARGS=	-DCOMPILE_GSETTINGS_ON_INSTALL:BOOL=ON \
		-DWANT_AYATANA:BOOL=OFF

MAN1=	steadyflow.1

NO_STAGE=	yes
post-install:
	@-update-desktop-database

.include <bsd.port.mk>
