PORTNAME=	images
PORTVERSION=	5.0.4
PORTEPOCH=	2
CATEGORIES=	graphics
PKGNAMEPREFIX=	ocaml-
DISTNAME=	v${PORTVERSION}

MAINTAINER=	michael.grunewald@laposte.net
COMMENT=	Objective Caml image processing library
WWW=		http://pauillac.inria.fr/camlimages/

LICENSE=	LGPL21

BUILD_DEPENDS=	cppo:devel/ocaml-cppo \
		${SA_DIR}/stdio/META:devel/ocaml-stdio

USES=		ocaml:dune
USE_GITLAB=	yes
GL_ACCOUNT=	camlspotter
GL_PROJECT=	camlimages
USE_OCAML=		yes
USE_OCAML_LDCONFIG=	yes
OCAML_LDLIBS=
OCAML_PACKAGES=		camlimages

DOCSDIR=	${OCAML_DOCSDIR}/camlimages
PORTDOCS=	README.md

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

FREETYPE_USES=		pkgconfig
FREETYPE_CONFIGURE_WITH=freetype
FREETYPE_LIB_DEPENDS=	libfreetype.so:print/freetype2

GHOSTSCRIPT_CONFIGURE_WITH=	gs
GHOSTSCRIPT_USES=	ghostscript

GTK2_CONFIGURE_WITH=	liblgtk2
GTK2_BUILD_DEPENDS=	lablgtk2:x11-toolkits/ocaml-lablgtk2
GTK2_RUN_DEPENDS=	lablgtk2:x11-toolkits/ocaml-lablgtk2

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXPM}
USES+=		xorg
USE_XORG=	x11 xpm
.endif

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/camlimages/dllcamlimages_exif_stubs.so \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/camlimages/core/camlimages.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/camlimages/exif/camlimages_exif.cmxs

post-install-FREETYPE-on:
	${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/camlimages/dllcamlimages_freetype_stubs.so \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/camlimages/freetype/camlimages_freetype.cmxs

post-install-GIF-on:
	${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/camlimages/dllcamlimages_gif_stubs.so \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/camlimages/gif/camlimages_gif.cmxs

post-install-JPEG-on:
	${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/camlimages/dllcamlimages_jpeg_stubs.so \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/camlimages/jpeg/camlimages_jpeg.cmxs

post-install-PNG-on:
	${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/camlimages/dllcamlimages_png_stubs.so \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/camlimages/png/camlimages_png.cmxs

post-install-TIFF-on:
	${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/camlimages/dllcamlimages_tiff_stubs.so \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/camlimages/tiff/camlimages_tiff.cmxs

post-install-XPM-on:
	${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/camlimages/dllcamlimages_xpm_stubs.so \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/camlimages/xpm/camlimages_xpm.cmxs

.include <bsd.port.mk>
