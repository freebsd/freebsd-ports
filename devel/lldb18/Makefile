PORTREVISION=	0

LLVM_COMPONENT=	lldb
LLVM_VERDIR=	${.CURDIR}/../../devel/llvm18

NOT_FOR_ARCHS=	riscv64
NOT_FOR_ARCHS_REASON=	lldb does not support riscv64 in this release

.include "${.CURDIR}/../../devel/llvm/Makefile.component"

# lldb < 20 requires exactly Lua 5.3 (FindLuaAndSwig.cmake).
USES:=		${USES:Nlua*} lua:53

.include <bsd.port.mk>
