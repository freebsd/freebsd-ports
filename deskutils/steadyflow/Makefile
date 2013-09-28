# $FreeBSD$

PORTNAME=	steadyflow
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	https://launchpadlibrarian.net/109019071/ \
	https://launchpad.net/${PORTNAME}/trunk/${PORTVERSION}/+download/ \
	LOCAL/olivierd

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Simple download manager

LICENSE=	GPLv3

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libgee-0.8.so:${PORTSDIR}/devel/libgee \
		libnotify.so:${PORTSDIR}/devel/libnotify
BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala

USE_XZ=	yes
USES=		cmake pkgconfig gettext
GLIB_SCHEMAS=	net.launchpad.steadyflow.gschema.xml
USE_GNOME=	glib20 gtk30 intltool
INSTALLS_ICONS=	yes
CMAKE_ARGS=	-DCOMPILE_GSETTINGS_ON_INSTALL:BOOL=ON \
		-DWANT_AYATANA:BOOL=OFF

.include <bsd.port.mk>
