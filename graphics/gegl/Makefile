# New ports collection Makefile for:	gegl
# Date created:				3 October 2008
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	gegl
PORTVERSION=	0.0.${GEGL_MINOR}
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gimp.org/pub/gegl/0.0/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A graph based image processing framework

LIB_DEPENDS=	babl-0.0:${PORTSDIR}/x11/babl \
    		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		IlmImf.6:${PORTSDIR}/graphics/OpenEXR \
		cairo.2:${PORTSDIR}/graphics/cairo \
		avcodec.1:${PORTSDIR}/multimedia/ffmpeg \
		rsvg-2.2:${PORTSDIR}/graphics/librsvg2

USE_GNOME=	glib20 gtk20 pango pkgconfig gnomehack
USE_SDL=	sdl
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	${PREFIX}/lib/gegl-0.0
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		CFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GEGL_MINOR=	20
PLIST_SUB+=	GEGL_MINOR="${GEGL_MINOR}"

EXAMPLES=	2geglbuffer gegl-paint geglbuffer-add-image \
		geglbuffer-clock hello-world hello-world-video

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

.include <bsd.port.mk>
