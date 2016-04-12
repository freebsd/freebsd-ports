# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xfce4-notifyd
PORTVERSION=	0.2.4
PORTREVISION=	1
CATEGORIES=	deskutils xfce
MASTER_SITES=	XFCE/src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Visually-appealing notification daemon for Xfce

LICENSE=	GPLv3

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libnotify.so:devel/libnotify

USES=		gmake libtool pkgconfig gettext-tools xfce tar:bzip2
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 intltool intlhack
USE_XFCE=	libmenu
INSTALLS_ICONS=	yes
USE_XORG=	x11

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext-runtime
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
EXTRA_PATCHES=	${FILESDIR}/extra-patch-configure
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
