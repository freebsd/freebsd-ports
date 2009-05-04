# New ports collection Makefile for:	gegl
# Date created:				3 October 2008
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	gegl
PORTVERSION=	0.0.${GEGL_MINOR}
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gimp.org/pub/gegl/0.0/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A graph based image processing framework

LIB_DEPENDS=	babl-0.0:${PORTSDIR}/x11/babl

OPTIONS=	CAIRO		"Enable Cairo" on \
		FFMPEG		"Enable videos through ffmpeg" on \
		GRAPHVIZ	"Enable Graphviz" on \
		JPEG		"Enable JPEG format support" on \
		OPENEXR		"Enable High Dynamic Range (HDR) format support" on \
		OPENRAW		"Enable RAW camera format support" on \
		PANGO		"Enable rendering through Pango " on \
		PNG		"Enable PNG format support" on \
		RSVG		"Enable RSVG format support" on \
		SPIRO		"Enable Spiro" on \
		SDL		"Enable SDL" on

USE_GNOME=	gtk20 glib20 pkgconfig gnomehack
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_RUBY=	build
USE_LDCONFIG=	${PREFIX}/lib/gegl-0.0
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		CFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=--disable-sse \
		--disable-mmx

GEGL_MINOR=	22
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

.if !defined(WITHOUT_FFMPEG)
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
LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg
PLIST_SUB+=	JPEG=""
.else
CONFIGURE_ARGS+=--without-libjpeg
PLIST_SUB+=	JPEG="@comment "
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

.if !defined(WITHOUT_PANGO)
USE_GNOME+=	pango
.else
CONFIGURE_ARGS+=--without-pango
.endif

.if !defined(WITHOUT_PNG)
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
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

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	a2x:${PORTSDIR}/textproc/asciidoc
.else
CONFIGURE_ARGS+=	--disable-docs
.endif

post-patch:
	${REINPLACE_CMD} -e 's|-T||' ${WRKSRC}/docs/Makefile.am ${WRKSRC}/docs/Makefile.in

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
