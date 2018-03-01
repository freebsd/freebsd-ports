# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$
#
# !!!NOTE!!! Update of x11-toolkits/gtk30 (specially >= 3.20.x) must be
# accompanied by PORTREVISION bumps of this port.
# Support of GTK+ is checked at compile time and themes directories too.

PORTNAME=	xfce4-notifyd
PORTVERSION=	0.4.2
CATEGORIES=	deskutils xfce
MASTER_SITES=	XFCE/src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Visually-appealing notification daemon for Xfce

LICENSE=	GPLv3

LIB_DEPENDS=	libnotify.so:devel/libnotify \
		libdbus-glib-1.so:devel/dbus-glib \
		libdbus-1.so:devel/dbus

USES=		gettext-tools gmake libtool pkgconfig tar:bzip2 xfce:gtk3
GNU_CONFIGURE=	yes
USE_GNOME=	gtk30 glib20 cairo intltool
USE_XFCE=	libutil panel
USE_XORG=	ice sm x11
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS
NLS_USES=	gettext-runtime
NLS_EXTRA_PATCHES=	${FILESDIR}/extra-patch-configure
OPTIONS_SUB=	yes

.include <bsd.port.mk>
