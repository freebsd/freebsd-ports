# $FreeBSD$

PORTNAME=	clang
DISTVERSION=	3.3
PORTREVISION=	2
CATEGORIES=	lang devel
MASTER_SITES=	http://llvm.org/releases/${PORTVERSION}/
PKGNAMESUFFIX=	${LLVM_SUFFIX}
DISTNAME=	${CLANG_NAME}
DISTFILES=	${CLANG_SOURCE} \
		${LLVM_SOURCE}

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	C, Objective-C, and C++ compiler

CLANG_NAME=	cfe-${PORTVERSION}.src
CLANG_SOURCE=	${CLANG_NAME}${EXTRACT_SUFX}
LLVM_NAME=	llvm-${PORTVERSION}.src
LLVM_SOURCE=	${LLVM_NAME}${EXTRACT_SUFX}

WRKSRC=		${WRKDIR}/${LLVM_NAME}
BUILD_WRKSRC=	${WRKSRC}/tools/clang
INSTALL_WRKSRC=	${WRKSRC}/tools/clang

BUILD_DEPENDS+=	llc${LLVM_SUFFIX}:${PORTSDIR}/devel/llvm${LLVM_SUFFIX}
RUN_DEPENDS+=	llc${LLVM_SUFFIX}:${PORTSDIR}/devel/llvm${LLVM_SUFFIX}

