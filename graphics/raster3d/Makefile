# New ports collection makefile for:	Raster3D
# Date Created:				2006-04-28
# Whom:					Shaun Amott <shaun@inerd.com>
#
# $FreeBSD$
#

PORTNAME=	raster3d
PORTVERSION=	2.7s
PORTREVISION=	2
CATEGORIES=	graphics biology
MASTER_SITES=	http://skuld.bmsc.washington.edu/${PORTNAME}/
DISTNAME=	Raster3D_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of tools for generating raster images of proteins and molecules

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

OPTIONS=	IMAGEMAGICK "ImageMagick graphics support" on

USE_FORTRAN=	yes
MAKE_ENV=	CC="${CC}" CFLAGS="${CFLAGS}" FC="${FC}" FFLAGS="${FFLAGS}" \
		RM="${RM}" OS="${OPSYS}"
ALL_TARGET=	strip-for-g77 all

MANL=		avs2ps.l balls.l label3d.l r3d_objects.l r3dtops.l rastep.l \
		raster3d.l render.l ribbon.l rods.l normal3d.l stereo3d.l

CFLAGS+=	-DLINUX -DNETWORKBYTEORDER
FFLAGS+=	-fno-range-check

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
.if ${ARCH} == "sparc64"
BROKEN=		Does not compile with GCC 4.2: internal compiler error
.endif
.endif

.if defined(WITHOUT_IMAGEMAGICK)
PLIST_SUB+=	IMAGEMAGICK="@comment "
.else
RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick
CFLAGS+=	-DIMAGEPIPE
PLIST_SUB+=	IMAGEMAGICK=""
.endif

do-configure:
	@cd ${WRKSRC}; ${SED} 's:^prefix.*$$:prefix = ${PREFIX}:g ; \
		 s:^INCDIRS.*$$:INCDIRS = -I${LOCALBASE}/include:g ; \
		 s:^LIBDIRS.*$$:LIBDIRS = -L${LOCALBASE}/lib:g ; \
		 s:IDEFS:#IDEFS:g' Makefile.template > Makefile.incl

do-install:
.for file in avs2ps balls normal3d rastep render ribbon rings3d rods
	cd ${WRKSRC} && ${INSTALL_PROGRAM} ${file} ${PREFIX}/bin
.endfor
.if !defined(WITHOUT_IMAGEMAGICK)
.for file in label3d stereo3d
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${file} ${PREFIX}/bin
.endfor
.endif
	cd ${WRKSRC}/doc && ${INSTALL_MAN} ${MANL} ${MANLPREFIX}/man/manl
	@${MKDIR} ${DATADIR}/materials
	cd ${WRKSRC}/materials && ${INSTALL_DATA} * ${DATADIR}/materials
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/html
	cd ${WRKSRC}/doc && ${INSTALL_DATA} R3D_manual.pdf ${DOCSDIR}
	cd ${WRKSRC}/html && ${INSTALL_DATA} * ${DOCSDIR}/html
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}/msms
	cd ${WRKSRC}/examples && ${INSTALL_DATA} *.* ${EXAMPLESDIR}
	cd ${WRKSRC}/examples/msms && ${INSTALL_DATA} * ${EXAMPLESDIR}/msms
.endif

.include <bsd.port.post.mk>
