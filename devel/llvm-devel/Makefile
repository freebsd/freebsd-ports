# New ports collection makefile for:	llvm
# Date created:		20 Nov 2005
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	llvm
DISTVERSION=	3.2.r${SVN_REV}
PORTREVISON=	1
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brooks
PKGNAMESUFFIX=	-devel

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Low Level Virtual Machine

.if defined(PACKAGE_BUILDING) || defined(MAINTAINER_MODE)
BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
.endif
.if defined(MAINTAINER_MODE)
BUILD_DEPENDS+=	f2c:${PORTSDIR}/lang/f2c
.endif

BUILD_DEPENDS+=	sphinx-build:${PORTSDIR}/textproc/py-sphinx

CONFLICTS=	llvm-[23]* llvm-etoile-2*

GNU_CONFIGURE=	yes
USE_GCC=	4.2+
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_PERL5=	yes
USE_PYTHON_BUILD=	yes
MAKE_JOBS_SAFE=	yes

# Suggested tweaks from http://llvm.org/docs/Packaging.html
CONFIGURE_ARGS+=	--enable-shared
MAKE_ARGS+=		REQUIRES_RTTI=1
LIBNAME=		libLLVM-${DISTVERSION:C/\.r[0-9]*//}svn.so

CONFIGURE_ARGS+=	--enable-bindings=none

OPTIONS_DEFINE=	ASSERTS DOCS LTOPLUGIN

ASSERTS_DESC=	Enable assertions (thread unsafe)
LTOPLUGIN_DESC=	Build LTO plugin (requires gold)

MAN1=		bugpoint.1 lit.1 llc.1 lli.1 llvm-ar.1 llvm-as.1 \
		llvm-bcanalyzer.1 llvm-cov.1 llvm-config.1 llvm-diff.1 \
		llvm-dis.1 llvm-extract.1 llvm-link.1 llvm-nm.1 \
		llvm-prof.1 llvm-ranlib.1 llvm-stress.1 opt.1 tblgen.1

LLVM_RELEASE=	${PORTVERSION:C/\.r[0-9]*//}
PLIST_SUB+=	LLVM_RELEASE=${LLVM_RELEASE}

.include <bsd.port.options.mk>

.if defined(MAINTAINER_MODE)
CONFIGURE_ARGS+=	--with-f2c=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--enable-optimized
.endif

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=	--enable-docs
.else
CONFIGURE_ARGS+=	--disable-docs
.endif

.if ${PORT_OPTIONS:MASSERTS}
CONFIGURE_ARGS+=	--enable-assertions
.else
CONFIGURE_ARGS+=	--disable-assertions
.endif

.if ${PORT_OPTIONS:MLTOPLUGIN}
BUILD_DEPENDS+=		ld.gold:${PORTSDIR}/devel/binutils
RUN_DEPENDS+=		ld.gold:${PORTSDIR}/devel/binutils
CONFIGURE_ARGS+=	--with-binutils-include=${LOCALBASE}/include
PLIST_FILES+=		lib/LLVMgold.so
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
.if ${USER} == brooks
	scp ${DISTDIR}/${DISTNAME}.tar.bz2 \
	    freefall.freebsd.org:public_distfiles/
.endif
.endif

post-patch:
	${REINPLACE_CMD} -e 's|\(PROJ_docsdir.*:=\).*$$|\1${DOCSDIR}|g' \
	    ${WRKSRC}/Makefile.config.in
	${REINPLACE_CMD} -e 's|\(PROJ_mandir.*:=\).*$$|\1${MANPREFIX}/man|g' \
	    ${WRKSRC}/Makefile.config.in

post-build:
	@cd ${WRKSRC}/docs && ${GMAKE} -f Makefile.sphinx man
.if ${PORT_OPTIONS:MDOCS}
	@cd ${WRKSRC}/docs && ${GMAKE} -f Makefile.sphinx html
.endif

post-install:
	${MV} ${PREFIX}/lib/${LIBNAME} ${PREFIX}/lib/${LIBNAME}.0
	${LN} -s ${LIBNAME}.0 ${PREFIX}/lib/${LIBNAME}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/html
	find ${WRKSRC}/docs/_build/html -type f | \
	    xargs -I _DOC_ ${INSTALL_DATA} _DOC_ ${DOCSDIR}/html/
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
	    ${SED} -e 's|${LLVM_RELEASE}|%%LLVM_RELEASE%%|' | \
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

.include <bsd.port.post.mk>
