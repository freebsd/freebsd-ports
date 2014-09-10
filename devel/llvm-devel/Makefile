# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	llvm
DISTVERSION=	3.6.r${SVN_REV}
PORTREVISION=	1
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brooks
PKGNAMESUFFIX=	-devel

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Low Level Virtual Machine

LLVM_SUFFIX=	-devel
LLVM_PREFIX=	${PREFIX}/llvm${LLVM_SUFFIX}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${LLVM_SUFFIX}
DATADIR=	${PREFIX}/share/${PORTNAME}${LLVM_SUFFIX}
UNIQUENAME=	${PORTNAME}${LLVM_SUFFIX}

USES=		compiler:c++11-lib gmake perl5 tar:bzip2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_PREFIX=	${LLVM_PREFIX}
USE_LDCONFIG=	${LLVM_PREFIX}/lib

SUB_FILES=	llvm-wrapper.sh
SUB_LIST=	LLVM_PREFIX="${LLVM_PREFIX}" LLVM_SUFFIX="${LLVM_SUFFIX}"

# Suggested tweaks from http://llvm.org/docs/Packaging.html
CONFIGURE_ARGS+=	--enable-shared
MAKE_ARGS+=		REQUIRES_RTTI=1
LIBNAME=		libLLVM-${DISTVERSION:C/\.r[0-9]*//}svn.so

CONFIGURE_ARGS+=	--enable-bindings=none
CONFIGURE_ARGS+=	--enable-optimized

OPTIONS_DEFINE=	ASSERTS CMAKE DOCS LIT LTOPLUGIN MANPAGES

ASSERTS_DESC=	Enable assertions (thread unsafe)
CMAKE_DESC=	Build cmake support files
LIT_DESC=	Install lit and FileCheck test tools (requires python)
LTOPLUGIN_DESC=	Build LTO plugin (requires gold)

OPTIONS_DEFAULT=	CMAKE LIT MANPAGES
OPTIONS_SUB=	yes

ASSERTS_CONFIGURE_ENABLE=	assertions
CMAKE_BUILD_DEPENDS=		cmake:${PORTSDIR}/devel/cmake
DOCS_BUILD_DEPENDS=		sphinx-build:${PORTSDIR}/textproc/py-sphinx
DOCS_CONFIGURE_ENABLE=		docs
LTOPLUGIN_BUILD_DEPENDS=	ld.gold:${PORTSDIR}/devel/binutils
LTOPLUGIN_RUN_DEPENDS=		ld.gold:${PORTSDIR}/devel/binutils
LTOPLUGIN_CONFIGURE_ON=		--with-binutils-include=${LOCALBASE}/include
LTOPLUGIN_PLIST_FILES=		llvm${LLVM_SUFFIX}/lib/LLVMgold.so
MANPAGES_BUILD_DEPENDS=		sphinx-build:${PORTSDIR}/textproc/py-sphinx

LLVM_RELEASE=	${PORTVERSION:C/\.r[0-9]*//}
PLIST_SUB+=	LLVM_RELEASE=${LLVM_RELEASE}

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
		llvm-profdata \
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

STRIP_LIBS=	BugpointPasses.so \
		LLVMHello.so \
		${LIBNAME}.0 \
		libLTO.so

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MASSERTS}
RELEASE_TYPE=		Release+Asserts
.else
RELEASE_TYPE=		Release
.endif

.if ${PORT_OPTIONS:MCMAKE}
PORTDATA+=	cmake
.endif

.if ${PORT_OPTIONS:MLIT}
MAN1SRCS+=		lit.1
USE_PYTHON=		yes
LIT_COMMANDS=		lit llvm-lit FileCheck
.else
USE_PYTHON_BUILD=	yes
.endif

.if ${PORT_OPTIONS:MMANPAGES}
MAN1SRCS+=	bugpoint.1 llc.1 lli.1 llvm-ar.1 llvm-as.1 \
		llvm-bcanalyzer.1 llvm-config.1 llvm-cov.1 llvm-diff.1 \
		llvm-dis.1 llvm-extract.1 llvm-link.1 llvm-nm.1 \
		llvm-profdata.1 llvm-readobj.1 llvm-stress.1 llvm-symbolizer.1 \
		opt.1 tblgen.1
PLIST_FILES+=	${MAN1SRCS:S|^|man/man1/|:S|.1$|${LLVM_SUFFIX}.1.gz|}
.endif

NOT_FOR_ARCH=	ia64

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900000
BROKEN=	GCC failing on 8.x
.endif

.if !defined(SVN_REV)
.if defined(BOOTSTRAP)
LANG=		"C"
SVN_REV!=	svn info http://llvm.org/svn/llvm-project/ | ${GREP} Revision | cut -d' ' -f2
.else
.include "Makefile.svn_rev"
.endif
.endif

.if ${ARCH} == "amd64"
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
	${REINPLACE_CMD} -e 's|import lit|import lit${LLVM_SUFFIX}|' \
	    -e 's|from lit|from lit${LLVM_SUFFIX}|' \
	    -e 's|lit\.|lit${LLVM_SUFFIX}.|' \
	    ${WRKSRC}/utils/lit/lit.py ${WRKSRC}/utils/lit/lit/*.py

.if ${PORT_OPTIONS:MCMAKE}
post-configure:
	${MKDIR} ${WRKDIR}/cmake
	cd ${WRKDIR}/cmake && cmake -G "Unix Makefiles" \
	    -DCMAKE_C_COMPILER:STRING="${CC}" \
	    -DCMAKE_CXX_COMPILER:STRING="${CXX}" \
	    ${WRKSRC}
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
	${REINPLACE_CMD} -e 's|${STAGEDIR}||' \
	    ${STAGEDIR}${DATADIR}/cmake/LLVMConfig.cmake
	${RM} -f ${STAGEDIR}${DATADIR}/cmake/LLVMConfig.cmake.bak
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
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/lit${LLVM_SUFFIX}
	${INSTALL_DATA} ${WRKSRC}/utils/lit/lit/*.py \
	    ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/lit${LLVM_SUFFIX}
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

.include <bsd.port.post.mk>
