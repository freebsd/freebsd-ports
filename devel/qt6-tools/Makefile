PORTNAME=	tools
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	devel
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt declarative framework for dynamic user interfaces

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon \
		libzstd.so:archivers/zstd

USES=		cmake compiler:c++17-lang gl llvm:min=17,max=21,lib,noexport \
		python:build qt-dist:6
USE_GL=		opengl
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}
USE_QT=		base declarative sqldriver-sqlite:run

CMAKE_ARGS=	-DClang_DIR:PATH="${LLVM_PREFIX}/lib/cmake/clang" \
		-DLLVM_DIR:PATH="${LLVM_PREFIX}/lib/cmake/llvm"
# QDOC_USER_CLANG_VERSION is a custom CMake variable intended to override the
# list of supported LLVM versions, i.e., QDOC_SUPPORTED_CLANG_VERSIONS in
# src/qdoc/cmake/QDocConfiguration.cmake with the chosen version of LLVM.
# Otherwise, the numerically greatest version found would be used. We must be
# careful here and adjust llvm min/max in USES to align with the versions
# of LLVM that future releases support. We also need to supply at least a
# major.minor version of llvm for this variable. Since LLVM_VERSION only provides
# the major version, we pass the full version via a command and let CMake process
# it during the configure stage.
CMAKE_ARGS+=	-DQDOC_USER_CLANG_VERSION:STRING="`${LLVM_CONFIG} --version`"

post-install:
# Install symlinks for user-facing tools
	while read line; do \
		source="$$(${ECHO_CMD} $${line} | ${AWK} '{print $$1}')"; \
		target="${STAGEDIR}${PREFIX}/$$(${ECHO_CMD} $${line} | ${AWK} '{print $$2}')"; \
		${RLN} $${source} $${target}; \
	done <${BUILD_WRKSRC}/user_facing_tool_links.txt

.include <bsd.port.mk>
