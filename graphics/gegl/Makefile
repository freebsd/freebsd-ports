# New ports collection Makefile for:	gegl
# Date created:				3 October 2008
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	gegl
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gimp.org/pub/gegl/0.1/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A graph based image processing framework

LIB_DEPENDS=	babl-0.1:${PORTSDIR}/x11/babl \
    		execinfo.1:${PORTSDIR}/devel/libexecinfo

OPTIONS=	CAIRO		"Enable Cairo" on \
		ENSCRIPT	"Enable Enscript" on \
		FFMPEG		"Enable videos through ffmpeg (BROKEN)" off \
		GRAPHVIZ	"Enable Graphviz" on \
		JPEG		"Enable JPEG format support" on \
		LUA		"Enable LUA" on \
		OPENEXR		"Enable High Dynamic Range (HDR) format support" on \
		OPENRAW		"Enable RAW camera format support" on \
		OPTIMIZE	"Enable optimizations autodetection (MMX, SSE)" off \
		PANGO		"Enable rendering through Pango " on \
		PNG		"Enable PNG format support" on \
		RSVG		"Enable RSVG format support" on \
		SDL		"Enable SDL" on \
		SPIRO		"Enable Spiro" on \
		V4L		"Enable Video4Linux" on

# Disable docs until I fix the problem with graphviz's dot
NOPORTDOCS=	yes

USE_GNOME=	gtk20 glib20 pkgconfig gnomehack
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_RUBY=	yes
RUBY_NO_RUN_DEPENDS=	yes
USE_LDCONFIG=	${PREFIX}/lib/gegl-0.1
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lexecinfo"

GEGL_MINOR=	101
PLIST_SUB+=	GEGL_MINOR="${GEGL_MINOR}"

EXAMPLES=	2geglbuffer gegl-paint geglbuffer-add-image \
		geglbuffer-clock hello-world hello-world-video

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_CAIRO)
LIB_DEPENDS+=	cairo.2:${PORTSDIR}/graphics/cairo
PLIST_SUB+=	CAIRO=""
.else
CONFIGURE_ARGS+=--without-cairo
PLIST_SUB+=	CAIRO="@comment "
.endif

.if !defined(WITHOUT_ENSCRIPT)
BUILD_DEPENDS+=	enscript:${PORTSDIR}/print/enscript-a4
.endif

.if !defined(WITHOUT_FFMPEG)
BROKEN=	ffmpeg support is currently broken
LIB_DEPENDS+=	avformat.1:${PORTSDIR}/multimedia/ffmpeg
PLIST_SUB+=	FFMPEG=""
.else
CONFIGURE_ARGS+=--without-libavformat
PLIST_SUB+=	FFMPEG="@comment "
.endif

.if !defined(WITHOUT_GRAPHVIZ)
LIB_DEPENDS+=	graph.4:${PORTSDIR}/graphics/graphviz
.else
CONFIGURE_ARGS+=--without-graphviz
.endif

.if !defined(WITHOUT_JPEG)
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg
PLIST_SUB+=	JPEG=""
.else
CONFIGURE_ARGS+=--without-libjpeg
PLIST_SUB+=	JPEG="@comment "
.endif

.if !defined(WITHOUT_LUA)
USE_LUA=	5.1
.else
CONFIGURE_ARGS+=--without-lua
.endif

.if !defined(WITHOUT_OPENEXR)
LIB_DEPENDS+=	IlmImf.6:${PORTSDIR}/graphics/OpenEXR
PLIST_SUB+=	OPENEXR=""
.else
CONFIGURE_ARGS+=--without-openexr
PLIST_SUB+=	OPENEXR="@comment "
.endif

.if !defined(WITHOUT_OPENRAW)
LIB_DEPENDS+=	openraw.6:${PORTSDIR}/graphics/libopenraw
PLIST_SUB+=	OPENRAW=""
.else
CONFIGURE_ARGS+=--without-libopenraw
PLIST_SUB+=	OPENRAW="@comment "
.endif

.if defined(WITHOUT_OPTIMIZE)
CONFIGURE_ARGS+=--disable-mmx \
		--disable-sse
.endif

.if !defined(WITHOUT_PANGO)
USE_GNOME+=	pango
.else
CONFIGURE_ARGS+=--without-pango
.endif

.if !defined(WITHOUT_PNG)
LIB_DEPENDS+=	png.6:${PORTSDIR}/graphics/png
PLIST_SUB+=	PNG=""
.else
CONFIGURE_ARGS+=--without-libpng
PLIST_SUB+=	PNG="@comment "
.endif

.if !defined(WITHOUT_RSVG)
LIB_DEPENDS+=	rsvg-2.2:${PORTSDIR}/graphics/librsvg2
PLIST_SUB+=	RSVG=""
.else
CONFIGURE_ARGS+=--without-librsvg
PLIST_SUB+=	RSVG="@comment "
.endif

.if !defined(WITHOUT_SDL)
USE_SDL=	sdl
PLIST_SUB+=	SDL=""
.else
CONFIGURE_ARGS+=--without-sdl
PLIST_SUB+=	SDL="@comment "
.endif

.if !defined(WITHOUT_SPIRO)
LIB_DEPENDS+=	spiro.0:${PORTSDIR}/graphics/libspiro
.else
CONFIGURE_ARGS+=--without-libspiro
.endif

.if !defined(WITHOUT_V4L)
BUILD_DEPENDS+=	${LOCALBASE}/include/linux/videodev.h:${PORTSDIR}/multimedia/v4l_compat
PLIST_SUB+=	V4L=""
.else
CONFIGURE_ARGS+=--without-libv4l
PLIST_SUB+=	V4L="@comment "
.endif

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	a2x:${PORTSDIR}/textproc/asciidoc
.else
CONFIGURE_ARGS+=	--disable-docs
.endif

post-patch:
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e '11,13d' ${WRKSRC}/Makefile.am
.endif
	${REINPLACE_CMD} -e 's|-T||' ${WRKSRC}/docs/Makefile.am ${WRKSRC}/docs/Makefile.in
	${REINPLACE_CMD} -e 's|\(lua\)\(5\.1\)|\1-\2|g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|/usr/bin/ruby|/usr/bin/env ruby|' ${WRKSRC}/tools/gobj2dot.rb

post-build:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/docs && ${GMAKE}
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/gallery
	(cd ${WRKSRC}/docs && \
	    ${COPYTREE_SHARE} \*.html ${DOCSDIR} && \
	    ${INSTALL_DATA} ChangeLog gegl.css gegl.devhelp devhelp.css ${DOCSDIR} && \
	    ${INSTALL_DATA} gallery/OpenRaster* ${DOCSDIR}/gallery && \
	    ${INSTALL_DATA} gallery/clones* ${DOCSDIR}/gallery && \
	    ${INSTALL_DATA} gallery/index.html ${DOCSDIR}/gallery )
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}/data
	${INSTALL_DATA} ${WRKSRC}/examples/data/surfer.png ${EXAMPLESDIR}/data
.for ex in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${ex}.c ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.post.mk>
