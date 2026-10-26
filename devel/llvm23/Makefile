PORTREVISION=	1

LLVM_COMPONENT=	llvm
LLVM_VERDIR=	${.CURDIR}

# LLVM 23 does not build the gold plugin.
OPTIONS_EXCLUDE=	GOLD

SHEBANG_FILES=	llvm/tools/opt-viewer/opt-diff.py \
		llvm/tools/opt-viewer/opt-stats.py \
		llvm/tools/opt-viewer/opt-viewer.py \
		llvm/tools/opt-viewer/optrecord.py \
		llvm/utils/lit/lit.py \
		llvm/utils/llvm-lit/llvm-lit.in

.include "${.CURDIR}/../llvm/Makefile.component"
.include <bsd.port.mk>
