# $FreeBSD$

PORTNAME=	llvm
DISTVERSION=	9.0.1
PORTREVISION=	0
CATEGORIES=	devel lang
MASTER_SITES=	https://github.com/llvm/llvm-project/releases/download/llvmorg-${DISTVERSION}/
PKGNAMESUFFIX=	${LLVM_SUFFIX}
DISTNAME=	${PORTNAME}-${DISTVERSION}.src
DISTFILES=	${PORTNAME}-${DISTVERSION}.src${EXTRACT_SUFX}

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	LLVM and Clang

.include "${.CURDIR}/../llvm-devel/Makefile.LICENSE"
LICENSE+=	LLVM2
LICENSE_FILE_LLVM2=	${WRKSRC}/LICENSE.TXT
LICENSE_NAME_LLVM2=	Apache License 2.0 with LLVM Exceptions
LICENSE_PERMS_LLVM2=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE:=	${LICENSE:NARM}

LLVM_RELEASE=	${DISTVERSION:C/rc.*//}
LLVM_MAJOR=	${LLVM_RELEASE:C/\.[0-9]\.[0-9]$//}
LLVM_SUFFIX=	${LLVM_RELEASE:C/\.[0-9]$//:C/\.//}
RCDIR=		${DISTVERSION:S/${LLVM_RELEASE}//:C|(rc.*)|\1/|}

LLVM_PREFIX=	${PREFIX}/llvm${LLVM_SUFFIX}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${LLVM_SUFFIX}
DATADIR=	${PREFIX}/share/${PORTNAME}${LLVM_SUFFIX}

USES=		cmake compiler:c++11-lib libedit perl5 tar:xz \
		shebangfix
_USES_PYTHON?=	python:3.6+,build
USES+=		${_USES_PYTHON}
USE_LDCONFIG=	${LLVM_PREFIX}/lib
SHEBANG_FILES=	utils/lit/lit.py utils/llvm-lit/llvm-lit.in \
		tools/opt-viewer/optrecord.py \
		tools/opt-viewer/opt-diff.py \
		tools/opt-viewer/opt-stats.py \
		tools/opt-viewer/opt-viewer.py

SUB_FILES=	llvm-wrapper.sh
SUB_LIST=	LLVM_PREFIX="${LLVM_PREFIX}" LLVM_SUFFIX="${LLVM_SUFFIX}"

CMAKE_INSTALL_PREFIX=	${LLVM_PREFIX}
CMAKE_ARGS=	-DLLVM_BUILD_LLVM_DYLIB=ON -DLLVM_LINK_LLVM_DYLIB=ON
CMAKE_ARGS+=	-DLLVM_ENABLE_RTTI=ON
CMAKE_ARGS+=	-DLLVM_DEFAULT_TARGET_TRIPLE=${CONFIGURE_TARGET}
CMAKE_ARGS+=	-DLLVM_HOST_TRIPLE=${CONFIGURE_TARGET}
# Following commit https://github.com/kitware/cmake/commit/956054
# we need to either change the whole man-shuffle below, or simply
# redefine CMAKE_INSTALL_MANDIR
CMAKE_ARGS+=	-DCMAKE_INSTALL_MANDIR:PATH="share/man"
CMAKE_ARGS+=	-DLLVM_PARALLEL_LINK_JOBS=1
CMAKE_ARGS+=	-DLLVM_ENABLE_Z3_SOLVER=OFF
CMAKE_ARGS+=	-DPYTHON_EXECUTABLE=${PYTHON_CMD} \
		-DPYTHON_INCLUDE_DIR=${PYTHON_INCLUDEDIR} \
		-DPYTHON_LIBRARY=${LOCALBASE}/lib/lib${PYTHON_VERSION}${PYTHON_ABIVER}.so

# Disable assertions.  They should be disabled by cmake, but USES=cmake
# overrides -DCMAKE_*_FLAGS_RELEASE.
CFLAGS+=	-DNDEBUG
CXXFLAGS+=	-DNDEBUG

OPTIONS_DEFINE=	BE_AMDGPU CLANG DOCS ELFV2 EXTRAS LIT LLD LLD_LINK LLDB PYCLANG
OPTIONS_DEFINE_amd64=	COMPILER_RT GOLD OPENMP
OPTIONS_DEFINE_i386=	COMPILER_RT OPENMP
OPTIONS_DEFINE_powerpc64=	OPENMP
OPTIONS_DEFAULT=	BE_AMDGPU BE_STANDARD CLANG EXTRAS LIT LLD LLD_LINK LLDB PYCLANG
OPTIONS_DEFAULT_amd64=	COMPILER_RT GOLD OPENMP
OPTIONS_DEFAULT_i386=	COMPILER_RT OPENMP
OPTIONS_DEFAULT_powerpc64=	${PPC_ABI:tu:MELFV2} OPENMP
OPTIONS_SINGLE=		BACKENDS
OPTIONS_SINGLE_BACKENDS=BE_FREEBSD BE_NATIVE BE_STANDARD
OPTIONS_SUB=	yes

BE_AMDGPU_DESC=		AMD GPU backend (required by mesa)
BE_FREEBSD_DESC=	Backends for FreeBSD architectures
BE_FREEBSD_CMAKE_ON=	-DLLVM_TARGETS_TO_BUILD="${FREEBSD_BACKENDS:ts;}"
BE_NATIVE_DESC=		Backend(s) for this architecture (${_NATIVE_BACKENDS})
BE_NATIVE_CMAKE_ON=	-DLLVM_TARGETS_TO_BUILD="${NATIVE_BACKENDS:ts;}"
BE_STANDARD_DESC=	All non-experimental backends
.for BE in FREEBSD NATIVE STANDARD
BE_${BE}_PLIST_FILES=	${_BE_LIBS_${BE}:O:S/$/.a/:S|^|${LLVM_PREFIX:S|${PREFIX}/||}/lib/libLLVM|}
.endfor
CLANG_DESC=	Build clang
CLANG_EXTRA_PATCHES=	${PATCHDIR}/clang
CLANG_DISTFILES=	clang-${DISTVERSION}.src${EXTRACT_SUFX}
CLANG_CMAKE_ON=		-DCLANG_DEFAULT_OPENMP_RUNTIME=libomp
CLANG_PORTDOCS=		clang
CLANG_USE=		GNOME=libxml2
COMPILER_RT_DESC=	Sanitizer libraries
COMPILER_RT_DISTFILES=	compiler-rt-${DISTVERSION}.src${EXTRACT_SUFX}
COMPILER_RT_PLIST_FILES=${_COMPILER_RT_LIBS:S|^|${_CRTLIBDIR}/|} \
			${_COMPILER_RT_BLACKLISTS:S|^|${_CRTBLDIR}/|}
DOCS_BUILD_DEPENDS=	sphinx-build-${PYTHON_VER}:textproc/py-sphinx@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}recommonmark>=0.0.20180530:textproc/py-recommonmark@${PY_FLAVOR}
DOCS_CONFLICTS_BUILD=	commonmark-cmark-*
DOCS_PORTDOCS=		llvm
DOCS_CMAKE_ON=		-DLLVM_ENABLE_SPHINX=ON \
			-DSPHINX_EXECUTABLE=${LOCALBASE}/bin/sphinx-build-${PYTHON_VER} \
			-DSPHINX_WARNINGS_AS_ERRORS=OFF \
			-DLLVM_BUILD_DOCS=ON
DOCS_PLIST_FILES=	${MAN1SRCS:S|^|man/man1/|:S|.1$|${LLVM_SUFFIX}.1.gz|}
ELFV2_DESC=		[PowerPC64] Use OpenPOWER ELF ABI v2 by default
ELFV2_EXTRA_PATCHES=	${PATCHDIR}/ppc64-elfv2
ELFV2_IMPLIES=		CLANG
EXTRAS_DESC=		Extra clang tools
EXTRAS_EXTRA_PATCHES=	${PATCHDIR}/extras
EXTRAS_IMPLIES=		CLANG
EXTRAS_DISTFILES=	clang-tools-extra-${DISTVERSION}.src${EXTRACT_SUFX}
GOLD_DESC=		Build the LLVM Gold plugin for LTO
GOLD_CMAKE_ON=		-DLLVM_BINUTILS_INCDIR=${LOCALBASE}/include
GOLD_BUILD_DEPENDS=	${LOCALBASE}/bin/ld.gold:devel/binutils
LIT_DESC=		Install lit and FileCheck test tools
LIT_VARS=		_USES_PYTHON=python:3.6+
LLD_DESC=		Install lld, the LLVM linker
LLD_DISTFILES=		lld-${DISTVERSION}.src${EXTRACT_SUFX}
LLD_EXTRA_PATCHES=	${PATCHDIR}/lld
LLD_LINK_DESC=		Link ld.lld as ld to clang uses it
LLD_LINK_IMPLIES=	LLD
LLDB_BUILD_DEPENDS=	swig3.0:devel/swig30 \
			${PY_ENUM34}
LLDB_DESC=		Install lldb, the LLVM debugger
LLDB_DISTFILES=		lldb-${DISTVERSION}.src${EXTRACT_SUFX}
LLDB_EXTRA_PATCHES=	${PATCHDIR}/lldb
LLDB_IMPLIES=		CLANG
LLDB_PORTDOCS=		lldb
LLDB_VARS=		_USES_PYTHON=python:3.6+
OPENMP_DESC=		Install libomp, the LLVM OpenMP runtime library
OPENMP_EXTRA_PATCHES=	${PATCHDIR}/openmp
OPENMP_DISTFILES=	openmp-${DISTVERSION}.src${EXTRACT_SUFX}
PYCLANG_DESC=	Install python bindings to libclang
PYCLANG_IMPLIES=	CLANG
PYCLANG_VARS=	_USES_PYTHON=python:3.6+
PYCLANG_CMAKE_ON= -DCLANG_PYTHON_BINDINGS_VERSIONS=${PYTHON_VER}

.if defined(WITH_DEBUG)
CMAKE_BUILD_TYPE=	RelWithDebInfo
STRIP=
.endif

# Emulate USE_GITHUB's ${WRKSRC_tag} to reduce diffs to ../llvm-devel
.for option in CLANG COMPILER_RT EXTRAS LLD LLDB OPENMP
WRKSRC_${option:tl}=		${WRKDIR}/${${option}_DISTFILES:S/${EXTRACT_SUFX}//}
.endfor

PLIST_SUB+=	LLVM_RELEASE=${LLVM_RELEASE} \
		LLVM_SUFFIX=${LLVM_SUFFIX} \
		LLVM_MAJOR=${LLVM_MAJOR}

COMMANDS=	${LLVM_COMMANDS}
FIRST_COMMAND=	${COMMANDS:C/^/XXXX/1:MXXXX*:C/^XXXX//}

MAN1SRCS+=	bugpoint.1 \
		dsymutil.1 \
		llc.1 \
		lli.1 \
		llvm-addr2line.1 \
		llvm-ar.1 \
		llvm-as.1 \
		llvm-bcanalyzer.1 \
		llvm-build.1 \
		llvm-config.1 \
		llvm-cov.1 \
		llvm-cxxfilt.1 \
		llvm-cxxmap.1 \
		llvm-diff.1 \
		llvm-dis.1 \
		llvm-dwarfdump.1 \
		llvm-exegesis.1 \
		llvm-extract.1 \
		llvm-lib.1 \
		llvm-lipo.1 \
		llvm-link.1 \
		llvm-mca.1 \
		llvm-nm.1 \
		llvm-objcopy.1 \
		llvm-objdump.1 \
		llvm-pdbutil.1 \
		llvm-profdata.1 \
		llvm-ranlib.1 \
		llvm-readelf.1 \
		llvm-readobj.1 \
		llvm-size.1 \
		llvm-stress.1 \
		llvm-strings.1 \
		llvm-strip.1 \
		llvm-symbolizer.1 \
		opt.1 \
		tblgen.1

STRIP_LIBS=	BugpointPasses.so \
		LLVMHello.so \
		${LIBNAME}.0 \
		libLTO.so

EXTRAS_LIBS=	libclangApplyReplacements \
		libclangChangeNamespace \
		libclangDaemon \
		libclangDoc \
		libclangIncludeFixer \
		libclangMove \
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
EXTRAS_PATTERN=	${EXTRAS_COMMANDS:tW:C/  */|/g}|${EXTRAS_LIBS:tW:C/  */|/g}

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
COMMANDS+=	${CLANG_COMMANDS}
MAN1SRCS+=	clang.1 \
		diagtool.1 \
		scan-build.1
CLANG_PATTERN=	(c-index-test|clang|diagtool|hmaptool|scan-|Reporter.py|ScanView.py|scanview.css|sorttable.js|startfile.py|-analyzer|AnalyzerPlugin.so)
SHEBANG_FILES+=	tools/clang/tools/scan-view/bin/scan-view \
		tools/clang/tools/clang-format/clang-format-diff.py \
		tools/clang/tools/clang-format/git-clang-format \
		tools/clang/utils/hmaptool/hmaptool
USES+=		gnome
.endif

.if ${PORT_OPTIONS:MCOMPILER_RT}
COMPILER_RT_PATTERN=	(_blacklist.txt|sanitizer|include.xray)
.endif

.if ${PORT_OPTIONS:MEXTRAS}
COMMANDS+=	${EXTRAS_COMMANDS}
MAN1SRCS+=	extraclangtools.1
PORTDOCS+=	clang-tools
SHEBANG_FILES+=	tools/clang/tools/extra/clang-include-fixer/find-all-symbols/tool/run-find-all-symbols.py \
		tools/clang/tools/extra/clang-tidy/tool/clang-tidy-diff.py \
		tools/clang/tools/extra/clang-tidy/tool/run-clang-tidy.py
.endif

.if ${PORT_OPTIONS:MLIT}
MAN1SRCS+=	lit.1 FileCheck.1
.endif

.if ${PORT_OPTIONS:MLLD}
COMMANDS+=	${LLD_COMMANDS}
PORTDOCS+=	lld
.endif

.if ${PORT_OPTIONS:MLLDB}
COMMANDS+=	${LLDB_COMMANDS}
.endif

.if ${PORT_OPTIONS:MPYCLANG}
PYCLANG_PATTERN=	(clang\/(__init__|cindex|enumerations).py)$$
.endif

.include <bsd.port.pre.mk>
.include "${.CURDIR}/Makefile.COMMANDS"

_FREEBSD_BACKENDS=	AArch64 ARM Mips PowerPC RISCV Sparc X86
FREEBSD_BACKENDS=	${_FREEBSD_BACKENDS}
.if ${ARCH} == amd64
_NATIVE_BACKENDS=	X86
.elif ${ARCH} == arm64
_NATIVE_BACKENDS=	AAarch64
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
STANDARD_BACKENDS=	${_FREEBSD_BACKENDS} AMDGPU BPF Hexagon Lanai MSP430 \
			NVPTX SystemZ WebAssembly XCore
_BE_LIBS_COMMON=	CodeGen Desc Info
_BE_LIBS_AArch64=	AsmParser Disassembler Utils
_BE_LIBS_AMDGPU=	AsmParser Disassembler Utils
_BE_LIBS_ARM=		AsmParser Disassembler Utils
_BE_LIBS_BPF=		AsmParser Disassembler 
_BE_LIBS_Hexagon=	AsmParser Disassembler
_BE_LIBS_Lanai=		AsmParser Disassembler
_BE_LIBS_MSP430=	AsmParser Disassembler
_BE_LIBS_Mips=		AsmParser Disassembler
_BE_LIBS_PowerPC=	AsmParser Disassembler
_BE_LIBS_RISCV=		AsmParser Disassembler Utils
_BE_LIBS_Sparc=		AsmParser Disassembler
_BE_LIBS_SystemZ=	AsmParser Disassembler
_BE_LIBS_WebAssembly=	AsmParser Disassembler
_BE_LIBS_X86=		AsmParser Disassembler Utils
_BE_LIBS_XCore=		Disassembler
.for BE in FREEBSD NATIVE STANDARD
.for BE_ARCH in ${${BE}_BACKENDS}
_BE_LIBS_${BE}+=	${_BE_LIBS_COMMON:S/^/${BE_ARCH}/} \
			${_BE_LIBS_${BE_ARCH}:S/^/${BE_ARCH}/}
.endfor
.endfor
BE_PATTERN=${_BE_LIBS_STANDARD:O:S/$/.a/:ts|}

_CRTLIBDIR=	${LLVM_PREFIX:S|${PREFIX}/||}/lib/clang/${LLVM_RELEASE}/lib/freebsd
_CRTBLDIR=	${LLVM_PREFIX:S|${PREFIX}/||}/share
_COMPILER_RT_BLACKLISTS=	cfi_blacklist.txt
.if ${ARCH} == "amd64"
_COMPILER_RT_BLACKLISTS+=	asan_blacklist.txt
_COMPILER_RT_BLACKLISTS+=	msan_blacklist.txt
_COMPILER_RT_LIBS= \
	libclang_rt.asan-preinit-x86_64.a \
	libclang_rt.asan-x86_64.a \
	libclang_rt.asan-x86_64.a.syms \
	libclang_rt.asan-x86_64.so \
	libclang_rt.asan_cxx-x86_64.a \
	libclang_rt.asan_cxx-x86_64.a.syms \
	libclang_rt.builtins-x86_64.a \
	libclang_rt.cfi-x86_64.a \
	libclang_rt.cfi_diag-x86_64.a \
	libclang_rt.dd-x86_64.a \
	libclang_rt.dyndd-x86_64.so \
	libclang_rt.fuzzer-x86_64.a \
	libclang_rt.fuzzer_no_main-x86_64.a \
	libclang_rt.msan-x86_64.a \
	libclang_rt.msan-x86_64.a.syms \
	libclang_rt.msan_cxx-x86_64.a \
	libclang_rt.msan_cxx-x86_64.a.syms \
	libclang_rt.profile-x86_64.a \
	libclang_rt.safestack-x86_64.a \
	libclang_rt.stats-x86_64.a \
	libclang_rt.stats_client-x86_64.a \
	libclang_rt.tsan-x86_64.a \
	libclang_rt.tsan-x86_64.a.syms \
	libclang_rt.tsan_cxx-x86_64.a \
	libclang_rt.tsan_cxx-x86_64.a.syms \
	libclang_rt.ubsan_minimal-x86_64.a \
	libclang_rt.ubsan_minimal-x86_64.a.syms \
	libclang_rt.ubsan_minimal-x86_64.so \
	libclang_rt.ubsan_standalone-x86_64.a \
	libclang_rt.ubsan_standalone-x86_64.a.syms \
	libclang_rt.ubsan_standalone-x86_64.so \
	libclang_rt.ubsan_standalone_cxx-x86_64.a \
	libclang_rt.ubsan_standalone_cxx-x86_64.a.syms \
	libclang_rt.xray-basic-x86_64.a \
	libclang_rt.xray-fdr-x86_64.a \
	libclang_rt.xray-profiling-x86_64.a \
	libclang_rt.xray-x86_64.a
.endif
.if ${ARCH} == "i386"
_COMPILER_RT_BLACKLISTS+=	asan_blacklist.txt
_COMPILER_RT_LIBS+= \
	libclang_rt.asan-i386.a \
	libclang_rt.asan-i386.so \
	libclang_rt.asan-preinit-i386.a \
	libclang_rt.asan_cxx-i386.a \
	libclang_rt.builtins-i386.a \
	libclang_rt.cfi-i386.a \
	libclang_rt.cfi_diag-i386.a \
	libclang_rt.profile-i386.a \
	libclang_rt.safestack-i386.a \
	libclang_rt.stats-i386.a \
	libclang_rt.stats_client-i386.a \
	libclang_rt.ubsan_minimal-i386.a \
	libclang_rt.ubsan_minimal-i386.so \
	libclang_rt.ubsan_standalone-i386.a \
	libclang_rt.ubsan_standalone-i386.so \
	libclang_rt.ubsan_standalone_cxx-i386.a
.endif

# Use lld for armv6 on clang 7 and up to avoid binutils ld issues
# PR: 235282
.if ${COMPILER_TYPE} == clang && ${COMPILER_VERSION} >= 70
LDFLAGS_armv6=-fuse-ld=lld
.endif

.if ${ARCH} == "armv6"
BUILD_DEPENDS+=	${LOCALBASE}/bin/ld:devel/binutils
CONFIGURE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
MAKE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
.endif

.if ! ${OPTIONS_DEFINE:MCOMPILER_RT}
# Hack to disable COMPILER_RT in plist of unsupported architectures
PLIST_SUB+=	COMPILER_RT="@comment "
.else
.endif

.if ! ${OPTIONS_DEFINE:MGOLD}
# Hack to disable GOLD in plist of unsupported architectures
PLIST_SUB+=	GOLD="@comment "
.else
.endif

.if ! ${OPTIONS_DEFINE:MOPENMP}
# Hack to disable OPENMP in plist of unsupported architectures
PLIST_SUB+=	OPENMP="@comment "
.else
.endif

post-extract-CLANG-on:
	${MV} ${WRKSRC_clang} ${PATCH_WRKSRC}/tools/clang

post-extract-EXTRAS-on:
	${MV} ${WRKSRC_extras} ${PATCH_WRKSRC}/tools/clang/tools/extra

post-extract-LLD-on:
	${MV} ${WRKSRC_lld} ${PATCH_WRKSRC}/tools/lld

post-extract-LLDB-on:
	${MV} ${WRKSRC_lldb} ${PATCH_WRKSRC}/tools/lldb

post-extract-OPENMP-on:
	${MV} ${WRKSRC_openmp} ${PATCH_WRKSRC}/projects/openmp

post-patch:
	${REINPLACE_CMD} -e 's|import lit|import lit${LLVM_SUFFIX}|' \
	    -e 's|from lit|from lit${LLVM_SUFFIX}|' \
	    -e 's|lit\.|lit${LLVM_SUFFIX}.|' \
	    ${WRKSRC}/utils/lit/lit.py ${WRKSRC}/utils/lit/lit/*.py \
	    ${WRKSRC}/utils/lit/lit/formats/*.py
	${REINPLACE_CMD} -e 's,/usr/local/,${LOCALBASE}/,' \
	    ${WRKSRC}/CMakeLists.txt

post-patch-CLANG-on:
	${REINPLACE_CMD} -e 's|%%LLVM_PREFIX%%|${LLVM_PREFIX}|' \
	    ${PATCH_WRKSRC}/tools/clang/lib/Driver/ToolChains/CommonArgs.cpp
	${REINPLACE_CMD} -e 's|%%LLVM_SUFFIX%%|${LLVM_SUFFIX}|' \
	    ${PATCH_WRKSRC}/tools/clang/tools/clang-format/clang-format.py \
	    ${PATCH_WRKSRC}/tools/clang/tools/clang-format/clang-format-sublime.py \
	    ${PATCH_WRKSRC}/tools/clang/tools/clang-format/git-clang-format

post-build-COMPILER_RT-on:
	${MKDIR} ${WRKDIR}/compiler-rt-build
	cd ${WRKDIR}/compiler-rt-build && \
	${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} \
	    -DLLVM_CONFIG_PATH=${CONFIGURE_WRKSRC}/bin/llvm-config \
	    ${WRKSRC_compiler_rt} && \
	    ${MAKE_ENV} ${MAKE_CMD}

post-install:
	${RM} -r ${STAGEDIR}${LLVM_PREFIX}/include/llvm/MC/MCAnalysis
	${INSTALL_SCRIPT} ${WRKDIR}/llvm-wrapper.sh \
	    ${STAGEDIR}${PREFIX}/bin/${FIRST_COMMAND}${LLVM_SUFFIX}
.for command in ${COMMANDS:C/^/XXXX/1:NXXXX*}
	${LN} -f ${STAGEDIR}${PREFIX}/bin/${FIRST_COMMAND}${LLVM_SUFFIX} \
	    ${STAGEDIR}${PREFIX}/bin/${command}${LLVM_SUFFIX}
.endfor

post-install-DOCS-on:
	${MV} ${STAGEDIR}${LLVM_PREFIX}/share/doc ${STAGEDIR}${DOCSDIR}
.for _man in ${MAN1SRCS}
	${MV} ${STAGEDIR}${LLVM_PREFIX}/share/man/man1/${_man} \
	    ${STAGEDIR}${MANPREFIX}/man/man1/${_man:R}${LLVM_SUFFIX}.1
.endfor
.if ! ${PORT_OPTIONS:MLIT}
	${RM} ${STAGEDIR}${LLVM_PREFIX}/share/man/man1/lit.1
	${RM} ${STAGEDIR}${LLVM_PREFIX}/share/man/man1/FileCheck.1
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

post-install-COMPILER_RT-on:
	cd ${WRKDIR}/compiler-rt-build && \
	    ${MAKE_ENV} ${MAKE_CMD} ${INSTALL_TARGET}
.if ${ARCH} == "amd64"
	${RM} ${STAGEDIR}${LLVM_PREFIX}/lib/freebsd/libclang_rt*i386*
.endif
	${MKDIR} ${STAGEDIR}${PREFIX}/${_CRTLIBDIR}
	${MV} ${STAGEDIR}${LLVM_PREFIX}/lib/freebsd/* \
	    ${STAGEDIR}${PREFIX}/${_CRTLIBDIR}
	${RMDIR} ${STAGEDIR}${LLVM_PREFIX}/lib/freebsd

post-install-LIT-on:
	${INSTALL_SCRIPT} ${PATCH_WRKSRC}/utils/lit/lit.py \
	    ${STAGEDIR}${LLVM_PREFIX}/bin/lit
	${LN} -f ${STAGEDIR}${LLVM_PREFIX}/bin/lit \
	    ${STAGEDIR}${LLVM_PREFIX}/bin/llvm-lit
	${LN} -f ${STAGEDIR}${LLVM_PREFIX}/bin/lit \
	    ${STAGEDIR}${PREFIX}/bin/lit${LLVM_SUFFIX}
	${LN} -f ${STAGEDIR}${LLVM_PREFIX}/bin/lit \
	    ${STAGEDIR}${PREFIX}/bin/llvm-lit${LLVM_SUFFIX}
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/lit${LLVM_SUFFIX}
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/lit${LLVM_SUFFIX}/builtin_commands
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/lit${LLVM_SUFFIX}/formats
	${INSTALL_DATA} ${WRKSRC}/utils/lit/lit/*.py \
	    ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/lit${LLVM_SUFFIX}
	${INSTALL_DATA} ${WRKSRC}/utils/lit/lit/builtin_commands/*.py \
			${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/lit${LLVM_SUFFIX}/builtin_commands
	${INSTALL_DATA} ${WRKSRC}/utils/lit/lit/formats/*.py \
			${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/lit${LLVM_SUFFIX}/formats
	${INSTALL_PROGRAM} ${WRKDIR}/.build/bin/FileCheck \
	    ${STAGEDIR}${LLVM_PREFIX}/bin/
	${LN} -f ${STAGEDIR}${LLVM_PREFIX}/bin/FileCheck \
	    ${STAGEDIR}${PREFIX}/bin/FileCheck${LLVM_SUFFIX}

post-install-LLD_LINK-on:
	${LN} -s ld.lld ${STAGEDIR}${LLVM_PREFIX}/bin/ld

TEST_CMD=	'(cd ${WRKSRC}/test; ${SETENV} ${MAKE_ENV} LD_LIBRARY_PATH=${WRKSRC}/Release/lib ${MAKE_CMD} check-local-lit)'
do-test:
	if [ `${ID} -u` = 0 ]; then \
		${CHOWN} -R nobody ${WRKSRC}/test; \
		su -m nobody -c ${TEST_CMD}; \
	else \
		${SH} -c ${TEST_CMD}; \
	fi

build-plist:
	${RM} ${PLIST} ${PLIST}.tmp
	${ECHO_CMD} "@comment >>>>> GENERATED FILE, DO NOT EDIT <<<<<" >> ${PLIST}.tmp
	${ECHO_CMD} "@comment Alter build-plist target and regenerate as required" >> ${PLIST}.tmp
.for command in ${COMMANDS}
	${ECHO_CMD} bin/${command}%%LLVM_SUFFIX%% >> ${PLIST}.tmp
.endfor
.for command in ${LIT_COMMANDS}
	${ECHO_CMD} %%LIT%%bin/${command}%%LLVM_SUFFIX%% >> ${PLIST}.tmp
	${ECHO_CMD} %%LIT%%${LLVM_PREFIX:S|${PREFIX}/||:C|${LLVM_SUFFIX}|%%LLVM_SUFFIX%%|}/bin/${command} >> ${PLIST}.tmp
.endfor

	${FIND} ${STAGEDIR}${LLVM_PREFIX} -type f -o -type l | \
	    ${GREP} -v '_blacklist.txt$$' | \
	    ${GREP} -v '[/-]lit$$' | ${GREP} -v 'FileCheck$$' | \
	    ${GREP} -v man/man1 | ${SED} -e 's|${STAGEDIR}${PREFIX}/||' \
	    -e 's|${PYTHON_SITELIBDIR:C|${PREFIX}/||}|%%PYTHON_SITELIBDIR%%|' \
	    -e 's|${LLVM_RELEASE}|%%LLVM_RELEASE%%|' \
	    -e 's|release.cmake|%%CMAKE_BUILD_TYPE%%.cmake|' \
	    -e 's|${LLVM_RELEASE:C/\./\\./g}|%%LLVM_RELEASE%%|' \
	    -e 's|${LLVM_SUFFIX:C/\./\\./g}|%%LLVM_SUFFIX%%|' \
	    -e 's|\([^0-9]\)${LLVM_MAJOR}$$|\1%%LLVM_MAJOR%%|' \
	    -e 's|\([^0-9]\)${LLVM_MAJOR}\([^0-9]\)|\1%%LLVM_MAJOR%%\2|' \
	    | ${SORT} >> ${PLIST}.tmp
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/lit${LLVM_SUFFIX} -type f | \
	    ${SED} -e 's|${STAGEDIR}${PYTHON_SITELIBDIR}|%%LIT%%%%PYTHON_SITELIBDIR%%|' \
	    -e 's|${LLVM_RELEASE:C/\./\\./g}|%%LLVM_RELEASE%%|' \
	    -e 's|${LLVM_SUFFIX:C/\./\\./g}|%%LLVM_SUFFIX%%|' \
	    -e 's|\([^0-9]\)${LLVM_MAJOR}$$|\1%%LLVM_MAJOR%%|' \
	    -e 's|\([^0-9]\)${LLVM_MAJOR}\([^0-9]\)|\1%%LLVM_MAJOR%%\2|' \
	    | ${SORT} >> ${PLIST}.tmp
	${AWK} '{ \
	    if ($$0 ~ /${CLANG_PATTERN}/ && $$0 !~ /(omp.h|ompt.h|${EXTRAS_PATTERN}|libclang_rt|${PYCLANG_PATTERN})/) {printf "%%%%CLANG%%%%"} \
	    if ($$0 ~ /${COMPILER_RT_PATTERN}/) \
		{printf "%%%%COMPILER_RT%%%%"} \
	    if ($$0 ~ /(${EXTRAS_PATTERN})/) {printf "%%%%EXTRAS%%%%"} \
	    if ($$0 ~ /(lld|wasm-ld)/ && $$0 !~ /(lldb)/) {printf "%%%%LLD%%%%"} \
	    if ($$0 ~ /(bin\/ld$$)/) {printf "%%%%LLD_LINK%%%%"} \
	    if ($$0 ~ /(argdumper|lldb|six.py)/) {printf "%%%%LLDB%%%%"} \
	    if ($$0 ~ /(lib.*omp|omp.h|ompt.h)/) {printf "%%%%OPENMP%%%%"} \
	    if ($$0 ~ /(LLVMgold)/) {printf "%%%%GOLD%%%%"} \
	    if ($$0 ~ /${PYCLANG_PATTERN}/) {printf "%%%%PYCLANG%%%%"} \
	    if ($$0 !~ /(libclang_rt)/ && $$0 !~ /(${BE_PATTERN})$$/) {print}}' ${PLIST}.tmp >> ${PLIST}
	${ECHO_CMD} '@postexec if type ccache-update-links >/dev/null 2>&1; then ccache-update-links -v; fi' >> ${PLIST}
	${ECHO_CMD} '@postunexec if type ccache-update-links >/dev/null 2>&1; then ccache-update-links -v; fi' >> ${PLIST}
	${RM} ${PLIST}.tmp

check-commands:
.for command in ${COMMANDS}
	test -e ${STAGEDIR}${LLVM_PREFIX}/bin/${command}
.endfor

.include <bsd.port.post.mk>
