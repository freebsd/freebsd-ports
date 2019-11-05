# Created by: ijliao
# $FreeBSD$

PORTNAME=	images
PORTVERSION=	4.0.1
PORTREVISION=	9
PORTEPOCH=	2
CATEGORIES=	graphics
MASTER_SITES=	https://bitbucket.org/camlspotter/camlimages/get/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	v${PORTVERSION}
DIST_SUBDIR=	ocaml-images

MAINTAINER=	michael.grunewald@laposte.net
COMMENT=	Objective Caml image processing library

BUILD_DEPENDS=	${LOCALBASE}/share/aclocal/ocaml.m4:lang/ocaml-autoconf
BUILD_DEPENDS+=	omake:devel/omake

USE_OCAML=		yes
USE_OCAML_FINDLIB=	yes

OCAML_PKGDIRS=	camlimages
OCAML_LDLIBS=	${OCAML_SITELIBDIR}/camlimages

OMAKESUBS+=	-e s@%%INCLUDESPORTS%%@${LOCALBASE}/include@
OMAKESUBS+=	-e s@%%INCLUDESX11%%@${LOCALBASE}/include/X11@
OMAKESUBS+=	-e s@%%INCLUDESPNG%%@${LOCALBASE}/include/libpng15@
OMAKESUBS+=	-e s@%%LDFLAGSPORTS%%@-L${LOCALBASE}/lib@

OMAKE=		omake 'PREFIX=${STAGEDIR}${PREFIX}'
OMARGS=		--dotomake .omake --force-dotomake
WRKSRC=		${WRKDIR}/camlspotter-camlimages-c803efa9d5d3

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	PNG JPEG TIFF XPM GIF FREETYPE GHOSTSCRIPT GTK2 DOCS
OPTIONS_DEFAULT=PNG JPEG TIFF XPM GIF FREETYPE GHOSTSCRIPT
OPTIONS_SUB=	yes

PNG_CONFIGURE_WITH=	png
PNG_LIB_DEPENDS=	libpng.so:graphics/png

JPEG_CONFIGURE_WITH=	jpeg
JPEG_USES=		jpeg

TIFF_CONFIGURE_WITH=	tiff
TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff

XPM_CONFIGURE_WITH=	xpm

GIF_CONFIGURE_WITH=	gif
GIF_LIB_DEPENDS=	libgif.so:graphics/giflib

FREETYPE_CONFIGURE_WITH=freetype
FREETYPE_LIB_DEPENDS=	libttf.so:print/freetype \
			libfreetype.so:print/freetype2

GHOSTSCRIPT_CONFIGURE_WITH=	gs
GHOSTSCRIPT_USES=	ghostscript

GTK2_CONFIGURE_WITH=	liblgtk2
GTK2_BUILD_DEPENDS=	lablgtk2:x11-toolkits/ocaml-lablgtk2
GTK2_RUN_DEPENDS=	lablgtk2:x11-toolkits/ocaml-lablgtk2

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXPM}
USES+=		xorg
USE_XORG=	xpm
.endif

do-configure:
	@(cd ${WRKSRC} && ${REINPLACE_CMD} ${OMAKESUBS} OMakefile)
	(cd ${WRKSRC} && ${OMAKE} ${OMARGS} configure)

do-build:
	(cd ${WRKSRC} && ${OMAKE} ${OMARGS})

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${OCAML_LDLIBS}
	(cd ${WRKSRC} && ${OMAKE} ${OMARGS} install)

.include <bsd.port.mk>
