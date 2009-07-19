# New ports collection makefile for:	Raster3D
# Date Created:				2006-04-28
# Whom:					Shaun Amott <shaun@inerd.com>
#
# $FreeBSD$
#

PORTNAME=	raster3d
DISTVERSION=	2.7d
PORTREVISION=	1
CATEGORIES=	graphics biology
MASTER_SITES=	http://skuld.bmsc.washington.edu/${PORTNAME}/
DISTNAME=	Raster3D_${DISTVERSION}

MAINTAINER=	shaun@FreeBSD.org
COMMENT=	A set of tools for generating raster images of proteins and molecules

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

BINARIES=	avs2ps balls rastep render ribbon rings3d rods normal3d
SCRIPTS=	label3d stereo3d

USE_FORTRAN=	g77

.if !defined(WITHOUT_IMAGEMAGICK)
RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick
PLIST_SUB+=	IMAGEMAGICK=""
.else
PLIST_SUB+=	IMAGEMAGICK="@comment "
.endif

MANL=		avs2ps.l label3d.l r3d_objects.l rastep.l render.l rods.l  \
		balls.l normal3d.l r3dtops.l raster3d.l ribbon.l stereo3d.l

pre-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} freebsd
	@${REINPLACE_CMD} -e 's#prefix#PREFIX#g' \
	                  -e 's#^LIBDIRS.*=.*#LIBDIRS	= -L${LOCALBASE}/lib#g' \
	                  -e 's#^INCDIRS.*=.*#INCDIRS	= -I/usr/include -I${LOCALBASE}/include#g' \
	                  ${WRKSRC}/Makefile*

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} ${BINARIES} ${PREFIX}/bin
.if !defined(WITHOUT_IMAGEMAGICK)
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${SCRIPTS} ${PREFIX}/bin
.endif
	@${MKDIR} ${DATADIR}/materials
	cd ${WRKSRC}/materials && ${INSTALL_DATA} * ${DATADIR}/materials

	cd ${WRKSRC}/doc && ${INSTALL_MAN} ${MANL} ${MANLPREFIX}/man/manl

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/html
	cd ${WRKSRC}/doc && ${INSTALL_DATA} R3D_manual.pdf ${DOCSDIR}
	cd ${WRKSRC}/html && ${INSTALL_DATA} * ${DOCSDIR}/html

	@${MKDIR} ${EXAMPLESDIR}/msms
	cd ${WRKSRC}/examples && ${INSTALL_DATA} *.* ${EXAMPLESDIR}
	cd ${WRKSRC}/examples/msms && ${INSTALL_DATA} * ${EXAMPLESDIR}/msms
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
.if ${ARCH} == "sparc64"
BROKEN=		Does not compile with GCC 4.2: internal compiler error
.endif
.endif

.include <bsd.port.post.mk>
