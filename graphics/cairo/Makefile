# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cairo
PORTVERSION=	1.14.8
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Vector graphics library with cross-device output support

LICENSE=	LGPL21 MPL11
LICENSE_COMB=	dual
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING-LGPL-2.1
LICENSE_FILE_MPL11=	${WRKSRC}/COPYING-MPL-1.1

USES=		tar:xz

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpng.so:graphics/png \
		libfontconfig.so:x11-fonts/fontconfig

PORTSCOUT=	skipv:5c-1.1,5c-1.2,5c-1.5

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-html-dir=${DOCSDIR} \
		--disable-directfb \
		--enable-tee
USES+=		cpe gnome libtool pathfix pkgconfig
CPE_VENDOR=	cairographics
USE_XORG=	pixman
USE_GNOME=	referencehack
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--with-html-dir=${DOCSDIR} \
		--disable-directfb \
		--disable-gallium \
		--disable-glesv2 \
		--disable-wgl \
		--enable-tee

OPTIONS_DEFINE=	OPENGL XCB GLIB X11
OPTIONS_DEFAULT=OPENGL XCB GLIB X11
OPTIONS_SLAVE=	${ARCH:tu}
XCB_DESC=	Enable XCB (X C-language Binding) Support
GLIB_DESC=	Enable GObject Functions Feature
OPTIONS_SUB=	yes
X11_USE=	xorg=x11,xext,xrender
X11_CONFIGURE_ENABLE=xlib
OPENGL_USE=	gl=gl,egl xorg=glproto:both,dri2proto:both
OPENGL_CONFIGURE_ENABLE=gl egl
OPENGL_IMPLIES=	X11
GLIB_USES=	gettext-runtime
GLIB_USE=	gnome=glib20
GLIB_CONFIGURE_ENABLE=	gobject
XCB_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xcb-renderutil.pc:x11/xcb-util-renderutil
XCB_RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xcb-renderutil.pc:x11/xcb-util-renderutil
XCB_USE=	xorg=xcb
XCB_CONFIGURE_ENABLE=	xcb
# this has another option --enable-xlib-xcb=auto but it is buggy.
MIPS_BUILD_DEPENDS=	${LOCALBASE}/include/atomic_ops.h:devel/libatomic_ops
MIPS_USES=	localbase
MIPS_CONFIGURE_ENV=	cairo_cv_atomic_primitives="libatomic-ops"

PLIST_SUB+=	LIBVER=2.11400.8

post-patch:
	@${REINPLACE_CMD} -e '/strings/s/ - / -a /' \
		-e '/test/s/==/=/g' \
		-e '/LIBS/s/-lrt//' -e '/LIBS/s|-ldld||' \
		-e '/LIBS/s|-ldl||' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-lcairo|-lcairo -lpthread|' \
		${WRKSRC}/src/*.pc.in
	@${REINPLACE_CMD} -e '/@CAIRO_HAS_PNG_FUNCTIONS_TRUE@.*=/d' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|-ldl||g' \
		${WRKSRC}/util/*/Makefile.in \
		${WRKSRC}/boilerplate/Makefile.in

.include <bsd.port.mk>

.endif
