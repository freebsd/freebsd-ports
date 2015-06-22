# Created by: Pietro Cerutti <gahr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gegl
PORTVERSION=	0.3.0.a1
CATEGORIES=	graphics
#MASTER_SITES=	GIMP
MASTER_SITES=	LOCAL/kwm
PKGNAMESUFFIX=	3
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.a1//}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Graph based image processing framework (0.3.0 snapshot)

LIB_DEPENDS=	libbabl-0.1.so:${PORTSDIR}/x11/babl \
		libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib

USES=		gettext gmake libtool pathfix pkgconfig shebangfix tar:bzip2
USE_GNOME=	glib20 intltool introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_header_execinfo_h=no
CONFIGURE_ARGS=	--without-vala --disable-docs
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GEGL_MINOR=	299
GEGL_VER=	0.3
PLIST_SUB+=	GEGL_MINOR="${GEGL_MINOR}" GEGL_VER=${GEGL_VER}

EXAMPLES=	2geglbuffer \
		gegl-convert gegl-slicer geglbuffer-add-image \
		geglbuffer-clock hello-world sdl-draw

SHEBANG_FILES=	tools/xml_insert.sh

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	CAIRO ENSCRIPT EXIV2 FFMPEG PIXBUF GRAPHVIZ JASPER JPEG \
		LUA OPENEXR OPENRAW SIMD PANGO PNG LIBRSVG2 SDL SPIRO V4L \
		EXAMPLES LCMS2 WEBP
#		DOCS EXAMPLES
OPTIONS_DEFAULT=CAIRO ENSCRIPT EXIV2 PIXBUF GRAPHVIZ JASPER JPEG LCMS2 LUA \
		OPENEXR OPENRAW PANGO PNG LIBRSVG2 SDL SPIRO V4L WEBP

ENSCRIPT_DESC=	Enscript support
SPIRO_DESC=	Spiro support
#UMFPACK_DESC=	UMFpack support

PIXBUF_USE=	GNOME=gdkpixbuf2
PIXBUF_CONFIGURE_WITH=	gdk-pixbuf

CAIRO_USE=	GNOME=cairo
CAIRO_CONFIGURE_WITH=	cairo

PANGO_USE=	GNOME=pango
PANGO_CONFIGURE_WITH=	pango

MENSCRIPT_BUILD_DEPENDS=	enscript:${PORTSDIR}/print/enscript-a4

FFMPEG_LIB_DEPENDS=	libavformat.so:${PORTSDIR}/multimedia/ffmpeg
FFMPEG_CONFIGURE_WITH=	libavformat

GRAPHVIZ_LIB_DEPENDS=	libcgraph.so:${PORTSDIR}/graphics/graphviz
GRAPHVIZ_CONFIGURE_WITH=	graphviz

JASPER_LIB_DEPENDS=	libjasper.so:${PORTSDIR}/graphics/jasper
JASPER_CONFIGURE_WITH=	jasper

JPEG_USES=		jpeg
JPEG_CONFIGURE_WITH=	libjpeg

LCMS2_LIB_DEPENDS=	liblcms2.so:${PORTSDIR}/graphics/lcms2
LCMS2_CONFIGURE_WITH=	lcms

LUA_USES=		lua
LUA_CONFIGURE_WITH=	lua

OPENEXR_LIB_DEPENDS=	libIlmImf.so:${PORTSDIR}/graphics/OpenEXR
OPENEXR_CONFIGURE_WITH=	openexr

OPENRAW_LIB_DEPENDS=	libopenraw.so:${PORTSDIR}/graphics/libopenraw
OPENRAW_CONFIGURE_WITH=	libopenraw

SIMD_CONFIGURE_DISABLE=	mmx sse

PNG_LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png
PNG_CONFIGURE_WITH=	libpng

LIBRSVG2_USE=		GNOME=librsvg2
LIBRSVG2_CONFIGURE_WITH=	librsvg

SDL_USE=		SDL=sdl
SDL_CONFIGURE_WITH=	sdl

SPIRO_LIB_DEPENDS=	libspiro.so:${PORTSDIR}/graphics/libspiro
SPIRO_CONFIGURE_WITH=	libspiro

