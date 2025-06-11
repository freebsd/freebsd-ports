PORTNAME=	tools
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	devel
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt declarative framework for dynamic user interfaces

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon \
		libzstd.so:archivers/zstd

USES=		cmake compiler:c++17-lang gl llvm:min=17,max=20,lib,noexport \
		python:build qt-dist:6
USE_GL=		opengl
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}
USE_QT=		base declarative sqldriver-sqlite:run

# QDOC_USER_CLANG_VERSION is an unofficial CMake variable intended to override
# the list of supported LLVM versions, i.e., QDOC_SUPPORTED_CLANG_VERSIONS in
# .cmake.conf with the chosen version of LLVM. We must be careful here and adjust
# llvm min/max in USES to align with the versions of LLVM that future releases
# support. LLVM_VERSION only provides the major version, but at least the minor
# version must also be passed, hence the use of "black magic" to determine this
# value, which does not respect relative paths.
CMAKE_ARGS=	-DClang_DIR:PATH="${LLVM_PREFIX}/lib/cmake/clang" \
		-DLLVM_DIR:PATH="${LLVM_PREFIX}/lib/cmake/llvm" \
		-DQDOC_USER_CLANG_VERSION:STRING="`${MAKE} -C ${PORTSDIR}/devel/llvm${LLVM_VERSION} -VDISTVERSION:R`"

post-install:
# Install symlinks for user-facing tools
	while read line; do \
		source="$$(${ECHO_CMD} $${line} | ${AWK} '{print $$1}')"; \
		target="${STAGEDIR}${PREFIX}/$$(${ECHO_CMD} $${line} | ${AWK} '{print $$2}')"; \
		${RLN} $${source} $${target}; \
	done <${BUILD_WRKSRC}/user_facing_tool_links.txt

.include <bsd.port.mk>
