PORTREVISION=	1

LLVM_COMPONENT=	llvm
LLVM_VERDIR=	${.CURDIR}

COMMENT=	LLVM core libraries and tools with support for CHERI

SHEBANG_FILES=	llvm/tools/opt-viewer/opt-diff.py \
		llvm/tools/opt-viewer/opt-stats.py \
		llvm/tools/opt-viewer/opt-viewer.py \
		llvm/tools/opt-viewer/optrecord.py \
		llvm/utils/lit/lit.py \
		llvm/utils/llvm-lit/llvm-lit.in

.include "${.CURDIR}/../llvm/Makefile.component"
.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == "clang" && ${COMPILER_VERSION} >= 210
EXTRA_PATCHES+=	${PATCHDIR}/clang21-patch-llvm_tools_sancov_sancov.cpp
.endif

.include <bsd.port.post.mk>
