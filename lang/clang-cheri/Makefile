PORTREVISION=	0

LLVM_COMPONENT=	clang
LLVM_VERDIR=	${.CURDIR}/../../devel/llvm-cheri

COMMENT=	C language family frontend for LLVM with support for CHERI

SHEBANG_FILES=	clang/tools/clang-format/clang-format-diff.py \
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

OPTIONS_DEFINE+=	XTOOLCHAIN
OPTIONS_DEFAULT+=	XTOOLCHAIN
XTOOLCHAIN_DESC=	Install cross toolchain file

.include "${.CURDIR}/../../devel/llvm/Makefile.component"

# Makefile.component always installs share/toolchains/llvm${LLVM_SUFFIX}.mk.
.if !${PORT_OPTIONS:MXTOOLCHAIN}
PLIST_FILES:=	${PLIST_FILES:Nshare/toolchains/*}
.endif

post-install-XTOOLCHAIN-off:
	${RM} -r ${STAGEDIR}${PREFIX}/share/toolchains

.include <bsd.port.mk>
