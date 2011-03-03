# New ports collection makefile for:	xfce4-notifyd
# Date created:				22 Oct 2009
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xfce4-notifyd
PORTVERSION=	0.2.1
CATEGORIES=	deskutils xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Visually-appealing notification daemon for Xfce

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		notify.1:${PORTSDIR}/devel/libnotify

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 gnomehack intltool intlhack desktopfileutils pkgconfig
USE_XFCE=	configenv libexo libmenu libutil xfconf
INSTALLS_ICONS=	yes
USE_XORG=	x11

CONFIGURE_ARGS=	--disable-debug

CONFLICTS=	notification-daemon-[0-9]* xfce4-notification-daemon-[0-9]* \
		xfce4-notifyd-0.1*

OPTIONS=	NLS      "Enable Native Language Support"             on

MAN1=	xfce4-notifyd-config.1

LICENSE=	GPLv3

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
