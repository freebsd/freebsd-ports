PORTREVISION=	0

LLVM_COMPONENT=	flang
LLVM_VERDIR=	${.CURDIR}/../../devel/llvm18

NOT_FOR_ARCHS=	armv6 armv7 i386 powerpc
NOT_FOR_ARCHS_REASON=	flang is only supported on 64-bit platforms

.include "${.CURDIR}/../../devel/llvm/Makefile.component"
.include <bsd.port.mk>
