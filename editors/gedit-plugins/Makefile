# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/editors/gedit-plugins/Makefile,v 1.48 2010/10/29 14:47:24 kwm Exp $

PORTNAME=	gedit-plugins
PORTVERSION=	2.32.0
PORTREVISION=	4
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Plugins for GEdit 2

BUILD_DEPENDS=	gedit:${PORTSDIR}/editors/gedit \
		gucharmap:${PORTSDIR}/deskutils/gucharmap
RUN_DEPENDS=	gedit:${PORTSDIR}/editors/gedit \
		gucharmap:${PORTSDIR}/deskutils/gucharmap

CONFLICTS=	gedit-plugins-3.[0-9]*

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:bzip2
USE_GNOME=	gnomeprefix intlhack gnomevfs2
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GCONF_SCHEMAS=	gedit-show-tabbar-plugin.schemas \
		gedit-drawspaces.schemas

OPTIONS_DEFINE=	PYTHON

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
USE_GNOME+=	pygtksourceview
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/gtk-2.0/vtemodule.so:${PORTSDIR}/x11-toolkits/py-vte \
		${PYTHON_SITELIBDIR}/dbus/bus.py:${PORTSDIR}/devel/py-dbus \
		${PYTHON_SITELIBDIR}/gtksourceview2.so:${PORTSDIR}/x11-toolkits/py-gtksourceview
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/gtk-2.0/vtemodule.so:${PORTSDIR}/x11-toolkits/py-vte \
		${PYTHON_SITELIBDIR}/dbus/bus.py:${PORTSDIR}/devel/py-dbus \
		${PYTHON_SITELIBDIR}/gtksourceview2.so:${PORTSDIR}/x11-toolkits/py-gtksourceview
CONFIGURE_ARGS+=--enable-python
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=--disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's| \\t\\r\\n\\f|[:space:]|g' \
	    	${WRKSRC}/configure

.include <bsd.port.mk>
