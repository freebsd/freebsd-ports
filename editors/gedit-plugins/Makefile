# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/editors/gedit-plugins/Makefile 20070 2014-11-12 11:53:48Z gusi $

PORTNAME=	gedit-plugins
PORTVERSION=	3.14.1
PORTREVISION=	3
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Plugins for GEdit 3

BUILD_DEPENDS=	gedit>=0:${PORTSDIR}/editors/gedit \
		itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libpeas-1.0.so:${PORTSDIR}/devel/libpeas
RUN_DEPENDS=	gedit>=0:${PORTSDIR}/editors/gedit

USES=		gettext gmake libtool pathfix pkgconfig \
		python:3 tar:xz
USE_GNOME=	gnomeprefix gtk30 gtksourceview3 intlhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.gedit.plugins.drawspaces.gschema.xml \
		org.gnome.gedit.plugins.wordcompletion.gschema.xml

PLIST_SUB+=	PYVER=${PYTHON_VER:S/.//}

OPTIONS_DEFINE=	PYTHON
OPTIONS_DEFAULT=PYTHON
PYTHON_DESC=	Build plugins that depend on python

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
USES+=		python
BUILD_DEPENDS+=	py3?-dbus>=0:${PORTSDIR}/devel/py3-dbus
LIB_DEPENDS+=	libgucharmap_2_90.so:${PORTSDIR}/deskutils/gucharmap
RUN_DEPENDS+=	py3?-dbus>=0:${PORTSDIR}/devel/py3-dbus \
		${PYTHON_PKGNAMEPREFIX}libpeas>=0:${PORTSDIR}/devel/py3-libpeas
USE_GNOME+=	vte3
CONFIGURE_ARGS+=--enable-python
GLIB_SCHEMAS+=	org.gnome.gedit.plugins.terminal.gschema.xml
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=--disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's| \\t\\r\\n\\f|[:space:]|g' \
	    	${WRKSRC}/configure

.include <bsd.port.mk>

