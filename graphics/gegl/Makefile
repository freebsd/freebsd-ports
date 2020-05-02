# Created by: Pietro Cerutti <gahr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gegl
PORTVERSION=	0.4.22
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	GIMP

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Graph based image processing framework

LICENSE=	BSD3CLAUSE GPLv3+ LGPL3+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING
LICENSE_FILE_LGPL3+ =	${WRKSRC}/COPYING.LESSER

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libbabl-0.1.so:x11/babl \
		libjson-glib-1.0.so:devel/json-glib \
		libfribidi.so:converters/fribidi \
		libnsgif.so:graphics/libnsgif \
		libpng.so:graphics/png

USES=		compiler:c++14-lang cpe gettext gnome jpeg localbase \
		meson pathfix pkgconfig shebangfix uniquefiles tar:xz
USE_GNOME=	glib20 intltool introspection:build
USE_LDCONFIG=	yes
MESON_ARGS=	-Ddocs=false \
		-Dworkshop=false \
		-Dintrospection=true \
		-Dvapigen=disabled \
		-Dlensfun=disabled \
		-Dlibjpeg=enabled \
		-Dlibpng=enabled \
		-Dmrg=disabled \
		-Dpygobject=disabled \
		-Dvapigen=disabled \
		-Dlua=disabled

GEGL_SHLIB=	0.421.1
GEGL_VER=	0.4
PLIST_SUB+=	GEGL_SHLIB=${GEGL_SHLIB} GEGL_VER=${GEGL_VER}

SHEBANG_FILES=	tools/xml_insert.sh

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	CAIRO ENSCRIPT FFMPEG PIXBUF GRAPHVIZ JASPER \
		OPENEXR RAW PANGO POPPLER LIBRSVG2 SDL SPIRO V4L \
		LCMS2 WEBP TIFF GEXIV2
OPTIONS_DEFAULT=CAIRO ENSCRIPT GEXIV2 PIXBUF GRAPHVIZ JASPER LCMS2 \
		OPENEXR RAW PANGO POPPLER LIBRSVG2 SDL SPIRO V4L WEBP TIFF

PIXBUF_USE=	GNOME=gdkpixbuf2
PIXBUF_MESON_ENABLED=	gdk-pixbuf

CAIRO_USE=	GNOME=cairo
CAIRO_MESON_ENABLED=	cairo

PANGO_USE=	GNOME=pango
PANGO_MESON_ENABLED=	pango

POPPLER_LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib
POPPLER_MESON_ENABLED=	poppler

ENSCRIPT_DESC=		Enscript support
ENSCRIPT_BUILD_DEPENDS=	enscript:print/enscript-a4

FFMPEG_LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg
FFMPEG_MESON_ENABLED=	libav

GRAPHVIZ_LIB_DEPENDS=	libcgraph.so:graphics/graphviz
GRAPHVIZ_MESON_ENABLED=	graphviz

JASPER_LIB_DEPENDS=	libjasper.so:graphics/jasper
JASPER_MESON_ENABLED=	jasper

LCMS2_LIB_DEPENDS=	liblcms2.so:graphics/lcms2
LCMS2_MESON_ENABLED=	lcms

OPENEXR_LIB_DEPENDS=	libIlmImf.so:graphics/openexr \
			libImath.so:graphics/ilmbase
OPENEXR_MESON_ENABLED=	openexr

RAW_LIB_DEPENDS=	libraw.so:graphics/libraw
RAW_MESON_ENABLED=	libraw

LIBRSVG2_USE=		GNOME=librsvg2
LIBRSVG2_MESON_ENABLED=	librsvg

SDL_USE=		SDL=sdl2
SDL_USES=		sdl
SDL_MESON_ENABLED=	sdl2

SPIRO_DESC=		Spiro support
SPIRO_LIB_DEPENDS=	libspiro.so:graphics/libspiro
SPIRO_MESON_ENABLED=	libspiro

V4L_BUILD_DEPENDS=	v4l_compat>=0:multimedia/v4l_compat
V4L_LIB_DEPENDS=	libv4l2.so:multimedia/libv4l
V4L_MESON_ENABLED=	libv4l2
V4L_VARS=		LICENSE+=LGPL20+

WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_MESON_ENABLED=	webp

# UMFPACK has two "problems"
# 1) it build with port gcc 2) needed libs aren't recorded in the libraries.
#UMFPACK_DESC=		UMFpack support
#UMFPACK_LIB_DEPENDS=	libumfpack.so:math/suitesparse
#UMFPACK_MESON_ENABLED=	umfpack
MESON_ARGS+=		-Dumfpack=disabled

GEXIV2_DESC=		EXIF and IPTC metadata support via gexiv2
GEXIV2_LIB_DEPENDS=	libgexiv2.so:graphics/gexiv2
GEXIV2_MESON_ENABLED=	gexiv2

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_MESON_ENABLED=	libtiff

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPANGO} && ${PORT_OPTIONS:MCAIRO}
PLIST_SUB+=	PANGOCAIRO=""
MESON_ARGS+=	-Dpangocairo=enabled
.else
MESON_ARGS+=	-Dpangocairo=disabled
PLIST_SUB+=	PANGOCAIRO="@comment "
.endif

post-patch:
.if ${CHOSEN_COMPILER_TYPE} == clang
	${REINPLACE_CMD} -e '/altivec.h/d' ${WRKSRC}/gegl/opencl/cl_platform.h
.endif

.include <bsd.port.post.mk>
