# Created by: Mahdi Mokhtari <mokhi64@gmail.com>
# $FreeBSD$

PORTNAME=		cling
PORTVERSION=		0.4
PORTREVISION?=		3
CATEGORIES=		lang devel
MASTER_SITES=		https://root.cern.ch/download/cling/
DISTNAME=		${PORTNAME}_2016-12-29_sources

MAINTAINER=		mmokhi@FreeBSD.org
COMMENT=		Interactive C++ Interpreter Based on LLVM and Clang Libs

LICENSE=		LLVM NCSA
LICENSE_COMB=		multi
LICENSE_NAME_LLVM=	LLVM Release License
LICENSE_FILE_LLVM=	${WRKSRC}/LICENSE.TXT
LICENSE_FILE_NCSA=	${WRKSRC}/tools/cling/LICENSE.TXT
LICENSE_PERMS_LLVM=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN_armv6=		fails to compile: AArch64TargetMachine.cpp: relocation truncated to fit: R_ARM_CALL against symbol '__aeabi_uldivmod'
BROKEN_armv7=		fails to compile: AArch64TargetMachine.cpp: relocation truncated to fit: R_ARM_CALL against symbol '__aeabi_uldivmod'
BROKEN_powerpc64=	fails to compile: IncrementalParser.cpp: 'to_string' is not a member of 'std'

WRKSRC=		${WRKDIR}/src

LLVM_RELEASE=	3.9.0
LLVM_SUFFIX=	39_cern-root
LLVM_PREFIX=	${PREFIX}/llvm${LLVM_SUFFIX}

USES=		cmake:outsource compiler:c11 compiler:c++11-lib cpe \
		python:build shebangfix tar:bzip2
USE_LDCONFIG=	${LLVM_PREFIX}/lib

SHEBANG_FILES=	tools/clang/tools/clang-format/clang-format-diff.py \
		tools/clang/tools/clang-format/git-clang-format \
		tools/clang/tools/scan-view/bin/scan-view

SUB_FILES=	llvm-wrapper.sh
SUB_LIST+=	LLVM_PREFIX="${LLVM_PREFIX}" LLVM_SUFFIX="${LLVM_SUFFIX}"
PLIST_SUB+=		LLVM_SUFFIX=${LLVM_SUFFIX} LLVM_RELEASE=${LLVM_RELEASE}

CMAKE_BUILD_TYPE=	Release
CMAKE_INSTALL_PREFIX=	${LLVM_PREFIX}

CMAKE_ARGS+=	-DINSTALL_LAYOUT=FREEBSD \
	    --target ${PORTNAME}

CLING_FILES=	bin/cling \
	    lib/libcling.so \
	    lib/libclingInterpreter.a \
	    lib/libclingJupyter.so \
	    lib/libclingMetaProcessor.a \
	    lib/libclingUserInterface.a \
	    lib/libclingUtils.a \
	    include/cling/Interpreter/AutoloadCallback.h \
	    include/cling/Interpreter/CIFactory.h \
	    include/cling/Interpreter/CValuePrinter.h \
	    include/cling/Interpreter/ClangInternalState.h \
	    include/cling/Interpreter/ClingCodeCompleteConsumer.h \
	    include/cling/Interpreter/ClingOptions.h \
	    include/cling/Interpreter/CompilationOptions.h \
	    include/cling/Interpreter/DynamicExprInfo.h \
	    include/cling/Interpreter/DynamicLibraryManager.h \
	    include/cling/Interpreter/DynamicLookupLifetimeHandler.h \
	    include/cling/Interpreter/DynamicLookupRuntimeUniverse.h \
	    include/cling/Interpreter/Exception.h \
	    include/cling/Interpreter/Interpreter.h \
	    include/cling/Interpreter/InterpreterCallbacks.h \
	    include/cling/Interpreter/InvocationOptions.h \
	    include/cling/Interpreter/LookupHelper.h \
	    include/cling/Interpreter/RuntimePrintValue.h \
	    include/cling/Interpreter/RuntimeUniverse.h \
	    include/cling/Interpreter/Transaction.h \
	    include/cling/Interpreter/Value.h \
	    include/cling/MetaProcessor/MetaProcessor.h \
	    include/cling/UserInterface/UserInterface.h \
	    include/cling/UserInterface/textinput/Callbacks.h \
	    include/cling/UserInterface/textinput/Color.h \
	    include/cling/UserInterface/textinput/Display.h \
	    include/cling/UserInterface/textinput/Editor.h \
	    include/cling/UserInterface/textinput/History.h \
	    include/cling/UserInterface/textinput/InputData.h \
	    include/cling/UserInterface/textinput/KeyBinding.h \
	    include/cling/UserInterface/textinput/Range.h \
	    include/cling/UserInterface/textinput/Reader.h \
	    include/cling/UserInterface/textinput/SignalHandler.h \
	    include/cling/UserInterface/textinput/StreamReader.h \
	    include/cling/UserInterface/textinput/StreamReaderUnix.h \
	    include/cling/UserInterface/textinput/StreamReaderWin.h \
	    include/cling/UserInterface/textinput/TerminalConfigUnix.h \
	    include/cling/UserInterface/textinput/TerminalDisplay.h \
	    include/cling/UserInterface/textinput/TerminalDisplayUnix.h \
	    include/cling/UserInterface/textinput/TerminalDisplayWin.h \
	    include/cling/UserInterface/textinput/Text.h \
	    include/cling/UserInterface/textinput/TextInput.h \
	    include/cling/UserInterface/textinput/TextInputContext.h \
	    include/cling/Utils/AST.h \
	    include/cling/Utils/Output.h \
	    include/cling/Utils/ParserStateRAII.h \
	    include/cling/Utils/Paths.h \
	    include/cling/Utils/Platform.h \
	    include/cling/Utils/SourceNormalization.h \
	    include/cling/Utils/Validation.h
FIRST_FILE=	${CLING_FILES:C/^/XXXX/1:MXXXX*:C/^XXXX//}

post-patch:
	@${REINPLACE_CMD} -e 's|%%LLVM_PREFIX%%|${LLVM_PREFIX}|g' \
	    ${PATCH_WRKSRC}/tools/cling/tools/driver/cling.cpp
	@${REINPLACE_CMD} -e 's|%%LLVM_PREFIX%%|${LLVM_PREFIX}|g' \
	    ${PATCH_WRKSRC}/tools/cling/lib/Interpreter/CIFactory.cpp

post-install:
	${RM} ${STAGEDIR}${LLVM_PREFIX}/man/man1/scan-build.1
	${RM} -rf ${STAGEDIR}${LLVM_PREFIX}/man
	${INSTALL_SCRIPT} ${WRKDIR}/llvm-wrapper.sh \
	    ${STAGEDIR}${PREFIX}/${FIRST_FILE}
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}/Interpreter
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}/MetaProcessor
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}/UserInterface/textinput
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}/Utils
.for file in ${CLING_FILES:C/^/XXXX/1:NXXXX*}
	${LN} -f ${STAGEDIR}${PREFIX}/${FIRST_FILE} ${STAGEDIR}${PREFIX}/${file}
.endfor

.include <bsd.port.mk>
