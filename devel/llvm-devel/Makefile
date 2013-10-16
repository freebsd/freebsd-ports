# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	llvm
DISTVERSION=	3.4.r${SVN_REV}
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brooks
PKGNAMESUFFIX=	-devel

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Low Level Virtual Machine

CONFLICTS=	llvm-2* llvm-3.[012]* llvm31-[3]*

USES=		gmake perl5
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_PYTHON=	yes

# Suggested tweaks from http://llvm.org/docs/Packaging.html
CONFIGURE_ARGS+=	--enable-shared
MAKE_ARGS+=		REQUIRES_RTTI=1
LIBNAME=		libLLVM-${DISTVERSION:C/\.r[0-9]*//}svn.so

CONFIGURE_ARGS+=	--enable-bindings=none
CONFIGURE_ARGS+=	--enable-optimized

OPTIONS_DEFINE=	ASSERTS CMAKE DOCS LTOPLUGIN MANPAGES

ASSERTS_DESC=	Enable assertions (thread unsafe)
CMAKE_DESC=	Build cmake support files
LTOPLUGIN_DESC=	Build LTO plugin (requires gold)

OPTIONS_DEFAULT=	CMAKE MANPAGES

LLVM_RELEASE=	${PORTVERSION:C/\.r[0-9]*//}
PLIST_SUB+=	LLVM_RELEASE=${LLVM_RELEASE}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MASSERTS}
CONFIGURE_ARGS+=	--enable-assertions
.else
CONFIGURE_ARGS+=	--disable-assertions
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

.if ${PORT_OPTIONS:MLTOPLUGIN}
BUILD_DEPENDS+=		ld.gold:${PORTSDIR}/devel/binutils
RUN_DEPENDS+=		ld.gold:${PORTSDIR}/devel/binutils
CONFIGURE_ARGS+=	--with-binutils-include=${LOCALBASE}/include
PLIST_FILES+=		lib/LLVMgold.so
.endif

.if ${PORT_OPTIONS:MMANPAGES}
_MAN1=		bugpoint.1 lit.1 llc.1 lli.1 llvm-ar.1 llvm-as.1 \
		llvm-bcanalyzer.1 llvm-config.1 llvm-cov.1 llvm-diff.1 \
		llvm-dis.1 llvm-extract.1 llvm-link.1 llvm-nm.1 \
		llvm-prof.1 llvm-stress.1 opt.1 tblgen.1
PLIST_FILES+=	man/man1/llvm-lit.1.gz ${_MAN1:S|^|man/man1/|:S|$|.gz|}
.endif

.include <bsd.port.pre.mk>

.if !defined(SVN_REV)
.if defined(BOOTSTRAP)
LANG=		"C"
SVN_REV!=	svn info http://llvm.org/svn/llvm-project/ | ${GREP} Revision | cut -d' ' -f2
.else
.include "Makefile.svn_rev"
.endif
.endif

.if ${ARCH} == "sparc64"
BROKEN=		does not compile on sparc64
.endif

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CONFIGURE_ARGS+=	--enable-pic --with-pic
.endif

.if ${ARCH} == "i386"
CONFIGURE_ARGS+=	--with-optimize-option=-O2
.endif

.if defined(BOOTSTRAP) || defined(SVN_FETCH)
FETCH_DEPENDS+=	svn:${PORTSDIR}/devel/subversion

do-fetch:
	${MKDIR} ${WRKDIR}
	svn export -r ${SVN_REV} \
	    http://llvm.org/svn/llvm-project/llvm/trunk ${WRKSRC}
	cd ${WRKDIR}; tar cvfy ${DISTDIR}/${DISTNAME}.tar.bz2 ${DISTNAME}
	echo "SVN_REV=	${SVN_REV}" > ${MASTERDIR}/Makefile.svn_rev
.if ${USER} == brooks || ${USER} == bed22
	scp ${DISTDIR}/${DISTNAME}.tar.bz2 \
	    brooks@freefall.freebsd.org:public_distfiles/
.endif
.endif

post-patch:
	${REINPLACE_CMD} -e 's|\(PROJ_docsdir.*:=\).*$$|\1${DOCSDIR}|g' \
	    ${WRKSRC}/Makefile.config.in
	${REINPLACE_CMD} -e 's|\(PROJ_mandir.*:=\).*$$|\1${MANPREFIX}/man|g' \
	    ${WRKSRC}/Makefile.config.in

.if ${PORT_OPTIONS:MCMAKE}
post-configure:
	${MKDIR} ${WRKDIR}/cmake
	cd ${WRKDIR}/cmake && cmake -G "Unix Makefiles" ${WRKSRC}
	${REINPLACE_CMD} -e 's|${WRKDIR}/cmake|${PREFIX}|' \
	    -e 's|${WRKSRC}|${DATADIR}|' \
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
	${MV} ${STAGEDIR}${PREFIX}/lib/${LIBNAME} ${STAGEDIR}${PREFIX}/lib/${LIBNAME}.0
	${LN} -sf ${LIBNAME}.0 ${STAGEDIR}${PREFIX}/lib/${LIBNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/utils/lit/lit.py ${STAGEDIR}${PREFIX}/bin/lit
	${LN} -sf lit ${STAGEDIR}${PREFIX}/bin/llvm-lit
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/lit
	${INSTALL_DATA} ${WRKSRC}/utils/lit/lit/*.py ${STAGEDIR}${PYTHON_SITELIBDIR}/lit
	${INSTALL_PROGRAM} ${WRKSRC}/Release/bin/FileCheck ${STAGEDIR}${PREFIX}/bin/
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
.if ${PORT_OPTIONS:MMANPAGES}
.for man in ${_MAN1}
	@${INSTALL_MAN} ${WRKSRC}/docs/_build/man/${man} \
	     ${STAGEDIR}${MANPREFIX}/man/man1/
.endfor
	${LN} -sf ${STAGEDIR}${MANPREFIX}/man/man1/lit.1 ${STAGEDIR}${MANPREFIX}/man/man1/llvm-lit.1
.endif

TEST_CMD=	'(cd ${WRKSRC}/test; ${SETENV} ${MAKE_ENV} LD_LIBRARY_PATH=${WRKSRC}/Release/lib ${GMAKE} check-local-lit)'
regression-test: ${BUILD_COOKIE}
	if [ `${ID} -u` = 0 ]; then \
		${CHOWN} -R nobody ${WRKSRC}/test; \
		su -m nobody -c ${TEST_CMD}; \
	else \
		${SH} -c ${TEST_CMD}; \
	fi

PLIST_FILE_LIST=	bin/FileCheck \
			bin/bugpoint \
			bin/lit \
			bin/llc \
			bin/lli \
			bin/lli-child-target \
			bin/llvm-ar \
			bin/llvm-as \
			bin/llvm-bcanalyzer \
			bin/llvm-config \
			bin/llvm-cov \
			bin/llvm-diff \
			bin/llvm-dis \
			bin/llvm-dwarfdump \
			bin/llvm-extract \
			bin/llvm-link \
			bin/llvm-lit \
			bin/llvm-mc \
			bin/llvm-mcmarkup \
			bin/llvm-nm \
			bin/llvm-objdump \
			bin/llvm-ranlib \
			bin/llvm-readobj \
			bin/llvm-rtdyld \
			bin/llvm-size \
			bin/llvm-stress \
			bin/llvm-symbolizer \
			bin/llvm-tblgen \
			bin/macho-dump \
			bin/opt \
			lib/BugpointPasses.so \
			lib/LLVMHello.so \
			lib/libLTO.* \
			lib/libLLVM*
PLIST_DIR_LIST=		include/llvm-c \
			include/llvm \
			${PYTHON_SITELIBDIR:S;${PYTHONBASE}/;;}/lit
build-plist:
	${RM} -f ${PLIST}
	cd ${PREFIX} && \
	    (ls ${PLIST_FILE_LIST}; \
	     ${FIND} ${PLIST_DIR_LIST} -type f -o -type l) | \
	    ${SED} -e 's|${LLVM_RELEASE}|%%LLVM_RELEASE%%|' \
	    -e 's|${PYTHON_SITELIBDIR:S;${PYTHONBASE}/;;}|%%PYTHON_SITELIBDIR%%|' | \
	    ${SORT} >> ${PLIST}
	${FIND} ${DOCSDIR} -type f | \
	    ${SED} -e 's|${DOCSDIR}|%%PORTDOCS%%%%DOCSDIR%%|' | \
	    ${SORT} >> ${PLIST}
	cd ${PREFIX} && \
	    ${FIND} ${PLIST_DIR_LIST} -type d | \
	    ${SED} -e 's|${PYTHON_SITELIBDIR:S;${PYTHONBASE}/;;}|%%PYTHON_SITELIBDIR%%|' | \
	    ${SORT} -r | ${SED} -e 's|^|@dirrm |' >> ${PLIST}
	${FIND} ${DOCSDIR} -type d | ${SORT} -r | \
	    ${SED} -e 's|${DOCSDIR}|%%DOCSDIR%%|' \
	     -e 's|^|%%PORTDOCS%%@dirrm |' >> ${PLIST}

.include <bsd.port.post.mk>
