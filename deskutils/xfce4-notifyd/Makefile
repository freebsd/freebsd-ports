# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xfce4-notifyd
PORTVERSION=	0.2.2
PORTREVISION=	4
CATEGORIES=	deskutils xfce
MASTER_SITES=	XFCE
MASTER_SITE_SUBDIR=	src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Visually-appealing notification daemon for Xfce

LICENSE=	GPLv3

LIB_DEPENDS=	dbus-glib:${PORTSDIR}/devel/dbus-glib \
		notify:${PORTSDIR}/devel/libnotify

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 gnomehack intltool intlhack desktopfileutils
USE_PKGCONFIG=	build
USE_XFCE=	configenv libexo libmenu libutil xfconf
INSTALLS_ICONS=	yes
USE_XORG=	x11

CONFIGURE_ARGS=	--disable-debug

CONFLICTS=	notification-daemon-[0-9]* xfce4-notification-daemon-[0-9]* \
		xfce4-notifyd-0.1*

MAN1=	xfce4-notifyd-config.1

OPTIONS_DEFINE=	NLS
OPTIONS_DEFAULT=NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
