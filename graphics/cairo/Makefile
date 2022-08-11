PORTNAME=	cairo
DISTVERSION=	1.17.4
PORTREVISION=	1
PORTEPOCH=	3
CATEGORIES=	graphics
MASTER_SITES=	https://cairographics.org/releases/ \
		https://cairographics.org/snapshots/

PATCH_SITES=	https://gitlab.freedesktop.org/${PORTNAME}/${PORTNAME}/commit/
PATCHFILES=	ebbaebdec12878836fc84d31c59ee324e67abc05.patch:-p1 # cairo-script-interpreter.pc

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Vector graphics library with cross-device output support

LICENSE=	LGPL21 MPL11
LICENSE_COMB=	dual
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING-LGPL-2.1
LICENSE_FILE_MPL11=	${WRKSRC}/COPYING-MPL-1.1

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpng.so:graphics/png \
		libfontconfig.so:x11-fonts/fontconfig

PORTSCOUT=	skipv:5c-1.1,5c-1.2,5c-1.5

USES=		autoreconf cpe gnome libtool pkgconfig tar:xz xorg
CPE_VENDOR=	cairographics
USE_XORG=	pixman
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-directfb \
		--disable-gallium \
		--disable-wgl \
		--enable-tee

OPTIONS_RADIO=	GL
OPTIONS_RADIO_GL=	OPENGL GLESV2
OPTIONS_DEFINE=	XCB GLIB X11 DOCS
OPTIONS_DEFAULT=OPENGL XCB GLIB X11
OPTIONS_SLAVE=	${ARCH:tu}
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc
DOCS_CONFIGURE_ON=	--with-html-dir=${DOCSDIR}

X11_USES=	xorg
X11_USE=	xorg=x11,xext,xorgproto,xrender
X11_CONFIGURE_ENABLE=xlib
X11_CONFIGURE_OFF=--disable-glx

OPENGL_USES=	gl
OPENGL_USE=	gl=egl
OPENGL_CONFIGURE_ENABLE=gl egl

GLESV2_USES=	gl
GLESV2_USE=	gl=glesv2
GLESV2_DESC=	Enable GLESv2 rendering
GLESV2_CONFIGURE_ENABLE=glesv2

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

PLIST_SUB+=	LIBVER=2.11704.0

post-patch-DOCS-off:
	@${REINPLACE_CMD} '/^SUBDIRS/s/doc//' ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e '/^GTK_DOC_CHECK/d' -e '/doc\/.*Makefile/d' \
		${WRKSRC}/configure.ac

.include <bsd.port.mk>
