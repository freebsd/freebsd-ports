# New ports collection makefile for:	CImg
# Date created:         11 September 2004
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	cimg
PORTVERSION=	1.4.9
PORTREVISION=	1
PORTEPOCH=	3
CATEGORIES=	graphics devel
MASTER_SITES=	SF/${PORTNAME}		\
		SF/${PORTNAME}/old
DISTNAME=	CImg-${DISTVERSION}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	The C++ Template Image Processing Library

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	"invokes i386 asm"

LICENSE=	CeCILL_C CeCILL
LICENSE_PERMS_CeCILL_C=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_CeCILL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_NAME_CeCILL_C=	CeCILL-C
LICENSE_NAME_CeCILL=	CeCILL
LICENSE_FILE_CeCILL_C=	${WRKSRC}/Licence_CeCILL-C_V1-en.txt
LICENSE_FILE_CeCILL=	${WRKSRC}/Licence_CeCILL_V2-en.txt
LICENSE_COMB=	dual

USE_ZIP=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:C/_/-/}
BUILD_WRKSRC=	${WRKSRC}/examples
MAKE_ENV=	X11PATH=${LOCALBASE} LOCALBASE=${LOCALBASE}
CPPFLAGS+=	${CFLAGS} ${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}

.if !defined(NOPORTDOCS)
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
REINPLACE_ARGS=	-i ""
LIB_DEPENDS+=	board.0:${PORTSDIR}/graphics/libboard

USE_FORTRAN=	yes

. if !defined(WITH_DEBUG)
LIB_DEPENDS+=	png:${PORTSDIR}/graphics/png		\
		jpeg:${PORTSDIR}/graphics/jpeg		\
		tiff:${PORTSDIR}/graphics/tiff		\
		opencv_legacy.2:${PORTSDIR}/graphics/opencv		\
		IlmImf:${PORTSDIR}/graphics/OpenEXR	\
		gimp-2.0:${PORTSDIR}/graphics/gimp-app	\
		fftw3:${PORTSDIR}/math/fftw3		\
		GraphicsMagick++:${PORTSDIR}/graphics/GraphicsMagick
ALL_TARGET=	oFreeBSD
. else
ALL_TARGET=	dFreeBSD
WITHOUT_MEDCON=	yes
WITHOUT_FFMPEG=	yes
WITHOUT_LAPACK=	yes
. endif

. if !defined(WITHOUT_MEDCON)
RUN_DEPENDS+=	medcon:${PORTSDIR}/graphics/xmedcon
. endif
. if !defined(WITHOUT_FFMPEG)
LIB_DEPENDS+=	avformat.1:${PORTSDIR}/multimedia/ffmpeg
. endif

DOCBASE=	CHANGES.txt README.txt
PROGS=		CImg_demo gmic use_jpeg_buffer
.else
NO_BUILD=	yes
.endif

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
. if !defined(WITHOUT_LAPACK)
.  if exists(${LOCALBASE}/lib/libatlas_r.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.  endif
.  if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
LAPACK_LIB=	-L${LOCALBASE}/lib -lalapack -lcblas -lf77blas -L`${CAT} ${WRKSRC}/LIBDIR`/../../.. -lgfortran -latlas
.  else
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
LAPACK_LIB=	-L${LOCALBASE}/lib -llapack -lblas -L`${CAT} ${WRKSRC}/LIBDIR`/../../.. -lgfortran
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
	${INSTALL_DATA} ${WRKSRC}/CImg.h ${PREFIX}/include
.if !defined(NOPORTDOCS)
	${INSTALL_PROGRAM} ${PROGS:C|^|${BUILD_WRKSRC}/|} ${PREFIX}/bin
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOCBASE:S|^|${WRKSRC}/|} ${DOCSDIR}
	cd ${WRKSRC}/html && ${COPYTREE_SHARE} \* ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}
	@(cd ${EXAMPLESDIR} && ${GMAKE} clean)
	@${RM} ${EXAMPLESDIR}/Makefile.orig
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
	${FIND} ${DOCSDIR} ${EXAMPLESDIR} -type f -exec ${CHMOD} ${SHAREMODE} {} \;
.endif

.include <bsd.port.post.mk>