V4L_BUILD_DEPENDS=	v4l_compat>=0:${PORTSDIR}/multimedia/v4l_compat
V4L_LIB_DEPENDS=	libv4l2.so:${PORTSDIR}/multimedia/libv4l
V4L_CONFIGURE_WITH=	libv4l

WEBP_LIB_DEPENDS=	libwebp.so:${PORTSDIR}/graphics/webp
WEBP_CONFIGURE_WITH=	webp

# UMFPACK has two "problems"
# 1) it build with port gcc 2) needed libs aren't recorded in the libraries.
#UMFPACK_LIB_DEPENDS=	libumfpack.so:${PORTSDIR}/math/suitesparse
#UMFPACK_CONFIGURE_WITH=	umfpack
CONFIGURE_ARGS+=	--without-umfpack

EXIV2_LIB_DEPENDS=	libexiv2.so:${PORTSDIR}/graphics/exiv2
EXIV2_CONFIGURE_WITH=	exiv2

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPANGO} && ${PORT_OPTIONS:MCAIRO}
PLIST_SUB+=	PANGOCAIRO=""
.else
CONFIGURE_ARGS+=--without-pangocairo
PLIST_SUB+=	PANGOCAIRO="@comment "
.endif

#.if ${PORT_OPTIONS:MDOCS}
#BUILD_DEPENDS+=	a2x:${PORTSDIR}/textproc/asciidoc \
#		${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash \
#		vimdot:${PORTSDIR}/graphics/graphviz
#USE_RUBY=	yes
#RUBY_NO_RUN_DEPENDS=yes
#.else
#CONFIGURE_ARGS+=--disable-docs
#.endif

post-patch:
	${REINPLACE_CMD} "s/lua >/lua-${LUA_VER} >/g" ${WRKSRC}/configure
.if ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e 's|tools examples|tools|g' \
		${WRKSRC}/Makefile.in
.endif
	${REINPLACE_CMD} -e 's|\(lua\)\(5\.1\)|\1-\2|g ; s|x86_64|amd64|g' \
		${WRKSRC}/configure

#.if ${PORT_OPTIONS:MDOCS}
#pre-configure:
#.if !exists(${LOCALBASE}/bin/vimdot)
#	@${ECHO_CMD} "${PKGNAME}: Needs graphics/graphviz with PANGOCAIRO support enabled."
#	@${FALSE}
#.endif
#.endif

#post-build:
#.if ${PORT_OPTIONS:MDOCS}
#	cd ${WRKSRC}/docs && ${MAKE_CMD} index.html
#.endif

post-install:
#.if ${PORT_OPTIONS:MDOCS}
#	${MKDIR} ${STAGEDIR}${DOCSDIR}/gallery
#	(cd ${WRKSRC}/docs && \
#	    ${COPYTREE_SHARE} \*.html ${STAGEDIR}${DOCSDIR} && \
#	    ${INSTALL_DATA} ChangeLog gegl.css gegl.devhelp devhelp.css ${STAGEDIR}${DOCSDIR} && \
#	    ${INSTALL_DATA} gallery/OpenRaster* ${STAGEDIR}${DOCSDIR}/gallery && \
#	    ${INSTALL_DATA} gallery/clones* ${STAGEDIR}${DOCSDIR}/gallery && \
#	    ${INSTALL_DATA} gallery/index.html ${STAGEDIR}${DOCSDIR}/gallery )
#.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/data
	${INSTALL_DATA} ${WRKSRC}/examples/data/surfer.png ${STAGEDIR}${EXAMPLESDIR}/data
.for ex in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${ex}.c ${STAGEDIR}${EXAMPLESDIR}
.endfor
.endif
# temporary hacks to allow parallel install
	@${MV} ${STAGEDIR}${PREFIX}/bin/gegl ${STAGEDIR}${PREFIX}/bin/gegl3
	@${MV} ${STAGEDIR}${PREFIX}/share/examples/gegl \
		${STAGEDIR}${PREFIX}/share/examples/gegl3
.include <bsd.port.mk>
