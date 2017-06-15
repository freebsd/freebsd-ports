# Created by: Shane Ambler <FreeBSD@Shaneware.biz>
# $FreeBSD$

PORTNAME=	opencolorio
PORTVERSION=	1.0.9
PORTREVISION?=	0
CATEGORIES=	graphics multimedia

MAINTAINER?=	FreeBSD@Shaneware.biz
COMMENT?=	Complete color management solution

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	imageworks
GH_PROJECT=	OpenColorIO
GH_TAGNAME=	a557a85454

OPTIONS_DEFINE=	DOCS

LDFLAGS+=	-L${LOCALBASE}/lib
USES=		alias cmake:outsource pkgconfig shebangfix
CMAKE_ARGS=	-DOCIO_BUILD_JNIGLUE:BOOL=OFF \
		-DOCIO_BUILD_NUKE:BOOL=OFF \
		-DOCIO_BUILD_STATIC:BOOL=OFF \
		-DUSE_EXTERNAL_TINYXML:BOOL=ON \
		-DUSE_EXTERNAL_YAML:BOOL=ON
SHEBANG_FILES=	share/sphinx/ExtractRstFromSourceCPP.py \
		share/sphinx/ExtractRstFromSourceSimple.py \
		src/pyglue/createPyDocH.py

#.if ${MACHINE_CPU:Msse2}
#CMAKE_ARGS+=	-DOCIO_USE_SSE:BOOL=ON
#.else
#CMAKE_ARGS+=	-DOCIO_USE_SSE:BOOL=OFF
#.endif

BROKEN_aarch64=		Does not compile: error: use of undeclared identifier __builtin_ia32_emms
BROKEN_armv6=		Does not compile: error: use of undeclared identifier __builtin_ia32_emms
BROKEN_mips64=		Does not compile: error: unrecognized command line option -msse2
BROKEN_powerpc64=	Does not build
BROKEN_sparc64=		Does not compile: error: unrecognized command line option -msse2

.include <bsd.port.options.mk>

.if defined(OCIO_SLAVE) && ${OCIO_SLAVE} == tools
LIB_DEPENDS=	libOpenImageIO.so:graphics/openimageio \
		libOpenColorIO.so:graphics/opencolorio
CMAKE_ARGS+=	-DOCIO_BUILD_APPS:BOOL=ON \
		-DOCIO_BUILD_SHARED:BOOL=OFF \
		-DOCIO_BUILD_PYGLUE:BOOL=OFF
USE_GL=		glew glut
PLIST=		${PKGDIR}/pkg-plist-tools
EXTRA_PATCHES=	${FILESDIR}/extra-patch-CMakeLists.txt \
		${FILESDIR}/extra-tools-patch-src_core_CMakeLists.txt
.elif defined(OCIO_SLAVE) && ${OCIO_SLAVE} == pymodule
LIB_DEPENDS=	libOpenImageIO.so:graphics/openimageio
USES+=		python
CMAKE_ARGS+=	-DOCIO_BUILD_APPS:BOOL=OFF \
		-DOCIO_BUILD_SHARED:BOOL=OFF \
		-DOCIO_BUILD_PYGLUE:BOOL=ON \
		-DPYTHON:STRING=${PYTHON_CMD}
PLIST=		${PKGDIR}/pkg-plist-pyglue
.else # master port
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2
LIB_DEPENDS=	libtinyxml.so:textproc/tinyxml \
		libyaml-cpp03.so:devel/yaml-cpp03
USES+=		python:2,build
USE_LDCONFIG=	yes
CMAKE_ARGS+=	-DOCIO_BUILD_APPS:BOOL=OFF \
		-DOCIO_BUILD_SHARED:BOOL=ON \
		-DOCIO_BUILD_PYGLUE:BOOL=ON \
		-DPYTHON:FILEPATH=${PYTHON_CMD}
# we enable pyglue in master port. This makes the python module
# available when generating docs, we leave the python header in place
# but only install the python module with the py-opencolorio port
# this makes it easier to allow multiple python versions installed
# doc building fails using python3 - but the py-opencolorio port can still
# be used to build a python 3 module
PLIST=		${PKGDIR}/pkg-plist
EXTRA_PATCHES=	${FILESDIR}/extra-patch-src_core_CMakeLists.txt
.endif

.if ${PORT_OPTIONS:MDOCS}
CMAKE_ARGS+=	-DOCIO_BUILD_DOCS:BOOL=ON
.else
CMAKE_ARGS+=	-DOCIO_BUILD_DOCS:BOOL=OFF
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
