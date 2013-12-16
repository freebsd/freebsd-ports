# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/graphics/cairo/Makefile,v 1.101 2010/10/29 15:40:04 kwm Exp $

PORTNAME=	cairo
PORTVERSION=	1.10.2
PORTREVISION=	7
PORTEPOCH?=	2
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Vector graphics library with cross-device output support

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	freetype:${PORTSDIR}/print/freetype2 \
		png15:${PORTSDIR}/graphics/png \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig

CONFIGURE_ARGS=	--with-html-dir=${DOCSDIR} \
		--disable-directfb \
		--enable-tee
USES=		pathfix pkgconfig
USE_XORG=	pixman
USE_GNOME=	ltverhack referencehack
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}

OPTIONS_DEFINE=	OPENGL XCB GLIB X11
OPTIONS_DEFAULT=	XCB GLIB X11
XCB_DESC=	Enable XCB (X C-language Binding) Support
GLIB_DESC=	Enable GObject Functions Feature

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "arm"
BROKEN=		Does not compile on arm
.endif

.if ${PORT_OPTIONS:MX11}
USE_XORG+=	xrender
PLIST_SUB+=	X11=""
.else
CONFIGURE_ARGS+=--disable-xlib
PLIST_SUB+=	X11="@comment "
.endif

.if ${PORT_OPTIONS:MOPENGL}
USE_GL=		gl
USE_XORG+=	glproto:both dri2proto:both
CONFIGURE_ARGS+=	--enable-gl
PLIST_SUB+=	GL=""
.else
CONFIGURE_ARGS+=	--disable-gl
PLIST_SUB+=	GL="@comment "
.endif

.if ${PORT_OPTIONS:MXCB}
BUILD_DEPENDS+= 	${LOCALBASE}/libdata/pkgconfig/xcb-renderutil.pc:${PORTSDIR}/x11/xcb-util-renderutil
RUN_DEPENDS+=		${LOCALBASE}/libdata/pkgconfig/xcb-renderutil.pc:${PORTSDIR}/x11/xcb-util-renderutil
CONFIGURE_ARGS+=	--enable-xcb
# this option exposes a bug --enable-xlib-xcb=auto
PLIST_SUB+=		XCB=""
.else
CONFIGURE_ARGS+=	--disable-xcb
PLIST_SUB+=		XCB="@comment "
.endif

.if ${PORT_OPTIONS:MGLIB}
USE_GNOME+=	glib20
PLIST_SUB+=	GLIB=""
.else
CONFIGURE_ARGS+=	--enable-gobject=no
PLIST_SUB+=	GLIB="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e '/test/s/==/=/g' \
		-e '/LIBS/s/-lrt//' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-lcairo|-lcairo ${PTHREAD_LIBS}|' \
		${WRKSRC}/src/*.pc.in
	@${REINPLACE_CMD} -e '/@CAIRO_HAS_PNG_FUNCTIONS_TRUE@.*=/d' \
		${WRKSRC}/Makefile.in
.if ${PORT_OPTIONS:MOPENGL}
	@${REINPLACE_CMD} 's|@CAIRO_CFLAGS@|-I$$(top_srcdir)/src/glew &|' \
		${WRKSRC}/src/Makefile.in
.endif

.include <bsd.port.post.mk>

.endif
