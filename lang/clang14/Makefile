PORTREVISION=	0

LLVM_COMPONENT=	clang
LLVM_VERDIR=	${.CURDIR}/../../devel/llvm14

SHEBANG_FILES=	clang-tools-extra/clang-include-fixer/find-all-symbols/tool/run-find-all-symbols.py \
		clang-tools-extra/clang-tidy/tool/clang-tidy-diff.py \
		clang-tools-extra/clang-tidy/tool/run-clang-tidy.py \
		clang/tools/clang-format/clang-format-diff.py \
		clang/tools/clang-format/git-clang-format \
		clang/tools/scan-build-py/bin/analyze-build \
		clang/tools/scan-build-py/bin/intercept-build \
		clang/tools/scan-build-py/bin/scan-build \
		clang/tools/scan-build-py/libexec/analyze-c++ \
		clang/tools/scan-build-py/libexec/analyze-cc \
		clang/tools/scan-build-py/libexec/intercept-c++ \
		clang/tools/scan-build-py/libexec/intercept-cc \
		clang/tools/scan-view/bin/scan-view \
		clang/utils/hmaptool/hmaptool

.include "${.CURDIR}/../../devel/llvm/Makefile.component"

# libclang keeps the soname of LLVM 13 in this release.
post-install:
	${LN} -sf libclang.so.13 ${STAGEDIR}${LLVM_PREFIX}/lib/libclang.so.${LLVM_MAJOR}

.include <bsd.port.mk>
