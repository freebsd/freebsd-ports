# Created by: Shane Ambler <FreeBSD@Shaneware.biz>
# $FreeBSD$

PORTNAME=	opencolorio
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.1
PORTREVISION?=	1
CATEGORIES=	graphics multimedia

MAINTAINER?=	FreeBSD@Shaneware.biz
COMMENT?=	Complete color management solution

LICENSE=	BSD3CLAUSE

USES=		alias cmake compiler:c++11-lang localbase:ldflags pkgconfig \
		shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	imageworks
GH_PROJECT=	OpenColorIO

CMAKE_ON=	USE_EXTERNAL_TINYXML USE_EXTERNAL_YAML
CMAKE_OFF=	OCIO_BUILD_JNIGLUE OCIO_BUILD_NUKE OCIO_BUILD_STATIC

CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_gcc=	-Wno-unused-function -Wno-error
CXXFLAGS_clang=	-Wno-deprecated-register

SHEBANG_FILES=	share/sphinx/ExtractRstFromSourceCPP.py \
		share/sphinx/ExtractRstFromSourceSimple.py \
		src/pyglue/createPyDocH.py

OPTIONS_DEFINE=		DOCS

DOCS_CMAKE_BOOL=	OCIO_BUILD_DOCS

PLIST_SUB+=		LIBVERS=${PORTVERSION}

.if ${MACHINE_CPU:Msse2}
CMAKE_ON+=	OCIO_USE_SSE
.else
CMAKE_OFF+=	OCIO_USE_SSE
.endif

.include <bsd.port.options.mk>

.if defined(OCIO_SLAVE) && ${OCIO_SLAVE} == tools
LIB_DEPENDS=	liblcms2.so:graphics/lcms2 \
		libOpenImageIO.so:graphics/openimageio \
		libOpenColorIO.so:graphics/opencolorio
CMAKE_ON+=	OCIO_BUILD_APPS USE_EXTERNAL_LCMS
CMAKE_OFF+=	OCIO_BUILD_SHARED OCIO_BUILD_PYGLUE
LDFLAGS+=	-lOpenColorIO
USES+=		gl xorg
USE_GL=		gl glu glut glew
USE_XORG=	xi xmu
PLIST=		${PKGDIR}/pkg-plist-tools
EXTRA_PATCHES=	${PATCHDIR}/tools
.elif defined(OCIO_SLAVE) && ${OCIO_SLAVE} == pymodule
LIB_DEPENDS=	libOpenImageIO.so:graphics/openimageio \
		libOpenColorIO.so:graphics/opencolorio
USES+=		python
USE_PYTHON=	flavors
LDFLAGS+=	-lOpenColorIO
CMAKE_ON+=	OCIO_BUILD_PYGLUE OCIO_PYGLUE_LINK
CMAKE_OFF+=	OCIO_BUILD_APPS OCIO_BUILD_SHARED
CMAKE_ARGS+=	-DPYTHON:FILEPATH=${PYTHON_CMD}
PLIST=		${PKGDIR}/pkg-plist-pyglue
.else # master port
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR}
LIB_DEPENDS=	libtinyxml.so:textproc/tinyxml \
		libyaml-cpp03.so:devel/yaml-cpp03
USES+=		python:2.7,build
USE_LDCONFIG=	yes
CMAKE_ON+=	OCIO_BUILD_SHARED OCIO_BUILD_PYGLUE
CMAKE_OFF+=	OCIO_BUILD_APPS
CMAKE_ARGS+=	-DPYTHON:FILEPATH=${PYTHON_CMD}
# we enable pyglue in master port. This makes the python module
# available when generating docs, we leave the python header in place
# but only install the python module with the py-opencolorio port
# this makes it easier to allow multiple python versions installed
# doc building fails using python3 - but the py-opencolorio port can still
# be used to build a python 3 module
PLIST=		${PKGDIR}/pkg-plist
EXTRA_PATCHES=	${PATCHDIR}/libs
.endif

post-patch:
	@${REINPLACE_CMD} -e '/pkg_check_modules/ s|yaml-cpp|&03|' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e '/YAML_CPP_INCLUDE_DIR/ s|yaml-cpp|&03|' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e '/YAML_CPP_LIBRARY/ s|yaml-cpp|&03|' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|yaml-cpp|&03|' ${WRKSRC}/src/core/OCIOYaml.cpp
.if ${SLAVE_PORT} == yes
	@${FIND} ${WRKSRC}/src/apps -name main.cpp | ${XARGS} \
		${REINPLACE_CMD} '/namespace OIIO/d'
.endif

.if defined(OCIO_SLAVE) && ${OCIO_SLAVE} == pymodule
do-install:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_LIB} ${BUILD_WRKSRC}/src/pyglue/PyOpenColorIO.so ${STAGEDIR}${PYTHON_SITELIBDIR}
.elif !defined(OCIO_SLAVE)
post-install:
	@${RM} -R ${STAGEDIR}${PYTHON_LIBDIR}
.endif

.include <bsd.port.mk>
