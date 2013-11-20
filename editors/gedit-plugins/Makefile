# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/editors/gedit-plugins3/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gedit-plugins
PORTVERSION=	3.6.1
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Plugins for GEdit 3

BUILD_DEPENDS=	gedit>=${GEDITVER}:${PORTSDIR}/editors/gedit
LIB_DEPENDS=	libpeas-1.0.so:${PORTSDIR}/devel/libpeas
RUN_DEPENDS=	gedit>=${GEDITVER}:${PORTSDIR}/editors/gedit

GEDITVER=	3.6.0
USE_LDCONFIG=	yes
USE_XZ=		yes
USES=		gettext gmake pathfix pkgconfig
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomeprefix intlhack gtk30 gtksourceview3
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.gedit.plugins.drawspaces.gschema.xml

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

