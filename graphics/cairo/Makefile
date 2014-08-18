# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/graphics/cairo/Makefile 19813 2014-08-15 19:44:33Z gusi $

PORTNAME=	cairo
PORTVERSION=	1.12.16
PORTREVISION=	1
PORTEPOCH?=	2
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Vector graphics library with cross-device output support

PORTSCOUT=	skipv:5c-1\.[1-3]

USES=		tar:xz

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libpng15.so:${PORTSDIR}/graphics/png \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig

USES+=		libtool pathfix pkgconfig
USE_XORG=	pixman xext
USE_GNOME=	referencehack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--with-html-dir=${DOCSDIR} \
		--disable-directfb \
		--disable-gallium \
		--disable-glesv2 \
		--disable-wgl \
		--disable-egl \
		--enable-tee

OPTIONS_DEFINE=	OPENGL XCB GLIB X11 
OPTIONS_DEFAULT=XCB GLIB X11
XCB_DESC=	Enable XCB (X C-language Binding) Support
GLIB_DESC=	Enable GObject Functions Feature

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
		-e '/LIBS/s/-lrt//'  -e '/LIBS/s|-ldld||' \
		-e '/LIBS/s|-ldl||' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-lcairo|-lcairo ${PTHREAD_LIBS}|' \
		${WRKSRC}/src/*.pc.in
	@${REINPLACE_CMD} -e '/@CAIRO_HAS_PNG_FUNCTIONS_TRUE@.*=/d' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|-ldl||g' \
		${WRKSRC}/util/*/Makefile.in \
		${WRKSRC}/boilerplate/Makefile.in
.if ${PORT_OPTIONS:MOPENGL}
	@${REINPLACE_CMD} 's|@CAIRO_CFLAGS@|-I$$(top_srcdir)/src/glew &|' \
		${WRKSRC}/src/Makefile.in
.endif

.include <bsd.port.post.mk>

.endif
