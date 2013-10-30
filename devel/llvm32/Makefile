# $FreeBSD$

PORTNAME=	llvm
PORTVERSION=	3.2
PORTREVISION=	2
CATEGORIES=	devel lang
MASTER_SITES=	http://llvm.org/releases/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src
PKGNAMESUFFIX=	${LLVM_SUFFIX}

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	The LLVM Compiler Infrastructure

LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo

LLVM_SUFFIX=	${PORTVERSION:S/.//g}
LLVM_PREFIX=	${PREFIX}/llvm${LLVM_SUFFIX}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${LLVM_SUFFIX}
DATADIR=	${PREFIX}/share/${PORTNAME}${LLVM_SUFFIX}
UNIQUENAME=	${PORTNAME}${LLVM_SUFFIX}

USES=		gmake perl5
GNU_CONFIGURE=	yes
GNU_CONFIGURE_PREFIX=	${LLVM_PREFIX}
USE_LDCONFIG=	${LLVM_PREFIX}/lib

SUB_FILES=	llvm-wrapper.sh
SUB_LIST=	LLVM_PREFIX="${LLVM_PREFIX}" LLVM_SUFFIX="${LLVM_SUFFIX}"

# Suggested tweaks from http://llvm.org/docs/Packaging.html
CONFIGURE_ARGS+=	--enable-shared
MAKE_ARGS+=		REQUIRES_RTTI=1
LIBNAME=		libLLVM-${DISTVERSION:C/\rc[0-9]//}.so

CONFIGURE_ARGS+=	--enable-bindings=none
CONFIGURE_ARGS+=	--enable-optimized

OPTIONS_DEFINE=	ASSERTS CMAKE DOCS LIT LTOPLUGIN MANPAGES

ASSERTS_DESC=	Enable assertions (thread unsafe)
CMAKE_DESC=	Build cmake support files
LIT_DESC=	Install lit and FileCheck test tools (requires python)
LTOPLUGIN_DESC=	Build LTO plugin (requires gold)

OPTIONS_DEFAULT=	CMAKE LIT MANPAGES
OPTIONS_SUB=	yes

PLIST_SUB+=		PORTVERSION=${PORTVERSION}

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
		llvm-prof \
		llvm-ranlib \
		llvm-readobj \
		llvm-rtdyld \
		llvm-size \
		llvm-stress \
		llvm-tblgen \
		macho-dump \
		opt
FIRST_COMMAND=	${COMMANDS:C/^/XXXX/1:MXXXX*:C/^XXXX//}

STRIP_LIBS=	BugpointPasses.so \
		LLVMHello.so \
		libLLVM-${PORTVERSION}.so.0 \
		libLTO.so \
		libprofile_rt.so

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MASSERTS}
CONFIGURE_ARGS+=	--enable-assertions
RELEASE_TYPE=		Release+Asserts
.else
CONFIGURE_ARGS+=	--disable-assertions
RELEASE_TYPE=		Release
.endif

.if ${PORT_OPTIONS:MCMAKE}
BUILD_DEPENDS+=	cmake:${PORTSDIR}/devel/cmake
PORTDATA+=	cmake
.endif

.if ${PORT_OPTIONS:MDOCS} || ${PORT_OPTIONS:MMANPAGES}
BUILD_DEPENDS+=	sphinx-build:${PORTSDIR}/textproc/py-sphinx
.endif

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=	--enable-docs
.else
CONFIGURE_ARGS+=	--disable-docs
.endif

.if ${PORT_OPTIONS:MLIT}
MAN1SRCS+=		lit.1
USE_PYTHON=		yes
LIT_COMMANDS=		lit llvm-lit FileCheck
.else
USE_PYTHON_BUILD=	yes
.endif

.if ${PORT_OPTIONS:MLTOPLUGIN}
BUILD_DEPENDS+=		ld.gold:${PORTSDIR}/devel/binutils
RUN_DEPENDS+=		ld.gold:${PORTSDIR}/devel/binutils
CONFIGURE_ARGS+=	--with-binutils-include=${LOCALBASE}/include
PLIST_FILES+=		llvm${LLVM_SUFFIX}/lib/LLVMgold.so
.endif

.if ${PORT_OPTIONS:MMANPAGES}
MAN1SRCS+=	bugpoint.1 llc.1 lli.1 llvm-ar.1 llvm-as.1 \
		llvm-bcanalyzer.1 llvm-config.1 llvm-cov.1 llvm-diff.1 \
		llvm-dis.1 llvm-extract.1 llvm-link.1 llvm-nm.1 \
		llvm-prof.1 llvm-ranlib.1 llvm-stress.1 opt.1 tblgen.1
PLIST_FILES+=	${MAN1SRCS:S|^|man/man1/|:S|.1$|${LLVM_SUFFIX}.1.gz|}
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "arm"
BROKEN=		Does not compile on arm
.elif ${ARCH} == "sparc64"
BROKEN=		does not compile on sparc64
.endif

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CONFIGURE_ARGS+=	--enable-pic --with-pic
.endif

.if ${ARCH} == "i386"
CONFIGURE_ARGS+=	--with-optimize-option=-O2
.endif

post-patch:
	${REINPLACE_CMD} -e 's|${PORTVERSION}svn|${PORTVERSION}|g' \
	    ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|\(PROJ_docsdir.*:=\).*$$|\1${DOCSDIR}|g' \
	    ${WRKSRC}/Makefile.config.in
	${REINPLACE_CMD} -e 's|\(PROJ_mandir.*:=\).*$$|\1${MANPREFIX}/man|g' \
	    ${WRKSRC}/Makefile.config.in
	${REINPLACE_CMD} -e 's|import lit|import lit${LLVM_SUFFIX}|' \
	    -e 's|from lit|from lit${LLVM_SUFFIX}|' \
	    -e 's|lit\.|lit${LLVM_SUFFIX}.|' \
	    ${WRKSRC}/utils/lit/lit.py ${WRKSRC}/utils/lit/lit/*.py

.if ${PORT_OPTIONS:MCMAKE}
post-configure:
	${MKDIR} ${WRKDIR}/cmake
	cd ${WRKDIR}/cmake && cmake -G "Unix Makefiles" ${WRKSRC}
	${REINPLACE_CMD} -e 's|${WRKDIR}/cmake|${LLVM_PREFIX}|' \
	    -e 's|${WRKSRC}/cmake/modules|${DATADIR}/cmake|' \
	    ${WRKDIR}/cmake/share/llvm/cmake/LLVMConfig.cmake
.endif

post-build:
.if ${PORT_OPTIONS:MMANPAGES}
	@cd ${WRKSRC}/docs && ${GMAKE} -f Makefile.sphinx man
.endif
.if ${PORT_OPTIONS:MDOCS}
	@cd ${WRKSRC}/docs && ${GMAKE} -f Makefile.sphinx html
.endif

post-install:
	${MV} ${STAGEDIR}${LLVM_PREFIX}/lib/${LIBNAME} \
	    ${STAGEDIR}${LLVM_PREFIX}/lib/${LIBNAME}.0
	${LN} -sf ${LIBNAME}.0 ${STAGEDIR}${LLVM_PREFIX}/lib/${LIBNAME}
	${STRIP_CMD} ${STRIP_LIBS:S|^|${STAGEDIR}${LLVM_PREFIX}/lib/|}
	${INSTALL_SCRIPT} ${WRKDIR}/llvm-wrapper.sh \
	    ${STAGEDIR}${PREFIX}/bin/${FIRST_COMMAND}${LLVM_SUFFIX}
.for command in ${COMMANDS:C/^/XXXX/1:NXXXX*}
	test -e ${STAGEDIR}${LLVM_PREFIX}/bin/${command}
	${LN} -f ${STAGEDIR}${PREFIX}/bin/${FIRST_COMMAND}${LLVM_SUFFIX} \
	    ${STAGEDIR}${PREFIX}/bin/${command}${LLVM_SUFFIX}
.endfor
.if ${PORT_OPTIONS:MCMAKE}
	${MKDIR} ${STAGEDIR}${DATADIR}/cmake
	${INSTALL_DATA} ${WRKSRC}/cmake/modules/*.cmake \
	    ${WRKDIR}/cmake/share/llvm/cmake/*.cmake \
	    ${STAGEDIR}${DATADIR}/cmake/
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${FIND} ${WRKSRC}/docs/_build/html -type f | \
	    ${XARGS} -I _DOC_ ${INSTALL_DATA} _DOC_ ${STAGEDIR}${DOCSDIR}/html/
.endif
.if ${PORT_OPTIONS:MLIT}
	${INSTALL_SCRIPT} ${WRKSRC}/utils/lit/lit.py \
	    ${STAGEDIR}${LLVM_PREFIX}/bin/lit
	${LN} -f ${STAGEDIR}${LLVM_PREFIX}/bin/lit \
	    ${STAGEDIR}${LLVM_PREFIX}/bin/llvm-lit
	${LN} -f ${STAGEDIR}${LLVM_PREFIX}/bin/lit \
	    ${STAGEDIR}${PREFIX}/bin/lit${LLVM_SUFFIX}
	${LN} -f ${STAGEDIR}${LLVM_PREFIX}/bin/lit \
	    ${STAGEDIR}${PREFIX}/bin/llvm-lit${LLVM_SUFFIX}
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/lit${LLVM_SUFFIX}
	${INSTALL_DATA} ${WRKSRC}/utils/lit/lit/*.py \
	    ${STAGEDIR}${PYTHON_SITELIBDIR}/lit${LLVM_SUFFIX}
	${INSTALL_PROGRAM} ${WRKSRC}/${RELEASE_TYPE}/bin/FileCheck \
	    ${STAGEDIR}${LLVM_PREFIX}/bin/
	${LN} -f ${STAGEDIR}${LLVM_PREFIX}/bin/FileCheck \
	    ${STAGEDIR}${PREFIX}/bin/FileCheck${LLVM_SUFFIX}
.endif
.if ${PORT_OPTIONS:MMANPAGES}
	for man in ${MAN1SRCS}; do \
		${INSTALL_MAN} ${WRKSRC}/docs/_build/man/$${man} \
		    ${STAGEDIR}${MANPREFIX}/man/man1/$${man%.1}${LLVM_SUFFIX}.1 ; \
	done
.endif

TEST_CMD=	'(cd ${WRKSRC}/test; ${SETENV} ${MAKE_ENV} LD_LIBRARY_PATH=${WRKSRC}/Release/lib ${GMAKE} check-local-lit)'
regression-test: ${BUILD_COOKIE}
	if [ `${ID} -u` = 0 ]; then \
		${CHOWN} -R nobody ${WRKSRC}/test; \
		su -m nobody -c ${TEST_CMD}; \
	else \
		${SH} -c ${TEST_CMD}; \
	fi

build-plist:
	${RM} -f ${PLIST}
.for command in ${COMMANDS}
	${ECHO_CMD} bin/${command}${LLVM_SUFFIX} >> ${PLIST}
.endfor
.for command in ${LIT_COMMANDS}
	${ECHO_CMD} %%LIT%%bin/${command}${LLVM_SUFFIX} >> ${PLIST}
	${ECHO_CMD} %%LIT%%${LLVM_PREFIX:S|${PREFIX}/||}/bin/${command} >> ${PLIST}
.endfor
	${FIND} ${STAGEDIR}${LLVM_PREFIX} -type f -o -type l | \
	    ${GREP} -v 'lit$$' | ${GREP} -v 'FileCheck$$' | \
	    ${GREP} -v man/man1 | ${SED} -e 's|${STAGEDIR}${PREFIX}/||' \
	    -e 's|${PORTVERSION}|%%PORTVERSION%%|' | \
	    ${SORT} >> ${PLIST}
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/lit${LLVM_SUFFIX} -type f | \
	    ${SED} -e 's|${STAGEDIR}${PYTHON_SITELIBDIR}|%%LIT%%%%PYTHON_SITELIBDIR%%|' | \
	    ${SORT} >> ${PLIST}
	${FIND} ${STAGEDIR}${DOCSDIR} -type f | \
	    ${SED} -e 's|${STAGEDIR}${DOCSDIR}|%%PORTDOCS%%%%DOCSDIR%%|' | \
	    ${SORT} >> ${PLIST}
	${FIND} ${STAGEDIR}${LLVM_PREFIX} -type d | \
	    ${SED} -e 's|${STAGEDIR}${PREFIX}/||' | \
	    ${SORT} -r | ${SED} -e 's|^|@dirrm |' >> ${PLIST}
	echo "%%LIT%%@dirrm %%PYTHON_SITELIBDIR%%/lit${LLVM_SUFFIX}" >> ${PLIST}
	${FIND} ${STAGEDIR}${DOCSDIR} -type d | \
	    ${SED} -e 's|${STAGEDIR}${DOCSDIR}|%%PORTDOCS%%@dirrm %%DOCSDIR%%|' | \
	    ${SORT} -r >> ${PLIST}

.if make(svn-patch)
.if !defined(PATCH_REV)
.error svn-patch requires that PATCH_REV be set
.endif
_PATCH_FILE=${FILESDIR}/patch-svn-${PATCH_REV}
_LLVM_BASE=http://llvm.org/svn/llvm-project/llvm/trunk
svn-patch:
	${PRINTF} "$$%s$$\n" FreeBSD > ${_PATCH_FILE}
	svn log -c ${PATCH_REV} ${_LLVM_BASE} >> ${_PATCH_FILE}
	svn diff -c ${PATCH_REV} ${_LLVM_BASE} >> ${_PATCH_FILE}
.endif

.include <bsd.port.post.mk>
