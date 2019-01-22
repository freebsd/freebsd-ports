# Created by: Thorsten Greiner <thorsten.greiner@web.de>
# $FreeBSD$

PORTNAME=	xfce4-notes-plugin
PORTVERSION=	1.8.1
PORTREVISION=	1
CATEGORIES=	deskutils xfce
MASTER_SITES=	XFCE/src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Notes plugin for the Xfce panel

LICENSE=	GPLv2

LIB_DEPENDS=	libunique-1.0.so:x11-toolkits/unique \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libdbus-glib-1.so:devel/dbus-glib \
		libdbus-1.so:devel/dbus

USES=		gettext-tools gmake gnome libtool pkgconfig tar:bzip2 xfce
USE_GNOME=	cairo glib20 gtk20 intlhack intltool
USE_XFCE=	panel
USE_XORG=	ice sm x11

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

.include <bsd.port.mk>
