PORTNAME=	opencolorio
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.1
# PORTREVISION must be set with ?= so as not to stomp over
# py-opencolorio's PORTREVISION.
# Also, just to be on the safe side, when resetting,
# best keep PORTREVISION?=	0.
PORTREVISION?=	0
CATEGORIES=	graphics multimedia

MAINTAINER?=	FreeBSD@Shaneware.biz
COMMENT?=	Complete color management solution

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libImath.so:math/Imath \
		libpystring.so:devel/pystring \
		libyaml-cpp.so:devel/yaml-cpp
USES=		alias cmake compiler:c++14-lang localbase:ldflags \
		pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	AcademySoftwareFoundation
GH_PROJECT=	OpenColorIO

CMAKE_OFF=	OCIO_BUILD_JAVA OCIO_BUILD_JNIGLUE OCIO_BUILD_NUKE \
		OCIO_BUILD_TESTS OCIO_BUILD_GPU_TESTS

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	DOCS
OPTIONS_SUB=		yes

DOCS_CMAKE_BOOL=	OCIO_BUILD_DOCS
DOCS_BUILD_DEPENDS=	doxygen>0:devel/doxygen

PLIST_SUB=	SHL3=${PORTVERSION} SHL2=${PORTVERSION:R}

.include <bsd.port.options.mk>

.if (defined(MACHINE_CPU) && ${MACHINE_CPU:Msse2})
CMAKE_ON+=	OCIO_USE_SSE
.else
CMAKE_OFF+=	OCIO_USE_SSE
.endif

.if ${PORT_OPTIONS:MDOCS}
# master and pymodule use these
# DOCS needs to be enabled for python docstrings to be generated
# py module can still be used without
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}breathe>=0:devel/py-breathe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}recommonmark>=0:textproc/py-recommonmark@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx_press_theme>=0:textproc/py-sphinx_press_theme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx-tabs>0:textproc/py-sphinx-tabs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}testresources>=0:devel/py-testresources@${PY_FLAVOR}
.endif

.if defined(OCIO_SLAVE) && ${OCIO_SLAVE} == tools
LIB_DEPENDS+=	liblcms2.so:graphics/lcms2 \
		libOpenColorIO.so:graphics/opencolorio \
		libOpenImageIO.so:graphics/openimageio \
		libopencv_core.so:graphics/opencv \
		libOpenEXR.so:graphics/openexr
CMAKE_ON+=	OCIO_BUILD_APPS USE_EXTERNAL_LCMS
CMAKE_OFF+=	BUILD_SHARED_LIBS OCIO_BUILD_DOCS \
		OCIO_BUILD_PYGLUE OCIO_BUILD_PYTHON
CMAKE_ARGS+=	-DCMAKE_CXX_STANDARD=14
LDFLAGS+=	-lOpenImageIO_Util
USES+=		gl xorg
USE_GL=		egl gl glu glut glew
USE_XORG=	xi xmu
PLIST=		${PKGDIR}/pkg-plist-tools

.elif defined(OCIO_SLAVE) && ${OCIO_SLAVE} == pymodule
BUILD_DEPENDS+=	pybind11>0:devel/pybind11
LIB_DEPENDS+=	libOpenColorIO.so:graphics/opencolorio
# textproc/py-sphinx_press_theme doesn't support py3.6
USES+=		python:3.7+
LDFLAGS+=	-lOpenColorIO
CMAKE_ON+=	OCIO_BUILD_PYTHON
CMAKE_OFF+=	OCIO_BUILD_APPS BUILD_SHARED_LIBS OCIO_BUILD_DOCS \
		OCIO_BUILD_TESTS OCIO_BUILD_GPU_TESTS
CMAKE_ARGS+=	-DOCIO_PYTHON_VERSION=${PYTHON_VER}
PLIST=		${PKGDIR}/pkg-plist-pyglue
# concurrent allows docs to not collide with master port
USE_PYTHON=	concurrent flavors

.else # master port
# we enable pyglue in master port. This makes the python module
# available when generating docs, we leave the python header in place
# but only install the python module with the py-opencolorio port
# this makes it easier to allow multiple python versions installed
BUILD_DEPENDS+=	pybind11>0:devel/pybind11
CMAKE_ON+=	BUILD_SHARED_LIBS OCIO_BUILD_PYGLUE OCIO_BUILD_PYTHON
CMAKE_OFF+=	OCIO_BUILD_APPS
CMAKE_ARGS+=	-DOCIO_PYTHON_VERSION=${PYTHON_VER}
USES+=		gl python:build xorg
USE_GL=		gl glu glut glew
USE_XORG=	xi xmu
USE_LDCONFIG=	yes
PLIST=		${PKGDIR}/pkg-plist ${PKGDIR}/pkg-plist-docs
.endif

post-install:
	@cd ${STAGEDIR}${PREFIX} && ${RM} -r share/ocio
.if defined(OCIO_SLAVE)
	@cd ${STAGEDIR}${PREFIX} && ${RM} -r include libdata lib/cmake lib/libOpenColorIO.a
.endif
.if !defined(OCIO_SLAVE) || (defined(OCIO_SLAVE) && ${OCIO_SLAVE} != pymodule)
	@cd ${STAGEDIR}${PREFIX} && ${RM} -r lib/libOpenColorIO*.a lib/python*
.endif

post-install-DOCS-on:
	@cd ${STAGEDIR}${PREFIX}/share/doc && ${MV} OpenColorIO ${PKGNAMEPREFIX}${PORTNAME}

.include <bsd.port.mk>
