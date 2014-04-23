# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/libpeas/Makefile 19006 2014-02-16 10:03:26Z kwm $

PORTNAME=	libpeas
PORTVERSION=	1.8.1
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Next evolution of the Gedit plugins engine

BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala

USE_XZ=		yes
USE_PYTHON=	2
USE_LDCONFIG=	yes
USES=		gettext gmake libtool:keepla pathfix pkgconfig
USE_GNOME=	gtk30 introspection:build
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS+=--disable-glade-catalog

OPTIONS_DEFINE=	PYTHON
OPTIONS_DEFAULT=PYTHON GJS
OPTIONS_MULTI=	JS
OPTIONS_MULTI_JS=SEED GJS
JS_DESC=JavaScript plugin support
SEED_DESC=	JavaScript support based on webkit-gtk3
GJS_DESC=	JavaScript support based on spidermonkey

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSEED}
CONFIGURE_ARGS+=--enable-seed=yes
LIB_DEPENDS=	libseed-gtk3.so:${PORTSDIR}/devel/seed3
PLIST_SUB+=	SEED=""
.else
CONFIGURE_ARGS+=--enable-seed=no
PLIST_SUB+=	SEED="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
CONFIGURE_ARGS+=--enable-python2 --disable-python3
USE_GNOME+=	pygobject3
PLIST_SUB+=	PYTHONS=""
.else
CONFIGURE_ARGS+=--disable-python2 --disable-python3
PLIST_SUB+=	PYTHONS="@comment "
.endif

.if ${PORT_OPTIONS:MGJS}
CONFIGURE_ARGS+=--enable-gjs
BUILD_DEPENDS+=	gjs>=1.32.0:${PORTSDIR}/lang/gjs
LIB_DEPENDS+=	libgjs.so:${PORTSDIR}/lang/gjs
PLIST_SUB+=	GJS=""
.else
CONFIGURE_ARGS+=--enable-gjs=no
PLIST_SUB+=	GJS="@comment "
.endif

.include <bsd.port.mk>
