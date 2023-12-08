PORTNAME=	llvm
DISTVERSION=	17.0.6
PORTREVISION=	2
CATEGORIES=	devel lang
MASTER_SITES=	https://github.com/llvm/llvm-project/releases/download/llvmorg-${DISTVERSION:S/rc/-rc/}/ \
		https://${PRE_}releases.llvm.org/${LLVM_RELEASE}${RCDIR}/
PKGNAMESUFFIX=	${LLVM_SUFFIX}
DISTNAME=	llvm-project-${DISTVERSION}.src
DISTFILES=	llvm-project-${DISTVERSION}.src${EXTRACT_SUFX}

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	LLVM and Clang
WWW=		https://llvm.org/

LICENSE_DIR=	${WRKSRC}/llvm
.include "${.CURDIR}/../llvm-devel/Makefile.LICENSE"
LICENSE+=	LLVM2
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/third-party/unittest/googletest/LICENSE.TXT
LICENSE_FILE_LLVM2=	${LICENSE_DIR}/LICENSE.TXT
LICENSE_NAME_LLVM2=	Apache License 2.0 with LLVM Exceptions
LICENSE_PERMS_LLVM2=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE:=	${LICENSE:NARM}

LIB_DEPENDS=	libzstd.so:archivers/zstd

FLAVORS=	default lite
FLAVOR?=	${FLAVORS:[1]}
lite_PKGNAMESUFFIX=	${LLVM_SUFFIX}-lite

