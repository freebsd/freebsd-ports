# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports-experimental/trunk/editors/gedit-plugins/Makefile 19502 2014-04-14 20:48:21Z gusi $

PORTNAME=	gedit-plugins
PORTVERSION=	3.12.1
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Plugins for GEdit 3

BUILD_DEPENDS=	gedit>=0:${PORTSDIR}/editors/gedit \
		itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libpeas-1.0.so:${PORTSDIR}/devel/libpeas
RUN_DEPENDS=	gedit>=0:${PORTSDIR}/editors/gedit

USES=		gettext gmake libtool:keepla pathfix pkgconfig \
		tar:xz
USE_GNOME=	gnomeprefix gtk30 gtksourceview3
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.gedit.plugins.drawspaces.gschema.xml \
		org.gnome.gedit.plugins.wordcompletion.gschema.xml

OPTIONS_DEFINE=	PYTHON
OPTIONS_DEFAULT=PYTHON
PYTHON_DESC=	Build plugins that depend on python

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/dbus/bus.py:${PORTSDIR}/devel/py-dbus
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/dbus/bus.py:${PORTSDIR}/devel/py-dbus
# the charmap plugin doesn't work, missing py-gucharmap stuff
CONFIGURE_ARGS+=--enable-python
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=--disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's| \\t\\r\\n\\f|[:space:]|g' \
	    	${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gedit/plugins/lib*.so

.include <bsd.port.mk>

