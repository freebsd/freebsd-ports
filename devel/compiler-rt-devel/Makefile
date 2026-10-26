PORTREVISION=	0

LLVM_COMPONENT=	compiler-rt
LLVM_VERDIR=	${.CURDIR}/../../devel/llvm-devel

# COMPILER_RT disabled due to https://github.com/llvm/llvm-project/issues/63418
NOT_FOR_ARCHS=		aarch64 armv6 armv7
NOT_FOR_ARCHS_REASON_aarch64=	https://github.com/llvm/llvm-project/issues/63418

.include "${.CURDIR}/../../devel/llvm/Makefile.component"
.include <bsd.port.mk>