LLVM_RELEASE=	${DISTVERSION:C/rc.*//}
LLVM_MAJOR=	${LLVM_RELEASE:C/\.[0-9]\.[0-9]$//}
LLVM_SUFFIX=	${LLVM_MAJOR}
PRE_=		${DISTVERSION:C/.*rc.*/pre/:N*[0-9]*}
RCDIR=		${DISTVERSION:S/${LLVM_RELEASE}//:C|(rc.*)|/\1|}

LLVM_DIR=	llvm${LLVM_SUFFIX}
LLVM_PREFIX=	${PREFIX}/${LLVM_DIR}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${LLVM_SUFFIX}
DATADIR=	${PREFIX}/share/${PORTNAME}${LLVM_SUFFIX}

USES=		cmake compiler:c++17-lang cpe tar:xz shebangfix
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

SUB_FILES=	llvm-wrapper.sh
SUB_LIST=	LLVM_PREFIX="${LLVM_PREFIX}" LLVM_SUFFIX="${LLVM_SUFFIX}"

CMAKE_INSTALL_PREFIX=	${LLVM_PREFIX}
CMAKE_SOURCE_PATH=	${WRKSRC}/llvm
CMAKE_ARGS=	-DLLVM_BUILD_LLVM_DYLIB=ON
CMAKE_ARGS+=	-DLLVM_LINK_LLVM_DYLIB=ON
CMAKE_ARGS+=	-DLLVM_ENABLE_RTTI=ON
CMAKE_ARGS+=	-DLLVM_DEFAULT_TARGET_TRIPLE=${CONFIGURE_TARGET}
CMAKE_ARGS+=	-DLLVM_HOST_TRIPLE=${CONFIGURE_TARGET}
# Following commit https://github.com/kitware/cmake/commit/956054
# we need to either change the whole man-shuffle below, or simply
# redefine CMAKE_INSTALL_MANDIR
CMAKE_ARGS+=	-DCMAKE_INSTALL_MANDIR:PATH="share/man"
CMAKE_ARGS+=	-DLLVM_PARALLEL_LINK_JOBS=1
CMAKE_ARGS+=	-DLLVM_ENABLE_Z3_SOLVER=OFF
CMAKE_ARGS+=	-DLLVM_ENABLE_LIBXML2=OFF
CMAKE_ARGS+=	-DLLVM_ENABLE_LIBEDIT=OFF
# LLVM likes to pick up ${LOCALBASE}/lib/libtinfo.so.*
CMAKE_ARGS+=	-DLLVM_ENABLE_TERMINFO=OFF

# Disable assertions.  They should be disabled by cmake, but USES=cmake
# overrides -DCMAKE_*_FLAGS_RELEASE.
CFLAGS+=	-DNDEBUG
CXXFLAGS+=	-DNDEBUG

OPTIONS_DEFINE=	BE_AMDGPU BE_WASM CLANG COMPILER_RT DOCS LLD STATIC_LIBS
OPTIONS_DEFAULT=	BE_AMDGPU BE_WASM CLANG LLD
OPTIONS_SINGLE=		BACKENDS
OPTIONS_SINGLE_BACKENDS=BE_FREEBSD BE_NATIVE BE_STANDARD
OPTIONS_EXCLUDE_armv6=	COMPILER_RT
OPTIONS_EXCLUDE_armv7=	COMPILER_RT
OPTIONS_SUB=	yes

.if ${FLAVOR:Mlite}
OPTIONS_DEFAULT+=	BE_FREEBSD
.else
OPTIONS_DEFINE+=	EXTRAS FLANG LIT LLDB MLIR OPENMP PYCLANG POLLY
OPTIONS_DEFINE_amd64=	GOLD
OPTIONS_DEFINE_powerpc=	GOLD
OPTIONS_DEFINE_powerpc64=	GOLD
OPTIONS_DEFINE_powerpc64le=	GOLD

OPTIONS_DEFAULT+=	BE_STANDARD COMPILER_RT EXTRAS LIT LLDB MLIR OPENMP \
			PYCLANG POLLY STATIC_LIBS
OPTIONS_DEFAULT_amd64=	GOLD
OPTIONS_DEFAULT_powerpc=	GOLD
OPTIONS_DEFAULT_powerpc64=	GOLD
OPTIONS_DEFAULT_powerpc64le=	GOLD

OPTIONS_EXCLUDE_armv6+=	FLANG OPENMP
OPTIONS_EXCLUDE_armv7+=	FLANG OPENMP
OPTIONS_EXCLUDE_i386=	FLANG OPENMP
OPTIONS_EXCLUDE_powerpc=	FLANG OPENMP
OPTIONS_EXCLUDE_riscv64=	LLDB
OPTIONS_EXCLUDE_FreeBSD_12=	OPENMP
.endif

# All non-backend options
_ALL_OPTIONS=	CLANG COMPILER_RT DOCS EXTRAS FLANG GOLD LIT LLD LLDB MLIR \
		OPENMP POLLY PYCLANG STATIC_LIBS

BE_AMDGPU_DESC=		AMD GPU backend (required by mesa)
BE_FREEBSD_DESC=	Backends for FreeBSD architectures
BE_FREEBSD_CMAKE_ON=	-DLLVM_TARGETS_TO_BUILD="${FREEBSD_BACKENDS:ts;}"
BE_NATIVE_DESC=		Backend(s) for this architecture (${_NATIVE_BACKENDS})
BE_NATIVE_CMAKE_ON=	-DLLVM_TARGETS_TO_BUILD="${NATIVE_BACKENDS:ts;}"
BE_STANDARD_DESC=	All non-experimental backends
BE_WASM_DESC=		WebAssembly backend (required by firefox via wasi)
.for BE in FREEBSD NATIVE STANDARD
BE_${BE}_PLIST_FILES= \
	${_BE_LIBS_${BE}:O:S/$/.a/:S|^|%%STATIC_LIBS%%${LLVM_DIR}/lib/libLLVM|} \
	${_BE_INCS_${BE}:S|^|${LLVM_DIR}/lib/clang/${LLVM_MAJOR}/include/|:N${LLVM_DIR}/lib/clang/${LLVM_MAJOR}/include/$}
.endfor
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
COMPILER_RT_CMAKE_ON=	-DCOMPILER_RT_INSTALL_PATH=${LLVM_PREFIX}/lib/clang/${LLVM_RELEASE}
COMPILER_RT_PLIST_FILES=${_COMPILER_RT_LIBS}
DOCS_BUILD_DEPENDS= \
	${PYTHON_PKGNAMEPREFIX}sphinx-markdown-tables>=0:textproc/py-sphinx-markdown-tables@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}recommonmark>=0.0.20180530:textproc/py-recommonmark@${PY_FLAVOR}
DOCS_CONFLICTS_BUILD=	cmark
DOCS_PORTDOCS=		llvm
DOCS_CMAKE_ON= \
	-DLLVM_ENABLE_SPHINX=ON \
	-DSPHINX_EXECUTABLE=${LOCALBASE}/bin/sphinx-build-${PYTHON_VER} \
	-DSPHINX_WARNINGS_AS_ERRORS=OFF \
	-DLLVM_BUILD_DOCS=ON
DOCS_PLIST_FILES=	${MAN1SRCS:S|^|man/man1/|:S|.1$|${LLVM_SUFFIX}.1.gz|}
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
LLD_DESC=		Install lld, the LLVM linker
LLDB_BUILD_DEPENDS=	swig:devel/swig
LLDB_CMAKE_ON= \
	-DLUA_INCLUDE_DIR=${LOCALBASE}/include/lua${LUA_VER_STR} \
	-DLUA_LIBRARY=${LOCALBASE}/lib/liblua-${LUA_VER}.so \
	-DCURSES_INCLUDE_PATH=/usr/include \
	-DCURSES_CURSES_LIBRARY=/usr/lib/libcurses.so \
	-DCURSES_FORM_LIBRARY=/usr/lib/libform.so \
	-DCURSES_NCURSES_LIBRARY=/usr/lib/libncurses.so \
	-DPANEL_LIBRARIES=/usr/lib/libpanel.so
LLDB_DESC=		Install lldb, the LLVM debugger
LLDB_IMPLIES=		CLANG
LLDB_PLIST_SUB=		PYTHON_ABIVER=${PYTHON_ABIVER}
LLDB_USES=		lua:53 libedit
LLDB_VARS=		_USES_PYTHON=python
MLIR_DESC=		Multi-Level Intermediate Representation
OPENMP_DESC=		Install libomp, the LLVM OpenMP runtime library
OPENMP_CMAKE_ON= \
	-DLIBOMPTARGET_BUILD_DEVICERTL_BCLIB=OFF \
	-DLIBOMPTARGET_DEP_LIBFFI_INCLUDE_DIR="" \
	-DLIBOMPTARGET_DEP_LIBFFI_LIBRARIES=""
OPENMP_PORTDOCS=	openmp
PYCLANG_DESC=		Install python bindings to libclang
PYCLANG_IMPLIES=	CLANG
PYCLANG_VARS=		_USES_PYTHON=python
PYCLANG_CMAKE_ON=	-DCLANG_PYTHON_BINDINGS_VERSIONS=${PYTHON_VER}
POLLY_DESC=		Polyhedral loop and data-locality optimizer
POLLY_PORTDOCS=		polly
STATIC_LIBS_DESC=	Install static libraries (does not effect sanitizers)

CONFLICTS_INSTALL=	${PORTNAME}${LLVM_SUFFIX} ${PORTNAME}${LLVM_SUFFIX}-lite

.if defined(WITH_DEBUG)
CMAKE_BUILD_TYPE=	RelWithDebInfo
STRIP=
.endif

PLIST_SUB+=	LLVM_MAJOR=${LLVM_MAJOR} \
		LLVM_RELEASE=${LLVM_RELEASE} \
		LLVM_SUFFIX=${LLVM_SUFFIX}

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

FLANG_PATTERN=	${FLANG_COMMANDS:S/^/bin./:tW:C/  */|/g}|flang|libFIR|libFortran|libHLFIR

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
CLANG_PATTERN=	(amdgpu-arch|c-index-test|clang|diagtool|hmaptool|intercept-|libear|libscanbuild|nvptx-arch|analyze-|scan-|Reporter.py|ScanView.py|scanview.css|sorttable.js|startfile.py|-analyzer|AnalyzerPlugin.so)
USES+=		gnome
.endif

.if ${PORT_OPTIONS:MCOMPILER_RT}
LLVM_ENABLE_PROJECTS+=	compiler-rt
COMPILER_RT_PATTERN=	(sanitizer|include.xray|include\/(fuzzer|orc)|profile\/InstrProfData.inc)
.if ${OSVERSION} < 1300525
# An unwind.h is require to build.  I think an in-tree one should be used
# but this seems to work as a workaround...
BUILD_DEPENDS+=	libunwind>0:devel/libunwind
# Allow unwind.h to be found reliably
USES+=	localbase
.endif
.endif

.if ${PORT_OPTIONS:MEXTRAS}
LLVM_ENABLE_PROJECTS+=	clang-tools-extra
COMMANDS+=	${EXTRAS_COMMANDS}
MAN1SRCS+=	${EXTRAS_MAN1SRCS}
PORTDOCS+=	clang-tools
.endif

.if ${PORT_OPTIONS:MFLANG}
LLVM_ENABLE_PROJECTS+=	flang
COMMANDS+=	${FLANG_COMMANDS}
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
LLVM_ENABLE_PROJECTS+=	openmp
MAN1SRCS+=	${OPENMP_MAN1SRCS}
COMMANDS+=	${OPENMP_COMMANDS}
.endif
OPENMP_PATTERN=	${OPENMP_COMMANDS:tW:C/  */|/g}|cmake\/openmp|libarcher|lib[ig]*omp|omp.h|ompt.h|ompt-multiplex.h|omp-tools.h

.if ${PORT_OPTIONS:MPOLLY}
LLVM_ENABLE_PROJECTS+=	polly
MAN1SRCS+=	${POLLY_MAN1SRCS}
.endif
POLLY_PATTERN=	include\/polly|cmake\/polly|LLVMPolly.so|libPolly

.if ${PORT_OPTIONS:MPYCLANG}
PYCLANG_PATTERN=	(clang\/(__init__|cindex|enumerations).py)$$
.endif

.if defined(LLVM_ENABLE_PROJECTS)
CMAKE_ARGS+=	-DLLVM_ENABLE_PROJECTS="${LLVM_ENABLE_PROJECTS:ts;}"
.endif

.include <bsd.port.pre.mk>
.include "${.CURDIR}/Makefile.COMMANDS"
.include "${.CURDIR}/Makefile.MAN1SRCS"

_FREEBSD_BACKENDS=	AArch64 ARM Mips PowerPC RISCV Sparc X86
FREEBSD_BACKENDS=	${_FREEBSD_BACKENDS}
.if ${ARCH} == amd64
_NATIVE_BACKENDS=	X86
.elif ${ARCH} == aarch64
_NATIVE_BACKENDS=	AArch64 ARM
.elif ${ARCH:Marmv*}
_NATIVE_BACKENDS=	ARM
.elif ${ARCH} == i386
_NATIVE_BACKENDS=	X86
.elif ${ARCH:Mmips*}
_NATIVE_BACKENDS=	Mips
.elif ${ARCH:Mpowerpc*}
_NATIVE_BACKENDS=	PowerPC
.elif ${ARCH:Mriscv*}
_NATIVE_BACKENDS=	RISCV
.endif
NATIVE_BACKENDS=	${_NATIVE_BACKENDS}
.if ${PORT_OPTIONS:MBE_AMDGPU}
FREEBSD_BACKENDS+=	AMDGPU
NATIVE_BACKENDS+=	AMDGPU
.endif
.if ${PORT_OPTIONS:MBE_WASM}
FREEBSD_BACKENDS+=	WebAssembly
NATIVE_BACKENDS+=	WebAssembly
.endif
STANDARD_BACKENDS=	${_FREEBSD_BACKENDS} AMDGPU AVR BPF Hexagon Lanai \
			LoongArch MSP430 NVPTX SystemZ VE WebAssembly XCore
_BE_LIBS_COMMON=	CodeGen Desc Info
_BE_INCS_AArch64=	arm_bf16.h arm_sme_draft_spec_subject_to_change.h
_BE_LIBS_AArch64=	AsmParser Disassembler Utils
_BE_LIBS_BACKWARDS_AArch64=Exegesis
_BE_LIBS_AMDGPU=	AsmParser Disassembler TargetMCA Utils
_BE_INCS_ARM=		arm_cde.h arm_fp16.h arm_mve.h arm_neon.h arm_sve.h
_BE_LIBS_ARM=		AsmParser Disassembler Utils
_BE_LIBS_AVR=		AsmParser Disassembler
_BE_LIBS_BPF=		AsmParser Disassembler
_BE_LIBS_Hexagon=	AsmParser Disassembler
_BE_LIBS_Lanai=		AsmParser Disassembler
_BE_LIBS_LoongArch=	AsmParser Disassembler
_BE_LIBS_MSP430=	AsmParser Disassembler
_BE_LIBS_Mips=		AsmParser Disassembler
_BE_LIBS_BACKWARDS_Mips=Exegesis
_BE_LIBS_PowerPC=	AsmParser Disassembler
_BE_LIBS_BACKWARDS_PowerPC=Exegesis
_BE_INCS_RISCV=		riscv_vector.h
_BE_LIBS_RISCV=		AsmParser Disassembler TargetMCA
_BE_LIBS_Sparc=		AsmParser Disassembler
_BE_LIBS_SystemZ=	AsmParser Disassembler
_BE_LIBS_VE=		AsmParser Disassembler
_BE_LIBS_WebAssembly=	AsmParser Disassembler Utils
_BE_LIBS_X86=		AsmParser Disassembler TargetMCA
_BE_LIBS_BACKWARDS_X86=Exegesis
_BE_LIBS_XCore=		Disassembler
.for BE in FREEBSD NATIVE STANDARD
.for BE_ARCH in ${${BE}_BACKENDS}
_BE_LIBS_${BE}+=	${_BE_LIBS_COMMON:S/^/${BE_ARCH}/} \
			${_BE_LIBS_${BE_ARCH}:S/^/${BE_ARCH}/} \
			${_BE_LIBS_BACKWARDS_${BE_ARCH}:S/$/${BE_ARCH}/}
_BE_INCS_${BE}+=	${_BE_INCS_${BE_ARCH}}
.endfor
.endfor
BE_PATTERN=LLVM(${_BE_LIBS_STANDARD:O:S/$/.a/:ts|})|${_BE_INCS_STANDARD:ts|}

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

.if ${ARCH} == "armv6"
BUILD_DEPENDS+=	${LOCALBASE}/bin/ld:devel/binutils
CONFIGURE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
MAKE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
.endif

# Comment out plist entries for unsupported options.
.for opt in ${_ALL_OPTIONS}
.if !${OPTIONS_DEFINE:M${opt}}
PLIST_SUB+=	${opt}="@comment "
.endif
.endfor

post-patch:
	${REINPLACE_CMD} -e 's|import lit|import lit${LLVM_SUFFIX}|' \
	    -e 's|from lit|from lit${LLVM_SUFFIX}|' \
	    -e 's|lit\.|lit${LLVM_SUFFIX}.|g' \
	    ${WRKSRC}/llvm/utils/lit/lit.py \
	    ${WRKSRC}/llvm/utils/lit/lit/*.py \
	    ${WRKSRC}/llvm/utils/lit/lit/formats/*.py
	${REINPLACE_CMD} -e 's,/usr/local/,${LOCALBASE}/,' \
	    ${WRKSRC}/llvm/CMakeLists.txt

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
	    ${STAGEDIR}${MANPREFIX}/man/man1/${_man:R}${LLVM_SUFFIX}.1
.endfor
.if ! ${PORT_OPTIONS:MLIT}
	${RM} ${STAGEDIR}${LLVM_PREFIX}/share/man/man1/lit.1
	${RM} ${STAGEDIR}${LLVM_PREFIX}/share/man/man1/FileCheck.1
.endif
.if ! ${PORT_OPTIONS:MLLDB}
	${RM} ${STAGEDIR}${LLVM_PREFIX}/share/man/man1/lldb-tblgen.1
.endif
.if ! ${PORT_OPTIONS:MMLIR}
	${RM} ${STAGEDIR}${LLVM_PREFIX}/share/man/man1/mlir-tblgen.1
.endif
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
	${INSTALL_PROGRAM} ${WRKDIR}/.build/bin/clang-tblgen \
	    ${STAGEDIR}${LLVM_PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/toolchains/
	${INSTALL_DATA} ${WRKDIR}/xtoolchain.mk \
	    ${STAGEDIR}${PREFIX}/share/toolchains/llvm${LLVM_SUFFIX}.mk

post-install-EXTRAS-on:
	${RMDIR} ${STAGEDIR}${LLVM_PREFIX}/include/clang-tidy/misc/ConfusableTable

post-install-FLANG-on:
	${RMDIR} ${STAGEDIR}${LLVM_PREFIX}/include/flang/Optimizer/CodeGen/CMakeFiles
	${RMDIR} ${STAGEDIR}${LLVM_PREFIX}/include/flang/Optimizer/Dialect/CMakeFiles
	${RMDIR} ${STAGEDIR}${LLVM_PREFIX}/include/flang/Optimizer/HLFIR/CMakeFiles
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
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/lit${LLVM_SUFFIX}
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/lit${LLVM_SUFFIX}/builtin_commands
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/lit${LLVM_SUFFIX}/formats
	${INSTALL_DATA} ${WRKSRC}/llvm/utils/lit/lit/*.py \
	    ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/lit${LLVM_SUFFIX}
	${INSTALL_DATA} ${WRKSRC}/llvm/utils/lit/lit/builtin_commands/*.py \
	    ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/lit${LLVM_SUFFIX}/builtin_commands/
	${INSTALL_DATA} ${WRKSRC}/llvm/utils/lit/lit/formats/*.py \
	    ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/lit${LLVM_SUFFIX}/formats/
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
	${ECHO_CMD} bin/${command}%%LLVM_SUFFIX%% >> ${PLIST}.tmp
.endfor
.for command in ${LIT_COMMANDS}
	${ECHO_CMD} %%LIT%%bin/${command}%%LLVM_SUFFIX%% >> ${PLIST}.tmp
	${ECHO_CMD} %%LIT%%${LLVM_DIR:C|${LLVM_SUFFIX}|%%LLVM_SUFFIX%%|}/bin/${command} >> ${PLIST}.tmp
.endfor

	${FIND} ${STAGEDIR}${LLVM_PREFIX} -type f -o -type l | \
	    ${GREP} -v '_ignorelist.txt$$' | \
	    ${GREP} -v '[/-]lit$$' | ${GREP} -v 'FileCheck$$' | \
	    ${GREP} -v man/man1 | ${SED} -e 's|${STAGEDIR}${PREFIX}/||' \
	    -e 's|${PYTHON_SITELIBDIR:C|${PREFIX}/||}|%%PYTHON_SITELIBDIR%%|' \
	    -e 's|${PYTHON_EXT_SUFFIX:C/\./\\./g}${PYTHON_ABIVER}|%%PYTHON_EXT_SUFFIX%%%%PYTHON_ABIVER%%|' \
	    -e 's|${LLVM_RELEASE}|%%LLVM_RELEASE%%|' \
	    -e 's|release.cmake|%%CMAKE_BUILD_TYPE%%.cmake|' \
	    -e 's|${LLVM_RELEASE:C/\./\\./g}|%%LLVM_RELEASE%%|' \
	    -e 's|${LLVM_SUFFIX:C/\./\\./g}|%%LLVM_SUFFIX%%|' \
	    -e 's|/${LLVM_MAJOR}/|/%%LLVM_MAJOR%%/|' \
	    -e 's|\([-./]\)${LLVM_MAJOR:C/\./\\./}$$|\1%%LLVM_MAJOR%%|' \
	    | ${SORT} >> ${PLIST}.tmp
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/lit${LLVM_SUFFIX} -type f | \
	    ${SED} -e 's|${STAGEDIR}${PYTHON_SITELIBDIR}|%%LIT%%%%PYTHON_SITELIBDIR%%|' \
	    -e 's|${LLVM_RELEASE:C/\./\\./g}|%%LLVM_RELEASE%%|' \
	    -e 's|${LLVM_SUFFIX:C/\./\\./g}|%%LLVM_SUFFIX%%|' \
	    -e 's|\([^0-9]\)${LLVM_MAJOR}$$|\1%%LLVM_MAJOR%%|' \
	    -e 's|\([^0-9]\)${LLVM_MAJOR}\([^0-9]\)|\1%%LLVM_MAJOR%%\2|' \
	    | ${SORT} >> ${PLIST}.tmp
	${AWK} '{ \
	    if ($$0 ~ /lib.lib[a-zA-Z].*\.a$$/ && $$0 !~ /(${BE_PATTERN})$$/) {printf "%%%%STATIC_LIBS%%%%"} \
	    if ($$0 ~ /${CLANG_PATTERN}/ && $$0 !~ /(${OPENMP_PATTERN}|${EXTRAS_PATTERN}|libclang_rt|${PYCLANG_PATTERN}|${BE_PATTERN})/) {printf "%%%%CLANG%%%%"} \
	    if ($$0 ~ /${COMPILER_RT_PATTERN}/) \
		{printf "%%%%COMPILER_RT%%%%"} \
	    if ($$0 ~ /(${EXTRAS_PATTERN})/) {printf "%%%%EXTRAS%%%%"} \
	    if ($$0 ~ /(${FLANG_PATTERN})/) {printf "%%%%FLANG%%%%"} \
	    if ($$0 ~ /(bin\/(ld|lld|wasm-ld))|liblld[^b]|\/lld\// && $$0 !~ /(lldb)/) {printf "%%%%LLD%%%%"} \
	    if ($$0 ~ /(argdumper|lldb|six.py)/) {printf "%%%%LLDB%%%%"} \
	    if ($$0 ~ /(${MLIR_PATTERN})/) {printf "%%%%MLIR%%%%"} \
	    if ($$0 ~ /(${OPENMP_PATTERN})/) {printf "%%%%OPENMP%%%%"} \
	    if ($$0 ~ /(${POLLY_PATTERN})/) {printf "%%%%POLLY%%%%"} \
	    if ($$0 ~ /${PYCLANG_PATTERN}/) {printf "%%%%PYCLANG%%%%"} \
	    if ($$0 !~ /(lib[a-z]*_rt|LLVMgold)/ && $$0 !~ /(${BE_PATTERN})$$/) {print}}' ${PLIST}.tmp >> ${PLIST}
	${ECHO_CMD} '@postexec if type ccache-update-links >/dev/null 2>&1; then ccache-update-links -v; fi' >> ${PLIST}
	${ECHO_CMD} '@postunexec if type ccache-update-links >/dev/null 2>&1; then ccache-update-links -v; fi' >> ${PLIST}
	${RM} ${PLIST}.tmp

check-commands:
.for command in ${COMMANDS}
	test -e ${STAGEDIR}${LLVM_PREFIX}/bin/${command}
.endfor

.include <bsd.port.post.mk>
