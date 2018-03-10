# Created by: Shaun Amott <shaun@inerd.com>
# $FreeBSD$

PORTNAME=	raster3d
PORTVERSION=	3.0.2
PORTREVISION=	11
CATEGORIES=	graphics biology
MASTER_SITES=	http://skuld.bmsc.washington.edu/${PORTNAME}/
DISTNAME=	Raster3D_${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of tools for generating raster images of proteins and molecules

LICENSE=	ART20

LIB_DEPENDS=	libgd.so:graphics/gd \
		libtiff.so:graphics/tiff

USES=		fortran
MAKE_ARGS=	INCDIRS="-I${LOCALBASE}/include" LIBDIRS="-L${LOCALBASE}/lib" \
		CC="${CC}" CFLAGS="${CFLAGS}" FC="${FC}" FFLAGS="${FFLAGS}" \
		RM="${RM}" OS="${OPSYS}"
ALL_TARGET=	linux all
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-DLINUX -DNETWORKBYTEORDER -Dgfortran
FFLAGS+=	-fno-range-check -ffixed-line-length-132

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	IMAGEMAGICK DOCS EXAMPLES
OPTIONS_DEFAULT=IMAGEMAGICK
OPTIONS_SUB=		yes

IMAGEMAGICK_RUN_DEPENDS=	convert:graphics/ImageMagick

do-install:
.for f in avs2ps balls normal3d rastep render ribbon rings3d rods
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/worms ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/*.l ${STAGEDIR}${MANLPREFIX}/man/manl
	@${MKDIR} ${STAGEDIR}${DATADIR}/materials
	${INSTALL_DATA} ${WRKSRC}/materials/* ${STAGEDIR}${DATADIR}/materials

do-install-IMAGEMAGICK-on:
.for f in label3d stereo3d
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/R3D_manual.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/html/* ${STAGEDIR}${DOCSDIR}/html

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	${RM} -r ${STAGEDIR}${EXAMPLESDIR}/msms/CVS

.include <bsd.port.mk>
