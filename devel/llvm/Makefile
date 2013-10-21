# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	llvm
PORTVERSION=	3.2
PORTREVISION=	3
CATEGORIES=	devel lang
MASTER_SITES=	http://llvm.org/releases/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Low Level Virtual Machine

LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo
.if defined(PACKAGE_BUILDING)
BUILD_DEPENDS+=	bash:${PORTSDIR}/shells/bash
.endif
.if defined(MAINTAINER_MODE)
BUILD_DEPENDS+=	f2c:${PORTSDIR}/lang/f2c
.endif

CONFLICTS=	llvm-devel-[23]* llvm31-3*

DEPRECATED=	Migrate to devel/llvm32 or newer
EXPIRATION_DATE=	2013-11-04

GNU_CONFIGURE=	yes
USES=		gmake perl5
USE_LDCONFIG=	yes
USE_PYTHON_BUILD=	yes

# Suggested tweaks from http://llvm.org/docs/Packaging.html
CONFIGURE_ARGS+=	--enable-shared
MAKE_ARGS+=		REQUIRES_RTTI=1
LIBNAME=		libLLVM-${DISTVERSION:C/\.r[0-9]*//}.so

CONFIGURE_ARGS+=	--enable-bindings=none
CONFIGURE_ARGS+=	--enable-optimized

OPTIONS_DEFINE=	ASSERTS DOCS LTOPLUGIN MANPAGES

ASSERTS_DESC=	Enable assertions (thread unsafe)
LTOPLUGIN_DESC=	Build LTO plugin (requires gold)

OPTIONS_DEFAULT=	MANPAGES

PLIST_SUB+=		PORTVERSION=${PORTVERSION}

NO_STAGE=	yes
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
PLIST_FILES+=		lib/LLVMgold.so
.endif

.if ${PORT_OPTIONS:MMANPAGES}
MAN1=		bugpoint.1 lit.1 llc.1 lli.1 llvm-ar.1 llvm-as.1 \
		llvm-bcanalyzer.1 llvm-config.1 llvm-cov.1 llvm-diff.1 \
		llvm-dis.1 llvm-extract.1 llvm-link.1 llvm-nm.1 \
		llvm-prof.1 llvm-ranlib.1 llvm-stress.1 opt.1 tblgen.1
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
	${MV} ${PREFIX}/lib/${LIBNAME} ${PREFIX}/lib/${LIBNAME}.0
	${LN} -s ${LIBNAME}.0 ${PREFIX}/lib/${LIBNAME}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/html
	${FIND} ${WRKSRC}/docs/_build/html -type f | \
	    ${XARGS} -I _DOC_ ${INSTALL_DATA} _DOC_ ${DOCSDIR}/html/
.endif
.for man in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/docs/_build/man/${man} \
	     ${MANPREFIX}/man/man1/
.endfor

TEST_CMD=	'(cd ${WRKSRC}/test; ${SETENV} ${MAKE_ENV} LD_LIBRARY_PATH=${WRKSRC}/Release/lib ${GMAKE} check-local-lit)'
regression-test: ${BUILD_COOKIE}
	if [ `${ID} -u` = 0 ]; then \
		${CHOWN} -R nobody ${WRKSRC}/test; \
		su -m nobody -c ${TEST_CMD}; \
	else \
		${SH} -c ${TEST_CMD}; \
	fi

PLIST_FILE_LIST=	bin/bugpoint \
			bin/llc \
			bin/lli \
			bin/llvm* \
			bin/macho-dump \
			bin/opt \
			lib/BugpointPasses.so \
			lib/LLVMHello.so \
			lib/libLTO.* \
			lib/libLLVM* \
			lib/libprofile_rt.a \
			lib/libprofile_rt.so
PLIST_DIR_LIST=		include/llvm-c \
			include/llvm
build-plist:
	${RM} -f ${PLIST}
	cd ${PREFIX} && \
	    (ls ${PLIST_FILE_LIST}; ${FIND} ${PLIST_DIR_LIST} -type f) | \
	    ${SED} -e 's|${PORTVERSION}|%%PORTVERSION%%|' | \
	    ${SORT} >> ${PLIST}
	${FIND} ${DOCSDIR} -type f | \
	    ${SED} -e 's|${DOCSDIR}|%%PORTDOCS%%%%DOCSDIR%%|' | \
	    ${SORT} >> ${PLIST}
	cd ${PREFIX} && \
	    ${FIND} ${PLIST_DIR_LIST} -type d | \
	    ${SORT} -r | ${SED} -e 's|^|@dirrm |' >> ${PLIST}
	${FIND} ${DOCSDIR} -type d | ${SORT} -r | \
	    ${SED} -e 's|${DOCSDIR}|%%DOCSDIR%%|' \
	     -e 's|^|%%PORTDOCS%%@dirrm |' >> ${PLIST}

.if make(svn-patch)
.if !defined(PATCH_REV)
.error svn-patch requires that PATCH_REV be set
.endif
_PATCH_FILE=${FILESDIR}/patch-svn-${PATCH_REV}
_LLVM_BASE=http://llvm.org/svn/llvm-project/llvm/trunk
svn-patch:
	printf "$$%s$$\n" FreeBSD > ${_PATCH_FILE}
	svn log -c ${PATCH_REV} ${_LLVM_BASE} >> ${_PATCH_FILE}
	svn diff -c ${PATCH_REV} ${_LLVM_BASE} >> ${_PATCH_FILE}
.endif

.include <bsd.port.post.mk>
