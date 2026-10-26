PORTREVISION=	0

LLVM_COMPONENT=	openmp
LLVM_VERDIR=	${.CURDIR}/../../devel/llvm15

ONLY_FOR_ARCHS=	aarch64 amd64 i386 powerpc64 powerpc64le riscv64
ONLY_FOR_ARCHS_REASON=	the LLVM 15 OpenMP runtime does not support this architecture

.include "${.CURDIR}/../../devel/llvm/Makefile.component"

# openmp < 16 ignores LIBOMP_HEADERS_INSTALL_PATH in a standalone build.
post-patch:
	${REINPLACE_CMD} -e 's|set(LIBOMP_HEADERS_INSTALL_PATH "$${CMAKE_INSTALL_INCLUDEDIR}")|set(LIBOMP_HEADERS_INSTALL_PATH "${CLANG_RESOURCE_DIR}/include")|' \
	    ${WRKSRC}/openmp/runtime/src/CMakeLists.txt

.include <bsd.port.mk>
