# Created by: Joe Maloney jmaloney@pkgdemon.com>
# $FreeBSD$
#    $MCom: ports/trunk/deskutils/alacarte/Makefile 18888 2013-11-13 15:24:02Z gusi $

PORTNAME=	alacarte
PORTVERSION=	3.6.1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@freebsd.org
COMMENT=	Freedesktop compliant menu editor for GNOME

USE_XZ=		yes
USE_GNOME=	gnomemenus3 gnomeprefix intlhack pygobject3
USES=		gettext gmake pkgconfig
USE_PYTHON=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|from gi._glib import|from gi.repository.GLib import|g' \
		${WRKSRC}/Alacarte/util.py
	@${REINPLACE_CMD} -e "s|ron\['XDG_MENU_PREFIX'\]|ron.get('XDG_MENU_PREFIX', '')|g" \
		${WRKSRC}/Alacarte/MenuEditor.py

.include <bsd.port.mk>
