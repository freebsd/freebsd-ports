PORTNAME=	shaderc
DISTVERSIONPREFIX=	v
DISTVERSION=	2025.4
PORTREVISION=	1
CATEGORIES=	graphics devel

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	GLSL/HLSL to SPIR-V shader compiler
WWW=		https://github.com/google/shaderc

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	glslang>0:graphics/glslang \
		spirv-tools>0:graphics/spirv-tools
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++11-lib localbase:ldflags \
		python:build shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_TUPLE=	KhronosGroup:SPIRV-Headers:1.5.4.raytracing.fixed-446-g01e0577:headers/third_party/spirv-headers

USE_LDCONFIG=	yes

SHEBANG_FILES=	utils/add_copyright.py

CMAKE_ARGS=	-Dglslang_SOURCE_DIR:PATH="${LOCALBASE}/include/glslang" \
		-DSPIRV-Headers_SOURCE_DIR:PATH="${WRKSRC}/third_party/spirv-headers"
CMAKE_ON+=	${CMAKE_TESTING_OFF}
CMAKE_TESTING_OFF=	SHADERC_SKIP_TESTS

LDFLAGS+=	-Wl,-z,defs # glslang

PORTDOCS=	AUTHORS CHANGES CONTRIBUTING.md CONTRIBUTORS \
		DEVELOPMENT.howto.md README.md

OPTIONS_DEFINE=	DOCS

post-patch:
# Disable bundled dependencies
	${REINPLACE_CMD} '/third_party/d' ${WRKSRC}/CMakeLists.txt
# Unbreak tests with system spirv-tools
	${REINPLACE_CMD} 's,\$$<TARGET_FILE:\(spirv-dis\)>,\1,' \
		${WRKSRC}/glslc/test/CMakeLists.txt

pre-configure:
# Extract (snapshot) version from the port instead of CHANGES + .git/
	${REINPLACE_CMD} '/build-version/d' ${WRKSRC}/glslc/CMakeLists.txt
	${ECHO_CMD} "\"${PORTNAME} ${DISTVERSIONFULL}\n\"" >> ${WRKSRC}/glslc/src/build-version.inc
	${ECHO_CMD} "\"`${PKG_BIN} query '%n v%v' spirv-tools`\n\"" >> ${WRKSRC}/glslc/src/build-version.inc
	${ECHO_CMD} "\"`${PKG_BIN} query '%n %v' glslang`\n\"" >> ${WRKSRC}/glslc/src/build-version.inc

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
