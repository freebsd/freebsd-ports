# Created by: Joe Maloney jmaloney@pkgdemon.com>
# $FreeBSD$
#   $MCom: ports/trunk/deskutils/alacarte/Makefile 19804 2014-08-13 14:55:11Z kwm $

PORTNAME=	alacarte
PORTVERSION=	3.11.91
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@freebsd.org
COMMENT=	Freedesktop compliant menu editor for GNOME

BUILD_DEPENDS=	docbook-xsl>=0:${PORTSDIR}/textproc/docbook-xsl

USES=		gettext gmake pkgconfig python:3 tar:xz
USE_GNOME=	gnomemenus3 gnomeprefix intlhack libxslt:build \
		py3gobject3
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
