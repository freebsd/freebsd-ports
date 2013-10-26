# Created by: Shaun Amott <shaun@inerd.com>
# $FreeBSD$

PORTNAME=	raster3d
PORTVERSION=	3.0.2
PORTREVISION=	3
CATEGORIES=	graphics biology
MASTER_SITES=	http://skuld.bmsc.washington.edu/${PORTNAME}/
DISTNAME=	Raster3D_${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of tools for generating raster images of proteins and molecules

LICENSE=	ART20

LIB_DEPENDS=	gd:${PORTSDIR}/graphics/gd \
		tiff:${PORTSDIR}/graphics/tiff

OPTIONS_DEFINE=	MAGICK DOCS EXAMPLES
OPTIONS_DEFAULT=	MAGICK

USE_FORTRAN=	yes
MAKE_ARGS=	INCDIRS="-I${LOCALBASE}/include" LIBDIRS="-L${LOCALBASE}/lib" \
		CC="${CC}" CFLAGS="${CFLAGS}" FC="${FC}" FFLAGS="${FFLAGS}" \
		RM="${RM}" OS="${OPSYS}"
ALL_TARGET=	linux all
MAKE_JOBS_UNSAFE=	yes

MANL=		avs2ps.l balls.l label3d.l r3d_objects.l r3dtops.l rastep.l \
		raster3d.l render.l ribbon.l rods.l normal3d.l stereo3d.l

CFLAGS+=	-DLINUX -DNETWORKBYTEORDER -Dgfortran
FFLAGS+=	-fno-range-check -ffixed-line-length-132

MAGICK_RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick
MAGICK_CFLAGS=		-DIMAGEPIPE
OPTIONS_SUB=		yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile with GCC 4.2: internal compiler error
.endif

do-install:
.for file in avs2ps balls normal3d rastep render ribbon rings3d rods
	cd ${WRKSRC} && ${INSTALL_PROGRAM} ${file} ${PREFIX}/bin
.endfor
.for file in worms
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${file} ${PREFIX}/bin
.endfor
.if ${PORT_OPTIONS:MIMAGEMAGICK}
.for file in label3d stereo3d
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${file} ${PREFIX}/bin
.endfor
.endif
	cd ${WRKSRC}/doc && ${INSTALL_MAN} ${MANL} ${MANLPREFIX}/man/manl
	@${MKDIR} ${DATADIR}/materials
	cd ${WRKSRC}/materials && ${INSTALL_DATA} * ${DATADIR}/materials
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} R3D_manual.pdf ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/html
	cd ${WRKSRC}/html && ${INSTALL_DATA} * ${DOCSDIR}/html
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${TAR} --exclude "CVS" -cf - . | \
		${TAR} -C ${EXAMPLESDIR} --unlink -xf -)
	@${FIND} ${EXAMPLESDIR} | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	@${FIND} ${EXAMPLESDIR} -type d | ${XARGS} ${CHMOD} a+rx
	@${FIND} ${EXAMPLESDIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
.endif

.include <bsd.port.post.mk>
