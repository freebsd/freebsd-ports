PORTREVISION=	0

LLVM_COMPONENT=	compiler-rt
LLVM_VERDIR=	${.CURDIR}/../../devel/llvm15

ONLY_FOR_ARCHS=	amd64 i386 powerpc powerpc64 powerpc64le riscv64
ONLY_FOR_ARCHS_REASON=	compiler-rt 15 does not support FreeBSD on this architecture

.include "${.CURDIR}/../../devel/llvm/Makefile.component"
.include <bsd.port.mk>
