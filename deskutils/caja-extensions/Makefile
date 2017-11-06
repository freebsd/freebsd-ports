# Created by: Eric Turgeon <ericturgeon@ghostbsd.org>
# $FreeBSD$

PORTNAME=	caja-extensions
PORTVERSION=	1.18.1
CATEGORIES=	deskutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Set of extensions for Caja

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgupnp-1.0.so:net/gupnp \
		libstartup-notification-1.so:x11/startup-notification \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib

PORTSCOUT=	limitw:1,even

USES=		gettext gmake libtool localbase pathfix \
		pkgconfig tar:xz
USE_MATE=	caja desktop
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.Caja.Sendto.gschema.xml \
		org.mate.caja-open-terminal.gschema.xml

.include <bsd.port.mk>
