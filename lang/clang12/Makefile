PORTREVISION=	0

LLVM_COMPONENT=	clang
LLVM_VERDIR=	${.CURDIR}/../../devel/llvm12

SHEBANG_FILES=	clang-tools-extra/clang-include-fixer/find-all-symbols/tool/run-find-all-symbols.py \
		clang-tools-extra/clang-tidy/tool/clang-tidy-diff.py \
		clang-tools-extra/clang-tidy/tool/run-clang-tidy.py \
		clang/tools/clang-format/clang-format-diff.py \
		clang/tools/clang-format/git-clang-format \
		clang/tools/scan-view/bin/scan-view \
		clang/utils/hmaptool/hmaptool

.include "${.CURDIR}/../../devel/llvm/Makefile.component"
.include <bsd.port.mk>
