PORTNAME=	spirv-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	2025.4 # please always bump all dependencies when updated because at least graphics/shaderc links in static libraries
CATEGORIES=	graphics

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Tools for processing SPIR-V intermediate shader language modules
WWW=		https://github.com/KhronosGroup/SPIRV-Tools

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++11-lib python:build shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	SPIRV-Tools
GH_TUPLE=	KhronosGroup:SPIRV-Headers:1.5.4.raytracing.fixed-446-g01e0577:headers/external/spirv-headers

USE_LDCONFIG=	yes

SHEBANG_FILES=	tools/lesspipe/spirv-lesspipe.sh

CMAKE_ON=		SPIRV_SKIP_TESTS
CMAKE_TESTING_OFF=	SPIRV_SKIP_TESTS

PORTDOCS=	CHANGES CONTRIBUTING.md README.md SECURITY.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
