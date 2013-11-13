# Created by: chinsan
# $FreeBSD$

PORTNAME=	xcowsay
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.nickg.me.uk/files/ \
		http://www.predatorlabs.net/dl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical configurable talking cow

OPTIONS_DEFINE=	DBUS

USE_GNOME=	gtk20
USES=		gettext gmake pkgconfig
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
PLIST_DIRS=	%%DATADIR%%

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DBUS_LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
DBUS_CFLAGS=		-DWITH_DBUS
DBUS_CONFIGURE_ENABLE=	dbus

.include <bsd.port.mk>
