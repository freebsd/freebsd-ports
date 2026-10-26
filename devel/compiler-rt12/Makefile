PORTREVISION=	0

LLVM_COMPONENT=	compiler-rt
LLVM_VERDIR=	${.CURDIR}/../../devel/llvm12

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	compiler-rt 12 does not support FreeBSD on this architecture

.include "${.CURDIR}/../../devel/llvm/Makefile.component"
.include <bsd.port.mk>
