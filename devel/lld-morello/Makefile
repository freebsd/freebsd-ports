PORTREVISION=	0

LLVM_COMPONENT=	lld
LLVM_VERDIR=	${.CURDIR}/../../devel/llvm-morello

COMMENT=	LLVM linker with support for Arm Morello

.include "${.CURDIR}/../../devel/llvm/Makefile.component"
FILESDIR=	${.CURDIR}/../../devel/llvm-cheri/files
PATCHDIR=	${FILESDIR}
.include <bsd.port.mk>
