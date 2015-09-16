# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	llvm
PORTVERSION=	3.8.d20150818
CATEGORIES=	devel lang
PKGNAMESUFFIX=	-devel

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	LLVM and Clang

LLVM_SUFFIX=	-devel
LLVM_PREFIX=	${PREFIX}/llvm${LLVM_SUFFIX}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${LLVM_SUFFIX}
DATADIR=	${PREFIX}/share/${PORTNAME}${LLVM_SUFFIX}

USES=		cmake:outsource compiler:c++11-lib libedit ninja perl5
USE_LDCONFIG=	${LLVM_PREFIX}/lib

SUB_FILES=	llvm-wrapper.sh
SUB_LIST=	LLVM_PREFIX="${LLVM_PREFIX}" LLVM_SUFFIX="${LLVM_SUFFIX}"

CMAKE_INSTALL_PREFIX=	${LLVM_PREFIX}
CMAKE_ARGS=	-DBUILD_SHARED_LIBS=ON

USE_GITHUB=	yes
GH_ACCOUNT=	llvm-mirror
GH_TAGNAME=	${LLVM_COMMIT}

LLVM_COMMIT=	27aa81cf903ceab79619111243e0e228e46c6747
CLANG_COMMIT=	f27472a5facd07e48e9cd6d1f8d1d793f866b05f
COMPILER_RT_COMMIT=	5708a2383ea388510464a12c9c708b224d492e74
LLD_COMMIT=	d8afe0be205f34c2576df36ee71d9ffadbdace22
LLDB_COMMIT=	7da1acdcab24b6fbcd3aa6c5e28b30e0226f2a96
OPENMP_COMMIT=	fc660a2d58e17f60c2904b4be9eb5686110d6d72

OPTIONS_DEFINE=	CLANG COMPILER_RT DOCS GOLD LIT LLD LLDB
OPTIONS_DEFINE_amd64=	OPENMP
OPTIONS_DEFAULT=	CLANG GOLD LIT LLD LLDB
OPTIONS_DEFAULT_amd64=	COMPILER_RT OPENMP
OPTIONS_DEFAULT_i386=	COMPILER_RT
OPTIONS_SUB=	yes

CLANG_DESC=	Build clang
CLANG_EXTRA_PATCHES= ${PATCHDIR}/clang-patch-tools_clang_lib_Headers_CMakeLists.txt
CLANG_CONFLICTS_INSTALL=	clang-devel-3.[1234567]*
CLANG_GH_PROJECT=	clang:clang
CLANG_GH_TAGNAME=	${CLANG_COMMIT}:clang
CLANG_CMAKE_ON=		-DCLANG_DEFAULT_OPENMP_RUNTIME=libomp
CLANG_PORTDOCS=		clang
COMPILER_RT_DESC=	Build compiler-rt (sanitizers)
COMPILER_RT_GH_PROJECT=	compiler-rt:compiler_rt
COMPILER_RT_GH_TAGNAME=	${COMPILER_RT_COMMIT}:compiler_rt
DOCS_PORTDOCS=		llvm
DOCS_CMAKE_ON=		-DLLVM_ENABLE_SPHINX=ON \
			-DSPHINX_WARNINGS_AS_ERRORS=OFF \
			-DLLVM_BUILD_DOCS=ON
DOCS_PLIST_FILES=	${MAN1SRCS:S|^|man/man1/|:S|.1$|${LLVM_SUFFIX}.1.gz|}
LIT_DESC=		Install lit and FileCheck test tools
LLD_DESC=		Install lld, the LLVM linker
LLD_GH_PROJECT=		lld:lld
LLD_GH_TAGNAME=		${LLD_COMMIT}:lld
LLDB_DESC=		Install lldb, the LLVM debugger (ignored on 9.x)
LLDB_BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13
LLDB_GH_PROJECT=	lldb:lldb
LLDB_GH_TAGNAME=	${LLDB_COMMIT}:lldb
OPENMP_DESC=		Install libomp, the LLVM OpenMP runtime library
OPENMP_CONFLICTS_INSTALL=	libiomp5-devel-*
OPENMP_GH_PROJECT=	openmp:openmp
OPENMP_GH_TAGNAME=	${OPENMP_COMMIT}:openmp
GOLD_DESC=		Build the LLVM Gold plugin for LTO
GOLD_CMAKE_ON=		-DLLVM_BINUTILS_INCDIR=${LOCALBASE}/include
GOLD_BUILD_DEPENDS=	ld.gold:${PORTSDIR}/devel/binutils

OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=		sphinx-build:${PORTSDIR}/textproc/py-sphinx

LLVM_RELEASE=	3.8.0

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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLANG}
COMMANDS+=	clang \
		clang++ \
		clang-check \
		clang-cpp \
		clang-format
MAN1SRCS+=	clang.1
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
COMMANDS+=	lld \
		lld-link
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
		llvm-extract.1 llvm-lib.1 llvm-link.1 llvm-nm.1 \
		llvm-profdata.1 llvm-readobj.1 llvm-stress.1 llvm-symbolizer.1 \
		opt.1 tblgen.1

NOT_FOR_ARCH=	ia64

.include <bsd.port.pre.mk>

.if ${OPSYS} == "FreeBSD" && ${COMPILER_TYPE} != clang
# Evil hack around gcc48 not providing a usable c++11 environment on 9.x
PLIST_SUB:=	${PLIST_SUB:NLLDB=*} LLDB="@comment "
.endif

post-extract-CLANG-on:
	${MV} ${WRKSRC_clang} ${PATCH_WRKSRC}/tools/clang

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
	    -e 's|${PORTVERSION}|%%PORTVERSION%%|' \
	    -e 's|release.cmake|%%CMAKE_BUILD_TYPE%%.cmake|' | \
	    ${SORT} >> ${PLIST}.tmp
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/lit${LLVM_SUFFIX} -type f | \
	    ${SED} -e 's|${STAGEDIR}${PYTHON_SITELIBDIR}|%%LIT%%%%PYTHON_SITELIBDIR%%|' | \
	    ${SORT} >> ${PLIST}.tmp
	awk '{if ($$0 ~ /clang/ && $$0 !~ /(omp.h|libclang_rt|sanitizer|blacklist.txt)/) {printf "%%%%CLANG%%%%"} if ($$0 ~ /(libclang_rt|sanitizer|blacklist.txt)/) {printf "%%%%COMPILER_RT%%%%"} if ($$0 ~ /lld/ && $$0 !~ /lldb/) {printf "%%%%LLD%%%%"} if ($$0 ~ /(argdumper|lldb)/) {printf "%%%%LLDB%%%%"} if ($$0 ~ /lib.*omp/) {printf "%%%%OPENMP%%%%"} if ($$0 ~ /LLVMgold/) {printf "%%%%GOLD%%%%"} if ($$0 !~ /libclang_rt/) {print}}' ${PLIST}.tmp >> ${PLIST}
	${RM} -f ${PLIST}.tmp

check-commands:
.for command in ${COMMANDS}
	test -e ${STAGEDIR}${LLVM_PREFIX}/bin/${command}
.endfor

.include <bsd.port.post.mk>
