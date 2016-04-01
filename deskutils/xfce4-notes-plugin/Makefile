# Created by: Thorsten Greiner <thorsten.greiner@web.de>
# $FreeBSD$

PORTNAME=	xfce4-notes-plugin
PORTVERSION=	1.8.1
CATEGORIES=	deskutils xfce
MASTER_SITES=	XFCE/src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Notes plugin for the Xfce panel

LICENSE=	GPLv2

LIB_DEPENDS=	libunique-1.0.so:x11-toolkits/unique

GNU_CONFIGURE=	yes
USES=		gettext gmake libtool pkgconfig xfce tar:bzip2
USE_GNOME=	glib20 gtk20 intltool intlhack
USE_XFCE=	panel
INSTALLS_ICONS=	yes
USE_XORG=	x11
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
