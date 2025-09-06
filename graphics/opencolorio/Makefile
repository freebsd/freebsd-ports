PORTNAME=	opencolorio
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.2
# PORTREVISION must be set with ?= so as not to stomp over
# py-opencolorio's PORTREVISION.
# Also, just to be on the safe side, when resetting,
# best keep PORTREVISION?=	0.
PORTREVISION?=	2
CATEGORIES=	graphics multimedia

MAINTAINER?=	FreeBSD@Shaneware.biz
COMMENT?=	Complete color management solution
WWW=		https://www.opencolorio.org

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libImath.so:math/Imath \
		libpystring.so:devel/pystring \
		libyaml-cpp.so:devel/yaml-cpp

USES=		alias cmake compiler:c++14-lang localbase:ldflags minizip:ng \
		pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	AcademySoftwareFoundation
GH_PROJECT=	OpenColorIO

#GH_TUPLE+=	madler:zlib:v1.2.13:zlib/ext/dist/zlib

CMAKE_OFF=	OCIO_BUILD_GPU_TESTS OCIO_BUILD_JAVA OCIO_BUILD_JNIGLUE \
		OCIO_BUILD_NUKE OCIO_BUILD_TESTS

PLIST_SUB=	SHL2=${PORTVERSION:R} \
		SHL3=${PORTVERSION}

OPTIONS_DEFINE=		DOCS
OPTIONS_SUB=		yes
DOCS_BUILD_DEPENDS=	doxygen>0:devel/doxygen
DOCS_CMAKE_BOOL=	OCIO_BUILD_DOCS

.include <bsd.port.options.mk>

.if (defined(MACHINE_CPU) && ${MACHINE_CPU:Msse2})
CMAKE_ON+=	OCIO_USE_SSE2
.else
CMAKE_OFF+=	OCIO_USE_SSE2
.endif

.if ${PORT_OPTIONS:MDOCS}
# master and pymodule use these
# DOCS needs to be enabled for python docstrings to be generated
# py module can still be used without
BUILD_DEPENDS+=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}breathe>=0:devel/py-breathe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.18.1:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}recommonmark>=0:textproc/py-recommonmark@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx-tabs>0:textproc/py-sphinx-tabs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx_press_theme>=0:textproc/py-sphinx_press_theme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}testresources>=0:devel/py-testresources@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>0:net/py-urllib3@${PY_FLAVOR}
.endif

.if defined(OCIO_SLAVE) && ${OCIO_SLAVE} == tools
LIB_DEPENDS+=	liblcms2.so:graphics/lcms2 \
		libOpenEXR.so:graphics/openexr \
		libOpenImageIO.so:graphics/openimageio
USES+=		gl xorg
USE_GL=		glew glu glut opengl
USE_XORG=	xi xmu
CMAKE_ARGS+=	-DCMAKE_CXX_STANDARD=14
CMAKE_ON+=	OCIO_BUILD_APPS USE_EXTERNAL_LCMS
CMAKE_OFF+=	BUILD_SHARED_LIBS OCIO_BUILD_DOCS \
		OCIO_BUILD_PYGLUE OCIO_BUILD_PYTHON
LDFLAGS+=	-lOpenImageIO_Util
PLIST=		${PKGDIR}/pkg-plist-tools

.elif defined(OCIO_SLAVE) && ${OCIO_SLAVE} == pymodule
BUILD_DEPENDS+=	pybind11>0:devel/pybind11
LIB_DEPENDS+=	libOpenColorIO.so:graphics/opencolorio
USES+=		python
USE_PYTHON=	concurrent flavors
CMAKE_ARGS+=	-DOCIO_PYTHON_VERSION=${PYTHON_VER}
CMAKE_ON+=	OCIO_BUILD_PYTHON
CMAKE_OFF+=	BUILD_SHARED_LIBS OCIO_BUILD_APPS OCIO_BUILD_DOCS \
		OCIO_BUILD_GPU_TESTS OCIO_BUILD_TESTS
LDFLAGS+=	-lOpenColorIO
PLIST=		${PKGDIR}/pkg-plist-pyglue
# concurrent allows docs to not collide with master port

.else # master port
# we enable pyglue in master port. This makes the python module
# available when generating docs, we leave the python header in place
# but only install the python module with the py-opencolorio port
# this makes it easier to allow multiple python versions installed
BUILD_DEPENDS+=	pybind11>0:devel/pybind11
USES+=		python:build xorg
USE_LDCONFIG=	yes
USE_XORG=	xi xmu
CMAKE_ARGS+=	-DOCIO_PYTHON_VERSION=${PYTHON_VER}
CMAKE_ON+=	BUILD_SHARED_LIBS OCIO_BUILD_PYGLUE OCIO_BUILD_PYTHON
CMAKE_OFF+=	OCIO_BUILD_APPS
PLIST=		${PKGDIR}/pkg-plist ${PKGDIR}/pkg-plist-docs
.endif

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/share/ocio
.if defined(OCIO_SLAVE)
	cd ${STAGEDIR}${PREFIX} && \
		${RM} -r include lib/cmake lib/libOpenColorIO*.a libdata \
			share/OpenColorIO
.else
	${RM} -r ${STAGEDIR}${PREFIX}/lib/python*
.endif

post-install-DOCS-on:
	@cd ${STAGEDIR}${PREFIX}/share/doc && \
		${MV} OpenColorIO ${PKGNAMEPREFIX}${PORTNAME}
	${RM} -r ${STAGEDIR}${DOCSDIR}/html/_sources

.include <bsd.port.mk>
