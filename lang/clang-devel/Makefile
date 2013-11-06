# Created by: Brooks Davis
# $FreeBSD$

PORTNAME=	clang
PORTVERSION=	3.4.r${SVN_REV}
CATEGORIES=	lang devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brooks
PKGNAMESUFFIX=	-devel
DISTFILES=	${CLANG_SOURCE} \
		${LLVM_SOURCE}

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	C, Objective-C, and C++ compiler

CLANG_NAME=	clang-${PORTVERSION}
CLANG_RELEASE=	${PORTVERSION:C/\.r[0-9]*//}svn
CLANG_SOURCE=	${CLANG_NAME}${EXTRACT_SUFX}
LLVM_NAME=	llvm-${PORTVERSION}
LLVM_SOURCE=	${LLVM_NAME}${EXTRACT_SUFX}

WRKSRC=		${WRKDIR}/${LLVM_NAME}
BUILD_WRKSRC=	${WRKSRC}/tools/clang
INSTALL_WRKSRC=	${WRKSRC}/tools/clang

BUILD_DEPENDS+=	llvm-config${LLVM_SUFFIX}:${PORTSDIR}/devel/llvm-devel
RUN_DEPENDS+=	llvm-config${LLVM_SUFFIX}:${PORTSDIR}/devel/llvm-devel

LLVM_SUFFIX=	-devel
LLVM_PREFIX=	${PREFIX}/llvm${LLVM_SUFFIX}
DATADIR=	${PREFIX}/share/${PORTNAME}${LLVM_SUFFIX}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${LLVM_SUFFIX}

GNU_CONFIGURE=	yes
GNU_CONFIGURE_PREFIX=	${LLVM_PREFIX}
USES=		gmake perl5
USE_BZIP2=	yes
USE_PYTHON=	yes

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

PLIST_SUB+=	CLANG_RELEASE=${CLANG_RELEASE}

COMMANDS=	c-index-test \
		clang \
		clang++ \
		clang-check \
		clang-cpp \
		clang-format \
		clang-tblgen \
		ccc-analyzer \
		c++-analyzer \
		scan-build \
		scan-view
FIRST_COMMAND=	${COMMANDS:C/^/XXXX/1:MXXXX*:C/^XXXX//}

PORTDATA=	scanview.css \
		sorttable.js

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MASSERTS}
CONFIGURE_ARGS+=	--enable-assertions
RELTYPE=		Release+Asserts
.else
CONFIGURE_ARGS+=	--disable-assertions
RELTYPE=		Release
.endif

.include <bsd.port.pre.mk>

.include "${.CURDIR}/../../devel/llvm-devel/Makefile.svn_rev"

# NB: I don't test arches I don't use so this may be out of date.
BROKEN_sparc64=	YES

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

.if defined(BOOTSTRAP) || defined(SVN_FETCH)
FETCH_DEPENDS+= svn:${PORTSDIR}/devel/subversion

do-fetch:
	${MKDIR} ${WRKDIR}
	svn export -r ${SVN_REV} \
	    http://llvm.org/svn/llvm-project/cfe/trunk ${WRKDIR}/${CLANG_NAME}
	cd ${WRKDIR}; tar cvfy ${DISTDIR}/${DISTNAME}.tar.bz2 ${DISTNAME}
.if ${USER} == brooks || ${USER} == bed22
	scp ${DISTDIR}/${DISTNAME}.tar.bz2 \
	    brooks@freefall.freebsd.org:public_distfiles/
.endif
.endif

post-extract:
	${RM} -f ${BUILD_WRKSRC}
	${MV} ${WRKDIR}/${CLANG_NAME} ${BUILD_WRKSRC}

post-patch:
	${REINPLACE_CMD} -e 's|\(PROJ_docsdir.*:=\).*$$|\1${DOCSDIR}|g' \
	    ${WRKSRC}/Makefile.config.in
	${REINPLACE_CMD} -e 's|\(PROJ_mandir.*:=\).*$$|\1${MANPREFIX}/man|g' \
	    ${WRKSRC}/Makefile.config.in
	${REINPLACE_CMD} -e 's|/usr/local/|${LOCALBASE}/|g' \
	    ${WRKSRC}/tools/clang/lib/Frontend/InitHeaderSearch.cpp
	${REINPLACE_CMD} -e 's|/usr/bin/env perl|${PERL}|' \
	    -e 's|%%DATADIR%%|${DATADIR}|' \
	    ${WRKSRC}/tools/clang/tools/scan-build/ccc-analyzer \
	    ${WRKSRC}/tools/clang/tools/scan-build/c++-analyzer \
	    ${WRKSRC}/tools/clang/tools/scan-build/scan-build
	${REINPLACE_CMD} -e 's|/usr/bin/env python|${PYTHON_CMD}|' \
	    ${WRKSRC}/tools/clang/tools/scan-view/scan-view

pre-build:
	${LN} -sf ${LLVM_PREFIX}/include/llvm/IR/Intrinsics.gen \
	    ${WRKSRC}/include/llvm/IR/
	${MKDIR} ${WRKSRC}/${RELTYPE}/lib
	${LN} -sf ${LLVM_PREFIX}/lib/libLLVM-${CLANG_RELEASE}.so \
	    ${WRKSRC}/${RELTYPE}/lib/
	${LN} -sf ${LLVM_PREFIX}/lib/libLLVMTableGen.a ${WRKSRC}/${RELTYPE}/lib/
	${LN} -sf ${LLVM_PREFIX}/lib/libLLVMSupport.a ${WRKSRC}/${RELTYPE}/lib/
	cd ${WRKSRC}/utils/unittest && ${GMAKE}

post-build:
	@cd ${WRKSRC}/tools/clang/docs/tools && ${GMAKE} man html ps

post-install:
	${STRIP_CMD} ${STAGEDIR}${LLVM_PREFIX}/lib/libclang.so
	${LN} -f ${STAGEDIR}${LLVM_PREFIX}/bin/clang \
	    ${STAGEDIR}${LLVM_PREFIX}/bin/clang-cpp
	${INSTALL_SCRIPT} ${WRKSRC}/tools/clang/tools/scan-build/ccc-analyzer \
	    ${WRKSRC}/tools/clang/tools/scan-build/c++-analyzer \
	    ${WRKSRC}/tools/clang/tools/scan-build/scan-build \
	    ${WRKSRC}/tools/clang/tools/scan-view/scan-view \
	    ${STAGEDIR}${LLVM_PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/llvm-wrapper.sh \
	    ${STAGEDIR}${PREFIX}/bin/${FIRST_COMMAND}${LLVM_SUFFIX}
.for command in ${COMMANDS:C/^/XXXX/1:NXXXX*}
	test -e ${STAGEDIR}${LLVM_PREFIX}/bin/${command}
	${LN} -f ${STAGEDIR}${PREFIX}/bin/${FIRST_COMMAND}${LLVM_SUFFIX} \
	    ${STAGEDIR}${PREFIX}/bin/${command}${LLVM_SUFFIX}
.endfor
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/Resources
	${INSTALL_SCRIPT} ${WRKSRC}/tools/clang/tools/scan-view/*.py \
	    ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/tools/clang/tools/scan-view/Resources/* \
	    ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/Resources
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/tools/clang/tools/scan-build/scanview.css \
	    ${WRKSRC}/tools/clang/tools/scan-build/sorttable.js \
	    ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/tools/clang/docs/tools && \
	    ${GMAKE} DESTDIR=${STAGEDIR}/ install-html install-ps
	${INSTALL_MAN} ${WRKSRC}/tools/clang/docs/tools/clang.1 \
	    ${STAGEDIR}${MANPREFIX}/man/man1/clang${LLVM_SUFFIX}.1

PLIST_FILE_LIST=	${COMMANDS:S|^|bin/|} \
			lib/libclang*
PLIST_DIR_LIST=		include/clang \
			include/clang-c \
			lib/clang
PLIST_PYFILE_LIST=	ScanView.py \
			Reporter.py \
			Resources/* \
			startfile.py
PLIST_PYDIR_LIST=	Resources

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
	cd ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} && \
	    ls ${PLIST_PYFILE_LIST} | ${SORT} | \
	    ${SED} -e 's|^|%%PYTHON_SITELIBDIR%%/|' >> ${PLIST}
	cd ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} && \
	    ${FIND} ${PLIST_PYDIR_LIST} -type d | ${SORT} -r | \
	    ${SED} -e 's|^|@dirrm %%PYTHON_SITELIBDIR%%/|' >> ${PLIST}

.include <bsd.port.post.mk>
