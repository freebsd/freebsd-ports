# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	llvm
PORTVERSION=	3.8.d20150720
CATEGORIES=	devel lang
MASTER_SITES=	\
    http://github.com/llvm-mirror/llvm/archive/${LLVM_COMMIT}.tar.gz?dummy=/ \
    http://github.com/llvm-mirror/clang/archive/${CLANG_COMMIT}.tar.gz?dummy=/:clang \
    http://github.com/llvm-mirror/openmp/archive/${OPENMP_COMMIT}.tar.gz?dummy=/:openmp
DISTFILES=	${LLVM_NAME}.tar.gz
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

LLVM_COMMIT=	4f50f9eba412b6c0d5e7a9616dfe7699a07cf17b
CLANG_COMMIT=	dc9de2d1a510a8b7b95610d338e89f1f91d3ecdf
OPENMP_COMMIT=	50be853810d64cf7ba61a0ee7281ce82672af972

LLVM_NAME=	${PORTNAME}-${LLVM_COMMIT}
CLANG_NAME=	clang-${CLANG_COMMIT}
OPENMP_NAME=	openmp-${OPENMP_COMMIT}

WRKSRC=		${WRKDIR}/${LLVM_NAME}

OPTIONS_DEFINE=	CLANG DOCS LIT OPENMP
OPTIONS_DEFAULT=	CLANG LIT OPENMP
OPTIONS_SUB=	yes

CLANG_DESC=	Build clang
CLANG_EXTRA_PATCHES= ${PATCHDIR}/clang-patch-tools_clang_lib_Headers_CMakeLists.txt
CLANG_DISTFILES=	${CLANG_NAME}.tar.gz:clang
CLANG_CONFLICTS_INSTALL=	clang-devel-3.[1234567]*
LIT_DESC=	Install lit and FileCheck test tools (requires python)
OPENMP_DISTFILES=	${OPENMP_NAME}.tar.gz:openmp
OPENMP_CONFLICTS_INSTALL=	libiomp5-devel-*

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
.endif

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS+=	llvm
CMAKE_ARGS+=		-DLLVM_ENABLE_SPHINX=ON \
			-DSPHINX_WARNINGS_AS_ERRORS=OFF \
			-DLLVM_BUILD_DOCS=ON
.endif

.if ${PORT_OPTIONS:MLIT}
MAN1SRCS+=		lit.1 FileCheck.1
USES+=			python
LIT_COMMANDS=		lit llvm-lit FileCheck
.else
USES+=			python:build
.endif

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
	${MV} ${WRKDIR}/${CLANG_NAME} ${PATCH_WRKSRC}/tools/clang
.endif
.if ${PORT_OPTIONS:MOPENMP}
	${MV} ${WRKDIR}/${OPENMP_NAME} ${PATCH_WRKSRC}/tools/openmp
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
	${RMDIR} ${STAGEDIR}${LLVM_PREFIX}/share/doc
.for _man in ${MAN1SRCS}
	${MV} ${STAGEDIR}${LLVM_PREFIX}/share/man/man1/${_man} \
	    ${STAGEDIR}${MANPREFIX}/man/man1/${_man:R}${LLVM_SUFFIX}.1
.endfor
.endif
	${RMDIR} ${STAGEDIR}${LLVM_PREFIX}/share/man/man1/
	${RMDIR} ${STAGEDIR}${LLVM_PREFIX}/share/man/

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
	awk '{if ($$0 ~ /clang/ && $$0 !~ /omp.h/) {printf "%%%%CLANG%%%%"} if ($$0 ~ /lib.*omp/) {printf "%%%%OPENMP%%%%"} print}' ${PLIST}.tmp >> ${PLIST}
	${RM} -f ${PLIST}.tmp

.include <bsd.port.post.mk>
