# Created by: gahr
# $FreeBSD$

PORTNAME=	gegl
PORTVERSION=	0.2.0
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gimp.org/pub/gegl/0.2/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Graph based image processing framework

LIB_DEPENDS=	babl-0.1:${PORTSDIR}/x11/babl

OPTIONS_DEFINE=	CAIRO ENSCRIPT EXIV2 FFMPEG PIXBUF GRAPHVIZ JASPER JPEG \
		LUA OPENEXR OPENRAW SIMD PANGO PNG LIBRSVG2 SDL SPIRO V4L
OPTIONS_DEFAULT=CAIRO ENSCRIPT EXIV2 PIXBUF GRAPHVIZ JASPER JPEG LUA \
		OPENEXR OPENRAW PANGO PNG LIBRSVG2 SDL SPIRO V4L

ENSCRIPT_DESC=	Enscript support
SPIRO_DESC=	Spiro support
#UMFPACK_DESC=	UMFpack support

USE_GNOME=	glib20 intltool
USES=		gettext pathfix pkgconfig shebangfix
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	${PREFIX}/lib/gegl-0.2
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	ac_cv_header_execinfo_h=no
CONFIGURE_ARGS+=--without-vala --disable-docs
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

GEGL_MINOR=	199
GEGL_VER=	0.2
PLIST_SUB+=	GEGL_MINOR="${GEGL_MINOR}" GEGL_VER=${GEGL_VER}

EXAMPLES=	2geglbuffer csugar float-lookup \
		gegl-convert gegl-slicer geglbuffer-add-image \
		geglbuffer-clock hello-world-video hello-world

SHEBANG_FILES=	tools/xml_insert.sh

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPIXBUF}
USE_GNOME+=	gdkpixbuf2
PLIST_SUB+=	GDK=""
.else
CONFIGURE_ARGS+=--without-gdk-pixbuf
PLIST_SUB+=	GDK="@comment "
.endif

.if ${PORT_OPTIONS:MCAIRO}
LIB_DEPENDS+=	cairo:${PORTSDIR}/graphics/cairo
PLIST_SUB+=	CAIRO=""
.else
CONFIGURE_ARGS+=--without-cairo
PLIST_SUB+=	CAIRO="@comment "
.endif

.if ${PORT_OPTIONS:MPANGO}
USE_GNOME+=	pango
PLIST_SUB+=	PANGO=""
.else
CONFIGURE_ARGS+=--without-pango
PLIST_SUB+=	PANGO="@comment "
.endif

.if ${PORT_OPTIONS:MPANGO} && ${PORT_OPTIONS:MCAIRO}
PLIST_SUB+=	PANGOCAIRO=""
.else
CONFIGURE_ARGS+=--without-pangocairo
PLIST_SUB+=	PANGOCAIRO="@comment "
.endif

.if ${PORT_OPTIONS:MENSCRIPT}
BUILD_DEPENDS+=	enscript:${PORTSDIR}/print/enscript-a4
.endif

.if ${PORT_OPTIONS:MFFMPEG}
LIB_DEPENDS+=	avformat:${PORTSDIR}/multimedia/ffmpeg
PLIST_SUB+=	FFMPEG=""
.else
CONFIGURE_ARGS+=--without-libavformat
PLIST_SUB+=	FFMPEG="@comment "
.endif

.if ${PORT_OPTIONS:MGRAPHVIZ}
LIB_DEPENDS+=	cgraph:${PORTSDIR}/graphics/graphviz
.else
CONFIGURE_ARGS+=--without-graphviz
.endif

.if ${PORT_OPTIONS:MJASPER}
LIB_DEPENDS+=	jasper:${PORTSDIR}/graphics/jasper
PLIST_SUB+=	JP2=""
.else
CONFIGURE_ARGS+=--without-jasper
PLIST_SUB+=	JP2="@comment "
.endif

.if ${PORT_OPTIONS:MJPEG}
LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg
PLIST_SUB+=	JPEG=""
.else
CONFIGURE_ARGS+=--without-libjpeg
PLIST_SUB+=	JPEG="@comment "
.endif

.if ${PORT_OPTIONS:MLUA}
USE_LUA=	5.1
.else
CONFIGURE_ARGS+=--without-lua
.endif

.if ${PORT_OPTIONS:MOPENEXR}
LIB_DEPENDS+=	IlmImf:${PORTSDIR}/graphics/OpenEXR
PLIST_SUB+=	OPENEXR=""
.else
CONFIGURE_ARGS+=--without-openexr
PLIST_SUB+=	OPENEXR="@comment "
.endif

