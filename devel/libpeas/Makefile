# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/libpeas/Makefile 18965 2013-12-20 11:02:42Z kwm $

PORTNAME=	libpeas
PORTVERSION=	1.6.1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Next evolution of the Gedit plugins engine

BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala

USE_XZ=		yes
USE_PYTHON=	2.5+
USE_LDCONFIG=	yes
USES=		gettext gmake pathfix pkgconfig
USE_GNOME=	gtk30 ltverhack introspection:build
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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSEED}
CONFIGURE_ARGS+=--enable-seed=yes
LIB_DEPENDS=	libseed-gtk3.so:${PORTSDIR}/devel/seed
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
LIB_DEPENDS+=	libgjs.so:${PORTSDIR}/lang/gjs
PLIST_SUB+=	GJS=""
.else
CONFIGURE_ARGS+=--enable-gjs=no
PLIST_SUB+=	GJS="@comment "
.endif

PLIST_SUB+=	VALA="@comment "

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpeas-1.0/loaders/lib*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/peas-demo/plugins/*/*.so

.include <bsd.port.mk>
