PORTREVISION=	0

LLVM_COMPONENT=	lldb
LLVM_VERDIR=	${.CURDIR}/../../devel/llvm-devel

NOT_FOR_ARCHS=	riscv64

CMAKE_ARGS+=	-DLLDB_EXPORT_ALL_SYMBOLS=ON

.include "${.CURDIR}/../../devel/llvm/Makefile.component"
.include <bsd.port.mk>
