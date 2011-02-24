# New ports collection makefile for:	clang
# Date created:		24 Oct 2009
# Whom:			Brooks Davis
#
# $FreeBSD$
#

PORTNAME=	clang
PORTVERSION=	2.9.r${SVN_REV}
CATEGORIES=	lang devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brooks
PKGNAMESUFFIX=	-devel
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${LLVM_SOURCE}
EXTRACT_ONLY=	${LLVM_SOURCE}

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	C, Objective-C, and (alpha-quality) C++ compiler

CONFLICTS=	clang-2.[0-9]* llvm-2.[0-9]*

CLANG_NAME=	clang-${PORTVERSION}
CLANG_SOURCE=	${CLANG_NAME}${EXTRACT_SUFX}
LLVM_NAME=	llvm-${PORTVERSION}
LLVM_SOURCE=	${LLVM_NAME}${EXTRACT_SUFX}

WRKSRC=		${WRKDIR}/${LLVM_NAME}
BUILD_WRKSRC=	${WRKSRC}/tools/clang
INSTALL_WRKSRC=	${WRKSRC}/tools/clang

BUILD_DEPENDS+=	llvm-devel>=${PORTVERSION}:${PORTSDIR}/devel/llvm-devel
RUN_DEPENDS+=	llvm-devel>=${PORTVERSION}:${PORTSDIR}/devel/llvm-devel
.if defined(PACKAGE_BUILDING) || defined(MAINTAINER_MODE)
BUILD_DEPENDS+=	runtest:${PORTSDIR}/misc/dejagnu
.endif
.if defined(MAINTAINER_MODE)
BUILD_DEPENDS+=	f2c:${PORTSDIR}/lang/f2c
.endif

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GCC=	4.2+
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_PERL5=	yes
USE_PYTHON=	yes
MAKE_JOBS_SAFE=	yes

MAKE_ARGS=	LLVMIncDir=${LOCALBASE}/include \
		LLVMToolDir=${LOCALBASE}/bin \
		LLVMLibDir=${LOCALBASE}/lib

.if defined(MAINTAINER_MODE)
CONFIGURE_ARGS+=	--with-f2c=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--enable-optimized
.endif

.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--disable-docs
.endif

MAN1=		clang.1

.include <bsd.port.pre.mk>

.include "${.CURDIR}/../../devel/llvm-devel/Makefile.svn_rev"

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.if defined(BOOTSTRAP) || defined(SVN_FETCH)
FETCH_DEPENDS+= svn:${PORTSDIR}/devel/subversion

do-fetch:
	${MKDIR} ${WRKDIR}
	svn export -r ${SVN_REV} \
	    http://llvm.org/svn/llvm-project/cfe/trunk ${WRKDIR}/${CLANG_NAME}
	cd ${WRKDIR}; tar cvfy ${DISTDIR}/${DISTNAME}.tar.bz2 ${DISTNAME}
.if ${USER} == brooks
	scp ${DISTDIR}/${DISTNAME}.tar.bz2 \
	    freefall.freebsd.org:public_distfiles/
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
	${LN} -sf ${LOCALBASE}/include/llvm/Intrinsics.gen ${WRKSRC}/include/llvm/
	cd ${WRKSRC}/utils/unittest/googletest && ${GMAKE}

.if defined(NOPORTDOCS)
post-build:
	@cd ${WRKSRC}/tools/clang/docs/tools && ${GMAKE} clang.1
.endif

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/tools/clang/tools/scan-build/ccc-analyzer \
		${WRKSRC}/tools/clang/tools/scan-build/c++-analyzer \
		${WRKSRC}/tools/clang/tools/scan-build/scan-build \
		${WRKSRC}/tools/clang/tools/scan-view/scan-view \
	    ${PREFIX}/bin
	@${MKDIR} ${PYTHONPREFIX_SITELIBDIR}
	@${MKDIR} ${PYTHONPREFIX_SITELIBDIR}/Resources
	@${INSTALL_SCRIPT} ${WRKSRC}/tools/clang/tools/scan-view/*.py \
	    ${PYTHONPREFIX_SITELIBDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/tools/clang/tools/scan-view/Resources/* \
	    ${PYTHONPREFIX_SITELIBDIR}/Resources
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/tools/clang/tools/scan-build/scanview.css ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/tools/clang/tools/scan-build/sorttable.js ${DATADIR}
.if defined(NOPORTDOCS)
	@${INSTALL_MAN} ${WRKSRC}/tools/clang/docs/tools/clang.1 \
	    ${MANPREFIX}/man/man1/
.else
	@${RMDIR} ${DOCSDIR}/html/img
.endif

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
			bin/scan-build \
			bin/scan-view \
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
	cd ${PREFIX} && \
	    (ls ${PLIST_FILE_LIST}; ${FIND} ${PLIST_DIR_LIST} -type f) | \
	    ${SORT} >> ${PLIST}
	${FIND} ${DATADIR} ${DOCSDIR} -type f | \
	    ${SED} -e 's|${DATADIR}|%%DATADIR%%|' \
	     -e 's|${DOCSDIR}|%%PORTDOCS%%%%DOCSDIR%%|' | ${SORT} >> ${PLIST}
	cd ${PYTHONPREFIX_SITELIBDIR} && \
	    ls ${PLIST_PYFILE_LIST} | ${SORT} | \
	    ${SED} -e 's|^|%%PYTHON_SITELIBDIR%%/|' >> ${PLIST}
	cd ${PREFIX} && \
	    ${FIND} ${PLIST_DIR_LIST} -type d | \
	    ${SORT} -r | ${SED} -e 's|^|@dirrm |' >> ${PLIST}
	cd ${PYTHONPREFIX_SITELIBDIR} && \
	    ${FIND} ${PLIST_PYDIR_LIST} -type d | ${SORT} -r | \
	    ${SED} -e 's|^|@dirrm %%PYTHON_SITELIBDIR%%/|' >> ${PLIST}
	${FIND} ${DATADIR} ${DOCSDIR} -type d | ${SORT} -r | \
	    ${SED} -e 's|${DATADIR}|@dirrm %%DATADIR%%|' \
	     -e 's|${DOCSDIR}|%%PORTDOCS%%@dirrm %%DOCSDIR%%|' >> ${PLIST}

.include <bsd.port.post.mk>
