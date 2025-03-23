PORTNAME=		cling
DISTVERSIONPREFIX=	v
DISTVERSION=		1.2
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
GH_TAGNAME=	cling-llvm18-20250207-01:llvm

CMAKE_SOURCE_PATH=${WRKSRC}/llvm/llvm
CMAKE_ARGS=	-DLLVM_EXTERNAL_PROJECTS=cling \
		-DLLVM_EXTERNAL_CLING_SOURCE_DIR=${WRKSRC} \
		-DLLVM_ENABLE_PROJECTS="clang" \
		-DLLVM_TARGETS_TO_BUILD="host;NVPTX"
# cling fails quickly with assertions enabled
CMAKE_ARGS+=	-DLLVM_ENABLE_ASSERTIONS:BOOL=OFF

ALL_TARGET=	cling

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CFLAGS=		-DNDEBUG -g -O0
CXXFLAGS=	-DNDEBUG -g -O0
INSTALL_TARGET=	tools/cling/tools/install
.else
INSTALL_TARGET=	tools/cling/tools/install/strip
.endif

post-extract:
# for patching purposes
	${MV} ${WRKSRC_llvm} ${WRKSRC}/llvm

.include <bsd.port.post.mk>
