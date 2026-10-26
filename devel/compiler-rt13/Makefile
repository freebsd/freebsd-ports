PORTREVISION=	0

LLVM_COMPONENT=	compiler-rt
LLVM_VERDIR=	${.CURDIR}/../../devel/llvm13

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	compiler-rt 13 does not support FreeBSD on this architecture

.include "${.CURDIR}/../../devel/llvm/Makefile.component"
.include <bsd.port.mk>
