PORTNAME=	llvm
PORTVERSION=	${LLVM_MAJOR}.0.d${SNAPDATE}
PORTREVISION=	1
CATEGORIES=	devel lang
PKGNAMESUFFIX=	${LLVM_SUFFIX}

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	LLVM and Clang
WWW=		https://llvm.org/

.include "Makefile.LICENSE"

LIB_DEPENDS=	libzstd.so:archivers/zstd

FLAVORS=	default lite
FLAVOR?=	${FLAVORS:[1]}
lite_PKGNAMESUFFIX=	${LLVM_SUFFIX}-lite

LLVM_MAJOR_MINOR=${LLVM_RELEASE:C/\.[0-9]$//}
LLVM_SUFFIX=	-devel
LLVM_DIR=	llvm${LLVM_SUFFIX}
LLVM_PREFIX=	${PREFIX}/${LLVM_DIR}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${LLVM_SUFFIX}
DATADIR=	${PREFIX}/share/${PORTNAME}${LLVM_SUFFIX}

USES=		cmake compiler:c++17-lang cpe shebangfix
_USES_PYTHON?=	python:build
USES+=		${_USES_PYTHON}
USE_LDCONFIG=	${LLVM_PREFIX}/lib
SHEBANG_FILES=	\
		clang-tools-extra/clang-include-fixer/find-all-symbols/tool/run-find-all-symbols.py \
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
		clang/utils/hmaptool/hmaptool \
		llvm/tools/opt-viewer/opt-diff.py \
		llvm/tools/opt-viewer/opt-stats.py \
		llvm/tools/opt-viewer/opt-viewer.py \
		llvm/tools/opt-viewer/optrecord.py \
		llvm/utils/lit/lit.py \
		llvm/utils/llvm-lit/llvm-lit.in
LIT_MOD_NAME=	lit${LLVM_SUFFIX:S/-/_/g}

SUB_FILES=	llvm-wrapper.sh
SUB_LIST=	LLVM_PREFIX="${LLVM_PREFIX}" LLVM_SUFFIX="${LLVM_SUFFIX}"

CMAKE_INSTALL_PREFIX=	${LLVM_PREFIX}
CMAKE_SOURCE_PATH=	${WRKSRC}/llvm
CMAKE_ARGS=	-DLLVM_BUILD_LLVM_DYLIB=ON
CMAKE_ARGS+=	-DLLVM_LINK_LLVM_DYLIB=ON
CMAKE_ARGS+=	-DCMAKE_BUILD_WITH_INSTALL_RPATH=ON
CMAKE_ARGS+=	-DLLVM_ENABLE_RTTI=ON
CMAKE_ARGS+=	-DLLVM_DEFAULT_TARGET_TRIPLE=${CONFIGURE_TARGET}
CMAKE_ARGS+=	-DLLVM_HOST_TRIPLE=${CONFIGURE_TARGET}
CMAKE_ARGS+=	-DLLVM_PARALLEL_LINK_JOBS=1
CMAKE_ARGS+=	-DLLVM_ENABLE_Z3_SOLVER=OFF
CMAKE_ARGS+=	-DLLVM_ENABLE_LIBXML2=OFF
CMAKE_ARGS+=	-DLLVM_ENABLE_LIBEDIT=OFF
CMAKE_ARGS+=	-DLLVM_ENABLE_ASSERTIONS=ON

USE_GITHUB=	yes
GH_PROJECT=	llvm-project
GH_TAGNAME=	${LLVM_PROJECT_COMMIT}

.include "Makefile.snapshot"

OPTIONS_DEFINE=		CLANG COMPILER_RT DOCS LLD STATIC_LIBS
OPTIONS_DEFAULT=	CLANG LLD
OPTIONS_EXCLUDE_armv6=	COMPILER_RT
OPTIONS_EXCLUDE_armv7=	COMPILER_RT
OPTIONS_SUB=	yes
.if !${FLAVOR:Mlite}
OPTIONS_DEFINE+=	EXTRAS FLANG LIT LLDB MLIR OPENMP POLLY
OPTIONS_DEFINE_amd64=	GOLD
OPTIONS_DEFINE_powerpc=	GOLD
OPTIONS_DEFINE_powerpc64=	GOLD
OPTIONS_DEFINE_powerpc64le=	GOLD

OPTIONS_DEFAULT+=	COMPILER_RT EXTRAS FLANG LIT LLDB MLIR OPENMP POLLY \
			STATIC_LIBS
OPTIONS_DEFAULT_amd64=	GOLD
OPTIONS_DEFAULT_powerpc=	GOLD
OPTIONS_DEFAULT_powerpc64=	GOLD
OPTIONS_DEFAULT_powerpc64le=	GOLD

# COMPILER_RT disabled due to https://github.com/llvm/llvm-project/issues/63418
OPTIONS_EXCLUDE_aarch64=	COMPILER_RT FLANG OPENMP
OPTIONS_EXCLUDE_armv6+=	FLANG OPENMP
OPTIONS_EXCLUDE_armv7+=	FLANG OPENMP
OPTIONS_EXCLUDE_i386=	FLANG OPENMP
OPTIONS_EXCLUDE_powerpc=	FLANG OPENMP
OPTIONS_EXCLUDE_riscv64=	LLDB
.endif

_ALL_OPTIONS=	CLANG COMPILER_RT DOCS EXTRAS FLANG GOLD LIT LLD LLDB MLIR \
		OPENMP POLLY STATIC_LIBS

CLANG_DESC=	Build clang
CLANG_CMAKE_ON=		-DCLANG_DEFAULT_OPENMP_RUNTIME=libomp
CLANG_PORTDOCS=		clang
CLANG_PLIST_FILES=	share/toolchains/llvm${LLVM_SUFFIX}.mk
CLANG_SUB_FILES=	xtoolchain.mk
CLANG_SUB_LIST=		XCC=clang${LLVM_SUFFIX} \
			XCXX=clang++${LLVM_SUFFIX} \
			XCPP=clang-cpp${LLVM_SUFFIX} \
			XLD=ld.lld${LLVM_SUFFIX} \
			X_COMPILER_TYPE=clang
CLANG_USES=		perl5
.if ${FLAVOR:Mlite}
# scan-build does require perl, but lite users can install it manually.
CLANG_USE=		PERL5=build
.endif
COMPILER_RT_DESC=	Sanitizer libraries
COMPILER_RT_IMPLIES=	CLANG
COMPILER_RT_PLIST_FILES=${_COMPILER_RT_LIBS}
COMPILER_RT_CONFLICTS_BUILD=${ARCH}-binutils
DOCS_BUILD_DEPENDS= \
	${PYTHON_PKGNAMEPREFIX}myst-parser>0:textproc/py-myst-parser@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}recommonmark>=0.0.20180530:textproc/py-recommonmark@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}sphinx-markdown-tables>=0:textproc/py-sphinx-markdown-tables@${PY_FLAVOR}
