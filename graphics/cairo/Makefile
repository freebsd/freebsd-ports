# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cairo
PORTVERSION=	1.16.0
PORTEPOCH=	2
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/releases/ \
		http://cairographics.org/snapshots/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Vector graphics library with cross-device output support

LICENSE=	LGPL21 MPL11
LICENSE_COMB=	dual
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING-LGPL-2.1
LICENSE_FILE_MPL11=	${WRKSRC}/COPYING-MPL-1.1

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpng.so:graphics/png \
		libfontconfig.so:x11-fonts/fontconfig

PORTSCOUT=	skipv:5c-1.1,5c-1.2,5c-1.5

USES=		cpe gnome libtool pathfix pkgconfig tar:xz xorg
CPE_VENDOR=	cairographics
USE_XORG=	pixman
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-html-dir=${DOCSDIR} \
		--disable-directfb \
		--disable-gallium \
		--disable-glesv2 \
		--disable-wgl \
		--enable-tee

OPTIONS_DEFINE=	OPENGL XCB GLIB X11 DOCS
OPTIONS_DEFAULT=OPENGL XCB GLIB X11
OPTIONS_SLAVE=	${ARCH:tu}
OPTIONS_SUB=	yes

X11_USES=	xorg
X11_USE=	xorg=x11,xext,xrender
X11_CONFIGURE_ENABLE=xlib

OPENGL_USES=	gl xorg
OPENGL_USE=	gl=gl,egl xorg=xorgproto:both
OPENGL_CONFIGURE_ENABLE=gl egl
OPENGL_IMPLIES=	X11

GLIB_DESC=	Enable GObject Functions Feature
GLIB_USES=	gettext-runtime
GLIB_USE=	gnome=glib20
GLIB_CONFIGURE_ENABLE=	gobject

XCB_DESC=	Enable XCB (X C-language Binding) Support
XCB_USES=	xorg
XCB_USE=	xorg=xcb
XCB_CONFIGURE_ENABLE=	xcb

# this has another option --enable-xlib-xcb=auto but it is buggy.
MIPS_BUILD_DEPENDS=	${LOCALBASE}/include/atomic_ops.h:devel/libatomic_ops
MIPS_USES=	localbase
MIPS_CONFIGURE_ENV=	cairo_cv_atomic_primitives="libatomic-ops"

PLIST_SUB+=	LIBVER=2.11600.0

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

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e 's|public||g' \
		${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>
