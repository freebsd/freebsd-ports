PORTNAME=		cling
DISTVERSIONPREFIX=	v
DISTVERSION=		1.3
PORTREVISION=		1
CATEGORIES=		lang devel

MAINTAINER=		arrowd@FreeBSD.org
COMMENT=		Interactive C++ Interpreter Based on LLVM and Clang Libs
WWW=			https://root.cern/cling/

LICENSE=		NCSA
LICENSE_FILE=		${WRKSRC}/LICENSE.TXT

USES=		cmake gnome
USE_GNOME=	libxml2

USE_GITHUB=	yes
GH_ACCOUNT=	root-project
GH_PROJECT=	llvm-project:llvm
GH_TAGNAME=	cling-llvm20-20260119-01:llvm

CMAKE_SOURCE_PATH=${WRKSRC}/llvm/llvm
CMAKE_ARGS=	-DLLVM_EXTERNAL_PROJECTS=cling \
		-DLLVM_EXTERNAL_CLING_SOURCE_DIR=${WRKSRC} \
		-DLLVM_ENABLE_PROJECTS="clang" \
		-DLLVM_TARGETS_TO_BUILD="host;NVPTX"

ALL_TARGET=	cling
INSTALL_TARGET=	install-clang-resource-headers \
		install-cling-cmake-exports-stripped

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
# even when building with debug, disable all assertions
CFLAGS+=		-DNDEBUG -g -O0
CXXFLAGS+=		-DNDEBUG -g -O0
INSTALL_TARGET+=	tools/cling/tools/install
.else
INSTALL_TARGET+=	tools/cling/tools/install/strip
.endif

post-extract:
# for patching purposes
	${MV} ${WRKSRC_llvm} ${WRKSRC}/llvm

post-patch:
	${REINPLACE_CMD} -e 's|Interp(argc, argv)|Interp(argc, argv, "${PREFIX}/cling")|' \
		${WRKSRC}/tools/driver/cling.cpp

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/cling
	cd ${WRKSRC}/include/cling && \
		${COPYTREE_SHARE} Interpreter ${STAGEDIR}${PREFIX}/include/cling
	cd ${WRKSRC}/include/cling && \
		${COPYTREE_SHARE} MetaProcessor ${STAGEDIR}${PREFIX}/include/cling
	cd ${WRKSRC}/include/cling && \
		${COPYTREE_SHARE} UserInterface ${STAGEDIR}${PREFIX}/include/cling
	cd ${WRKSRC}/include/cling && \
		${COPYTREE_SHARE} Utils ${STAGEDIR}${PREFIX}/include/cling
	${INSTALL_DATA} ${BUILD_WRKSRC}/lib/libclingInterpreter.a ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${BUILD_WRKSRC}/lib/libclingMetaProcessor.a ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${BUILD_WRKSRC}/lib/libclingUserInterface.a ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${BUILD_WRKSRC}/lib/libclingUtils.a ${STAGEDIR}${PREFIX}/lib/

.include <bsd.port.post.mk>
