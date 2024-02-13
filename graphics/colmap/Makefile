PORTNAME=	colmap
DISTVERSION=	3.8
PORTREVISION=	5
CATEGORIES=	graphics

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Structure from motion and multi-view stereo
WWW=		https://colmap.github.io/

LICENSE=	BSD2CLAUSE BSD3CLAUSE CC-BY-3.0 GPLv3+ MIT SIFTGPU
LICENSE_COMB=	multi
LICENSE_NAME_SIFTGPU=	SiftGPU non-commercial license
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/lib/VLFeat/LICENSE
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/COPYING.txt # also FLANN
LICENSE_FILE_CC-BY-3.0=	${WRKSRC}/src/ui/media/LICENSE
LICENSE_FILE_GPLv3+ =	${WRKSRC}/lib/PBA/LICENSE # also Graclus, LSD
LICENSE_FILE_MIT=	${WRKSRC}/lib/PoissonRecon/LICENSE
LICENSE_FILE_SIFTGPU=	${WRKSRC}/lib/SiftGPU/LICENSE
LICENSE_PERMS_SIFTGPU=	dist-mirror pkg-mirror auto-accept

LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libceres.so:math/ceres-solver \
		libflann.so:math/flann \
		libfreeimage.so:graphics/freeimage \
		libglog.so:devel/glog \
		liblz4.so:archivers/liblz4 \
		libmetis.so:math/metis

USES=		cmake compiler:${OPENMP}c++11-lib desktop-file-utils eigen:3 gl \
		localbase python:env qt:5 sqlite
USE_CXXSTD=	c++17
USE_GITHUB=	yes
USE_GL=		gl glew
USE_QT=		core gui widgets buildtools:build opengl:build qmake:build
EXCLUDE=	SQLite
CMAKE_OFF=	BOOST_STATIC CUDA_ENABLED
TEST_TARGET=	test

LDFLAGS+=	-Wl,--as-needed # gflags, glu, xi, xmu

EXTRACT_AFTER_ARGS=	${EXCLUDE:S,^,--exclude lib/,}

OPTIONS_DEFINE=		CGAL DOCS OPENMP SIMD TEST
OPTIONS_DEFAULT=	CGAL OPENMP SIMD

CGAL_DESC=		Graph-cut on Delaunay triangulation based meshing algorithm
CGAL_BUILD_DEPENDS=	cgal>0:math/cgal
CGAL_LIB_DEPENDS=	libgmp.so:math/gmp
CGAL_CMAKE_BOOL=	CGAL_ENABLED

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR} \
			gmake:devel/gmake \
			sphinx-build:textproc/py-sphinx
DOCS_PORTDOCS=		*

OPENMP_CMAKE_BOOL=	OPENMP_ENABLED
.if !exists(/usr/include/omp.h)
# XXX ports/199603: LLVM openmp in base doesn't support armv6, armv7 yet
OPENMP_VARS=		OPENMP=gcc-
.endif

SIMD_CMAKE_BOOL=	SIMD_ENABLED

TEST_CMAKE_BOOL=	TESTS_ENABLED

post-patch:
# XXX math/flann has -DUSE_OPENMP=OFF and lacks tunning:
# https://github.com/colmap/colmap/commit/4b594eb85c13
# https://github.com/colmap/colmap/commit/1e9f1f3324cd
.if !defined(DISPLAY) # QApplication
	@${REINPLACE_CMD} -e '/opengl_utils_test/d' \
		${WRKSRC}/src/util/CMakeLists.txt
.endif

post-build-DOCS-on:
	@${SETENV} ${MAKE_ENV} ${GMAKE} ${_MAKE_JOBS} html -C${WRKSRC}/doc

pre-install-TEST-on: do-test

post-install:
# XXX Clean up garbage after install(DIRECTORY)
	@${FIND} ${STAGEDIR}${PREFIX}/include -type d -empty -delete

post-install-DOCS-on:
	(cd ${WRKSRC}/doc/_build/html && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
