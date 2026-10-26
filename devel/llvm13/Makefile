PORTREVISION=	10

LLVM_COMPONENT=	llvm
LLVM_VERDIR=	${.CURDIR}

SHEBANG_FILES=	llvm/tools/opt-viewer/opt-diff.py \
		llvm/tools/opt-viewer/opt-stats.py \
		llvm/tools/opt-viewer/opt-viewer.py \
		llvm/tools/opt-viewer/optrecord.py \
		llvm/utils/lit/lit.py \
		llvm/utils/llvm-lit/llvm-lit.in

# LLVM likes to pick up ${LOCALBASE}/lib/libtinfo.so.*
CMAKE_ARGS+=	-DLLVM_ENABLE_TERMINFO=OFF

.include "${.CURDIR}/../llvm/Makefile.component"
.include <bsd.port.mk>
