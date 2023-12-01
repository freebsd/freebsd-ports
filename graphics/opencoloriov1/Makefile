PORTNAME=	opencolorio
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.1
CATEGORIES=	graphics multimedia
PKGNAMESUFFIX=	v1

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Complete color management solution (legacy version)
WWW=		https://opencolorio.org/

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libtinyxml.so:textproc/tinyxml \
		libyaml-cpp.so:devel/yaml-cpp

USES=		alias cmake compiler:c++11-lang pkgconfig \
		python:build shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	AcademySoftwareFoundation
GH_PROJECT=	OpenColorIO

CMAKE_ON=	USE_EXTERNAL_TINYXML USE_EXTERNAL_YAML OCIO_BUILD_SHARED
CMAKE_OFF=	OCIO_BUILD_APPS OCIO_BUILD_JNIGLUE OCIO_BUILD_NUKE \
		OCIO_BUILD_PYGLUE OCIO_BUILD_STATIC OCIO_BUILD_DOCS
CMAKE_ARGS+=	-DPYTHON:FILEPATH=${PYTHON_CMD}

CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_gcc=	-Wno-unused-function -Wno-error
CXXFLAGS_clang=	-Wno-deprecated-register
USE_LDCONFIG=	yes

SHEBANG_FILES=	share/sphinx/ExtractRstFromSourceCPP.py \
		share/sphinx/ExtractRstFromSourceSimple.py \
		src/pyglue/createPyDocH.py

PLIST_SUB=	SHL3=${PORTVERSION} SHL1=${PORTVERSION:R:R}

.if (defined(MACHINE_CPU) && ${MACHINE_CPU:Msse2})
CMAKE_ON+=	OCIO_USE_SSE
.else
CMAKE_OFF+=	OCIO_USE_SSE
.endif

post-patch:
	@${REINPLACE_CMD} -e 's| : std::binary_function.*||' \
		${WRKSRC}/src/core/PathUtils.h

post-install:
	@${REINPLACE_CMD} -e 's|e <OpenColorIO|&v1|' \
		${STAGEDIR}${PREFIX}/include/OpenColorIOv1/*[Os].h
	@(cd ${STAGEDIR}${PREFIX} && ${MKDIR} lib/cmake/Modules && \
		${MV} OpenColorIOv1Config.cmake lib/cmake/Modules && \
		${MV} cmake/OpenColorIO-release.cmake \
			lib/cmake/Modules/OpenColorIOv1-release.cmake && \
		${MV} cmake/OpenColorIO.cmake \
			lib/cmake/Modules/OpenColorIOv1.cmake && \
		${RMDIR} cmake)

.include <bsd.port.mk>
