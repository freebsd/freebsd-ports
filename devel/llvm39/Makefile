# $FreeBSD$

PORTNAME=	llvm
DISTVERSION=	3.9.0
PORTREVISION=	5
CATEGORIES=	devel lang
MASTER_SITES=	http://llvm.org/${PRE_}releases/${LLVM_RELEASE}/${RCDIR}
PKGNAMESUFFIX=	${LLVM_SUFFIX}
DISTNAME=	${PORTNAME}-${DISTVERSION}.src
DISTFILES=	${PORTNAME}-${DISTVERSION}.src${EXTRACT_SUFX}

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	LLVM and Clang

LICENSE=	LLVM
LICENSE_NAME=	LLVM Release License
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN_FreeBSD_9=	COMPILER_RT does not compile

LLVM_RELEASE=	${DISTVERSION:C/rc.*//}
LLVM_MAJOR=	${LLVM_RELEASE:C/\.[0-9]$//}
RCDIR=		${DISTVERSION:S/${LLVM_RELEASE}//:C|(rc.*)|\1/|}
PRE_=		${DISTVERSION:C/.*rc.*/pre-/:N*[0-9]*}
LLVM_SUFFIX=	${DISTVERSION:R:S/.//}

LLVM_PREFIX=	${PREFIX}/llvm${LLVM_SUFFIX}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${LLVM_SUFFIX}
DATADIR=	${PREFIX}/share/${PORTNAME}${LLVM_SUFFIX}

USES=		cmake:outsource compiler:c++11-lib libedit ninja perl5 tar:xz
_USES_PYTHON?=	python:build
USES+=		${_USES_PYTHON}
USE_LDCONFIG=	${LLVM_PREFIX}/lib

SUB_FILES=	llvm-wrapper.sh
SUB_LIST=	LLVM_PREFIX="${LLVM_PREFIX}" LLVM_SUFFIX="${LLVM_SUFFIX}"

CMAKE_INSTALL_PREFIX=	${LLVM_PREFIX}
CMAKE_ARGS=	-DLLVM_BUILD_LLVM_DYLIB=ON
# Following commit https://github.com/kitware/cmake/commit/956054
# we need to either change the whole man-shuffle below, or simply
# redefine CMAKE_INSTALL_MANDIR
CMAKE_ARGS+=	-DCMAKE_INSTALL_MANDIR:PATH="share/man"

OPTIONS_DEFINE=	CLANG DOCS EXTRAS LIT LLD LLDB
OPTIONS_DEFINE_amd64=	COMPILER_RT GOLD OPENMP
OPTIONS_DEFINE_i386=	COMPILER_RT
OPTIONS_DEFAULT=	CLANG EXTRAS LIT LLD LLDB
OPTIONS_DEFAULT_amd64=	COMPILER_RT GOLD OPENMP
OPTIONS_DEFAULT_i386=	COMPILER_RT
OPTIONS_SUB=	yes

CLANG_DESC=	Build clang
CLANG_EXTRA_PATCHES= \
	${PATCHDIR}/clang-patch-svn-r280672 \
	${PATCHDIR}/clang-patch-fformat_extensions.diff \
	${PATCHDIR}/clang-patch-fopenmp.diff \
	${PATCHDIR}/clang-patch-tools_clang_lib_Headers_CMakeLists.txt \
	${PATCHDIR}/clang-patch-tools_clang_tools_clang-format_clang-format.py \
	${PATCHDIR}/clang-patch-tools_clang_tools_scan-build_libexec_ccc-analyzer
CLANG_CONFLICTS_INSTALL=	clang-devel-3.[1234567]*
CLANG_DISTFILES=	cfe-${DISTVERSION}.src${EXTRACT_SUFX}
CLANG_CMAKE_ON=		-DCLANG_DEFAULT_OPENMP_RUNTIME=libomp
CLANG_PORTDOCS=		clang
CLANG_USE=		GNOME=libxml2
COMPILER_RT_DESC=	Sanitizer libraries
COMPILER_RT_DISTFILES=	compiler-rt-${DISTVERSION}.src${EXTRACT_SUFX}
COMPILER_RT_PLIST_FILES=${_COMPILER_RT_LIBS:S|^|${_CRTLIBDIR}/|}
DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx
DOCS_PORTDOCS=		llvm
DOCS_CMAKE_ON=		-DLLVM_ENABLE_SPHINX=ON \
			-DSPHINX_WARNINGS_AS_ERRORS=OFF \
			-DLLVM_BUILD_DOCS=ON
DOCS_PLIST_FILES=	${MAN1SRCS:S|^|man/man1/|:S|.1$|${LLVM_SUFFIX}.1.gz|}
EXTRAS_DESC=		Extra clang tools
EXTRAS_IMPLIES=		CLANG
EXTRAS_DISTFILES=	clang-tools-extra-${DISTVERSION}.src${EXTRACT_SUFX}
GOLD_DESC=		Build the LLVM Gold plugin for LTO
GOLD_CMAKE_ON=		-DLLVM_BINUTILS_INCDIR=${LOCALBASE}/include
GOLD_BUILD_DEPENDS=	${LOCALBASE}/bin/ld.gold:devel/binutils
LIT_DESC=		Install lit and FileCheck test tools
LIT_VARS=		_USES_PYTHON=python
LLD_DESC=		Install lld, the LLVM linker
LLD_DISTFILES=		lld-${DISTVERSION}.src${EXTRACT_SUFX}
LLDB_DESC=		Install lldb, the LLVM debugger (ignored on 9.x)
LLDB_EXTRA_PATCHES=	${PATCHDIR}/lldb-patch-tools_lldb_source_Host_common_FileSpec.cpp
LLDB_BUILD_DEPENDS=	swig:devel/swig13
LLDB_DISTFILES=		lldb-${DISTVERSION}.src${EXTRACT_SUFX}
LLDB_USES=		execinfo
LLDB_VARS=		_USES_PYTHON=python
OPENMP_DESC=		Install libomp, the LLVM OpenMP runtime library
OPENMP_DISTFILES=	openmp-${DISTVERSION}.src${EXTRACT_SUFX}

# Emulate USE_GITHUB's ${WRKSRC_tag} to reduce diffs to ../llvm-devel
.for option in CLANG COMPILER_RT EXTRAS LLD LLDB OPENMP
WRKSRC_${option:tl}=		${WRKDIR}/${${option}_DISTFILES:S/${EXTRACT_SUFX}//}
.endfor

OPTIONS_SUB=	yes

PLIST_SUB+=	LLVM_RELEASE=${LLVM_RELEASE} LLVM_MAJOR=${LLVM_MAJOR}

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
		llvm-split \
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
		clang-include-fixer \
		clang-modernize \
		clang-query \
		clang-rename \
		clang-tidy \
		find-all-symbols \
		modularize
EXTRAS_LIBS=	libclangApplyReplacements \
		libclangIncludeFixer \
		libclangRename \
		libclangQuery \
		libclangRename \
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
CONFIGURE_TARGET:=${ARCH:C/amd64/x86_64/:C/armv6hf/armv6/}-portbld-${OPSYS:tl}${OSREL}

.if ${PORT_OPTIONS:MCLANG}
COMMANDS+=	clang \
		clang++ \
		clang-check \
		clang-cpp \
		clang-format \
		clang-tblgen \
		scan-build \
		scan-view
MAN1SRCS+=	clang.1 \
		scan-build.1
CLANG_PATTERN=	(c-index-test|clang|scan-|Reporter.py|ScanView.py|scanview.css|sorttable.js|startfile.py|-analyzer)
.endif

.if ${PORT_OPTIONS:MCOMPILER_RT}
COMPILER_RT_PATTERN=	(asan_blacklist.txt|sanitizer|xray)
.endif

.if ${PORT_OPTIONS:MLIT}
MAN1SRCS+=	lit.1 FileCheck.1
LIT_COMMANDS=	lit llvm-lit FileCheck
.endif

.if ${PORT_OPTIONS:MLLDB}
COMMANDS+=	argdumper \
		lldb \
		lldb-mi \
		lldb-server
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

MAN1SRCS+=	bugpoint.1 llc.1 lli.1 llvm-ar.1 llvm-as.1 \
		llvm-bcanalyzer.1 llvm-build.1 llvm-config.1 llvm-cov.1 \
		llvm-diff.1 llvm-dis.1 llvm-dwarfdump.1 \
		llvm-extract.1 llvm-lib.1 llvm-link.1 llvm-nm.1 \
		llvm-profdata.1 llvm-readobj.1 llvm-stress.1 llvm-symbolizer.1 \
		opt.1 tblgen.1

NOT_FOR_ARCH=	ia64

.include <bsd.port.pre.mk>

_CRTLIBDIR=	${LLVM_PREFIX:S|${PREFIX}/||}/lib/clang/${LLVM_RELEASE}/lib/freebsd
.if ${ARCH} == "amd64"
_COMPILER_RT_LIBS= \
	libclang_rt.asan-preinit-x86_64.a \
	libclang_rt.asan-x86_64.a \
	libclang_rt.asan-x86_64.a.syms \
	libclang_rt.asan-x86_64.so \
	libclang_rt.asan_cxx-x86_64.a \
	libclang_rt.asan_cxx-x86_64.a.syms \
	libclang_rt.builtins-x86_64.a \
	libclang_rt.dd-x86_64.a \
	libclang_rt.dyndd-x86_64.so \
	libclang_rt.lsan-x86_64.a \
	libclang_rt.profile-x86_64.a \
	libclang_rt.safestack-x86_64.a \
	libclang_rt.stats-x86_64.a \
	libclang_rt.stats_client-x86_64.a \
	libclang_rt.tsan-x86_64.a \
	libclang_rt.tsan-x86_64.a.syms \
	libclang_rt.tsan_cxx-x86_64.a \
	libclang_rt.tsan_cxx-x86_64.a.syms \
	libclang_rt.ubsan_standalone-x86_64.a \
	libclang_rt.ubsan_standalone-x86_64.a.syms \
	libclang_rt.ubsan_standalone_cxx-x86_64.a \
	libclang_rt.ubsan_standalone_cxx-x86_64.a.syms
.endif
.if ${ARCH} == "i386"
_COMPILER_RT_LIBS+= \
	libclang_rt.asan-i386.a \
	libclang_rt.asan-i386.so \
	libclang_rt.asan-preinit-i386.a \
	libclang_rt.asan_cxx-i386.a \
	libclang_rt.builtins-i386.a \
	libclang_rt.profile-i386.a \
	libclang_rt.safestack-i386.a \
	libclang_rt.stats-i386.a \
	libclang_rt.stats_client-i386.a \
	libclang_rt.ubsan_standalone-i386.a \
	libclang_rt.ubsan_standalone_cxx-i386.a
.endif

.if ${PORT_OPTIONS:MEXTRAS}
COMMANDS+=	${EXTRAS_COMMANDS}
MAN1SRCS+=	extraclangtools.1
PORTDOCS+=	clang-tools
.endif

.if ${PORT_OPTIONS:MLLD}
COMMANDS+=	lld \
		lld-link
PORTDOCS+=	lld
.endif

.if ${OPSYS} == "FreeBSD" && ${COMPILER_TYPE} != clang
CXXFLAGS+=	-D_GLIBCXX_USE_C99
.endif

.if ${PYTHON_REL} < 3400
LLDB_BUILD_DEPENDS+= \
	${PYTHON_PKGNAMEPREFIX}enum34>0:devel/py-enum34
.endif

.if ${PORT_OPTIONS:MLLDB} && ${PYTHON_REL} >= 3000
BROKEN=	LLDB does not build with Python 3
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
	${MV} ${WRKSRC_openmp} ${PATCH_WRKSRC}/tools/openmp

post-patch:
	${REINPLACE_CMD} -e 's|import lit|import lit${LLVM_SUFFIX}|' \
	    -e 's|from lit|from lit${LLVM_SUFFIX}|' \
	    -e 's|lit\.|lit${LLVM_SUFFIX}.|' \
	    ${WRKSRC}/utils/lit/lit.py ${WRKSRC}/utils/lit/lit/*.py \
	    ${WRKSRC}/utils/lit/lit/formats/*.py

post-patch-CLANG-on:
	${REINPLACE_CMD} -e 's|%%LLVM_PREFIX%%|${LLVM_PREFIX}|' \
	    ${PATCH_WRKSRC}/tools/clang/lib/Driver/Tools.cpp

post-build-COMPILER_RT-on:
	${MKDIR} ${WRKDIR}/compiler-rt-build
	cd ${WRKDIR}/compiler-rt-build && \
	${CMAKE_BIN} ${CMAKE_ARGS} \
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

post-install-LLDB-on:
	${RM} ${STAGEDIR}${LLVM_PREFIX}/lib/python*/site-packages/lib
	${RM} -r ${STAGEDIR}${LLVM_PREFIX}/include/lldb/Host/windows/getopt

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
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/lit${LLVM_SUFFIX}/formats
	${INSTALL_DATA} ${WRKSRC}/utils/lit/lit/*.py \
	    ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/lit${LLVM_SUFFIX}
	${INSTALL_DATA} ${WRKSRC}/utils/lit/lit/formats/*.py \
			${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/lit${LLVM_SUFFIX}/formats
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
	${RM} ${PLIST} ${PLIST}.tmp
.for command in ${COMMANDS}
	${ECHO_CMD} bin/${command}${LLVM_SUFFIX} >> ${PLIST}.tmp
.endfor
.for command in ${LIT_COMMANDS}
	${ECHO_CMD} %%LIT%%bin/${command}${LLVM_SUFFIX} >> ${PLIST}.tmp
	${ECHO_CMD} %%LIT%%${LLVM_PREFIX:S|${PREFIX}/||}/bin/${command} >> ${PLIST}.tmp
.endfor

	${FIND} ${STAGEDIR}${LLVM_PREFIX} -type f -o -type l | \
	    ${GREP} -v '[/-]lit$$' | ${GREP} -v 'FileCheck$$' | \
	    ${GREP} -v man/man1 | ${SED} -e 's|${STAGEDIR}${PREFIX}/||' \
	    -e 's|${LLVM_RELEASE}|%%LLVM_RELEASE%%|' \
	    -e 's|release.cmake|%%CMAKE_BUILD_TYPE%%.cmake|' \
	    -e 's|${LLVM_RELEASE:C/\./\\./g}|%%LLVM_RELEASE%%|' \
	    -e 's|${LLVM_MAJOR:C/\./\\./}|%%LLVM_MAJOR%%|' | \
	    ${SORT} >> ${PLIST}.tmp
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/lit${LLVM_SUFFIX} -type f | \
	    ${SED} -e 's|${STAGEDIR}${PYTHON_SITELIBDIR}|%%LIT%%%%PYTHON_SITELIBDIR%%|' \
	    -e 's|${LLVM_RELEASE:C/\./\\./g}|%%LLVM_RELEASE%%|' \
	    -e 's|${LLVM_MAJOR:C/\./\\./}|%%LLVM_MAJOR%%|' | \
	    ${SORT} >> ${PLIST}.tmp
	${AWK} '{ \
	    if ($$0 ~ /${CLANG_PATTERN}/ && $$0 !~ /(omp.h|${EXTRAS_PATTERN}|libclang_rt)/) {printf "%%%%CLANG%%%%"} \
	    if ($$0 ~ /${COMPILER_RT_PATTERN}/) \
		{printf "%%%%COMPILER_RT%%%%"} \
	    if ($$0 ~ /(${EXTRAS_PATTERN})/) {printf "%%%%EXTRAS%%%%"} \
	    if ($$0 ~ /lld/ && $$0 !~ /lldb/) {printf "%%%%LLD%%%%"} \
	    if ($$0 ~ /(argdumper|lldb|six.py)/) {printf "%%%%LLDB%%%%"} \
	    if ($$0 ~ /lib.*omp/) {printf "%%%%OPENMP%%%%"} \
	    if ($$0 ~ /LLVMgold/) {printf "%%%%GOLD%%%%"} \
	    if ($$0 !~ /libclang_rt/) {print}}' ${PLIST}.tmp >> ${PLIST}
	${RM} ${PLIST}.tmp

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
	    ${SED} -E -e 's;^(---|\+\+\+) ;\1 tools/clang/;' >> ${_PATCH_FILE}
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
	    ${SED} -E -e 's;^(---|\+\+\+) ;\1 tools/compiler-rt/;' >> ${_PATCH_FILE}
.endif
.if make(svn-patch-lldb)
.if !defined(PATCH_REV)
.error svn-patch-lldb requires that PATCH_REV be set
.endif
_PATCH_FILE=${FILESDIR}/lldb-patch-svn-${PATCH_REV}
_LLVM_BASE=http://llvm.org/svn/llvm-project/lldb/trunk
svn-patch-lldb:
	svn log -c ${PATCH_REV} ${_LLVM_BASE} >> ${_PATCH_FILE}
	svn diff -c ${PATCH_REV} ${_LLVM_BASE} | >> ${_PATCH_FILE}
.endif

.include <bsd.port.post.mk>
