# Created by: Brooks Davis
# $FreeBSD$

PORTNAME=	clang
PORTVERSION=	3.4.r${SVN_REV}
CATEGORIES=	lang devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brooks
PKGNAMESUFFIX=	-devel
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${LLVM_SOURCE}
EXTRACT_ONLY=	${LLVM_SOURCE}

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	C, Objective-C, and C++ compiler

CONFLICTS=	clang-3.[012]* clang31-*

CLANG_NAME=	clang-${PORTVERSION}
CLANG_RELEASE=	${PORTVERSION:C/\.r[0-9]*//}
CLANG_SOURCE=	${CLANG_NAME}${EXTRACT_SUFX}
LLVM_NAME=	llvm-${PORTVERSION}
LLVM_SOURCE=	${LLVM_NAME}${EXTRACT_SUFX}

WRKSRC=		${WRKDIR}/${LLVM_NAME}
BUILD_WRKSRC=	${WRKSRC}/tools/clang
INSTALL_WRKSRC=	${WRKSRC}/tools/clang

BUILD_DEPENDS+=	llvm-devel>=${PORTVERSION}:${PORTSDIR}/devel/llvm-devel
RUN_DEPENDS+=	llvm-devel>=${PORTVERSION}:${PORTSDIR}/devel/llvm-devel
.if defined(PACKAGE_BUILDING)
BUILD_DEPENDS+=	runtest:${PORTSDIR}/misc/dejagnu
.endif

GNU_CONFIGURE=	yes
USES=		gmake perl5
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_PYTHON=	yes

MAKE_ARGS=	CLANG_TBLGEN=${WRKSRC}/${RELTYPE}/bin/clang-tblgen \
		LLVMIncDir=${LOCALBASE}/include \
		LLVMToolDir=${LOCALBASE}/bin \
		LLVMLibDir=${LOCALBASE}/lib

OPTIONS_DEFINE=	ASSERTS DOCS MIPS_FPHACK

ASSERTS_DESC=	Enable assertions (thread unsafe)
MIPS_FPHACK_DESC=	MIPS long double hack (breaks ABI)

CONFIGURE_ARGS+=	--enable-optimized

PLIST_SUB+=	CLANG_RELEASE=${CLANG_RELEASE}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MASSERTS}
CONFIGURE_ARGS+=	--enable-assertions
RELTYPE=		Release+Asserts
.else
CONFIGURE_ARGS+=	--disable-assertions
RELTYPE=		Release
.endif

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=	--enable-docs
.else
CONFIGURE_ARGS+=	--disable-docs
.endif

.if ${PORT_OPTIONS:MMIPS_FPHACK}
EXTRA_PATCHES=	${FILESDIR}/mips-long-double-hack.diff
.endif

.include <bsd.port.pre.mk>

.include "${.CURDIR}/../../devel/llvm-devel/Makefile.svn_rev"

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.if ${OSVERSION} < 900033
RUN_DEPENDS+=	${LOCALBASE}/bin/ld:${PORTSDIR}/devel/binutils
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
	cd ${WRKSRC}/tools && \
	    tar xf ${DISTDIR}/${CLANG_SOURCE} && \
	    ${MV} ${CLANG_NAME} clang

post-patch:
	${REINPLACE_CMD} -e 's|\(PROJ_docsdir.*:=\).*$$|\1${DOCSDIR}|g' \
	    ${WRKSRC}/Makefile.config.in
	${REINPLACE_CMD} -e 's|\(PROJ_mandir.*:=\).*$$|\1${MANPREFIX}/man|g' \
	    ${WRKSRC}/Makefile.config.in
	${REINPLACE_CMD} -e 's|/usr/bin/env perl|${PERL}|' \
	    -e 's|%%DATADIR%%|${DATADIR}|' \
	    ${WRKSRC}/tools/clang/tools/scan-build/ccc-analyzer \
	    ${WRKSRC}/tools/clang/tools/scan-build/c++-analyzer \
	    ${WRKSRC}/tools/clang/tools/scan-build/scan-build
	${REINPLACE_CMD} -e 's|/usr/bin/env python|${PYTHON_CMD}|' \
	    ${WRKSRC}/tools/clang/tools/scan-view/scan-view

