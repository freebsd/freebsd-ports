# Created by: Radek Kozlowski <radek@raadradd.com>
# $FreeBSD$

PORTNAME=	gwget
PORTVERSION=	1.0.4
PORTREVISION=	10
CATEGORIES=	ftp gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME wget front-end

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib
RUN_DEPENDS=	wget:ftp/wget

OPTIONS_DEFINE=	NOTIFY
OPTIONS_DEFAULT=	NOTIFY

USES=		gettext gmake libtool pathfix tar:bzip2
USE_GNOME=	gnomeprefix gtk20 gconf2 intltool libgnomeui
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_SUB+=	EPHY_VERSION="2.30"
CONFIGURE_ARGS=	--disable-epiphany-extension

GCONF_SCHEMAS=	${PORTNAME}.schemas

NOTIFY_CONFIGURE_ENABLE=	libnotify
NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_RUN_DEPENDS=	${LOCALBASE}/libexec/notification-daemon:deskutils/notification-daemon

post-patch:
	@${REINPLACE_CMD} 's|glib/gerror|glib|' \
		${WRKSRC}/src/gwget-application.h

.include <bsd.port.mk>
