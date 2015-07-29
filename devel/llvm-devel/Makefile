# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	llvm
PORTVERSION=	3.8.d20150720
PORTREVISION=	3
CATEGORIES=	devel lang
PKGNAMESUFFIX=	-devel

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	LLVM and Clang

LLVM_SUFFIX=	-devel
LLVM_PREFIX=	${PREFIX}/llvm${LLVM_SUFFIX}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${LLVM_SUFFIX}
DATADIR=	${PREFIX}/share/${PORTNAME}${LLVM_SUFFIX}
UNIQUENAME=	${PORTNAME}${LLVM_SUFFIX}

USES=		cmake:outsource compiler:c++11-lib libedit ninja perl5
USE_LDCONFIG=	${LLVM_PREFIX}/lib

SUB_FILES=	llvm-wrapper.sh
SUB_LIST=	LLVM_PREFIX="${LLVM_PREFIX}" LLVM_SUFFIX="${LLVM_SUFFIX}"

CMAKE_INSTALL_PREFIX=	${LLVM_PREFIX}
CMAKE_ARGS=	-DBUILD_SHARED_LIBS=ON

USE_GITHUB=	yes
GH_ACCOUNT=	llvm-mirror
GH_TAGNAME=	${LLVM_COMMIT}

LLVM_COMMIT=	4f50f9eba412b6c0d5e7a9616dfe7699a07cf17b
CLANG_COMMIT=	dc9de2d1a510a8b7b95610d338e89f1f91d3ecdf
LLD_COMMIT=	3002cb875e292930a1a8f375f00b36abd1a4a83a
LLDB_COMMIT=	6160cbd3d3bcbbc409bf48a67ee097672256b03f
OPENMP_COMMIT=	50be853810d64cf7ba61a0ee7281ce82672af972

OPTIONS_DEFINE=	CLANG DOCS LIT LLD LLDB
OPTIONS_DEFINE_amd64=	OPENMP
OPTIONS_DEFAULT=	CLANG LIT LLD LLDB
OPTIONS_DEFAULT_amd64=	OPENMP
OPTIONS_SUB=	yes

CLANG_DESC=	Build clang
CLANG_EXTRA_PATCHES= ${PATCHDIR}/clang-patch-tools_clang_lib_Headers_CMakeLists.txt
CLANG_CONFLICTS_INSTALL=	clang-devel-3.[1234567]*
_CLANG_GH_PROJECT=	clang:clang
_CLANG_GH_TAGNAME=	${CLANG_COMMIT}:clang
LIT_DESC=		Install lit and FileCheck test tools
LLD_DESC=		Install lld, the LLVM linker
_LLD_GH_PROJECT=		lld:lld
_LLD_GH_TAGNAME=		${LLD_COMMIT}:lld
LLDB_DESC=		Install lldb, the LLVM debugger
LLDB_BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13
_LLDB_GH_PROJECT=	lldb:lldb
_LLDB_GH_TAGNAME=	${LLDB_COMMIT}:lldb
OPENMP_DESC=		Install libomp, the LLVM OpenMP runtime library
OPENMP_CONFLICTS_INSTALL=	libiomp5-devel-*
_OPENMP_GH_PROJECT=	openmp:openmp
_OPENMP_GH_TAGNAME=	${OPENMP_COMMIT}:openmp

OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=		sphinx-build:${PORTSDIR}/textproc/py-sphinx

