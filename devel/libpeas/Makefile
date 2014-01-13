# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/libpeas/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	libpeas
PORTVERSION=	1.6.1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Next evolution of the Gedit plugins engine

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection \
		valac:${PORTSDIR}/lang/vala

USE_XZ=		yes
USE_PYTHON=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USES=		pathfix gettext gmake pkgconfig
USE_GNOME=	glib20 gtk30 ltverhack
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--disable-glade-catalog

OPTIONS_DEFINE=	PYTHON JS
OPTIONS_DEFAULT=PYTHON JS GJS
OPTIONS_MULTI=	JS
OPTIONS_MULTI_JS=SEED GJS
JS_DESC=JavaScript plugin support
SEED_DESC=	JavaScript support based on webkit-gtk3
GJS_DESC=	JavaScript support based on spidermonkey

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSEED}
CONFIGURE_ARGS+=--enable-seed=yes
LIB_DEPENDS=	seed-gtk3:${PORTSDIR}/devel/seed3
PLIST_SUB+=	SEED=""
.else
CONFIGURE_ARGS+=--enable-seed=no
PLIST_SUB+=	SEED="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
CONFIGURE_ARGS+=--enable-python
USE_GNOME+=	pygobject3
PLIST_SUB+=	PYTHONS=""
.else
CONFIGURE_ARGS+=--enable-python=no
PLIST_SUB+=	PYTHONS="@comment "
.endif

.if ${PORT_OPTIONS:MGJS}
CONFIGURE_ARGS+=--enable-gjs
BUILD_DEPENDS+=	gjs>=1.32.0:${PORTSDIR}/lang/gjs
LIB_DEPENDS+=	gjs:${PORTSDIR}/lang/gjs
PLIST_SUB+=	GJS=""
.else
CONFIGURE_ARGS+=--enable-gjs=no
PLIST_SUB+=	GJS="@comment "
.endif

PLIST_SUB+=	VALA="@comment "

.include <bsd.port.mk>
