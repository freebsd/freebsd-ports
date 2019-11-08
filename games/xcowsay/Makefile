# Created by: chinsan
# $FreeBSD$

PORTNAME=	xcowsay
PORTVERSION=	1.4
CATEGORIES=	games
MASTER_SITES=	http://www.nickg.me.uk/files/ \
		http://www.predatorlabs.net/dl/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Graphical configurable talking cow

LICENSE=	GPLv3

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USE_GNOME=	cairo gdkpixbuf2 gtk20
USES=		gettext gmake gnome pkgconfig
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/xcowdream \
		bin/xcowfortune \
		bin/xcowsay \
		bin/xcowthink \
		share/locale/pt_BR/LC_MESSAGES/xcowsay.mo \
		share/locale/ru/LC_MESSAGES/xcowsay.mo \
		man/man6/xcowsay.6.gz \
		%%DATADIR%%/cow_large.png \
		%%DATADIR%%/cow_med.png \
		%%DATADIR%%/cow_small.png

OPTIONS_DEFINE=	DBUS

DBUS_LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
			libdbus-1.so:devel/dbus
DBUS_CFLAGS=		-DWITH_DBUS
DBUS_CONFIGURE_ENABLE=	dbus

.include <bsd.port.mk>
