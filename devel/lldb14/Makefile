PORTREVISION=	0

LLVM_COMPONENT=	lldb
LLVM_VERDIR=	${.CURDIR}/../../devel/llvm14

NOT_FOR_ARCHS=	riscv64
NOT_FOR_ARCHS_REASON=	lldb 14 does not support FreeBSD/riscv64

# lldb 14 only works with Lua 5.3 (it must come before the framework's lua:54).
USES=		lua:53

.include "${.CURDIR}/../../devel/llvm/Makefile.component"
.include <bsd.port.mk>
