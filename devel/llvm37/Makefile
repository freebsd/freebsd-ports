# $FreeBSD$

PORTNAME=	llvm
DISTVERSION=	3.7.0
PORTREVISION=	4
CATEGORIES=	devel lang
MASTER_SITES=	http://llvm.org/${PRE_}releases/${LLVM_RELEASE}/${RCDIR}
DISTNAME=	${PORTNAME}-${DISTVERSION}.src
DISTFILES=	${PORTNAME}-${DISTVERSION}.src${EXTRACT_SUFX}
PKGNAMESUFFIX=	${LLVM_SUFFIX}

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	LLVM and Clang

LLVM_RELEASE=	${DISTVERSION:C/rc.*//}
RCDIR=		${DISTVERSION:S/${LLVM_RELEASE}//:C|(rc.*)|\1/|}
PRE_=		${DISTVERSION:C/.*rc.*/pre-/:N*[0-9]*}
LLVM_SUFFIX=	${DISTVERSION:R:S/.//}

LLVM_PREFIX=	${PREFIX}/llvm${LLVM_SUFFIX}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${LLVM_SUFFIX}
DATADIR=	${PREFIX}/share/${PORTNAME}${LLVM_SUFFIX}

USES=		cmake:outsource compiler:c++11-lib libedit ninja perl5 tar:xz
USE_LDCONFIG=	${LLVM_PREFIX}/lib

SUB_FILES=	llvm-wrapper.sh
SUB_LIST=	LLVM_PREFIX="${LLVM_PREFIX}" LLVM_SUFFIX="${LLVM_SUFFIX}"

CMAKE_INSTALL_PREFIX=	${LLVM_PREFIX}
CMAKE_ARGS=	-DBUILD_SHARED_LIBS=ON

OPTIONS_DEFINE=	CLANG COMPILER_RT DOCS EXTRAS GOLD LIT LLD LLDB
OPTIONS_DEFINE_amd64=	OPENMP
OPTIONS_DEFAULT=	CLANG EXTRAS GOLD LIT LLD LLDB
OPTIONS_DEFAULT_amd64=	COMPILER_RT OPENMP
OPTIONS_DEFAULT_i386=	COMPILER_RT
OPTIONS_SUB=	yes

CLANG_DESC=	Build clang
CLANG_EXTRA_PATCHES= \
	${PATCHDIR}/clang-patch-fformat_extensions.diff \
	${PATCHDIR}/clang-patch-tools_clang_lib_Headers_CMakeLists.txt \
	${PATCHDIR}/clang-patch-tools_clang_tools_clang-format_clang-format.py \
	${PATCHDIR}/clang-patch-svn-250416
CLANG_CONFLICTS_INSTALL=	clang-devel-3.[1234567]*
CLANG_DISTFILES=	cfe-${DISTVERSION}.src${EXTRACT_SUFX}
CLANG_CMAKE_ON=		-DCLANG_DEFAULT_OPENMP_RUNTIME=libomp
CLANG_PORTDOCS=		clang
COMPILER_RT_DESC=	Build compiler-rt (sanitizers)
COMPILER_RT_DISTFILES=	compiler-rt-${DISTVERSION}.src${EXTRACT_SUFX}
COMPILER_RT_EXTRA_PATCHES= \
	${PATCHDIR}/compiler-rt-patch-svn-249051
DOCS_PORTDOCS=		llvm
DOCS_CMAKE_ON=		-DLLVM_ENABLE_SPHINX=ON \
			-DSPHINX_WARNINGS_AS_ERRORS=OFF \
			-DLLVM_BUILD_DOCS=ON
DOCS_PLIST_FILES=	${MAN1SRCS:S|^|man/man1/|:S|.1$|${LLVM_SUFFIX}.1.gz|}
EXTRAS_DESC=		Extra clang tools
EXTRAS_IMPLIES=		CLANG
EXTRAS_DISTFILES= clang-tools-extra-${DISTVERSION}.src${EXTRACT_SUFX}
EXTRAS_EXTRA_PATCHES= \
	${PATCHDIR}/extras-patch-cmake_include_hack.diff
LIT_DESC=		Install lit and FileCheck test tools
LLD_DESC=		Install lld, the LLVM linker
LLD_DISTFILES=		lld-${DISTVERSION}.src${EXTRACT_SUFX}
LLDB_DESC=		Install lldb, the LLVM debugger (ignored on 9.x)
LLDB_BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13
LLDB_DISTFILES=		lldb-${DISTVERSION}.src${EXTRACT_SUFX}
LLDB_EXTRA_PATCHES= \
	${PATCHDIR}/lldb-patch-svn-247116 \
	${PATCHDIR}/lldb-patch-svn-249467
OPENMP_DESC=		Install libomp, the LLVM OpenMP runtime library
OPENMP_DISTFILES=	openmp-${DISTVERSION}.src${EXTRACT_SUFX}
GOLD_DESC=		Build the LLVM Gold plugin for LTO
GOLD_CMAKE_ON=		-DLLVM_BINUTILS_INCDIR=${LOCALBASE}/include
GOLD_BUILD_DEPENDS=	ld.gold:${PORTSDIR}/devel/binutils

# Emulate USE_GITHUB's ${WRKSRC_tag} to reduce diffs to ../llvm-devel
.for option in CLANG COMPILER_RT EXTRAS LLD LLDB OPENMP
WRKSRC_${option:tl}=		${WRKDIR}/${${option}_DISTFILES:S/${EXTRACT_SUFX}//}
.endfor

OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=		sphinx-build:${PORTSDIR}/textproc/py-sphinx

PLIST_SUB+=	LLVM_RELEASE=${LLVM_RELEASE}

COMMANDS=	bugpoint \
		llc \
		lli \
		llvm-ar \
		llvm-as \
		llvm-bcanalyzer \
		llvm-config \
		llvm-cov \
		llvm-diff \
		llvm-dis \
		llvm-dwarfdump \
		llvm-extract \
		llvm-link \
		llvm-mc \
		llvm-mcmarkup \
		llvm-nm \
		llvm-objdump \
		llvm-profdata \
		llvm-ranlib \
		llvm-readobj \
		llvm-rtdyld \
		llvm-size \
		llvm-stress \
		llvm-symbolizer \
		llvm-tblgen \
		macho-dump \
		opt
FIRST_COMMAND=	${COMMANDS:C/^/XXXX/1:MXXXX*:C/^XXXX//}

STRIP_LIBS=	BugpointPasses.so \
		LLVMHello.so \
		${LIBNAME}.0 \
		libLTO.so

EXTRAS_COMMANDS+= \
		clang-apply-replacements \
		clang-modernize \
		clang-rename \
		clang-tidy
EXTRAS_LIBS=	libclangApplyReplacements \
		libclangQuery \
		libclangRename \
		libclangTidy \
		libclangTidyGoogleModule \
		libclangTidyLLVMModule \
		libclangTidyMiscModule \
		libclangTidyReadabilityModule \
		libclangTidyUtils \
		libmodernizeCore
EXTRAS_PATTERN=	${EXTRAS_COMMANDS:tW:C/  */|/g}${EXTRAS_LIBS:tW:C/  */|/g}

.include <bsd.port.options.mk>

# keep in sync with /usr/src/lib/clang/clang.build.mk
CONFIGURE_TARGET:=${ARCH:C/amd64/x86_64/:C/armv6hf/armv6/}-portbld-${OPSYS:tl}${OSREL}

.if ${PORT_OPTIONS:MCLANG}
COMMANDS+=	clang \
		clang++ \
		clang-check \
		clang-cpp \
		clang-format
MAN1SRCS+=	clang.1
.endif

.if ${PORT_OPTIONS:MEXTRAS}
COMMANDS+=	${EXTRAS_COMMANDS}
.endif

.if ${PORT_OPTIONS:MCOMPILER_RT}
SAN_LIBDIR=${LLVM_PREFIX}/lib/clang/${LLVM_RELEASE}/lib/freebsd
.if ${ARCH} == "amd64"
# Disable i386 variants on amd64.
EXTRA_PATCHES+= \
    ${PATCHDIR}/compiler-rt-patch-tools_compiler-rt_cmake_config-ix.cmake
PLIST_FILES+=	\
	${SAN_LIBDIR}/libclang_rt.asan-preinit-x86_64.a \
	${SAN_LIBDIR}/libclang_rt.asan-x86_64.a \
	${SAN_LIBDIR}/libclang_rt.asan-x86_64.a.syms \
	${SAN_LIBDIR}/libclang_rt.asan-x86_64.so \
	${SAN_LIBDIR}/libclang_rt.asan_cxx-x86_64.a \
	${SAN_LIBDIR}/libclang_rt.asan_cxx-x86_64.a.syms \
	${SAN_LIBDIR}/libclang_rt.builtins-x86_64.a \
	${SAN_LIBDIR}/libclang_rt.dd-x86_64.a \
	${SAN_LIBDIR}/libclang_rt.dyndd-x86_64.so \
	${SAN_LIBDIR}/libclang_rt.lsan-x86_64.a \
	${SAN_LIBDIR}/libclang_rt.profile-x86_64.a \
	${SAN_LIBDIR}/libclang_rt.safestack-x86_64.a \
	${SAN_LIBDIR}/libclang_rt.tsan-x86_64.a \
	${SAN_LIBDIR}/libclang_rt.tsan-x86_64.a.syms \
	${SAN_LIBDIR}/libclang_rt.tsan_cxx-x86_64.a \
	${SAN_LIBDIR}/libclang_rt.tsan_cxx-x86_64.a.syms \
	${SAN_LIBDIR}/libclang_rt.ubsan_standalone-x86_64.a \
	${SAN_LIBDIR}/libclang_rt.ubsan_standalone-x86_64.a.syms \
	${SAN_LIBDIR}/libclang_rt.ubsan_standalone_cxx-x86_64.a \
	${SAN_LIBDIR}/libclang_rt.ubsan_standalone_cxx-x86_64.a.syms
.elif ${ARCH} == "i386"
PLIST_FILES+=	\
	${SAN_LIBDIR}/libclang_rt.asan-i386.a \
	${SAN_LIBDIR}/libclang_rt.asan-i386.so \
	${SAN_LIBDIR}/libclang_rt.asan-preinit-i386.a \
	${SAN_LIBDIR}/libclang_rt.asan_cxx-i386.a \
	${SAN_LIBDIR}/libclang_rt.builtins-i386.a \
	${SAN_LIBDIR}/libclang_rt.profile-i386.a \
	${SAN_LIBDIR}/libclang_rt.safestack-i386.a \
	${SAN_LIBDIR}/libclang_rt.ubsan_standalone-i386.a \
	${SAN_LIBDIR}/libclang_rt.ubsan_standalone_cxx-i386.a
.else
BROKEN=	no packaging data for sanitizers on ${ARCH}.  Disable COMPILER_RT.
.endif
.endif

.if ${PORT_OPTIONS:MLIT}
MAN1SRCS+=	lit.1 FileCheck.1
_USES_PYTHON=	python
LIT_COMMANDS=	lit llvm-lit FileCheck
.endif

.if ${PORT_OPTIONS:MLLD}
COMMANDS+=	lld
PORTDOCS+=	lld
.endif

.if ${PORT_OPTIONS:MLLDB}
COMMANDS+=	argdumper \
		lldb \
		lldb-mi \
		lldb-server
_USES_PYTHON=	python
.endif

.if ! ${OPTIONS_DEFINE:MOPENMP}
# Hack to disable OPENMP in plist of unsupported architectures
PLIST_SUB+=    OPENMP="@comment "
.else
.endif

_USES_PYTHON?=	python:build
USES+=		${_USES_PYTHON}

MAN1SRCS+=	bugpoint.1 llc.1 lli.1 llvm-ar.1 llvm-as.1 \
		llvm-bcanalyzer.1 llvm-build.1 llvm-config.1 llvm-cov.1 \
		llvm-diff.1 llvm-dis.1 llvm-dwarfdump.1 \
		llvm-extract.1 llvm-link.1 llvm-nm.1 \
		llvm-profdata.1 llvm-readobj.1 llvm-stress.1 llvm-symbolizer.1 \
		opt.1 tblgen.1

NOT_FOR_ARCH=	ia64

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3400
LLDB_BUILD_DEPENDS+= \
	${PYTHON_PKGNAMEPREFIX}enum34>0:${PORTSDIR}/devel/py-enum34
.endif

.if ${OPSYS} == "FreeBSD" && ${COMPILER_TYPE} != clang
# Evil hack around gcc48 not providing a usable c++11 environment on 9.x
PLIST_SUB:=	${PLIST_SUB:NLLDB=*} LLDB="@comment "
.endif

post-extract-CLANG-on:
	${MV} ${WRKSRC_clang} ${PATCH_WRKSRC}/tools/clang

post-extract-EXTRAS-on:
	${MV} ${WRKSRC_extras} ${PATCH_WRKSRC}/tools/clang-tools-extra

post-extract-COMPILER_RT-on:
	${MV} ${WRKSRC_compiler_rt} ${PATCH_WRKSRC}/tools/compiler-rt

post-extract-LLD-on:
	${MV} ${WRKSRC_lld} ${PATCH_WRKSRC}/tools/lld

post-extract-LLDB-on:
.if ${OPSYS} != "FreeBSD" || ${COMPILER_TYPE} == clang
	${MV} ${WRKSRC_lldb} ${PATCH_WRKSRC}/tools/lldb
.endif

post-extract-OPENMP-on:
	${MV} ${WRKSRC_openmp} ${PATCH_WRKSRC}/tools/openmp

post-patch:
	${REINPLACE_CMD} -e 's|import lit|import lit${LLVM_SUFFIX}|' \
	    -e 's|from lit|from lit${LLVM_SUFFIX}|' \
	    -e 's|lit\.|lit${LLVM_SUFFIX}.|' \
	    ${WRKSRC}/utils/lit/lit.py ${WRKSRC}/utils/lit/lit/*.py

post-install:
	${RMDIR} ${STAGEDIR}${LLVM_PREFIX}/include/llvm/MC/MCAnalysis
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

post-install-LLDB-on:
.if ${OPSYS} != "FreeBSD" || ${COMPILER_TYPE} == clang
	${RM} ${STAGEDIR}${LLVM_PREFIX}/lib/python*/site-packages/lib
.endif

post-install-CLANG-on:
	${LN} -f ${STAGEDIR}${LLVM_PREFIX}/bin/clang \
	   ${STAGEDIR}${LLVM_PREFIX}/bin/clang-cpp

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
	${INSTALL_DATA} ${WRKSRC}/utils/lit/lit/*.py \
	    ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/lit${LLVM_SUFFIX}
	${INSTALL_PROGRAM} ${WRKDIR}/.build/bin/FileCheck \
	    ${STAGEDIR}${LLVM_PREFIX}/bin/
	${LN} -f ${STAGEDIR}${LLVM_PREFIX}/bin/FileCheck \
	    ${STAGEDIR}${PREFIX}/bin/FileCheck${LLVM_SUFFIX}

TEST_CMD=	'(cd ${WRKSRC}/test; ${SETENV} ${MAKE_ENV} LD_LIBRARY_PATH=${WRKSRC}/Release/lib ${MAKE_CMD} check-local-lit)'
regression-test: ${BUILD_COOKIE}
	if [ `${ID} -u` = 0 ]; then \
		${CHOWN} -R nobody ${WRKSRC}/test; \
		su -m nobody -c ${TEST_CMD}; \
	else \
		${SH} -c ${TEST_CMD}; \
	fi

build-plist:
	${RM} -f ${PLIST} ${PLIST}.tmp
.for command in ${COMMANDS}
	${ECHO_CMD} bin/${command}${LLVM_SUFFIX} >> ${PLIST}.tmp
.endfor
.for command in ${LIT_COMMANDS}
	${ECHO_CMD} %%LIT%%bin/${command}${LLVM_SUFFIX} >> ${PLIST}.tmp
	${ECHO_CMD} %%LIT%%${LLVM_PREFIX:S|${PREFIX}/||}/bin/${command} >> ${PLIST}.tmp
.endfor

	${FIND} ${STAGEDIR}${LLVM_PREFIX} -type f -o -type l | \
	    ${GREP} -v 'lit$$' | ${GREP} -v 'FileCheck$$' | \
	    ${GREP} -v man/man1 | ${SED} -e 's|${STAGEDIR}${PREFIX}/||' \
	    -e 's|${LLVM_RELEASE}|%%LLVM_RELEASE%%|' \
	    -e 's|release.cmake|%%CMAKE_BUILD_TYPE%%.cmake|' | \
	    ${SORT} >> ${PLIST}.tmp
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/lit${LLVM_SUFFIX} -type f | \
	    ${SED} -e 's|${STAGEDIR}${PYTHON_SITELIBDIR}|%%LIT%%%%PYTHON_SITELIBDIR%%|' | \
	    ${SORT} >> ${PLIST}.tmp
	awk '{ \
	    if ($$0 ~ /clang/ && $$0 !~ /(omp.h|libclang_rt|sanitizer|blacklist.txt|${EXTRAS_PATTERN})/) {printf "%%%%CLANG%%%%"} \
	    if ($$0 ~ /(sanitizer|blacklist.txt)/) {printf "%%%%COMPILER_RT%%%%"} \
	    if ($$0 ~ /(${EXTRAS_PATTERN})/) {printf "%%%%EXTRAS%%%%"} \
	    if ($$0 ~ /lld/ && $$0 !~ /lldb/) {printf "%%%%LLD%%%%"} \
	    if ($$0 ~ /(argdumper|lldb)/) {printf "%%%%LLDB%%%%"} \
	    if ($$0 ~ /lib.*omp/) {printf "%%%%OPENMP%%%%"} \
	    if ($$0 ~ /LLVMgold/) {printf "%%%%GOLD%%%%"} \
		if ($$0 !~ /libclang_rt/) {print}}' ${PLIST}.tmp >> ${PLIST}
	${RM} -f ${PLIST}.tmp

check-commands:
.for command in ${COMMANDS}
	test -e ${STAGEDIR}${LLVM_PREFIX}/bin/${command}
.endfor

.if make(svn-patch-clang)
.if !defined(PATCH_REV)
.error svn-patch-clang requires that PATCH_REV be set
.endif
_PATCH_FILE=${FILESDIR}/clang-patch-svn-${PATCH_REV}
_LLVM_BASE=http://llvm.org/svn/llvm-project/cfe/trunk
svn-patch-clang:
	svn log -c ${PATCH_REV} ${_LLVM_BASE} >> ${_PATCH_FILE}
	svn diff -c ${PATCH_REV} ${_LLVM_BASE} | \
	    sed -E -e 's;^(---|\+\+\+) ;\1 tools/clang/;' >> ${_PATCH_FILE}
.endif
.if make(svn-patch-compiler-rt)
.if !defined(PATCH_REV)
.error svn-patch-compiler-rt requires that PATCH_REV be set
.endif
_PATCH_FILE=${FILESDIR}/compiler-rt-patch-svn-${PATCH_REV}
_LLVM_BASE=http://llvm.org/svn/llvm-project/compiler-rt/trunk
svn-patch-compiler-rt:
	svn log -c ${PATCH_REV} ${_LLVM_BASE} >> ${_PATCH_FILE}
	svn diff -c ${PATCH_REV} ${_LLVM_BASE} | \
	    sed -E -e 's;^(---|\+\+\+) ;\1 tools/compiler-rt/;' >> ${_PATCH_FILE}
.endif
.if make(svn-patch-lldb)
.if !defined(PATCH_REV)
.error svn-patch-lldb requires that PATCH_REV be set
.endif
_PATCH_FILE=${FILESDIR}/lldb-patch-svn-${PATCH_REV}
_LLVM_BASE=http://llvm.org/svn/llvm-project/lldb/trunk
svn-patch-lldb:
	svn log -c ${PATCH_REV} ${_LLVM_BASE} >> ${_PATCH_FILE}
	svn diff -c ${PATCH_REV} ${_LLVM_BASE} | \
	    sed -E -e 's;^(---|\+\+\+) ;\1 tools/lldb/;' >> ${_PATCH_FILE}
.endif

.include <bsd.port.post.mk>
