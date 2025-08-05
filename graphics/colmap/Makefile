PORTNAME=	colmap
DISTVERSION=	3.12.4
CATEGORIES=	graphics

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Structure from motion and multi-view stereo
WWW=		https://colmap.github.io/

LICENSE=	BSD2CLAUSE BSD3CLAUSE CC-BY-3.0 MIT SIFTGPU
LICENSE_COMB=	multi
LICENSE_NAME_SIFTGPU=	SiftGPU non-commercial license
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/src/thirdparty/VLFeat/LICENSE
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/COPYING.txt # also FLANN
LICENSE_FILE_CC-BY-3.0=	${WRKSRC}/src/colmap/ui/media/LICENSE
LICENSE_FILE_MIT=	${WRKSRC}/src/thirdparty/PoissonRecon/LICENSE
LICENSE_FILE_SIFTGPU=	${WRKSRC}/src/thirdparty/SiftGPU/LICENSE
LICENSE_PERMS_SIFTGPU=	dist-mirror pkg-mirror auto-accept

LIB_DEPENDS=	libPoseLib.so:graphics/poselib \
		libboost_program_options.so:devel/boost-libs \
		libceres.so:math/ceres-solver \
		libcurl.so:ftp/curl \
		libfaiss.so:math/faiss \
		libfreeimage.so:graphics/freeimage \
		libglog.so:devel/glog \
		libmetis.so:math/metis
TEST_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gtest.pc:devel/googletest

USES=		cmake:testing compiler:${OPENMP}c++11-lib desktop-file-utils eigen:3 gl \
		localbase python:env qt:5 sqlite ssl
USE_CXXSTD=	c++17
USE_GITHUB=	yes
USE_GL=		gl glew
USE_QT=		core gui widgets buildtools:build opengl:build qmake:build
CMAKE_OFF=	CUDA_ENABLED FETCH_FAISS FETCH_POSELIB
CMAKE_TESTING_ON=	TESTS_ENABLED

LDFLAGS+=	-Wl,--as-needed # gflags, glu, xi, xmu

OPTIONS_DEFINE=		CGAL DOCS OPENMP SIMD
OPTIONS_DEFAULT=	CGAL OPENMP SIMD

CGAL_DESC=		Graph-cut on Delaunay triangulation based meshing algorithm
CGAL_BUILD_DEPENDS=	cgal>0:math/cgal
CGAL_LIB_DEPENDS=	libgmp.so:math/gmp
CGAL_CMAKE_BOOL=	CGAL_ENABLED

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR} \
			gmake:devel/gmake sphinx-build:textproc/py-sphinx

OPENMP_CMAKE_BOOL=	OPENMP_ENABLED
.if !exists(/usr/include/omp.h)
# XXX ports/199603: LLVM openmp in base doesn't support armv7 yet
OPENMP_VARS=		OPENMP=gcc-
.endif

SIMD_CMAKE_BOOL=	SIMD_ENABLED
SIMD_CFLAGS_i386=	-msse2
SIMD_CFLAGS=		${SIMD_CFLAGS_${ARCH}}

post-build-DOCS-on:
	${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GMAKE} ${_MAKE_JOBS} -C ${WRKSRC}/doc html

post-install:
	${FIND} ${STAGEDIR}${PREFIX}/include -type d -empty -delete

post-install-DOCS-on:
	(cd ${WRKSRC}/doc/_build/html && ${COPYTREE_SHARE} \
		. ${STAGEDIR}${DOCSDIR})
	${RM} ${STAGEDIR}${DOCSDIR}/.buildinfo

# https://github.com/colmap/colmap/issues/3021#issuecomment-2536520512
pre-test:
	@${ECHO_MSG} Expected test suite failures on displayless machines:
	@${ECHO_MSG} "24 - feature/colmap_feature_sift_test (Subprocess aborted)"
	@${ECHO_MSG} "88 - util/colmap_util_opengl_utils_test (Subprocess aborted)"

.include <bsd.port.mk>
