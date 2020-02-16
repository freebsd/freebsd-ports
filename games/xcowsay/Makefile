# Created by: chinsan
# $FreeBSD$

PORTNAME=	xcowsay
PORTVERSION=	1.5
CATEGORIES=	games
MASTER_SITES=	http://www.nickg.me.uk/files/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Graphical configurable talking cow

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gettext gmake gnome pkgconfig
USE_CSTD=	c99
USE_GNOME=	cairo gdkpixbuf2 gtk30
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DBUS

DBUS_LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
			libdbus-1.so:devel/dbus
DBUS_CFLAGS=		-DWITH_DBUS
DBUS_CONFIGURE_ENABLE=	dbus

.include <bsd.port.mk>
