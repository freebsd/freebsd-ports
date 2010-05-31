# New ports collection makefile for:	gwget
# Date created:				1 November 2004
# Whom:					Radek Kozlowski <radek@raadradd.com>
#
# $FreeBSD$
#

PORTNAME=	gwget
PORTVERSION=	1.0.4
PORTREVISION=	4
CATEGORIES=	ftp gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	avl@FreeBSD.org
COMMENT=	GNOME wget front-end

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

OPTIONS=	LIBNOTIFY	"Enable libnotify support"	on \
		EPIPHANY	"Enable Epiphany extension"	on

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix gnomehack gtk20 gconf2 libgnomeui \
		desktopfileutils
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	${PORTNAME}.schemas

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_LIBNOTIFY)
LIB_DEPENDS+=	notify.1:${PORTSDIR}/devel/libnotify
RUN_DEPENDS+=	${LOCALBASE}/libexec/notification-daemon:${PORTSDIR}/deskutils/notification-daemon
.else
CONFIGURE_ARGS+=	--disable-libnotify
.endif

.if defined(WITH_EPIPHANY)
BUILD_DEPENDS+=	epiphany:${PORTSDIR}/www/epiphany
RUN_DEPENDS+=	epiphany:${PORTSDIR}/www/epiphany
CONFIGURE_ARGS+=	--enable-epiphany-extension
PLIST_SUB+=	EPIPHANY="" EPHY_VERSION="2.30"
.else
CONFIGURE_ARGS+=	--disable-epiphany-extension
PLIST_SUB+=	EPIPHANY="@comment "
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
