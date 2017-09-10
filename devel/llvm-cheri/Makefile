# $FreeBSD$

PORTNAME=	llvm
PORTVERSION=	${LLVM_MAJOR}.d${SNAPDATE}
PORTREVISION=	3
CATEGORIES=	devel lang
PKGNAMESUFFIX=	${LLVM_SUFFIX}

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	LLVM and Clang with support for the CHERI architecture

BROKEN_powerpc64=	Does not build

LLVM_SUFFIX?=	-cheri
LLVM_PREFIX=	${PREFIX}/llvm${LLVM_SUFFIX}
COMMAND_SUFFIX=	${LLVM_SUFFIX}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${LLVM_SUFFIX}
DATADIR=	${PREFIX}/share/${PORTNAME}${LLVM_SUFFIX}

USES=		cmake:outsource compiler:c++11-lib libedit perl5 \
		shebangfix
USE_LDCONFIG=	${LLVM_PREFIX}/lib
SHEBANG_FILES=	utils/lit/lit.py utils/llvm-lit/llvm-lit.in \
		tools/clang/tools/clang-format/git-clang-format \
		tools/clang/tools/clang-format/clang-format-diff.py

SUB_FILES=	llvm-wrapper.sh
SUB_LIST=	LLVM_PREFIX="${LLVM_PREFIX}" LLVM_SUFFIX="${LLVM_SUFFIX}"

CMAKE_INSTALL_PREFIX=	${LLVM_PREFIX}
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON \
		-DLLVM_DEFAULT_TARGET_TRIPLE=cheri-unknown-freebsd

USE_GITHUB=	yes
GH_ACCOUNT=	CTSRD-CHERI
GH_TAGNAME=	${LLVM_COMMIT}

.include "Makefile.snapshot"

OPTIONS_DEFINE=	CLANG DOCS LIT
OPTIONS_DEFAULT=	CLANG LIT
OPTIONS_SUB=	yes

CLANG_DESC=	Build clang
CLANG_EXTRA_PATCHES= ${PATCHDIR}/clang-patch-tools_clang_lib_Headers_CMakeLists.txt
CLANG_GH_PROJECT=	clang:clang
CLANG_GH_TAGNAME=	${CLANG_COMMIT}:clang
CLANG_PORTDOCS=		clang
DOCS_PORTDOCS=		llvm
DOCS_CMAKE_ON=		-DLLVM_ENABLE_SPHINX=ON \
			-DSPHINX_WARNINGS_AS_ERRORS=OFF \
			-DLLVM_BUILD_DOCS=ON
DOCS_PLIST_FILES=	${MAN1SRCS:S|^|man/man1/|:S|.1$|${LLVM_SUFFIX}.1.gz|}
LIT_DESC=		Install lit and FileCheck test tools
LLDB_DESC=		Install lldb, the LLVM debugger (ignore on 9.x)
LLDB_BUILD_DEPENDS=	swig:devel/swig13
LLDB_GH_PROJECT=	lldb:lldb
LLDB_GH_TAGNAME=	${LLDB_COMMIT}:lldb

OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=		sphinx-build:textproc/py-sphinx

