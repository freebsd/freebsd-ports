PORTNAME=	cimg
DISTVERSIONPREFIX=	v.
DISTVERSION=	3.5.5
PORTREVISION=	1
PORTEPOCH=	3
CATEGORIES=	graphics devel

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	C++ Template Image Processing Library
WWW=		https://cimg.eu/

LICENSE=	CeCILL_C CeCILL
LICENSE_COMB=	dual
LICENSE_NAME_CeCILL_C=	CeCILL-C
LICENSE_NAME_CeCILL=	CeCILL
LICENSE_FILE_CeCILL_C=	${WRKSRC}/Licence_CeCILL-C_V1-en.txt
LICENSE_FILE_CeCILL=	${WRKSRC}/Licence_CeCILL_V2-en.txt
LICENSE_PERMS_CeCILL_C=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_CeCILL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USE_GITHUB=	yes
GH_ACCOUNT=	GreycLab
GH_PROJECT=	CImg

BUILD_WRKSRC=	${WRKSRC}/examples

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS} || ${PORT_OPTIONS:MEXAMPLES}
USES+=		compiler:c11 gmake pkgconfig:build xorg
.endif

.if ${PORT_OPTIONS:MDOCS}

.if !defined(WITHOUT_LAPACK)
. if defined(WITH_ATLAS)
USES+=		blaslapack:atlas
. else
USES+=		blaslapack
. endif
.endif

REINPLACE_ARGS=	-i ""

. if !defined(WITH_DEBUG)
LIB_DEPENDS+=	libcurl.so:ftp/curl			\
		libpng.so:graphics/png			\
		libtiff.so:graphics/tiff		\
		libImath.so:math/Imath			\
		libheif.so:graphics/libheif		\
		libOpenEXR.so:graphics/openexr		\
		libfftw3.so:math/fftw3			\
		libwebp.so:graphics/webp		\
		libboard.so:graphics/libboard		\
		libopencv_core.so:graphics/opencv	\
		libGraphicsMagick.so:graphics/GraphicsMagick
RUN_DEPENDS+=	dcraw:graphics/dcraw
USES+=		jpeg magick:7
ALL_TARGET=	Mlinux
. else
ALL_TARGET=	dlinux
WITHOUT_MEDCON=	yes
WITHOUT_FFMPEG=	yes
WITHOUT_LAPACK=	yes
. endif

. if !defined(WITHOUT_MEDCON)
RUN_DEPENDS+=	medcon:graphics/xmedcon
. endif
. if !defined(WITHOUT_FFMPEG)
LIB_DEPENDS+=	libavformat.so:multimedia/ffmpeg
. endif

. if !defined(WITHOUT_LAPACK)
# Don't really need Fortran, but required to link with blas/lapack
USES+=	fortran
. endif

USE_XORG+=	x11 xrandr
. if defined(WITH_XSHM)
USE_XORG+=	xext
. endif

DOCBASE=	README.txt
CFLAGS+=	-I${LOCALBASE}/include/Imath -I${LOCALBASE}/include/OpenEXR
MAKE_ARGS+=	CPPFLAGS="${CFLAGS}" FREEBSD_LDFLAGS="${LDFLAGS}"
. if !exists(/usr/include/omp.h)
MAKE_ARGS+=	OPENMP_CFLAGS=
. endif
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

pre-configure-DOCS-on:
	${REINPLACE_CMD} -e 's|make|${MAKE_CMD}|' ${BUILD_WRKSRC}/Makefile

pre-configure-DOCS-off:
	${REINPLACE_CMD} -e 's|^OPTFLAGS|#OPTFLAGS|' ${BUILD_WRKSRC}/Makefile

pre-configure:
. if !defined(WITHOUT_FFMPEG)
	${REINPLACE_CMD} -e 's|#FFMPEG_CFLAGS|FFMPEG_CFLAGS|'	\
		-e 's|#FFMPEG_DEFINE|FFMPEG_DEFINE|'		\
		-e 's|#FFMPEG_LIBS|FFMPEG_LIBS|'		\
		${BUILD_WRKSRC}/Makefile
. endif
. if !defined(WITHOUT_LAPACK)
	${REINPLACE_CMD} -e 's|#LAPACK_CFLAGS|LAPACK_CFLAGS|'			\
		-e 's|#LAPACK_DEFINE|LAPACK_DEFINE|'				\
		-e 's|#LAPACK_LIBS|LAPACK_LIBS|'				\
		-e 's|-lblas -llapack|-L${LOCALBASE}/lib ${BLASLIB} ${LAPACKLIB}|'	\
		${BUILD_WRKSRC}/Makefile
. endif
. if defined(WITH_XSHM)
	${REINPLACE_CMD} -e 's|XSHM_CFLAGS = #|XSHM_CFLAGS =|'	\
		-e 's|XSHM_LDFLAGS = #|XSHM_LDFLAGS =|'		\
		${BUILD_WRKSRC}/Makefile
. endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/CImg.h ${STAGEDIR}${PREFIX}/include

do-install-DOCS-on:
	${INSTALL_PROGRAM} ${PROGS:C|^|${BUILD_WRKSRC}/|} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCBASE:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${STAGEDIR}${EXAMPLESDIR} && ${MAKE_CMD} clean)
	@${RM} ${STAGEDIR}${EXAMPLESDIR}/*.orig

.include <bsd.port.post.mk>
