PORTREVISION=	0

LLVM_COMPONENT=	compiler-rt
LLVM_VERDIR=	${.CURDIR}/../../devel/llvm18

NOT_FOR_ARCHS=	armv6 armv7
NOT_FOR_ARCHS_REASON=	compiler-rt is not supported on 32-bit arm

.include "${.CURDIR}/../../devel/llvm/Makefile.component"
.include <bsd.port.mk>
