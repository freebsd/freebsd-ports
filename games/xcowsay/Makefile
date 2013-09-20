# Created by: chinsan
# $FreeBSD$

PORTNAME=	xcowsay
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.nickg.me.uk/files/ \
		http://www.predatorlabs.net/dl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical configurable talking cow

OPTIONS_DEFINE=	DBUS

USE_GNOME=	gtk20
USES=		gettext gmake pkgconfig
GNU_CONFIGURE=	yes

MAN6=		xcowsay.6
PLIST_FILES=	bin/xcowdream \
		bin/xcowfortune \
		bin/xcowsay \
		bin/xcowthink \
		share/locale/pt_BR/LC_MESSAGES/xcowsay.mo \
		share/locale/ru/LC_MESSAGES/xcowsay.mo \
		%%DATADIR%%/cow_large.png \
		%%DATADIR%%/cow_med.png \
		%%DATADIR%%/cow_small.png
PLIST_DIRS=	%%DATADIR%%

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
CFLAGS+=	-DWITH_DBUS
CONFIGURE_ARGS+=	--enable-dbus
.endif

.include <bsd.port.mk>