.if ${PORT_OPTIONS:MOPENRAW}
LIB_DEPENDS+=	openraw:${PORTSDIR}/graphics/libopenraw
PLIST_SUB+=	OPENRAW=""
.else
CONFIGURE_ARGS+=--without-libopenraw
PLIST_SUB+=	OPENRAW="@comment "
.endif

.if ${PORT_OPTIONS:MSIMD}
CONFIGURE_ARGS+=--disable-mmx \
		--disable-sse
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png
PLIST_SUB+=	PNG=""
.else
CONFIGURE_ARGS+=--without-libpng
PLIST_SUB+=	PNG="@comment "
.endif

.if ${PORT_OPTIONS:MLIBRSVG2}
LIB_DEPENDS+=	rsvg-2:${PORTSDIR}/graphics/librsvg2
PLIST_SUB+=	RSVG=""
.else
CONFIGURE_ARGS+=--without-librsvg
PLIST_SUB+=	RSVG="@comment "
.endif

.if ${PORT_OPTIONS:MSDL}
USE_SDL=	sdl
PLIST_SUB+=	SDL=""
.else
CONFIGURE_ARGS+=--without-sdl
PLIST_SUB+=	SDL="@comment "
.endif

.if ${PORT_OPTIONS:MSPIRO}
LIB_DEPENDS+=	spiro:${PORTSDIR}/graphics/libspiro
.else
CONFIGURE_ARGS+=--without-libspiro
.endif

.if ${PORT_OPTIONS:MV4L}
BUILD_DEPENDS+=	${LOCALBASE}/include/linux/videodev.h:${PORTSDIR}/multimedia/v4l_compat
PLIST_SUB+=	V4L=""
.else
CONFIGURE_ARGS+=--without-libv4l
PLIST_SUB+=	V4L="@comment "
.endif

# umfpack library is broken
#.if ${PORT_OPTIONS:MUMFPACK}
#LIB_DEPENDS+=	umfpack:${PORTSDIR}/math/suitesparse
#PLIST_SUB+=	UMFPACK=""
#.else
CONFIGURE_ARGS+=--without-umfpack
PLIST_SUB+=	UMFPACK="@comment "
#.endif

.if ${PORT_OPTIONS:MEXIV2}
LIB_DEPENDS+=	exiv2:${PORTSDIR}/graphics/exiv2
PLIST_SUB+=	EXIV2=""
.else
CONFIGURE_ARGS+=--without-exiv2
PLIST_SUB+=	EXIV2="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	a2x:${PORTSDIR}/textproc/asciidoc \
		${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash \
		vimdot:${PORTSDIR}/graphics/graphviz
USE_RUBY=	yes
RUBY_NO_RUN_DEPENDS=yes
.else
CONFIGURE_ARGS+=--disable-docs
.endif

post-patch:
.if ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e 's|tools examples|tools|g' \
		${WRKSRC}/Makefile.in
.endif
	${REINPLACE_CMD} -e 's|\(lua\)\(5\.1\)|\1-\2|g ; s|x86_64|amd64|g' \
		${WRKSRC}/configure

.if ${PORT_OPTIONS:MDOCS}
pre-configure:
.if !exists(${LOCALBASE}/bin/vimdot)
	@${ECHO_CMD} "${PKGNAME}: Needs graphics/graphviz with PANGOCAIRO support enabled."
	@${FALSE}
.endif
.endif

post-build:
.if ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC}/docs && ${GMAKE} index.html
	cd ${WRKSRC}/docs/gallery && ${GMAKE} index.html
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/gallery
	(cd ${WRKSRC}/docs && \
	    ${COPYTREE_SHARE} \*.html ${DOCSDIR} && \
	    ${INSTALL_DATA} ChangeLog gegl.css gegl.devhelp devhelp.css ${DOCSDIR} && \
	    ${INSTALL_DATA} gallery/OpenRaster* ${DOCSDIR}/gallery && \
	    ${INSTALL_DATA} gallery/clones* ${DOCSDIR}/gallery && \
	    ${INSTALL_DATA} gallery/index.html ${DOCSDIR}/gallery )
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}/data
	${INSTALL_DATA} ${WRKSRC}/examples/data/surfer.png ${EXAMPLESDIR}/data
.for ex in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${ex}.c ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
