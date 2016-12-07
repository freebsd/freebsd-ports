# Created by: Shaun Amott <shaun@inerd.com>
# $FreeBSD$

PORTNAME=	raster3d
PORTVERSION=	3.0.2
PORTREVISION=	8
CATEGORIES=	graphics biology
MASTER_SITES=	http://skuld.bmsc.washington.edu/${PORTNAME}/
DISTNAME=	Raster3D_${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of tools for generating raster images of proteins and molecules

LICENSE=	ART20

LIB_DEPENDS=	libgd.so:graphics/gd \
		libtiff.so:graphics/tiff

OPTIONS_DEFINE=	IMAGEMAGICK DOCS EXAMPLES
OPTIONS_DEFAULT=IMAGEMAGICK

USES=		fortran
MAKE_ARGS=	INCDIRS="-I${LOCALBASE}/include" LIBDIRS="-L${LOCALBASE}/lib" \
		CC="${CC}" CFLAGS="${CFLAGS}" FC="${FC}" FFLAGS="${FFLAGS}" \
		RM="${RM}" OS="${OPSYS}"
ALL_TARGET=	linux all
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-DLINUX -DNETWORKBYTEORDER -Dgfortran
FFLAGS+=	-fno-range-check -ffixed-line-length-132

IMAGEMAGICK_RUN_DEPENDS=	convert:graphics/ImageMagick
OPTIONS_SUB=		yes

.include <bsd.port.options.mk>

do-install:
.for install_file in avs2ps balls normal3d rastep render ribbon rings3d rods
	cd ${WRKSRC} && ${INSTALL_PROGRAM} ${install_file} ${STAGEDIR}${PREFIX}/bin
.endfor
.for install_file in worms
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${install_file} ${STAGEDIR}${PREFIX}/bin
.endfor
.if ${PORT_OPTIONS:MIMAGEMAGICK}
.for install_file in label3d stereo3d
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${install_file} ${STAGEDIR}${PREFIX}/bin
.endfor
.endif
	cd ${WRKSRC}/doc && ${INSTALL_MAN} *.l ${STAGEDIR}${MANLPREFIX}/man/manl
	${MKDIR} ${STAGEDIR}${DATADIR}/materials
	cd ${WRKSRC}/materials && ${INSTALL_DATA} * ${STAGEDIR}${DATADIR}/materials
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} R3D_manual.pdf ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	cd ${WRKSRC}/html && ${INSTALL_DATA} * ${STAGEDIR}${DOCSDIR}/html
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	${RM} -r ${STAGEDIR}${EXAMPLESDIR}/msms/CVS
.endif

.include <bsd.port.mk>