pre-build:
	${LN} -sf ${LOCALBASE}/include/llvm/IR/Intrinsics.gen \
	    ${WRKSRC}/include/llvm/IR/
	${MKDIR} ${WRKSRC}/${RELTYPE}/lib
	${LN} -sf ${LOCALBASE}/lib/libLLVMTableGen.a ${WRKSRC}/${RELTYPE}/lib/
	${LN} -sf ${LOCALBASE}/lib/libLLVMSupport.a ${WRKSRC}/${RELTYPE}/lib/
	cd ${WRKSRC}/utils/unittest && ${GMAKE}

post-build:
	@cd ${WRKSRC}/tools/clang/docs/tools && ${GMAKE} clang.1

post-install:
	@${LN} -sf clang ${STAGEDIR}${PREFIX}/bin/clang-cpp
	@${INSTALL_SCRIPT} ${WRKSRC}/tools/clang/tools/scan-build/ccc-analyzer \
		${WRKSRC}/tools/clang/tools/scan-build/c++-analyzer \
		${WRKSRC}/tools/clang/tools/scan-build/scan-build \
		${WRKSRC}/tools/clang/tools/scan-view/scan-view \
	    ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/Resources
	@${INSTALL_SCRIPT} ${WRKSRC}/tools/clang/tools/scan-view/*.py \
	    ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/tools/clang/tools/scan-view/Resources/* \
	    ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/Resources
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/tools/clang/tools/scan-build/scanview.css \
	    ${WRKSRC}/tools/clang/tools/scan-build/sorttable.js \
	    ${STAGEDIR}${DATADIR}
	@${INSTALL_MAN} ${WRKSRC}/tools/clang/docs/tools/clang.1 \
	    ${STAGEDIR}${MANPREFIX}/man/man1/

TEST_CMD=	'(cd ${WRKSRC}/test; ${SETENV} ${MAKE_ENV} ${GMAKE} check)'
regression-test: ${BUILD_COOKIE}
	if [ `${ID} -u` = 0 ]; then \
		${CHOWN} -R nobody ${WRKSRC}/test; \
		su -m nobody -c ${TEST_CMD}; \
	else \
		${SH} -c ${TEST_CMD}; \
	fi

PLIST_FILE_LIST=	bin/ccc-analyzer \
			bin/c++-analyzer \
			bin/c-index-test \
			bin/clang \
			bin/clang++ \
			bin/clang-check \
			bin/clang-cpp \
			bin/clang-format \
			bin/clang-tblgen \
			bin/scan-build \
			bin/scan-view \
			lib/libclang* \
			man/man1/clang.1.gz
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
	cd ${PREFIX} && \
	    (ls ${PLIST_FILE_LIST}; ${FIND} ${PLIST_DIR_LIST} -type f) | \
	    ${SED} -e 's|${CLANG_RELEASE}|%%CLANG_RELEASE%%|' | \
	    ${SORT} >> ${PLIST}
	${FIND} ${DATADIR} ${DOCSDIR} -type f | \
	    ${SED} -e 's|${DATADIR}|%%DATADIR%%|' \
	     -e 's|${DOCSDIR}|%%PORTDOCS%%%%DOCSDIR%%|' | ${SORT} >> ${PLIST}
	cd ${PYTHONPREFIX_SITELIBDIR} && \
	    ls ${PLIST_PYFILE_LIST} | ${SORT} | \
	    ${SED} -e 's|^|%%PYTHON_SITELIBDIR%%/|' >> ${PLIST}
	cd ${PREFIX} && \
	    ${FIND} ${PLIST_DIR_LIST} -type d | \
	    ${SED} -e 's|${CLANG_RELEASE}|%%CLANG_RELEASE%%|' | \
	    ${SORT} -r | ${SED} -e 's|^|@dirrm |' >> ${PLIST}
	cd ${PYTHONPREFIX_SITELIBDIR} && \
	    ${FIND} ${PLIST_PYDIR_LIST} -type d | ${SORT} -r | \
	    ${SED} -e 's|^|@dirrm %%PYTHON_SITELIBDIR%%/|' >> ${PLIST}
	echo "@dirrmtry %%PYTHON_SITELIBDIR%%" >> ${PLIST}
	echo "@dirrmtry %%PYTHON_LIBDIR%%" >> ${PLIST}
	${FIND} ${DATADIR} ${DOCSDIR} -type d | ${SORT} -r | \
	    ${SED} -e 's|${DATADIR}|@dirrm %%DATADIR%%|' \
	     -e 's|${DOCSDIR}|%%PORTDOCS%%@dirrm %%DOCSDIR%%|' >> ${PLIST}

.include <bsd.port.post.mk>