DOCS_PORTDOCS=		llvm
DOCS_CMAKE_ON= \
	-DLLVM_ENABLE_SPHINX=ON \
	-DSPHINX_EXECUTABLE=${LOCALBASE}/bin/sphinx-build-${PYTHON_VER} \
	-DSPHINX_WARNINGS_AS_ERRORS=OFF \
	-DLLVM_BUILD_DOCS=ON
DOCS_PLIST_FILES=	${MAN1SRCS:S|^|share/man/man1/|:S|.1$|${LLVM_SUFFIX}.1.gz|}
EXTRAS_DESC=		Extra clang tools
EXTRAS_IMPLIES=		CLANG
EXTRAS_PLIST_DIRS=	${LLVM_DIR}/include/clang-tidy/plugin
FLANG_DESC=		Flang FORTRAN compiler
FLANG_IMPLIES=		MLIR
FLANG_PORTDOCS=		flang
FLANG_PLIST_DIRS=	${LLVM_DIR}/include/flang/Config
GOLD_DESC=		Build the LLVM Gold plugin for LTO
GOLD_CMAKE_ON=		-DLLVM_BINUTILS_INCDIR=${LOCALBASE}/include
GOLD_BUILD_DEPENDS=	${LOCALBASE}/bin/ld.gold:devel/binutils
GOLD_PLIST_FILES=	${LLVM_DIR}/lib/LLVMgold.so
LIT_DESC=		Install lit and FileCheck test tools
LIT_VARS=		_USES_PYTHON=python
LIT_PLIST_SUB=		LIT_MOD_NAME=${LIT_MOD_NAME}
LLD_DESC=		Install lld, the LLVM linker
LLDB_BUILD_DEPENDS=	\
	${PYTHON_PKGNAMEPREFIX}pexpect>0:misc/py-pexpect@${PY_FLAVOR} \
	swig:devel/swig
