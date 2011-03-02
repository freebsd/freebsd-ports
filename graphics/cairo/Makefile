# New ports collection makefile for:	cairo
# Date created:		2004-10-06
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/graphics/cairo/Makefile,v 1.101 2010/10/29 15:40:04 kwm Exp $
#

PORTNAME=	cairo
PORTVERSION=	1.10.2
PORTREVISION=	1
PORTEPOCH?=	1
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/releases/
#MASTER_SITES=	http://cairographics.org/snapshots/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Vector graphics library with cross-device output support

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		png.6:${PORTSDIR}/graphics/png \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig \
		pixman-1.9:${PORTSDIR}/x11/pixman

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-html-dir=${DOCSDIR} \
		--disable-directfb \
		--enable-tee \
		--enable-gobject
USE_GNOME=	glib20 gnomehack ltverhack referencehack
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=--disable-xlib
PLIST_SUB+=	X11="@comment "
.else
USE_XORG+=	xrender
PLIST_SUB+=	X11=""
.endif

OPTIONS+=	GL "Enable OpenGL Support" Off \
		XCB "Enable XCB (X C-language Binding) Support" On

.include <bsd.port.pre.mk>

.if defined(WITH_GL)
USE_GL=		gl
CONFIGURE_ARGS+=	--enable-gl
PLIST_SUB+=	GL=""
.else
CONFIGURE_ARGS+=	--disable-gl
PLIST_SUB+=	GL="@comment "
.endif

.if defined(WITH_XCB)
BUILD_DEPENDS+= 	${LOCALBASE}/libdata/pkgconfig/xcb-renderutil.pc:${PORTSDIR}/x11/xcb-util
RUN_DEPENDS+=		${LOCALBASE}/libdata/pkgconfig/xcb-renderutil.pc:${PORTSDIR}/x11/xcb-util
CONFIGURE_ARGS+=	--enable-xcb
# this option exposes a bug --enable-xlib-xcb=auto
PLIST_SUB+=		XCB=""
.else
CONFIGURE_ARGS+=	--disable-xcb
PLIST_SUB+=		XCB="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e '/test/s/==/=/g' \
		-e '/LIBS/s/-lrt//' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-lcairo|-lcairo ${PTHREAD_LIBS}|' \
		${WRKSRC}/src/*.pc.in
	@${REINPLACE_CMD} -e '/@CAIRO_HAS_PNG_FUNCTIONS_TRUE@.*=/d' \
		${WRKSRC}/Makefile.in
.if defined(WITH_GL)
	@${REINPLACE_CMD} 's|@CAIRO_CFLAGS@|-I$$(top_srcdir)/src/glew &|' \
		${WRKSRC}/src/Makefile.in
.endif

.include <bsd.port.post.mk>

.endif
