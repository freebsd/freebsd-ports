# Created by: Radek Kozlowski <radek@raadradd.com>
# $FreeBSD$

PORTNAME=	gwget
PORTVERSION=	1.0.4
PORTREVISION=	6
CATEGORIES=	ftp gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME wget front-end

LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

OPTIONS_DEFINE=	NOTIFY EPIPHANY
OPTIONS_DEFAULT=	NOTIFY EPIPHANY
EPIPHANY_DESC=	Epiphany extension

USE_BZIP2=	yes
USE_GMAKE=	yes
USES=		pathfix gettext
USE_GNOME=	desktopfileutils gnomeprefix gtk20 gconf2 libgnomeui
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	${PORTNAME}.schemas

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=	notify:${PORTSDIR}/devel/libnotify
RUN_DEPENDS+=	${LOCALBASE}/libexec/notification-daemon:${PORTSDIR}/deskutils/notification-daemon
.else
CONFIGURE_ARGS+=	--disable-libnotify
.endif

.if ${PORT_OPTIONS:MEPIPHANY}
BUILD_DEPENDS+=	epiphany:${PORTSDIR}/www/epiphany
RUN_DEPENDS+=	epiphany:${PORTSDIR}/www/epiphany
CONFIGURE_ARGS+=	--enable-epiphany-extension
PLIST_SUB+=	EPIPHANY="" EPHY_VERSION="2.30"
.else
CONFIGURE_ARGS+=	--disable-epiphany-extension
PLIST_SUB+=	EPIPHANY="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} 's|glib/gerror|glib|' \
		${WRKSRC}/src/gwget-application.h

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