LLDB_DESC=		Install lldb, the LLVM debugger
LLDB_IMPLIES=		CLANG
LLDB_PLIST_SUB=		PYTHON_ABIVER=${PYTHON_ABIVER}
LLDB_USES=		gnome lua:54 libedit
LLDB_USE=		GNOME=libxml2
LLDB_VARS=		_USES_PYTHON=python
MLIR_DESC=		Multi-Level Intermediate Representation
OPENMP_DESC=		Install libomp, the LLVM OpenMP runtime library
OPENMP_CMAKE_ON= \
	-DLIBOMPTARGET_BUILD_DEVICERTL_BCLIB=OFF \
	-DLIBOMPTARGET_DEP_LIBFFI_INCLUDE_DIR="" \
	-DLIBOMPTARGET_DEP_LIBFFI_LIBRARIES=""
POLLY_DESC=		Polyhedral loop and data-locality optimizer
POLLY_PORTDOCS=	polly
STATIC_LIBS_DESC= Install static libraries (does not effect sanitizers)

CONFLICTS_INSTALL=	${PORTNAME}${LLVM_SUFFIX} ${PORTNAME}${LLVM_SUFFIX}-lite

PLIST_SUB+=	CONFIGURE_TARGET=${CONFIGURE_TARGET} \
		LLVM_MAJOR_MINOR=${LLVM_MAJOR_MINOR} \
		LLVM_MAJOR=${LLVM_MAJOR} \
		LLVM_RELEASE=${LLVM_RELEASE}

