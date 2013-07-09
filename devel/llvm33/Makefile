# $FreeBSD$

PORTNAME=	llvm
PORTVERSION=	3.3
PORTREVISION=	1
CATEGORIES=	devel lang
MASTER_SITES=	http://llvm.org/releases/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Low Level Virtual Machine

LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo

LLVM_SUFFIX=	${PORTVERSION:S/.//g}
LLVM_PREFIX=	${PREFIX}/llvm${LLVM_SUFFIX}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${LLVM_SUFFIX}
LATEST_LINK=	${PORTNAME}${LLVM_SUFFIX}

GNU_CONFIGURE=	yes
GNU_CONFIGURE_PREFIX=	${LLVM_PREFIX}
USE_GMAKE=	yes
USE_LDCONFIG=	${LLVM_PREFIX}/lib
USE_PERL5=	yes
USE_PYTHON_BUILD=	yes
MAKE_JOBS_SAFE=	yes

SUB_FILES=	llvm-wrapper.sh
SUB_LIST=	LLVM_PREFIX="${LLVM_PREFIX}" LLVM_SUFFIX="${LLVM_SUFFIX}"

# Suggested tweaks from http://llvm.org/docs/Packaging.html
CONFIGURE_ARGS+=	--enable-shared
MAKE_ARGS+=		REQUIRES_RTTI=1
LIBNAME=		libLLVM-${DISTVERSION:C/\rc[0-9]//}.so

CONFIGURE_ARGS+=	--enable-bindings=none
CONFIGURE_ARGS+=	--enable-optimized

OPTIONS_DEFINE=	ASSERTS DOCS LTOPLUGIN MANPAGES

ASSERTS_DESC=	Enable assertions (thread unsafe)
LTOPLUGIN_DESC=	Build LTO plugin (requires gold)

OPTIONS_DEFAULT=	MANPAGES

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
		llvm-symbolizer \
		llvm-tblgen \
		macho-dump \
		opt
FIRST_COMMAND=	${COMMANDS:C/^/XXXX/1:MXXXX*:C/^XXXX//}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MASSERTS}
CONFIGURE_ARGS+=	--enable-assertions
.else
CONFIGURE_ARGS+=	--disable-assertions
.endif

.if ${PORT_OPTIONS:MDOCS} || ${PORT_OPTIONS:MMANPAGES}
BUILD_DEPENDS+=	sphinx-build:${PORTSDIR}/textproc/py-sphinx
.endif

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=	--enable-docs
.else
CONFIGURE_ARGS+=	--disable-docs
.endif

.if ${PORT_OPTIONS:MLTOPLUGIN}
BUILD_DEPENDS+=		ld.gold:${PORTSDIR}/devel/binutils
RUN_DEPENDS+=		ld.gold:${PORTSDIR}/devel/binutils
CONFIGURE_ARGS+=	--with-binutils-include=${LOCALBASE}/include
PLIST_FILES+=		llvm${LLVM_SUFFIX}/lib/LLVMgold.so
.endif

.if ${PORT_OPTIONS:MMANPAGES}
MAN1SRCS=	bugpoint.1 lit.1 llc.1 lli.1 llvm-ar.1 llvm-as.1 \
		llvm-bcanalyzer.1 llvm-config.1 llvm-cov.1 llvm-diff.1 \
		llvm-dis.1 llvm-extract.1 llvm-link.1 llvm-nm.1 \
		llvm-prof.1 llvm-ranlib.1 llvm-stress.1 opt.1 tblgen.1
MAN1=	${MAN1SRCS:S/.1/${LLVM_SUFFIX}.1/}
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

post-build:
.if ${PORT_OPTIONS:MMANPAGES}
	@cd ${WRKSRC}/docs && ${GMAKE} -f Makefile.sphinx man
.endif
.if ${PORT_OPTIONS:MDOCS}
	@cd ${WRKSRC}/docs && ${GMAKE} -f Makefile.sphinx html
.endif

post-install:
	${MV} ${PREFIX}/llvm33/lib/${LIBNAME} ${LLVM_PREFIX}/lib/${LIBNAME}.0
	${LN} -sf ${LIBNAME}.0 ${LLVM_PREFIX}/lib/${LIBNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/llvm-wrapper.sh \
	    ${PREFIX}/bin/${FIRST_COMMAND}${LLVM_SUFFIX}
.for command in ${COMMANDS:C/^/XXXX/1:NXXXX*}
	${LN} -f ${PREFIX}/bin/${FIRST_COMMAND}${LLVM_SUFFIX} \
	    ${PREFIX}/bin/${command}${LLVM_SUFFIX}
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/html
	${FIND} ${WRKSRC}/docs/_build/html -type f | \
	    ${XARGS} -I _DOC_ ${INSTALL_DATA} _DOC_ ${DOCSDIR}/html/
.endif
.if ${PORT_OPTIONS:MMANPAGES}
	for man in ${MAN1SRCS}; do \
		${INSTALL_MAN} ${WRKSRC}/docs/_build/man/$${man} \
		     ${MANPREFIX}/man/man1/$${man%.1}${LLVM_SUFFIX}.1 ; \
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
	${FIND} ${LLVM_PREFIX} -type f -o -type l | \
	    ${GREP} -v man/man1 | ${SED} -e 's|${PREFIX}/||' \
	    -e 's|${PORTVERSION}|%%PORTVERSION%%|' | \
	    ${SORT} >> ${PLIST}
	${FIND} ${DOCSDIR} -type f | \
	    ${SED} -e 's|${DOCSDIR}|%%PORTDOCS%%%%DOCSDIR%%|' | \
	    ${SORT} >> ${PLIST}
	${FIND} ${LLVM_PREFIX} -type d | \
	    ${SED} -e 's|${PREFIX}/||' | \
	    ${SORT} -r | ${SED} -e 's|^|@dirrm |' >> ${PLIST}
	${FIND} ${DOCSDIR} -type d | \
	    ${SED} -e 's|${DOCSDIR}|%%PORTDOCS%%@dirrm %%DOCSDIR%%|' | \
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
