# $FreeBSD$

PORTNAME=	llvm
DISTVERSION=	3.6.2
PORTREVISION=	2
CATEGORIES=	devel lang
MASTER_SITES=	http://llvm.org/releases/3.6.2/
DISTNAME=	${PORTNAME}-${DISTVERSION}.src
PKGNAMESUFFIX=	${LLVM_SUFFIX}

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Low Level Virtual Machine

LLVM_SUFFIX=	${PORTVERSION:C/([0-9]\.[0-9]).*/\1/:S/.//g:C/r.//}
LLVM_RELEASE=	${PORTVERSION:C/([0-9]\.[0-9].[0-9]).*/\1/}
LLVM_PREFIX=	${PREFIX}/llvm${LLVM_SUFFIX}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${LLVM_SUFFIX}
DATADIR=	${PREFIX}/share/${PORTNAME}${LLVM_SUFFIX}

WRKSRC=		${WRKDIR}/llvm-${DISTVERSION}.src

USES=		compiler:c++11-lib execinfo gmake perl5 tar:xz libedit
GNU_CONFIGURE=	yes
GNU_CONFIGURE_PREFIX=	${LLVM_PREFIX}
USE_LDCONFIG=	${LLVM_PREFIX}/lib

SUB_FILES=	llvm-wrapper.sh
SUB_LIST=	LLVM_PREFIX="${LLVM_PREFIX}" LLVM_SUFFIX="${LLVM_SUFFIX}"

# Suggested tweaks from http://llvm.org/docs/Packaging.html
CONFIGURE_ARGS+=	--enable-shared
MAKE_ARGS+=		REQUIRES_RTTI=1
LIBNAME=		libLLVM-${LLVM_RELEASE:C/([0-9]\.[0-9]).*/\1/}.so

CONFIGURE_ARGS+=	--enable-bindings=none
CONFIGURE_ARGS+=	--enable-optimized

OPTIONS_DEFINE=	ASSERTS CMAKE DOCS LIT LTOPLUGIN MANPAGES

ASSERTS_DESC=	Enable assertions (thread unsafe)
CMAKE_DESC=	Build cmake support files
LIT_DESC=	Install lit and FileCheck test tools (requires python)
LTOPLUGIN_DESC=	Build LTO plugin (requires gold)

OPTIONS_DEFAULT=	LIT MANPAGES
OPTIONS_SUB=	yes

PLIST_SUB+=		LLVM_SUFFIX=${LLVM_SUFFIX} \
			LLVM_RELEASE=${LLVM_RELEASE}

COMMANDS=	bugpoint \
		count \
		llc \
		lli \
		lli-child-target \
		llvm-ar \
		llvm-as \
		llvm-bcanalyzer \
		llvm-config \
		llvm-cov \
		llvm-diff \
		llvm-dis \
		llvm-dsymutil \
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
		llvm-vtabledump \
		macho-dump \
		not \
		obj2yaml \
		opt \
		verify-uselistorder \
		yaml2obj
FIRST_COMMAND=	${COMMANDS:C/^/XXXX/1:MXXXX*:C/^XXXX//}

STRIP_LIBS=	BugpointPasses.so \
		LLVMHello.so \
		${LIBNAME}.0 \
		libLTO.so

# Enable AMD r600 backend used by the r600/radeonsi graphics/dri gallium drivers
CONFIGURE_ARGS+=--enable-experimental-targets=R600

.include <bsd.port.options.mk>

# keep in sync with /usr/src/lib/clang/clang.build.mk
CONFIGURE_TARGET:=${ARCH:C/amd64/x86_64/:C/armv6hf/armv6/}-portbld-${OPSYS:tl}${OSREL}

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
USES+=			python
LIT_COMMANDS=		lit llvm-lit FileCheck
.else
USES+=			python:build
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
		llvm-profdata.1 llvm-stress.1 opt.1 tblgen.1
PLIST_FILES+=	${MAN1SRCS:S|^|man/man1/|:S|.1$|${LLVM_SUFFIX}.1.gz|}
.endif

NOT_FOR_ARCH=	ia64

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MCMAKE} && ${COMPILER_TYPE} != clang
BROKEN=	CMake support only works with clang
.endif

.if ${ARCH} == "amd64"
CONFIGURE_ARGS+=	--enable-pic --with-pic
.endif

.if ${ARCH} == "i386"
CONFIGURE_ARGS+=	--with-optimize-option=-O2
.endif

post-patch:
	${REINPLACE_CMD} -e 's|${LLVM_RELEASE}svn|${LLVM_RELEASE}|g' \
	    ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|\(PROJ_docsdir.*:=\).*$$|\1${DOCSDIR}|g' \
	    ${WRKSRC}/Makefile.config.in
	${REINPLACE_CMD} -e 's|\(PROJ_mandir.*:=\).*$$|\1${MANPREFIX}/man|g' \
	    ${WRKSRC}/Makefile.config.in
	${REINPLACE_CMD} -e 's|import lit|import lit${LLVM_SUFFIX}|' \
	    -e 's|from lit|from lit${LLVM_SUFFIX}|' \
	    -e 's|lit\.|lit${LLVM_SUFFIX}.|' \
	    ${WRKSRC}/utils/lit/lit.py ${WRKSRC}/utils/lit/lit/*.py \
	    ${WRKSRC}/utils/lit/lit/formats/*.py

.if ${PORT_OPTIONS:MCMAKE}
post-configure:
	${MKDIR} ${WRKDIR}/cmake
	cd ${WRKDIR}/cmake && cmake -G "Unix Makefiles" -DCMAKE_C_COMPILER:STRING="${CC}" -DCMAKE_CXX_COMPILER:STRING="${CXX}" ${WRKSRC}
	${REINPLACE_CMD} -e 's|${WRKDIR}/cmake|${LLVM_PREFIX}|' \
	    -e 's|${WRKSRC}/cmake/modules|${DATADIR}/cmake|' \
	    ${WRKDIR}/cmake/share/llvm/cmake/LLVMConfig.cmake
.endif

post-build:
.if ${PORT_OPTIONS:MMANPAGES}
	@cd ${WRKSRC}/docs && ${MAKE_CMD} -f Makefile.sphinx man
.endif
.if ${PORT_OPTIONS:MDOCS}
	@cd ${WRKSRC}/docs && ${MAKE_CMD} -f Makefile.sphinx html
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
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/lit${LLVM_SUFFIX}/formats
	${INSTALL_DATA} ${WRKSRC}/utils/lit/lit/formats/*.py \
	    ${STAGEDIR}${PYTHON_SITELIBDIR}/lit${LLVM_SUFFIX}/formats
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

TEST_CMD=	'(cd ${WRKSRC}/test; ${SETENV} ${MAKE_ENV} LD_LIBRARY_PATH=${WRKSRC}/Release/lib ${MAKE_CMD} check-local-lit)'
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
	${ECHO_CMD} bin/${command}%%LLVM_SUFFIX%% >> ${PLIST}
.endfor
.for command in ${LIT_COMMANDS}
	${ECHO_CMD} %%LIT%%bin/${command}%%LLVM_SUFFIX%% >> ${PLIST}
	${ECHO_CMD} %%LIT%%${LLVM_PREFIX:S|${PREFIX}/||:C|${LLVM_SUFFIX}|%%LLVM_SUFFIX%%|}/bin/${command} \
	    >> ${PLIST}
.endfor
	${FIND} ${STAGEDIR}${LLVM_PREFIX} -type f -o -type l | \
	    ${GREP} -v 'lit$$' | ${GREP} -v 'FileCheck$$' | \
	    ${GREP} -v man/man1 | ${SED} -e 's|${STAGEDIR}${PREFIX}/||' \
	    -e 's|${LLVM_SUFFIX}|%%LLVM_SUFFIX%%|' \
	    -e 's|${LLVM_RELEASE}|%%LLVM_RELEASE%%|' | \
	    ${SORT} >> ${PLIST}
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/lit${LLVM_SUFFIX} -type f | \
	    ${SED} -e 's|${STAGEDIR}${PYTHON_SITELIBDIR}|%%LIT%%%%PYTHON_SITELIBDIR%%|' \
	    -e 's|${LLVM_SUFFIX}|%%LLVM_SUFFIX%%|' | \
	    ${SORT} >> ${PLIST}
	${FIND} ${STAGEDIR}${DOCSDIR} -type f | \
	    ${SED} -e 's|${STAGEDIR}${DOCSDIR}|%%PORTDOCS%%%%DOCSDIR%%|' | \
	    ${SORT} >> ${PLIST}

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
