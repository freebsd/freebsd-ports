# $FreeBSD$

PORTNAME=	colmap
DISTVERSION=	2.1-0 # synthetic tag
DISTVERSIONSUFFIX=	-g55fbe10
PORTREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Structure from motion and multi-view stereo

LICENSE=	BSD2CLAUSE BSD3CLAUSE CC-BY-3.0 GPLv3+ MIT SIFTGPU
LICENSE_COMB=	multi
LICENSE_NAME_SIFTGPU=	SiftGPU non-commercial license
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/src/ext/VLFeat/LICENSE
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/src/ext/FLANN/LICENSE
LICENSE_FILE_CC-BY-3.0=	${WRKSRC}/src/ui/media/LICENSE
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING.txt
LICENSE_FILE_MIT=	${WRKSRC}/src/ext/PoissonRecon/LICENSE
LICENSE_FILE_SIFTGPU=	${WRKSRC}/src/ext/SiftGPU/LICENSE
LICENSE_PERMS_SIFTGPU=	dist-mirror pkg-mirror auto-accept

BUILD_DEPENDS=	eigen>=3:math/eigen3
LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libglog.so:devel/glog \
		libfreeimage.so:graphics/freeimage \
		libceres.so:math/ceres-solver

USES=		cmake compiler:${OPENMP}c++11-lib fortran localbase sqlite
USE_GITHUB=	yes
USE_GL=		gl glew glut
USE_QT5=	qmake_build buildtools_build core gui opengl_build widgets
EXCLUDE=	SQLite
EXTRACT_AFTER_ARGS=	${EXCLUDE:S,^,--exclude src/ext/,}
CMAKE_ARGS=	-DBOOST_STATIC=off -DCUDA_ENABLED=off
CFLAGS+=	-DVL_OS_LINUX=1
CXXFLAGS+=	-fpermissive # libc++ <future> vs. g++49
CXXFLAGS+=	-D_GLIBCXX_USE_C99 -D_GLIBCXX_USE_C99_MATH_TR1 \
		-D_DECLARE_C99_LDBL_MATH # XXX ports/193528
LDFLAGS+=	-Wl,--as-needed # gflags, glu, xi, xmu
TEST_TARGET=	test ARGS="-V"

OPTIONS_DEFINE=		DOCS OPENMP SIMD
OPTIONS_DEFAULT=	OPENMP SIMD
# XXX ports/215138: exclude still broken
OPTIONS_EXCLUDE=	${OPTIONS_EXCLUDE_${OPSYS}_${OSREL}} # not OSREL:R
OPTIONS_EXCLUDE_FreeBSD_10.1=	OPENMP

DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx
DOCS_USES=		gmake
DOCS_PORTDOCS=		*

OPENMP_USES=		compiler:openmp
OPENMP_CMAKE_BOOL=	OPENMP_ENABLED
# XXX ports/199603 + ports/210337
OPENMP_VARS=		OPENMP=gcc-

SIMD_CMAKE_BOOL=	SIMD_ENABLED

post-patch:
	@${REINPLACE_CMD} -e 's/Qt5OpenGL/Qt5Widgets/' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e '/install.*test/d' \
		${WRKSRC}/cmake/CMakeHelper.cmake
# XXX Unbundle FLANN as it has more consumers
	@${REINPLACE_CMD} -e '/SQLite/d' \
		${WRKSRC}/src/ext/CMakeLists.txt
	@${REINPLACE_CMD} -e 's,ext/SQLite/,,' \
		${WRKSRC}/src/base/database.h \
		${WRKSRC}/src/util/sqlite3_utils.h
.if !defined(DISPLAY) # QApplication
	@${REINPLACE_CMD} -e '/feature_matching_test/d' \
		-e '/feature_extraction_test/d' \
		${WRKSRC}/src/base/CMakeLists.txt
	@${REINPLACE_CMD} -e '/opengl_utils_test/d' \
		${WRKSRC}/src/util/CMakeLists.txt
.endif

post-build-DOCS-on:
	@${DO_MAKE_BUILD} html -C${WRKSRC}/doc

pre-install:	do-test

post-install-DOCS-on:
	(cd ${WRKSRC}/doc/_build/html && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

# FreeBSD 11.0 i386 has:
#          7 - base/database_test (Failed)
#         26 - estimators/epnp_test (Failed)
#         34 - mvs/depth_map_test (Failed)
#         39 - optim/loransac_test (Failed)
#         42 - optim/ransac_test (Failed)
do-test:	.IGNORE
