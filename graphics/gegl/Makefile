# Created by: Pietro Cerutti <gahr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gegl
PORTVERSION=	0.4.16
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	GIMP

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Graph based image processing framework

LICENSE=	BSD3CLAUSE GPLv3+ LGPL3+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING
LICENSE_FILE_LGPL3+ =	${WRKSRC}/COPYING.LESSER

LIB_DEPENDS=	libbabl-0.1.so:x11/babl \
		libjson-glib-1.0.so:devel/json-glib \
		libfribidi.so:converters/fribidi \
		libpng.so:graphics/png

USES=		compiler:c++14-lang cpe gettext gmake gnome jpeg libtool localbase \
		pathfix pkgconfig shebangfix uniquefiles tar:bzip2
USE_GNOME=	glib20 intltool introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_header_execinfo_h=no
CONFIGURE_ARGS=	--without-vala --disable-docs
CONFIGURE_ARGS+=--without-mrg --without-lensfun
INSTALL_TARGET=	install-strip

GEGL_MINOR=	416
GEGL_VER=	0.4
PLIST_SUB+=	GEGL_MINOR="${GEGL_MINOR}" GEGL_VER=${GEGL_VER}

EXAMPLES=	2geglbuffer \
		gegl-convert gegl-slicer geglbuffer-add-image \
		geglbuffer-clock hello-world sdl-draw

SHEBANG_FILES=	tools/xml_insert.sh

# Fix conflicts with sysutils/coreutils
UNIQUE_SUFFIX=	-${GEGL_VER}
UNIQUE_SUFFIX_FILES=	bin/gcut

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	CAIRO ENSCRIPT FFMPEG PIXBUF GRAPHVIZ JASPER \
		LUA OPENEXR RAW PANGO POPPLER LIBRSVG2 SDL SPIRO V4L \
		EXAMPLES LCMS2 WEBP TIFF GEXIV2
OPTIONS_DEFAULT=CAIRO ENSCRIPT GEXIV2 PIXBUF GRAPHVIZ JASPER LCMS2 LUA \
		OPENEXR RAW PANGO POPPLER LIBRSVG2 SDL SPIRO V4L WEBP TIFF

ENSCRIPT_DESC=	Enscript support
SPIRO_DESC=	Spiro support
#UMFPACK_DESC=	UMFpack support
GEXIV2_DESC=	EXIF and IPTC metadata support via gexiv2

PIXBUF_USE=	GNOME=gdkpixbuf2
PIXBUF_CONFIGURE_WITH=	gdk-pixbuf

CAIRO_USE=	GNOME=cairo
CAIRO_CONFIGURE_WITH=	cairo

PANGO_USE=	GNOME=pango
PANGO_CONFIGURE_WITH=	pango

POPPLER_LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib
POPPLER_CONFIGURE_WITH=	popplerglib

ENSCRIPT_BUILD_DEPENDS=	enscript:print/enscript-a4

FFMPEG_LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg
FFMPEG_CONFIGURE_WITH=	libavformat

GRAPHVIZ_LIB_DEPENDS=	libcgraph.so:graphics/graphviz
GRAPHVIZ_CONFIGURE_WITH=	graphviz

JASPER_LIB_DEPENDS=	libjasper.so:graphics/jasper
JASPER_CONFIGURE_WITH=	jasper

LCMS2_LIB_DEPENDS=	liblcms2.so:graphics/lcms2
LCMS2_CONFIGURE_OFF=	--without-lcms

LUA_USES=		lua
LUA_CONFIGURE_WITH=	lua

OPENEXR_LIB_DEPENDS=	libIlmImf.so:graphics/openexr \
			libImath.so:graphics/ilmbase
OPENEXR_CONFIGURE_WITH=	openexr

RAW_LIB_DEPENDS=	libraw.so:graphics/libraw
RAW_CONFIGURE_WITH=	libraw

LIBRSVG2_USE=		GNOME=librsvg2
LIBRSVG2_CONFIGURE_OFF=	--without-librsvg

SDL_USE=		SDL=sdl
SDL_USES=		sdl
SDL_CONFIGURE_WITH=	sdl

SPIRO_LIB_DEPENDS=	libspiro.so:graphics/libspiro
SPIRO_CONFIGURE_WITH=	libspiro

V4L_BUILD_DEPENDS=	v4l_compat>=0:multimedia/v4l_compat
V4L_LIB_DEPENDS=	libv4l2.so:multimedia/libv4l
V4L_CONFIGURE_WITH=	libv4l
V4L_VARS=		LICENSE+=LGPL20+

WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_CONFIGURE_WITH=	webp

# UMFPACK has two "problems"
# 1) it build with port gcc 2) needed libs aren't recorded in the libraries.
#UMFPACK_LIB_DEPENDS=	libumfpack.so:math/suitesparse
#UMFPACK_CONFIGURE_WITH=	umfpack
CONFIGURE_ARGS+=	--without-umfpack

GEXIV2_LIB_DEPENDS=	libgexiv2.so:graphics/gexiv2
GEXIV2_CONFIGURE_WITH=	gexiv2

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_CONFIGURE_WITH=	libtiff

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPANGO} && ${PORT_OPTIONS:MCAIRO}
PLIST_SUB+=	PANGOCAIRO=""
.else
CONFIGURE_ARGS+=--without-pangocairo
PLIST_SUB+=	PANGOCAIRO="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e "s/lua >/lua-${LUA_VER} >/g" \
		-e 's|\(lua\)\(5\.1\)|\1-\2|g ; s|x86_64|amd64|g' \
		${WRKSRC}/configure
.if ${CHOSEN_COMPILER_TYPE} == clang
	${REINPLACE_CMD} -e '/altivec.h/d' ${WRKSRC}/gegl/opencl/cl_platform.h
.endif

post-patch-EXAMPLES-off:
	${REINPLACE_CMD} -e 's|tools examples|tools|g' \
		${WRKSRC}/Makefile.in

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/data
	${INSTALL_DATA} ${WRKSRC}/examples/data/surfer.png ${STAGEDIR}${EXAMPLESDIR}/data
.for ex in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${ex}.c ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.post.mk>
