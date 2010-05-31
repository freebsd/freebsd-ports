# New ports collection makefile for:	xcowsay
# Date created:		2008/09/07
# Whom:			chinsan
#
# $FreeBSD$
#

PORTNAME=	xcowsay
PORTVERSION=	1.2
PORTREVISION=	3
CATEGORIES=	games gnome
MASTER_SITES=	http://www.nickg.me.uk/files/ \
		http://www.predatorlabs.net/dl/

MAINTAINER=	rfarmer@predatorlabs.net
COMMENT=	A graphical configurable talking cow

OPTIONS=	DBUS "Enable DBus support" off

USE_GNOME=	gtk20
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN6=		xcowsay.6
PLIST_FILES=	bin/xcowdream \
		bin/xcowfortune \
		bin/xcowsay \
		bin/xcowthink \
		share/locale/pt_BR/LC_MESSAGES/xcowsay.mo \
		%%DATADIR%%/cow_large.png \
		%%DATADIR%%/cow_med.png \
		%%DATADIR%%/cow_small.png
PLIST_DIRS=	%%DATADIR%%

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if defined(WITH_DBUS)
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
CFLAGS+=	-DWITH_DBUS
CONFIGURE_ARGS+=	--enable-dbus
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-DWITH_DBUS||g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
