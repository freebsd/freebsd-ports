PORTNAME=	opencolorio
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.1
CATEGORIES=	graphics multimedia
PKGNAMESUFFIX=	v1

MAINTAINER?=	FreeBSD@Shaneware.biz
COMMENT?=	Complete color management solution v1

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libtinyxml.so:textproc/tinyxml \
		libyaml-cpp03.so:devel/yaml-cpp03

USES=		alias cmake compiler:c++11-lang localbase:ldflags pkgconfig \
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
	${REINPLACE_CMD} -e 's|yaml-cpp|&03|' ${WRKSRC}/src/core/OCIOYaml.cpp

post-install:
	${RM} -R ${STAGEDIR}/${PREFIX}/share/ocio
	# add v1 suffix
	${REINPLACE_CMD} -e 's|<OpenColorIO/|<OpenColorIOv1/|g' \
		${STAGEDIR}/${PREFIX}/include/OpenColorIOv1/*
	${FIND} ${STAGEDIR}${PREFIX}/include/OpenColorIOv1 -name '*.bak' -delete
	@(cd ${STAGEDIR}/${PREFIX} && ${MKDIR} lib/cmake/Modules && \
		${MV} OpenColorIOv1Config.cmake lib/cmake/Modules/ && \
		${MV} cmake/OpenColorIO-release.cmake lib/cmake/Modules/OpenColorIOv1-release.cmake && \
		${MV} cmake/OpenColorIO.cmake lib/cmake/Modules/OpenColorIOv1.cmake && \
		${RMDIR} cmake)

.include <bsd.port.mk>
