PORTNAME=	gegl
DISTVERSION=	0.4.62
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	GIMP

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Graph based image processing framework
WWW=		https://gegl.org/

LICENSE=	BSD3CLAUSE GPLv3+ LGPL3+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING
LICENSE_FILE_LGPL3+ =	${WRKSRC}/COPYING.LESSER

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libbabl-0.1.so:x11/babl \
		libjson-glib-1.0.so:devel/json-glib \
		libnsgif.so:graphics/libnsgif \
		libpng.so:graphics/png

USES=		compiler:c++14-lang cpe gettext gnome jpeg localbase:ldflags \
		meson pkgconfig shebangfix uniquefiles tar:xz
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes

SHEBANG_FILES=	tools/xml_insert.sh

MESON_ARGS=	-Ddocs=false \
		-Dgi-docgen=disabled \
		-Dworkshop=false \
		-Dintrospection=true \
		-Dlensfun=disabled \
		-Dlibjpeg=enabled \
		-Dlibpng=enabled \
		-Dmaxflow=disabled \
		-Dmrg=disabled \
		-Dpygobject=disabled \
		-Dlua=disabled
.if !exists(/usr/include/omp.h)
MESON_ARGS+=	-Dopenmp=disabled
.endif

GEGL_SHLIB=	0.461.1
GEGL_VER=	0.4
PLIST_SUB+=	GEGL_SHLIB=${GEGL_SHLIB} GEGL_VER=${GEGL_VER}

OPTIONS_DEFINE=		CAIRO ENSCRIPT FFMPEG GEXIV2 GRAPHVIZ JASPER LCMS2 LIBRSVG2 \
			OPENEXR PANGO PIXBUF POPPLER RAW SDL SPIRO TIFF UMFPACK V4L \
			VAPI WEBP
OPTIONS_DEFAULT=	CAIRO ENSCRIPT FFMPEG GEXIV2 GRAPHVIZ JASPER LCMS2 LIBRSVG2 \
			OPENEXR PANGO PIXBUF POPPLER RAW SDL SPIRO TIFF UMFPACK V4L \
			VAPI WEBP
OPTIONS_EXCLUDE_i386=	GEXIV2
OPTIONS_SUB=		yes

ENSCRIPT_DESC=		Enscript support
GEXIV2_DESC=		EXIF and IPTC metadata support via gexiv2
SPIRO_DESC=		Spiro support
UMFPACK_DESC=		UMFpack support

CAIRO_USE=		GNOME=cairo
CAIRO_MESON_ENABLED=	cairo

ENSCRIPT_BUILD_DEPENDS=	enscript:print/enscript-a4

FFMPEG_LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg
FFMPEG_MESON_ENABLED=	libav

GEXIV2_LIB_DEPENDS=	libgexiv2.so:graphics/gexiv2
GEXIV2_MESON_ENABLED=	gexiv2

GRAPHVIZ_BUILD_DEPENDS=	dot:graphics/graphviz
GRAPHVIZ_RUN_DEPENDS=	dot:graphics/graphviz
GRAPHVIZ_MESON_ENABLED=	graphviz

JASPER_LIB_DEPENDS=	libjasper.so:graphics/jasper
JASPER_MESON_ENABLED=	jasper

LCMS2_LIB_DEPENDS=	liblcms2.so:graphics/lcms2
LCMS2_MESON_ENABLED=	lcms

LIBRSVG2_IMPLIES=	CAIRO
LIBRSVG2_USE=		GNOME=librsvg2
LIBRSVG2_MESON_ENABLED=	librsvg

OPENEXR_LIB_DEPENDS=	libOpenEXR.so:graphics/openexr \
			libImath.so:math/Imath
OPENEXR_MESON_ENABLED=	openexr

PANGO_IMPLIES=		CAIRO
PANGO_USE=		GNOME=pango
PANGO_MESON_ENABLED=	pango pangocairo

PIXBUF_USE=		GNOME=gdkpixbuf
PIXBUF_MESON_ENABLED=	gdk-pixbuf

POPPLER_IMPLIES=	CAIRO
POPPLER_LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib
POPPLER_MESON_ENABLED=	poppler

RAW_LIB_DEPENDS=	libraw.so:graphics/libraw
RAW_MESON_ENABLED=	libraw

SDL_USES=		sdl
SDL_USE=		SDL=sdl2
SDL_MESON_ENABLED=	sdl2

SPIRO_LIB_DEPENDS=	libspiro.so:graphics/libspiro
SPIRO_MESON_ENABLED=	libspiro

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_MESON_ENABLED=	libtiff

UMFPACK_LIB_DEPENDS=	libumfpack.so:math/suitesparse-umfpack
UMFPACK_MESON_ENABLED=	umfpack

V4L_BUILD_DEPENDS=	libv4l>0:multimedia/libv4l \
			v4l_compat>=0:multimedia/v4l_compat
V4L_RUN_DEPENDS=	libv4l>0:multimedia/libv4l
V4L_MESON_ENABLED=	libv4l libv4l2
V4L_VARS=		LICENSE+=LGPL20+

VAPI_USES=		vala:build
VAPI_MESON_ENABLED=	vapigen

WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_MESON_ENABLED=	webp

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
LDFLAGS+=	-lexecinfo
.endif

.if ${ARCH} == "amd64"
PLIST_SUB+=	AMD64="" ARM="@comment "
.elif ${ARCH} == "armv6" || ${ARCH} == "armv7"
PLIST_SUB+=	AMD64="@comment " ARM=""
.else
PLIST_SUB+=	AMD64="@comment " ARM="@comment "
.endif

.include <bsd.port.post.mk>
