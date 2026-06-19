PORTNAME=	caja-extensions
DISTVERSION=	1.28.0
PORTREVISION=	3
CATEGORIES=	deskutils mate
MASTER_SITES=	https://github.com/mate-desktop/${PORTNAME}/releases/download/v${DISTVERSION}/
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Set of extensions for Caja
WWW=		https://mate-desktop.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib

USES=		compiler:c11 gettext gmake gnome libtool localbase mate \
		pkgconfig gstreamer tar:xz
USE_MATE=	caja desktop
USE_GNOME=	cairo gdkpixbuf gtk30 intltool
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--enable-gksu=no
INSTALL_TARGET=	install-strip

PORTSCOUT=	site:https://github.com/mate-desktop/caja-extensions/releases/ limitw:1,even

GLIB_SCHEMAS=	org.mate.Caja.Sendto.gschema.xml \
		org.mate.caja-open-terminal.gschema.xml

.include <bsd.port.mk>
