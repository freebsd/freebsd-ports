PORTREVISION=	0

LLVM_COMPONENT=	flang
LLVM_VERDIR=	${.CURDIR}/../../devel/llvm14

NOT_FOR_ARCHS=	armv6 armv7 i386 powerpc
NOT_FOR_ARCHS_REASON=	flang 14 requires a 64-bit architecture

# flang < 16 looks for ClangConfig.cmake via CLANG_DIR.
CMAKE_ARGS+=	-DCLANG_DIR=${LLVM_PREFIX}/lib/cmake/clang

.include "${.CURDIR}/../../devel/llvm/Makefile.component"
.include <bsd.port.mk>
