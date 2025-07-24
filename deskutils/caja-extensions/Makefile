PORTNAME=	caja-extensions
PORTVERSION=	1.28.0
PORTREVISION=	1
CATEGORIES=	deskutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Set of extensions for Caja
WWW=		https://mate-desktop.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc
LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib

PORTSCOUT=	limitw:1,even

USES=		autoreconf compiler:c11 gettext gmake gnome libtool \
		localbase mate pkgconfig tar:xz gstreamer
USE_MATE=	caja desktop
USE_GNOME=	cairo gdkpixbuf gtk30 intltool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS= --enable-gksu=no
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.Caja.Sendto.gschema.xml \
		org.mate.caja-open-terminal.gschema.xml

.include <bsd.port.mk>
