# $FreeBSD$

PORTNAME=	clang
DISTVERSION=	3.3
PORTREVISION=	9
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

BUILD_DEPENDS+=	llc${LLVM_SUFFIX}:devel/llvm${LLVM_SUFFIX}
RUN_DEPENDS+=	llc${LLVM_SUFFIX}:devel/llvm${LLVM_SUFFIX}

LLVM_SUFFIX=	${PORTVERSION:S/.//g}
LLVM_PREFIX=	${PREFIX}/llvm${LLVM_SUFFIX}
DATADIR=	${PREFIX}/share/${PORTNAME}${LLVM_SUFFIX}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${LLVM_SUFFIX}
PYTHONLIBDIR=	${LLVM_PREFIX}/lib/python

GNU_CONFIGURE=	yes
GNU_CONFIGURE_PREFIX=	${LLVM_PREFIX}
USES=		gmake perl5 python
USE_LDCONFIG=	yes

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

PLIST_SUB+=		LLVM_SUFFIX=${LLVM_SUFFIX} \
			PORTVERSION=${PORTVERSION}

COMMANDS=	c++-analyzer \
		c-index-test \
		ccc-analyzer \
		clang \
		clang++ \
		clang-check \
		clang-cpp \
		clang-format \
		clang-tblgen \
		scan-build \
		scan-view
FIRST_COMMAND=	${COMMANDS:C/^/XXXX/1:MXXXX*:C/^XXXX//}

PORTDATA=	scanview.css \
		sorttable.js

.include <bsd.port.options.mk>

# keep in sync with /usr/src/lib/clang/clang.build.mk
CONFIGURE_TARGET:=${ARCH:C/amd64/x86_64/:C/armv6hf/armv6/}-portbld-${OPSYS:tl}${OSREL}

.if ${PORT_OPTIONS:MASSERTS}
CONFIGURE_ARGS+=	--enable-assertions
RELTYPE=		Release+Asserts
.else
CONFIGURE_ARGS+=	--disable-assertions
RELTYPE=		Release
.endif

.include <bsd.port.pre.mk>

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
	${RM} ${BUILD_WRKSRC}
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
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}/|g' \
	    -e 's|%%LLVM_SUFFIX%%|${LLVM_SUFFIX}|g' \
	    ${WRKSRC}/tools/clang/tools/scan-build/scan-build

pre-build:
	${LN} -sf ${LLVM_PREFIX}/include/llvm/IR/Intrinsics.gen \
	    ${WRKSRC}/include/llvm/IR/
	${MKDIR} ${WRKSRC}/${RELTYPE}/lib
	${LN} -sf ${LLVM_PREFIX}/lib/libLLVM-${PORTVERSION}.so \
	    ${WRKSRC}/${RELTYPE}/lib/
	${LN} -sf ${LLVM_PREFIX}/lib/libLLVMTableGen.a ${WRKSRC}/${RELTYPE}/lib/
	${LN} -sf ${LLVM_PREFIX}/lib/libLLVMSupport.a ${WRKSRC}/${RELTYPE}/lib/
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC}/utils/unittest

post-build:
	${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} -C ${WRKSRC}/tools/clang/docs/tools man
	${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} -C ${WRKSRC}/tools/clang/docs/tools html ps

post-install:
	${STRIP_CMD} ${STAGEDIR}${LLVM_PREFIX}/lib/libclang.so
	${LN} -f ${STAGEDIR}${LLVM_PREFIX}/bin/clang \
	    ${STAGEDIR}${LLVM_PREFIX}/bin/clang-cpp
	${INSTALL_SCRIPT} ${WRKDIR}/llvm-wrapper.sh \
	    ${STAGEDIR}${PREFIX}/bin/${FIRST_COMMAND}${LLVM_SUFFIX}
	${INSTALL_SCRIPT} ${WRKSRC}/tools/clang/tools/scan-build/ccc-analyzer \
	    ${WRKSRC}/tools/clang/tools/scan-build/c++-analyzer \
	    ${WRKSRC}/tools/clang/tools/scan-build/scan-build \
	    ${WRKSRC}/tools/clang/tools/scan-view/scan-view \
	    ${STAGEDIR}${LLVM_PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/tools/clang/tools/scan-build/scanview.css \
	    ${WRKSRC}/tools/clang/tools/scan-build/sorttable.js \
	    ${STAGEDIR}${DATADIR}
.for command in ${COMMANDS:C/^/XXXX/1:NXXXX*}
	test -e ${STAGEDIR}${LLVM_PREFIX}/bin/${command}
	${LN} -f ${STAGEDIR}${PREFIX}/bin/${FIRST_COMMAND}${LLVM_SUFFIX} \
	    ${STAGEDIR}${PREFIX}/bin/${command}${LLVM_SUFFIX}
.endfor
	cd ${WRKSRC}/tools/clang/docs/tools && \
	    ${MAKE_CMD} DESTDIR=${STAGEDIR}/ install-html install-ps
	${MKDIR} ${STAGEDIR}${PYTHONLIBDIR}
	${MKDIR} ${STAGEDIR}${PYTHONLIBDIR}/Resources
	${INSTALL_SCRIPT} ${WRKSRC}/tools/clang/tools/scan-view/*.py \
	    ${STAGEDIR}${PYTHONLIBDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/tools/clang/tools/scan-view/Resources/* \
	    ${STAGEDIR}${PYTHONLIBDIR}/Resources
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/tools/clang/tools/scan-build/scanview.css \
	    ${WRKSRC}/tools/clang/tools/scan-build/sorttable.js \
	    ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/tools/clang/docs/tools/clang.1 \
	    ${STAGEDIR}${MANPREFIX}/man/man1/clang${LLVM_SUFFIX}.1
	${INSTALL_MAN} ${WRKSRC}/tools/clang/tools/scan-build/scan-build.1 \
	    ${STAGEDIR}${MANPREFIX}/man/man1/scan-build${LLVM_SUFFIX}.1

PLIST_FILE_LIST=	${COMMANDS:S|^|bin/|} \
			lib/libclang*
PLIST_DIR_LIST=		include/clang \
			include/clang-c \
			lib/clang \
			lib/python

build-plist:
	${RM} ${PLIST}
.for command in ${COMMANDS}
	${ECHO_CMD} bin/${command}${LLVM_SUFFIX} >> ${PLIST}
.endfor
	(ls ${PLIST_FILE_LIST:S|^|${STAGEDIR}${LLVM_PREFIX}/|}; \
	    ${FIND} ${PLIST_DIR_LIST:S|^|${STAGEDIR}${LLVM_PREFIX}/|} -type f) \
	    | ${SED} -e 's|${STAGEDIR}${PREFIX}/||' | ${SORT} >> ${PLIST}
	echo man/man1/clang${LLVM_SUFFIX}.1.gz >> ${PLIST}
	echo man/man1/scan-build%%LLVM_SUFFIX%%.1.gz >> ${PLIST}
	${FIND} ${STAGEDIR}${DOCSDIR} -type f | \
	    ${SED} -e 's|${STAGEDIR}${DOCSDIR}|%%PORTDOCS%%%%DOCSDIR%%|' | \
	    ${SORT} >> ${PLIST}

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