LLVM_RELEASE=	${PORTVERSION:C/\.d[0-9]*//}
PLIST_SUB+=	COMMAND_SUFFIX=${COMMAND_SUFFIX} \
		LLVM_RELEASE=${LLVM_RELEASE} \
		LLVM_SUFFIX=${LLVM_SUFFIX}

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
		llvm-split \
		llvm-symbolizer \
		llvm-tblgen \
		opt
FIRST_COMMAND=	${COMMANDS:C/^/XXXX/1:MXXXX*:C/^XXXX//}

STRIP_LIBS=	BugpointPasses.so \
		LLVMHello.so \
		${LIBNAME}.0 \
		libLTO.so

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

.if ${PORT_OPTIONS:MLIT}
MAN1SRCS+=	lit.1 FileCheck.1
_USES_PYTHON=	python
LIT_COMMANDS=	lit llvm-lit FileCheck
.endif

.if ${PORT_OPTIONS:MLLDB}
COMMANDS+=	argdumper \
		lldb \
		lldb-mi \
		lldb-server
_USES_PYTHON=	python
.endif

_USES_PYTHON?=	python:build
USES+=		${_USES_PYTHON}

MAN1SRCS+=	bugpoint.1 llc.1 lli.1 llvm-ar.1 llvm-as.1 \
		llvm-bcanalyzer.1 llvm-build.1 llvm-config.1 llvm-cov.1 \
		llvm-diff.1 llvm-dis.1 llvm-dwarfdump.1 \
		llvm-extract.1 llvm-lib.1 llvm-link.1 llvm-nm.1 \
		llvm-profdata.1 llvm-readobj.1 llvm-stress.1 llvm-symbolizer.1 \
		opt.1 tblgen.1

.include <bsd.port.pre.mk>

.if ${OPSYS} == "FreeBSD" && ${COMPILER_TYPE} != clang
# Evil hack around gcc48 not providing a usable c++11 environment on 9.x
PLIST_SUB:=	${PLIST_SUB:NLLDB=*} LLDB="@comment "
.endif

post-extract-CLANG-on:
	${MV} ${WRKSRC_clang} ${PATCH_WRKSRC}/tools/clang

post-extract-LLDB-on:
.if ${OPSYS} != "FreeBSD" || ${COMPILER_TYPE} == clang
	${MV} ${WRKSRC_lldb} ${PATCH_WRKSRC}/tools/lldb
.endif

post-patch:
	${REINPLACE_CMD} -e 's|import lit|import lit${LLVM_SUFFIX}|' \
	    -e 's|from lit|from lit${LLVM_SUFFIX}|' \
	    -e 's|lit\.|lit${LLVM_SUFFIX}.|' \
	    ${WRKSRC}/utils/lit/lit.py ${WRKSRC}/utils/lit/lit/*.py
	${REINPLACE_CMD} -e 's,/usr/local/,${LOCALBASE}/,' \
	    ${WRKSRC}/CMakeLists.txt

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/llvm-wrapper.sh \
	    ${STAGEDIR}${PREFIX}/bin/${COMMAND_PREFIX}${FIRST_COMMAND}${COMMAND_SUFFIX}
.for command in ${COMMANDS:C/^/XXXX/1:NXXXX*}
	${LN} -f ${STAGEDIR}${PREFIX}/bin/${COMMAND_PREFIX}${FIRST_COMMAND}${COMMAND_SUFFIX} \
	    ${STAGEDIR}${PREFIX}/bin/${COMMAND_PREFIX}${command}${COMMAND_SUFFIX}
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
	    ${STAGEDIR}${PREFIX}/bin/${COMMAND_PREFIX}lit${COMMAND_SUFFIX}
	${LN} -f ${STAGEDIR}${LLVM_PREFIX}/bin/lit \
	    ${STAGEDIR}${PREFIX}/bin/${COMMAND_PREFIX}llvm-lit${COMMAND_SUFFIX}
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/lit${LLVM_SUFFIX}
	${INSTALL_DATA} ${WRKSRC}/utils/lit/lit/*.py \
	    ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/lit${LLVM_SUFFIX}
	${INSTALL_PROGRAM} ${WRKDIR}/.build/bin/FileCheck \
	    ${STAGEDIR}${LLVM_PREFIX}/bin/
	${LN} -f ${STAGEDIR}${LLVM_PREFIX}/bin/FileCheck \
	    ${STAGEDIR}${PREFIX}/bin/${COMMAND_PREFIX}FileCheck${COMMAND_SUFFIX}

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
	${ECHO_CMD} bin/${COMMAND_PREFIX}${command}%%COMMAND_SUFFIX%% >> ${PLIST}.tmp
.endfor
.for command in ${LIT_COMMANDS}
	${ECHO_CMD} %%LIT%%bin/${COMMAND_PREFIX}${command}%%COMMAND_SUFFIX%% >> ${PLIST}.tmp
	${ECHO_CMD} %%LIT%%${LLVM_PREFIX:S|${PREFIX}/||:S|${LLVM_SUFFIX}|%%LLVM_SUFFIX%%|}/bin/${command} >> ${PLIST}.tmp
.endfor
	${FIND} ${STAGEDIR}${LLVM_PREFIX} -type f -o -type l | \
	    ${GREP} -v '[/-]lit$$' | ${GREP} -v 'FileCheck$$' | \
	    ${GREP} -v man/man1 | ${SED} -e 's|${STAGEDIR}${PREFIX}/||' \
	    -e 's|${PORTVERSION}|%%PORTVERSION%%|' \
	    -e 's|release.cmake|%%CMAKE_BUILD_TYPE%%.cmake|' \
	    -e 's|${LLVM_RELEASE}|%%LLVM_RELEASE%%|' \
	    -e 's|${LLVM_SUFFIX}|%%LLVM_SUFFIX%%|' | \
	    ${SORT} >> ${PLIST}.tmp
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/lit${LLVM_SUFFIX} -type f | \
	    ${SED} -e 's|${STAGEDIR}${PYTHON_SITELIBDIR}|%%LIT%%%%PYTHON_SITELIBDIR%%|' \
	    -e 's|${LLVM_SUFFIX}|%%LLVM_SUFFIX%%|' | \
	    ${SORT} >> ${PLIST}.tmp
	awk '{if ($$0 ~ /clang/ && $$0 !~ /omp.h/) {printf "%%%%CLANG%%%%"} if ($$0 ~ /(argdumper|lldb)/) {printf "%%%%LLDB%%%%"} print}' ${PLIST}.tmp >> ${PLIST}
	${RM} ${PLIST}.tmp

check-commands:
.for command in ${COMMANDS}
	test -e ${STAGEDIR}${LLVM_PREFIX}/bin/${command}
.endfor

.include <bsd.port.post.mk>