LLVM_SUFFIX=	${PORTVERSION:S/.//g}
LLVM_PREFIX=	${PREFIX}/llvm${LLVM_SUFFIX}
DATADIR=	${PREFIX}/share/${PORTNAME}${LLVM_SUFFIX}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${LLVM_SUFFIX}

GNU_CONFIGURE=	yes
GNU_CONFIGURE_PREFIX=	${LLVM_PREFIX}
USES=		gmake perl5
USE_LDCONFIG=	yes
USE_PYTHON_BUILD=	yes

MAKE_ARGS=	CLANG_TBLGEN=${WRKSRC}/${RELTYPE}/bin/clang-tblgen \
		LLVMIncDir=${LLVM_PREFIX}/include \
		LLVMToolDir=${LLVM_PREFIX}/bin \
		LLVMLibDir=${LLVM_PREFIX}/lib

SUB_FILES=	llvm-wrapper.sh
SUB_LIST=	LLVM_PREFIX="${LLVM_PREFIX}" LLVM_SUFFIX="${LLVM_SUFFIX}"

OPTIONS_DEFINE=	ASSERTS DOCS

ASSERTS_DESC=	Enable assertions (thread unsafe)

CONFIGURE_ARGS+=	--enable-optimized --enable-shared
# Build some docs manually later
CONFIGURE_ARGS+=	--disable-docs

PLIST_SUB+=		PORTVERSION=${PORTVERSION}

COMMANDS=	c-index-test \
		clang \
		clang++ \
		clang-check \
		clang-cpp \
		clang-format \
		clang-tblgen
FIRST_COMMAND=	${COMMANDS:C/^/XXXX/1:MXXXX*:C/^XXXX//}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MASSERTS}
CONFIGURE_ARGS+=	--enable-assertions
RELTYPE=		Release+Asserts
.else
CONFIGURE_ARGS+=	--disable-assertions
RELTYPE=		Release
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.if ${PORT_OPTIONS:MASSERTS}
pre-fetch:
	@if [ "`llvm-config${LLVM_SUFFIX} --build-mode`" != ${RELTYPE} ]; then \
		${ECHO_MSG}	;\
		${ECHO_MSG} ASSERTS option enabled, but devel/llvm${LLVM_SUFFIX} was compiled without ASSERTS. ;\
		${ECHO_MSG} Correct options mismatch to proceed. ;\
		${ECHO_MSG}	;\
		false	;\
	fi
.endif

post-extract:
	${RM} -f ${BUILD_WRKSRC}
	${MV} ${WRKDIR}/${CLANG_NAME} ${BUILD_WRKSRC}

post-patch:
	${REINPLACE_CMD} -e 's|${PORTVERSION}svn|${PORTVERSION}|g' \
	    ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|\(PROJ_docsdir.*:=\).*$$|\1${DOCSDIR}|g' \
	    ${WRKSRC}/Makefile.config.in
	${REINPLACE_CMD} -e 's|\(PROJ_mandir.*:=\).*$$|\1${MANPREFIX}/man|g' \
	    ${WRKSRC}/Makefile.config.in
	${REINPLACE_CMD} -e 's|/usr/local/|${LOCALBASE}/|g' \
	    ${WRKSRC}/tools/clang/lib/Frontend/InitHeaderSearch.cpp

pre-build:
	${LN} -sf ${LLVM_PREFIX}/include/llvm/IR/Intrinsics.gen \
	    ${WRKSRC}/include/llvm/IR/
	${MKDIR} ${WRKSRC}/${RELTYPE}/lib
	${LN} -sf ${LLVM_PREFIX}/lib/libLLVM-${PORTVERSION}.so \
	    ${WRKSRC}/${RELTYPE}/lib/
	${LN} -sf ${LLVM_PREFIX}/lib/libLLVMTableGen.a ${WRKSRC}/${RELTYPE}/lib/
	${LN} -sf ${LLVM_PREFIX}/lib/libLLVMSupport.a ${WRKSRC}/${RELTYPE}/lib/
	cd ${WRKSRC}/utils/unittest && ${GMAKE}

post-build:
	@cd ${WRKSRC}/tools/clang/docs/tools && ${GMAKE} man
.if ${PORT_OPTIONS:MDOCS}
	@cd ${WRKSRC}/tools/clang/docs/tools && ${GMAKE} html ps
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${LLVM_PREFIX}/lib/libclang.so
	${LN} -f ${STAGEDIR}${LLVM_PREFIX}/bin/clang \
	    ${STAGEDIR}${LLVM_PREFIX}/bin/clang-cpp
	${INSTALL_SCRIPT} ${WRKDIR}/llvm-wrapper.sh \
	    ${STAGEDIR}${PREFIX}/bin/${FIRST_COMMAND}${LLVM_SUFFIX}
.for command in ${COMMANDS:C/^/XXXX/1:NXXXX*}
	test -e ${STAGEDIR}${LLVM_PREFIX}/bin/${command}
	${LN} -f ${STAGEDIR}${PREFIX}/bin/${FIRST_COMMAND}${LLVM_SUFFIX} \
	    ${STAGEDIR}${PREFIX}/bin/${command}${LLVM_SUFFIX}
.endfor
.if ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC}/tools/clang/docs/tools && \
	    ${GMAKE} DESTDIR=${STAGEDIR}/ install-html install-ps
.endif
	${INSTALL_MAN} ${WRKSRC}/tools/clang/docs/tools/clang.1 \
	    ${STAGEDIR}${MANPREFIX}/man/man1/clang${LLVM_SUFFIX}.1

PLIST_FILE_LIST=	${COMMANDS:S|^|bin/|} \
			lib/libclang*
PLIST_DIR_LIST=		include/clang \
			include/clang-c \
			lib/clang

build-plist:
	${RM} -f ${PLIST}
.for command in ${COMMANDS}
	${ECHO_CMD} bin/${command}${LLVM_SUFFIX} >> ${PLIST}
.endfor
	(ls ${PLIST_FILE_LIST:S|^|${STAGEDIR}${LLVM_PREFIX}/|}; \
	    ${FIND} ${PLIST_DIR_LIST:S|^|${STAGEDIR}${LLVM_PREFIX}/|} -type f) \
	    | ${SED} -e 's|${STAGEDIR}${PREFIX}/||' | ${SORT} >> ${PLIST}
	echo man/man1/clang${LLVM_SUFFIX}.1.gz >> ${PLIST}
	${FIND} ${STAGEDIR}${DOCSDIR} -type f | \
	    ${SED} -e 's|${STAGEDIR}${DOCSDIR}|%%PORTDOCS%%%%DOCSDIR%%|' | \
	    ${SORT} >> ${PLIST}
	${FIND} ${PLIST_DIR_LIST:S|^|${STAGEDIR}${LLVM_PREFIX}/|} -type d | \
	    ${SED} -e 's|${STAGEDIR}${PREFIX}/|@dirrm |' | \
	    ${SORT} -r >> ${PLIST}
	${FIND} ${STAGEDIR}${DOCSDIR} -type d | ${SORT} -r | \
	    ${SED} -e 's|${STAGEDIR}${DOCSDIR}|%%PORTDOCS%%@dirrm %%DOCSDIR%%|' \
	    >> ${PLIST}

.if make(svn-patch)
.if !defined(PATCH_REV)
.error svn-patch requires that PATCH_REV be set
.endif
_PATCH_FILE=${FILESDIR}/patch-svn-${PATCH_REV}
_LLVM_BASE=http://llvm.org/svn/llvm-project/cfe/trunk
svn-patch:
	${PRINTF} "$$%s$$\n" FreeBSD > ${_PATCH_FILE}
	svn log -c ${PATCH_REV} ${_LLVM_BASE} >> ${_PATCH_FILE}
	svn diff -c ${PATCH_REV} ${_LLVM_BASE} | \
	   ${SED} -e 's;^--- ;--- tools/clang/;' | \
	   ${SED} -e 's;^+++ ;+++ tools/clang/;' >> \
	   ${_PATCH_FILE}
.endif

.include <bsd.port.post.mk>
