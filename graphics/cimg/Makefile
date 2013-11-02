# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	cimg
PORTVERSION=	1.5.7
PORTEPOCH=	3
CATEGORIES=	graphics devel
MASTER_SITES=	SF/${PORTNAME}		\
		SF/${PORTNAME}/old
DISTNAME=	CImg-${DISTVERSION}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	The C++ Template Image Processing Library

LICENSE=	CeCILL_C CeCILL
LICENSE_COMB=	dual
LICENSE_NAME_CeCILL_C=	CeCILL-C
LICENSE_NAME_CeCILL=	CeCILL
LICENSE_FILE_CeCILL_C=	${WRKSRC}/Licence_CeCILL-C_V1-en.txt
LICENSE_FILE_CeCILL=	${WRKSRC}/Licence_CeCILL_V2-en.txt
LICENSE_PERMS_CeCILL_C=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_CeCILL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	"invokes i386 asm"

USE_ZIP=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:C/_/-/}
BUILD_WRKSRC=	${WRKSRC}/examples
MAKE_ENV=	X11PATH=${LOCALBASE} LOCALBASE=${LOCALBASE}
CPPFLAGS+=	${CFLAGS} ${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}

.if !defined(NOPORTDOCS)
USES=		gmake
REINPLACE_ARGS=	-i ""
LIB_DEPENDS+=	libboard.so:${PORTSDIR}/graphics/libboard

USE_FORTRAN=	yes

. if !defined(WITH_DEBUG)
LIB_DEPENDS+=	libpng15.so:${PORTSDIR}/graphics/png		\
		libjpeg.so:${PORTSDIR}/graphics/jpeg		\
		libtiff.so:${PORTSDIR}/graphics/tiff		\
		libIlmImf.so:${PORTSDIR}/graphics/OpenEXR	\
		libgimp-2.0.so:${PORTSDIR}/graphics/gimp-app	\
		libfftw3.so:${PORTSDIR}/math/fftw3		\
		libGraphicsMagick++.so:${PORTSDIR}/graphics/GraphicsMagick
#		libopencv_legacy.so:${PORTSDIR}/graphics/opencv
ALL_TARGET=	Mlinux
. else
ALL_TARGET=	dlinux
WITHOUT_MEDCON=	yes
WITHOUT_FFMPEG=	yes
WITHOUT_LAPACK=	yes
. endif

. if !defined(WITHOUT_MEDCON)
RUN_DEPENDS+=	medcon:${PORTSDIR}/graphics/xmedcon
. endif
. if !defined(WITHOUT_FFMPEG)
LIB_DEPENDS+=	libavformat.so:${PORTSDIR}/multimedia/ffmpeg
. endif

DOCBASE=	README.txt
PROGS=		CImg_demo captcha curve_editor2d dtmri_view3d			\
	edge_explorer2d fade_images gaussian_fit1d generate_loop_macros		\
	hough_transform2d image2ascii image_registration2d image_surface3d	\
	jawbreaker mcf_levelsets2d mcf_levelsets3d odykill			\
	pde_TschumperleDeriche2d pde_heatflow2d plotter1d radon_transform2d	\
	scene3d spherical_function3d tetris tron tutorial use_RGBclass		\
	use_chlpca use_draw_gradient use_jpeg_buffer use_nlmeans use_skeleton	\
	wavelet_atrous
.else
NO_BUILD=	yes
.endif

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
. if !defined(WITHOUT_LAPACK)
.  if exists(${LOCALBASE}/lib/libatlas.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.  endif
.  if defined(WITH_ATLAS)
LIB_DEPENDS+=	libatlas.so:${PORTSDIR}/math/atlas
LAPACK_LIB=	-L${LOCALBASE}/lib -lalapack -lcblas -lf77blas
.  else
LIB_DEPENDS+=	libblas.so:${PORTSDIR}/math/blas
LIB_DEPENDS+=	liblapack.so:${PORTSDIR}/math/lapack
LAPACK_LIB=	-L${LOCALBASE}/lib -llapack -lblas
.  endif
. endif
.endif

pre-configure:
.if !defined(NOPORTDOCS)
	${DIRNAME} `${LOCALBASE}/bin/${FC} -print-libgcc-file-name` > ${WRKSRC}/LIBDIR
	${REINPLACE_CMD} -e 's|make|${GMAKE}|' ${BUILD_WRKSRC}/Makefile
.else
	${REINPLACE_CMD} -e 's|^OPTFLAGS|#OPTFLAGS|' ${BUILD_WRKSRC}/Makefile
.endif
. if !defined(WITHOUT_FFMPEG)
	${REINPLACE_CMD} -e 's|#CIMG_FFMPEG_CFLAGS|CIMG_FFMPEG_CFLAGS|'	\
		-e 's|#CIMG_FFMPEG_LDFLAGS|CIMG_FFMPEG_LDFLAGS|'	\
		${BUILD_WRKSRC}/Makefile
. endif
. if !defined(WITHOUT_LAPACK)
	${REINPLACE_CMD} -e 's|#CIMG_LAPACK_CFLAGS|CIMG_LAPACK_CFLAGS|'	\
		-e 's|#CIMG_LAPACK_LDFLAGS|CIMG_LAPACK_LDFLAGS|'	\
		-e 's|-lblas -llapack|${LAPACK_LIB}|'			\
		${BUILD_WRKSRC}/Makefile
. endif
	${REINPLACE_CMD} -e 's|-pedantic|${CFLAGS}|'			\
		-e 's|-lpthread|${PTHREAD_LIBS}|' ${BUILD_WRKSRC}/Makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/CImg.h ${STAGEDIR}${PREFIX}/include
.if !defined(NOPORTDOCS)
	${INSTALL_PROGRAM} ${PROGS:C|^|${BUILD_WRKSRC}/|} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCBASE:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/html && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${STAGEDIR}${EXAMPLESDIR} && ${GMAKE} clean)
	@${RM} ${STAGEDIR}${EXAMPLESDIR}/*.orig
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${EXAMPLESDIR}
	${FIND} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${EXAMPLESDIR} -type f -exec ${CHMOD} ${SHAREMODE} {} \;
.endif

.include <bsd.port.post.mk>