LLVM_RELEASE=	${PORTVERSION:C/\.r[0-9]*//}
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
PORTDOCS+=	clang
CMAKE_ARGS+=	-DCLANG_DEFAULT_OPENMP_RUNTIME=libomp
GH_PROJECT+=	${_CLANG_GH_PROJECT}
GH_TAGNAME+=	${_CLANG_GH_TAGNAME}
.endif

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS+=	llvm
CMAKE_ARGS+=	-DLLVM_ENABLE_SPHINX=ON \
		-DSPHINX_WARNINGS_AS_ERRORS=OFF \
		-DLLVM_BUILD_DOCS=ON
.endif

.if ${PORT_OPTIONS:MLIT}
MAN1SRCS+=	lit.1 FileCheck.1
_USES_PYTHON=	python
LIT_COMMANDS=	lit llvm-lit FileCheck
.endif

.if ${PORT_OPTIONS:MLLD}
COMMANDS+=	lld
PORTDOCS+=	lld
GH_PROJECT+=	${_LLD_GH_PROJECT}
GH_TAGNAME+=	${_LLD_GH_TAGNAME}
.endif

.if ${PORT_OPTIONS:MLLDB}
COMMANDS+=	argdumper \
		lldb \
		lldb-mi \
		lldb-server
_USES_PYTHON=	python
GH_PROJECT+=	${_LLDB_GH_PROJECT}
GH_TAGNAME+=	${_LLDB_GH_TAGNAME}
.endif

.if ! ${OPTIONS_DEFINE:MOPENMP}
# Hack to disable OPENMP in plist of unsupported architectures
PLIST_SUB+=    OPENMP="@comment "
.else
GH_PROJECT+=	${_OPENMP_GH_PROJECT}
GH_TAGNAME+=	${_OPENMP_GH_TAGNAME}
.endif

_USES_PYTHON?=	python:build
USES+=		${_USES_PYTHON}

MAN1SRCS+=	bugpoint.1 llc.1 lli.1 llvm-ar.1 llvm-as.1 \
		llvm-bcanalyzer.1 llvm-build.1 llvm-config.1 llvm-cov.1 \
		llvm-diff.1 llvm-dis.1 llvm-dwarfdump.1 \
		llvm-extract.1 llvm-lib.1 llvm-link.1 llvm-nm.1 \
		llvm-profdata.1 llvm-readobj.1 llvm-stress.1 llvm-symbolizer.1 \
		opt.1 tblgen.1
PLIST_FILES+=	${MAN1SRCS:S|^|man/man1/|:S|.1$|${LLVM_SUFFIX}.1.gz|}

NOT_FOR_ARCH=	ia64

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900000
BROKEN=	GCC failing on 8.x
.endif

post-extract:
.if ${PORT_OPTIONS:MCLANG}
	${MV} ${WRKSRC_clang} ${PATCH_WRKSRC}/tools/clang
.endif
.if ${PORT_OPTIONS:MLLD}
	${MV} ${WRKSRC_lld} ${PATCH_WRKSRC}/tools/lld
.endif
.if ${PORT_OPTIONS:MLLDB}
	${MV} ${WRKSRC_lldb} ${PATCH_WRKSRC}/tools/lldb
.endif
.if ${PORT_OPTIONS:MOPENMP}
	${MV} ${WRKSRC_openmp} ${PATCH_WRKSRC}/tools/openmp
.endif

post-patch:
	${REINPLACE_CMD} -e 's|import lit|import lit${LLVM_SUFFIX}|' \
	    -e 's|from lit|from lit${LLVM_SUFFIX}|' \
	    -e 's|lit\.|lit${LLVM_SUFFIX}.|' \
	    ${WRKSRC}/utils/lit/lit.py ${WRKSRC}/utils/lit/lit/*.py

post-install:
#	${MV} ${STAGEDIR}${LLVM_PREFIX}/lib/${LIBNAME} \
#	    ${STAGEDIR}${LLVM_PREFIX}/lib/${LIBNAME}.0
#	${LN} -sf ${LIBNAME}.0 ${STAGEDIR}${LLVM_PREFIX}/lib/${LIBNAME}
#	${STRIP_CMD} ${STRIP_LIBS:S|^|${STAGEDIR}${LLVM_PREFIX}/lib/|}
.if ${PORT_OPTIONS:MCLANG}
	${LN} -f ${STAGEDIR}${LLVM_PREFIX}/bin/clang \
	    ${STAGEDIR}${LLVM_PREFIX}/bin/clang-cpp
.endif
	${INSTALL_SCRIPT} ${WRKDIR}/llvm-wrapper.sh \
	    ${STAGEDIR}${PREFIX}/bin/${FIRST_COMMAND}${LLVM_SUFFIX}
.for command in ${COMMANDS:C/^/XXXX/1:NXXXX*}
	test -e ${STAGEDIR}${LLVM_PREFIX}/bin/${command}
	${LN} -f ${STAGEDIR}${PREFIX}/bin/${FIRST_COMMAND}${LLVM_SUFFIX} \
	    ${STAGEDIR}${PREFIX}/bin/${command}${LLVM_SUFFIX}
.endfor
.if ${PORT_OPTIONS:MLIT}
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
.else
	${RM} ${STAGEDIR}${LLVM_PREFIX}/share/man/man1/lit.1
	${RM} ${STAGEDIR}${LLVM_PREFIX}/share/man/man1/FileCheck.1
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MV} ${STAGEDIR}${LLVM_PREFIX}/share/doc/llvm ${STAGEDIR}${DOCSDIR}
.if ${PORT_OPTIONS:MCLANG}
	${MV} ${STAGEDIR}${LLVM_PREFIX}/share/doc/clang ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MLLD}
	${MV} ${STAGEDIR}${LLVM_PREFIX}/share/doc/lld ${STAGEDIR}${DOCSDIR}
.endif
	${RMDIR} ${STAGEDIR}${LLVM_PREFIX}/share/doc
.for _man in ${MAN1SRCS}
	${MV} ${STAGEDIR}${LLVM_PREFIX}/share/man/man1/${_man} \
	    ${STAGEDIR}${MANPREFIX}/man/man1/${_man:R}${LLVM_SUFFIX}.1
.endfor
.endif
	${RMDIR} ${STAGEDIR}${LLVM_PREFIX}/share/man/man1/
	${RMDIR} ${STAGEDIR}${LLVM_PREFIX}/share/man/
.if ${PORT_OPTIONS:MLLDB}
	${RM} ${STAGEDIR}${LLVM_PREFIX}/lib/python*/site-packages/lib
.endif

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
	    -e 's|${PORTVERSION}|%%PORTVERSION%%|' | \
	    ${SORT} >> ${PLIST}.tmp
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/lit${LLVM_SUFFIX} -type f | \
	    ${SED} -e 's|${STAGEDIR}${PYTHON_SITELIBDIR}|%%LIT%%%%PYTHON_SITELIBDIR%%|' | \
	    ${SORT} >> ${PLIST}.tmp
#	${FIND} ${STAGEDIR}${DOCSDIR} -type f | \
#	    ${SED} -e 's|${STAGEDIR}${DOCSDIR}|%%PORTDOCS%%%%DOCSDIR%%|' | \
#	    ${SORT} >> ${PLIST}.tmp
	awk '{if ($$0 ~ /clang/ && $$0 !~ /omp.h/) {printf "%%%%CLANG%%%%"} if ($$0 ~ /lld/ && $$0 !~ /lldb/) {printf "%%%%LLD%%%%"} if ($$0 ~ /(argdumper|lldb)/) {printf "%%%%LLDB%%%%"} if ($$0 ~ /lib.*omp/) {printf "%%%%OPENMP%%%%"} print}' ${PLIST}.tmp >> ${PLIST}
	${RM} -f ${PLIST}.tmp

.include <bsd.port.post.mk>
