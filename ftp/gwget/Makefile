# Created by: Radek Kozlowski <radek@raadradd.com>
# $FreeBSD$

PORTNAME=	gwget
PORTVERSION=	1.0.4
PORTREVISION=	8
CATEGORIES=	ftp gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME wget front-end

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

OPTIONS_DEFINE=	NOTIFY EPIPHANY
OPTIONS_DEFAULT=	NOTIFY EPIPHANY
EPIPHANY_DESC=	Epiphany extension

USES=		desktop-file-utils gettext gmake libtool pathfix tar:bzip2
USE_GNOME=	gnomeprefix gtk20 gconf2 libgnomeui
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_SUB+=	EPHY_VERSION="2.30"

GCONF_SCHEMAS=	${PORTNAME}.schemas

OPTIONS_SUB=	yes

NOTIFY_CONFIGURE_ENABLE=	libnotify
NOTIFY_LIB_DEPENDS=	libnotify.so:${PORTSDIR}/devel/libnotify
NOTIFY_RUN_DEPENDS=	${LOCALBASE}/libexec/notification-daemon:${PORTSDIR}/deskutils/notification-daemon

EPIPHANY_BUILD_DEPENDS+=	epiphany:${PORTSDIR}/www/epiphany
EPIPHANY_RUN_DEPENDS=	epiphany:${PORTSDIR}/www/epiphany
EPIPHANY_CONFIGURE_ENABLE=	epiphany-extension

post-patch:
	@${REINPLACE_CMD} 's|glib/gerror|glib|' \
		${WRKSRC}/src/gwget-application.h

.include <bsd.port.mk>