COMMANDS=	${LLVM_COMMANDS}
FIRST_COMMAND=	${COMMANDS:C/^/XXXX/1:MXXXX*:C/^XXXX//}

MAN1SRCS+=	${LLVM_MAN1SRCS}

STRIP_LIBS=	BugpointPasses.so \
		LLVMHello.so \
		${LIBNAME}.0 \
		libLTO.so

EXTRAS_LIBS=	\
		libclangApplyReplacements \
		libclangChangeNamespace \
		libclangDaemon \
		libclangDoc \
		libclangIncludeCleaner \
		libclangIncludeFixer \
		libclangMove \
		libclangPseudo \
		libclangQuery \
		libclangRename \
		libclangReorderFields \
		libclangTidy \
		libclangTidyGoogleModule \
		libclangTidyLLVMModule \
		libclangTidyMiscModule \
		libclangTidyReadabilityModule \
		libclangTidyUtils \
		libfindAllSymbols \
		libmodernizeCore
EXTRAS_FILES=	index.js
EXTRAS_PATTERN=	${EXTRAS_COMMANDS:tW:C/  */|/g}|${EXTRAS_LIBS:tW:C/  */|/g}|${EXTRAS_FILES:tW:C/  */|/g}

FLANG_PATTERN=	${FLANG_COMMANDS:S/^/bin./:tW:C/  */|/g}|flang|libCUF|libFIR|libFlang|libFortran|libHLFIR|ISO_Fortran_binding.h

MLIR_PATTERN=	${MLIR_COMMANDS:S/^/bin./:tW:C/  */|/g}|mlir|libMLIR|obj.MLIRCAP

.include <bsd.port.options.mk>

# keep in sync with /usr/src/lib/clang/clang.build.mk
# ----------- start of sync block ------------------
# Armv6 and armv7 uses hard float abi, unless the CPUTYPE has soft in it.
# arm (for armv4 and armv5 CPUs) always uses the soft float ABI.
# For all other targets, we stick with 'unknown'.
.if ${ARCH:Marmv[67]*} && (!defined(CPUTYPE) || ${CPUTYPE:M*soft*} == "")
TARGET_ABI=	-gnueabihf
.elif ${ARCH:Marm*}
TARGET_ABI=	-gnueabi
.else
TARGET_ABI=
.endif

CONFIGURE_TARGET:=${ARCH:C/amd64/x86_64/:C/arm64/aarch64/}-portbld-${OPSYS:tl}${OSREL}${TARGET_ABI}
# ----------- end of sync block --------------------

.if ${PORT_OPTIONS:MCLANG}
LLVM_ENABLE_PROJECTS+=	clang
COMMANDS+=	${CLANG_COMMANDS}
MAN1SRCS+=	${CLANG_MAN1SRCS}
CLANG_PATTERN=	(amdgpu-arch|c-index-test|clang|diagtool|hmaptool|intercept-|libear|libscanbuild|nvptx-arch|analyze-|scan-|Reporter.py|ScanView.py|scanview.css|sorttable.js|startfile.py|c..-analyzer|AnalyzerPlugin.so)
.endif

.if ${PORT_OPTIONS:MCOMPILER_RT}
LLVM_ENABLE_RUNTIMES+=	compiler-rt
COMPILER_RT_PATTERN=	(sanitizer|include.xray|include\/(fuzzer|orc)|profile\/InstrProfData.inc|profile\/instr_prof_interface.h)
.endif

.if ${PORT_OPTIONS:MEXTRAS}
LLVM_ENABLE_PROJECTS+=	clang-tools-extra
COMMANDS+=	${EXTRAS_COMMANDS}
MAN1SRCS+=	${EXTRAS_MAN1SRCS}
PORTDOCS+=	clang-tools
.endif

.if ${PORT_OPTIONS:MFLANG}
LLVM_ENABLE_PROJECTS+=	flang
LLVM_ENABLE_RUNTIMES+=	flang-rt
COMMANDS+=	${FLANG_COMMANDS}
MAN1SRCS+=	${FLANG_MAN1SRCS}
.endif

.if ${PORT_OPTIONS:MLIT}
MAN1SRCS+=	${LIT_MAN1SRCS}
.endif

.if ${PORT_OPTIONS:MLLD}
LLVM_ENABLE_PROJECTS+=	lld
COMMANDS+=	${LLD_COMMANDS}
PORTDOCS+=	lld
.endif

.if ${PORT_OPTIONS:MLLDB}
LLVM_ENABLE_PROJECTS+=	lldb
MAN1SRCS+=	${LLDB_MAN1SRCS}
COMMANDS+=	${LLDB_COMMANDS}
.endif

.if ${PORT_OPTIONS:MMLIR}
LLVM_ENABLE_PROJECTS+=	mlir
MAN1SRCS+=	${MLIR_MAN1SRCS}
COMMANDS+=	${MLIR_COMMANDS}
.endif

.if ${PORT_OPTIONS:MOPENMP}
LLVM_ENABLE_RUNTIMES+=	openmp
USE_LDCONFIG+=	${LLVM_PREFIX}/lib/${CONFIGURE_TARGET}
MAN1SRCS+=	${OPENMP_MAN1SRCS}
COMMANDS+=	${OPENMP_COMMANDS}
.endif
#OPENMP_PATTERN=	${OPENMP_COMMANDS:tW:C/  */|/g}|cmake\/openmp|libarcher|lib[ig]*omp|omp.h|ompt.h|ompt-multiplex.h|ompx.h|omp-tools.h|omp_lib
OPENMP_PATTERN=	cmake\/openmp|libarcher|lib[ig]*omp|omp.h|ompt.h|ompt-multiplex.h|ompx.h|omp-tools.h|omp_lib

.if ${PORT_OPTIONS:MPOLLY}
LLVM_ENABLE_PROJECTS+=	polly
MAN1SRCS+=	${POLLY_MAN1SRCS}
.endif
POLLY_PATTERN=	include\/polly|cmake\/polly|LLVMPolly.so|libPolly

.if defined(LLVM_ENABLE_PROJECTS)
CMAKE_ARGS+=	-DLLVM_ENABLE_PROJECTS="${LLVM_ENABLE_PROJECTS:ts;}"
.endif
.if defined(LLVM_ENABLE_RUNTIMES)
CMAKE_ARGS+=	-DLLVM_ENABLE_RUNTIMES="${LLVM_ENABLE_RUNTIMES:ts;}"
.endif

.include <bsd.port.pre.mk>
.include "${.CURDIR}/Makefile.COMMANDS"
.include "${.CURDIR}/Makefile.MAN1SRCS"

.if defined(WITH_DEBUG)
CMAKE_BUILD_TYPE=	RelWithDebInfo
STRIP=
.endif

.if ${ARCH} == "aarch64"
COMPILER_RT_ARCHS=	aarch64
.elif ${ARCH} == "amd64"
COMPILER_RT_ARCHS=	x86_64
.if exists(/usr/lib32/libc.so.7)
COMPILER_RT_ARCHS+=	i386
.endif
.elif ${ARCH} == "i386"
COMPILER_RT_ARCHS=	i386
.elif ${ARCH} == "powerpc"
COMPILER_RT_ARCHS=	powerpc
.elif ${ARCH} == "powerpc64"
COMPILER_RT_ARCHS=	powerpc64
.if exists(/usr/lib32/libc.so.7)
COMPILER_RT_ARCHS+=	powerpc
.endif
.elif ${ARCH} == "powerpc64le"
COMPILER_RT_ARCHS=	powerpc64le
.elif ${ARCH} == "riscv64"
COMPILER_RT_ARCHS=	riscv64
.endif

_CRTBASEDIR=	${LLVM_DIR}/lib/clang/${LLVM_MAJOR}
_CRTILDIR=	${_CRTBASEDIR}/share
.if ${ARCH} != powerpc
COMPILER_RT_PLIST_FILES+=	${COMPILER_RT_IGNORELISTS:S|^|${_CRTILDIR}/|}
.endif
_CRTLIBDIR=	${_CRTBASEDIR}/lib

.include "Makefile.RUNTIMES"

_COMPILER_RT_LIBS=
.for CRT_ARCH in ${COMPILER_RT_ARCHS}
_COMPILER_RT_LIBS:= ${_COMPILER_RT_LIBS} ${COMPILER_RT_LIBS_${CRT_ARCH}:S|^|${_CRTLIBDIR}/${CRT_ARCH}-portbld-${OPSYS:tl}${OSREL}/|}
.endfor

COMPILER_RT_IGNORELISTS=
.for RT in asan cfi msan
.if ${_COMPILER_RT_LIBS:M*/libclang_rt.${RT}.a}
COMPILER_RT_IGNORELISTS:=	${COMPILER_RT_IGNORELISTS} ${RT}_ignorelist.txt
.endif
.endfor
# Strip empty element
COMPILER_RT_IGNORELISTS:=${COMPILER_RT_IGNORELISTS:N^$$}

# Comment out plist entries for unsupported options.
.for opt in ${_ALL_OPTIONS}
.if !${OPTIONS_DEFINE:M${opt}}
PLIST_SUB+=	${opt}="@comment "
.endif
.endfor

post-patch:
	${REINPLACE_CMD} -e 's|import lit|import ${LIT_MOD_NAME}|' \
	    -e 's|from lit|from ${LIT_MOD_NAME}|' \
	    -e 's|lit\.|${LIT_MOD_NAME}.|g' \
	    ${WRKSRC}/llvm/utils/lit/lit.py \
	    ${WRKSRC}/llvm/utils/lit/lit/*.py \
	    ${WRKSRC}/llvm/utils/lit/lit/builtin_commands/*.py \
	    ${WRKSRC}/llvm/utils/lit/lit/formats/*.py \
	    ${WRKSRC}/llvm/utils/lit/lit/llvm/*.py

post-patch-CLANG-on:
	${REINPLACE_CMD} -e 's|%%LLVM_PREFIX%%|${LLVM_PREFIX}|' \
	    ${WRKSRC}/clang/lib/Driver/ToolChains/CommonArgs.cpp
	${REINPLACE_CMD} -e 's|%%LLVM_SUFFIX%%|${LLVM_SUFFIX}|' \
	    ${WRKSRC}/clang/tools/clang-format/clang-format.py \
	    ${WRKSRC}/clang/tools/clang-format/clang-format-sublime.py \
	    ${WRKSRC}/clang/tools/clang-format/git-clang-format

post-patch-LLD-on:
	${REINPLACE_CMD} -e "s|'indexsidebar.html'|['indexsidebar.html']|" \
	    ${WRKSRC}/lld/docs/conf.py

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/llvm-wrapper.sh \
	    ${STAGEDIR}${PREFIX}/bin/${FIRST_COMMAND}${LLVM_SUFFIX}
.for command in ${COMMANDS:C/^/XXXX/1:NXXXX*}
	${LN} -f ${STAGEDIR}${PREFIX}/bin/${FIRST_COMMAND}${LLVM_SUFFIX} \
	    ${STAGEDIR}${PREFIX}/bin/${command}${LLVM_SUFFIX}
.endfor

post-install-DOCS-on:
	${RM} -r ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MV} ${STAGEDIR}${LLVM_PREFIX}/share/doc/LLVM/* ${STAGEDIR}${DOCSDIR}
	${RMDIR} ${STAGEDIR}${LLVM_PREFIX}/share/doc/LLVM
	${RMDIR} ${STAGEDIR}${LLVM_PREFIX}/share/doc
.for _man in ${MAN1SRCS}
	${MV} ${STAGEDIR}${LLVM_PREFIX}/share/man/man1/${_man} \
	    ${STAGEDIR}${PREFIX}/share/man/man1/${_man:R}${LLVM_SUFFIX}.1
.endfor
.if ! ${PORT_OPTIONS:MLIT}
	${RM} ${STAGEDIR}${LLVM_PREFIX}/share/man/man1/lit.1
	${RM} ${STAGEDIR}${LLVM_PREFIX}/share/man/man1/FileCheck.1
.endif
	${RM} "${STAGEDIR}${LLVM_PREFIX}/share/man/man1/tblgen Family.1"
	${RMDIR} ${STAGEDIR}${LLVM_PREFIX}/share/man/man1/
	${RMDIR} ${STAGEDIR}${LLVM_PREFIX}/share/man/

.if ${PORT_OPTIONS:MCLANG}
post-install-DOCS-off:
	${RM} ${STAGEDIR}${LLVM_PREFIX}/share/man/man1/scan-build.1
	${RMDIR} ${STAGEDIR}${LLVM_PREFIX}/share/man/man1/
	${RMDIR} ${STAGEDIR}${LLVM_PREFIX}/share/man/
.endif

post-install-CLANG-on:
	${LN} -f ${STAGEDIR}${LLVM_PREFIX}/bin/clang \
	    ${STAGEDIR}${LLVM_PREFIX}/bin/clang-cpp
	${MKDIR} ${STAGEDIR}${PREFIX}/share/toolchains/
	${INSTALL_DATA} ${WRKDIR}/xtoolchain.mk \
	    ${STAGEDIR}${PREFIX}/share/toolchains/llvm${LLVM_SUFFIX}.mk
	${RMDIR} ${STAGEDIR}${LLVM_PREFIX}/include/clang/Basic/Target/MSP430/
	${RMDIR} ${STAGEDIR}${LLVM_PREFIX}/include/clang/Basic/Target/

post-install-EXTRAS-on:
	${RMDIR} ${STAGEDIR}${LLVM_PREFIX}/include/clang-tidy/misc/ConfusableTable

post-install-FLANG-on:
	${RMDIR} ${STAGEDIR}${LLVM_PREFIX}/include/flang/Optimizer/CodeGen/CMakeFiles
	${RMDIR} ${STAGEDIR}${LLVM_PREFIX}/include/flang/Optimizer/Dialect/CMakeFiles
	${RMDIR} ${STAGEDIR}${LLVM_PREFIX}/include/flang/Optimizer/Dialect/CUF/Attributes/CMakeFiles
	${RMDIR} ${STAGEDIR}${LLVM_PREFIX}/include/flang/Optimizer/Dialect/CUF/CMakeFiles
	${RMDIR} ${STAGEDIR}${LLVM_PREFIX}/include/flang/Optimizer/Dialect/FIRCG/CMakeFiles
	${RMDIR} ${STAGEDIR}${LLVM_PREFIX}/include/flang/Optimizer/HLFIR/CMakeFiles
	${RMDIR} ${STAGEDIR}${LLVM_PREFIX}/include/flang/Optimizer/OpenMP/CMakeFiles
	${RMDIR} ${STAGEDIR}${LLVM_PREFIX}/include/flang/Optimizer/Transforms/CMakeFiles
	${RMDIR} ${STAGEDIR}${LLVM_PREFIX}/include/flang/Optimizer/CMakeFiles
	${RMDIR} ${STAGEDIR}${LLVM_PREFIX}/include/flang/CMakeFiles

post-install-LIT-on:
	${INSTALL_SCRIPT} ${PATCH_WRKSRC}/llvm/utils/lit/lit.py \
	    ${STAGEDIR}${LLVM_PREFIX}/bin/lit
	${LN} -f ${STAGEDIR}${LLVM_PREFIX}/bin/lit \
	    ${STAGEDIR}${LLVM_PREFIX}/bin/llvm-lit
	${LN} -fs ../${LLVM_DIR}/bin/lit \
	    ${STAGEDIR}${PREFIX}/bin/lit${LLVM_SUFFIX}
	${LN} -fs ../${LLVM_DIR}/bin/llvm-lit \
	    ${STAGEDIR}${PREFIX}/bin/llvm-lit${LLVM_SUFFIX}
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${LIT_MOD_NAME}
	${INSTALL_DATA} ${WRKSRC}/llvm/utils/lit/lit/*.py \
	    ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${LIT_MOD_NAME}
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${LIT_MOD_NAME}/builtin_commands
	${INSTALL_DATA} ${WRKSRC}/llvm/utils/lit/lit/builtin_commands/*.py \
	    ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${LIT_MOD_NAME}/builtin_commands/
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${LIT_MOD_NAME}/formats
	${INSTALL_DATA} ${WRKSRC}/llvm/utils/lit/lit/formats/*.py \
	    ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${LIT_MOD_NAME}/formats/
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${LIT_MOD_NAME}/llvm
	${INSTALL_DATA} ${WRKSRC}/llvm/utils/lit/lit/llvm/*.py \
	    ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${LIT_MOD_NAME}/llvm/
	${INSTALL_PROGRAM} ${WRKDIR}/.build/bin/FileCheck \
	    ${STAGEDIR}${LLVM_PREFIX}/bin/
	${LN} -fs ../${LLVM_DIR}/bin/FileCheck \
	    ${STAGEDIR}${PREFIX}/bin/FileCheck${LLVM_SUFFIX}

post-install-LLD-on:
	${LN} -s ld.lld ${STAGEDIR}${LLVM_PREFIX}/bin/ld

TEST_CMD=	'(cd ${WRKSRC}/test; ${SETENV} ${MAKE_ENV} LD_LIBRARY_PATH=${WRKSRC}/Release/lib ${MAKE_CMD} check-local-lit)'
do-test:
	if [ `${ID} -u` = 0 ]; then \
		${CHOWN} -R nobody ${WRKSRC}/test; \
		su -m nobody -c ${TEST_CMD}; \
	else \
		${SH} -c ${TEST_CMD}; \
	fi

post-install-STATIC_LIBS-off:
	${RM} ${STAGEDIR}${LLVM_PREFIX}/lib/lib*.a

build-plist:
	@[ -d ${STAGEDIR} ] || (echo "Can't make plist before package is staged ${STAGEDIR}" && exit 1)
	${RM} ${PLIST} ${PLIST}.tmp
	${ECHO_CMD} "@comment >>>>> GENERATED FILE, DO NOT EDIT <<<<<" >> ${PLIST}.tmp
	${ECHO_CMD} "@comment Alter build-plist target and regenerate as required" >> ${PLIST}.tmp
.for command in ${COMMANDS}
	${ECHO_CMD} bin/${command}${LLVM_SUFFIX} >> ${PLIST}.tmp
.endfor
.for command in ${LIT_COMMANDS}
	${ECHO_CMD} %%LIT%%bin/${command}${LLVM_SUFFIX} >> ${PLIST}.tmp
	${ECHO_CMD} %%LIT%%${LLVM_DIR}/bin/${command} >> ${PLIST}.tmp
.endfor
	${FIND} ${STAGEDIR}${LLVM_PREFIX} -type f -o -type l | \
	    ${GREP} -v '_ignorelist.txt$$' | \
	    ${GREP} -v '[/-]lit$$' | ${GREP} -v 'FileCheck$$' | \
	    ${GREP} -v man/man1 | ${SED} -e 's|${STAGEDIR}${PREFIX}/||' \
	    -e 's|${LUA_MODLIBDIR:C|${PREFIX}/||}|%%LUA_MODLIBDIR%%|' \
	    -e 's|${PYTHON_SITELIBDIR:C|${PREFIX}/||}|%%PYTHON_SITELIBDIR%%|' \
	    -e 's|${PYTHON_TAG:C/\./\\./g}${PYTHON_ABIVER}|%%PYTHON_TAG%%%%PYTHON_ABIVER%%|' \
	    -e 's|${PORTVERSION}|%%PORTVERSION%%|' \
	    -e 's|release.cmake|%%CMAKE_BUILD_TYPE%%.cmake|' \
	    -e 's|${LLVM_RELEASE:C/\./\\./g}|%%LLVM_RELEASE%%|' \
	    -e 's|${LLVM_MAJOR_MINOR:C/\./\\./}git|%%LLVM_MAJOR_MINOR%%git|' \
	    -e 's|${LLVM_MAJOR}git|%%LLVM_MAJOR%%git|' \
	    -e 's|/${LLVM_MAJOR}/|/%%LLVM_MAJOR%%/|' \
	    -e 's|\([-./]\)${LLVM_MAJOR:C/\./\\./}$$|\1%%LLVM_MAJOR%%|' \
	    -e 's|${CONFIGURE_TARGET}|%%CONFIGURE_TARGET%%|' \
	    | ${SORT} >> ${PLIST}.tmp
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/${LIT_MOD_NAME} -type f | \
	    ${SED} -e 's|${STAGEDIR}${PYTHON_SITELIBDIR}|%%LIT%%%%PYTHON_SITELIBDIR%%|' \
	    -e 's|${LIT_MOD_NAME}|%%LIT_MOD_NAME%%|' \
	    -e 's|${LLVM_RELEASE:C/\./\\./g}|%%LLVM_RELEASE%%|' \
	    -e 's|${LLVM_MAJOR}|%%LLVM_MAJOR%%|' | \
	    ${SORT} >> ${PLIST}.tmp
	${AWK} '{ \
	    if ($$0 ~ /lib.lib[a-zA-Z].*\.a$$/) {printf "%%%%STATIC_LIBS%%%%"} \
	    if ($$0 ~ /${CLANG_PATTERN}/ && $$0 !~ /${OPENMP_PATTERN}|${EXTRAS_PATTERN}|${COMPILER_RT_PATTERN}|lib[a-z]*_rt/) {printf "%%%%CLANG%%%%"} \
	    if ($$0 ~ /${COMPILER_RT_PATTERN}/) \
		{printf "%%%%COMPILER_RT%%%%"} \
	    if ($$0 ~ /(${EXTRAS_PATTERN})/) {printf "%%%%EXTRAS%%%%"} \
	    if ($$0 ~ /(${FLANG_PATTERN})/) {printf "%%%%FLANG%%%%"} \
	    if ($$0 ~ /(bin\/(ld|lld|wasm-ld))|liblld[^b]|\/lld\// && $$0 !~ /lldb/) {printf "%%%%LLD%%%%"} \
	    if ($$0 ~ /(argdumper|lldb|six.py)/) {printf "%%%%LLDB%%%%"} \
	    if ($$0 ~ /(${MLIR_PATTERN})/) {printf "%%%%MLIR%%%%"} \
	    if ($$0 ~ /(${OPENMP_PATTERN})/) {printf "%%%%OPENMP%%%%"} \
	    if ($$0 ~ /(${POLLY_PATTERN})/) {printf "%%%%POLLY%%%%"} \
	    if ($$0 !~ /(lib[a-z]*_rt|LLVMgold)/) {print} \
	    if ($$0 ~ /libflang_rt.runtime.a/) {print} \
	}' ${PLIST}.tmp >> ${PLIST}
	${ECHO_CMD} '@postexec if type ccache-update-links >/dev/null 2>&1; then ccache-update-links -v; fi' >> ${PLIST}
	${ECHO_CMD} '@postunexec if type ccache-update-links >/dev/null 2>&1; then ccache-update-links -v; fi' >> ${PLIST}
	${RM} ${PLIST}.tmp

check-commands:
.for command in ${COMMANDS}
	test -e ${STAGEDIR}${LLVM_PREFIX}/bin/${command}
.endfor

.include <bsd.port.post.mk>
