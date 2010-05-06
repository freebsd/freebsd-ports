# New ports collection makefile for:	llvm
# Date created:		20 Nov 2005
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	llvm
DISTVERSION=	2.8.r${SVN_REV}
PORTREVISION=	1
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

CONFLICTS=	clang-2.[0-9]* llvm-2.[0-9]*

GNU_CONFIGURE=	yes
USE_GCC=	4.2+
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_PERL5=	yes
USE_PYTHON_RUN=	yes
MAKE_JOBS_SAFE=	yes

# Suggested tweaks from http://llvm.org/docs/Packaging.html
# Commented out ones are currently broken.
MAKE_ARGS+=		REQUIRES_RTTI=1
#CONFIGURE_ARGS+=	--enable-shared

.if defined(MAINTAINER_MODE)
CONFIGURE_ARGS+=	--with-f2c=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--disable-assertions \
			--enable-optimized
.endif

CONFIGURE_ARGS+=	--enable-bindings=none

OPTIONS=	NO_ASSERTS "Disable assertions" off

MAN1=		bugpoint.1 clang.1 lit.1 llc.1 lli.1 llvmc.1 llvm-ar.1 \
		llvm-as.1 llvm-bcanalyzer.1 llvm-config.1 \
		llvm-dis.1 llvm-extract.1 llvm-ld.1 llvm-link.1 llvm-nm.1 \
		llvm-prof.1 llvm-ranlib.1 llvmgcc.1 \
		llvmgxx.1 opt.1 tblgen.1

.include <bsd.port.pre.mk>

.if defined(BOOTSTRAP)
LANG=		"C"
SVN_REV!=	svn info http://llvm.org/svn/llvm-project/ | ${GREP} Revision | cut -d' ' -f2
.else
.include "Makefile.svn_rev"
.endif

.if ${OSVERSION} < 700000 && ${ARCH} == "amd64"
BROKEN=		does not compile
.elif ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CONFIGURE_ARGS+=	--enable-pic --with-pic
.endif

.if ${ARCH} == "i386"
CONFIGURE_ARGS+=	--with-optimize-option=-O2
.endif

.ifdef(WITH_NO_ASSERTS)
CONFIGURE_ARGS+=	--disable-assertions
.else
CONFIGURE_ARGS+=	--enable-assertions
.endif

.if defined(BOOTSTRAP)
FETCH_DEPENDS+=	svn:${PORTSDIR}/devel/subversion

do-fetch:
	${MKDIR} ${WRKDIR}
	svn export -r ${SVN_REV} \
	    http://llvm.org/svn/llvm-project/llvm/trunk ${WRKSRC}
	svn export -r ${SVN_REV} \
	    http://llvm.org/svn/llvm-project/cfe/trunk ${WRKSRC}/tools/clang
	cd ${WRKDIR}; tar cvfy ${DISTDIR}/${DISTNAME}.tar.bz2 ${DISTNAME}
	echo "SVN_REV=	${SVN_REV}" > ${MASTERDIR}/Makefile.svn_rev
.if ${USER} == brooks
	scp ${DISTDIR}/${DISTNAME}.tar.bz2 \
	    freefall.freebsd.org:public_distfiles/
.endif
.endif

post-patch:
	${REINPLACE_CMD} -e 's,\(PROJ_docsdir.*:=\).*$$,\1${DOCSDIR},g' \
		${WRKSRC}/Makefile.config.in
	${REINPLACE_CMD} -e 's,\(PROJ_mandir.*:=\).*$$,\1${MANPREFIX}/man,g' \
		${WRKSRC}/Makefile.config.in
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' \
		${WRKSRC}/tools/clang/tools/scan-build/scan-build
	${REINPLACE_CMD} -e 's|/usr/bin/env perl|${PERL}|' \
	    ${WRKSRC}/tools/clang/tools/scan-build/ccc-analyzer \
	    ${WRKSRC}/tools/clang/tools/scan-build/scan-build

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/tools/clang/tools/scan-build/ccc-analyzer \
	    ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/tools/clang/tools/scan-build/scan-build \
	    ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/tools/clang/tools/scan-build/scanview.css ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/tools/clang/tools/scan-build/sorttable.js ${DATADIR}

TEST_CMD=	'(cd ${WRKSRC}/test; ${SETENV} ${MAKE_ENV} ${GMAKE} check-local-lit)'
regression-test: ${BUILD_COOKIE}
	if [ `${ID} -u` = 0 ]; then \
		${CHOWN} -R nobody ${WRKSRC}/test; \
		su -m nobody -c ${TEST_CMD}; \
	else \
		${SH} -c ${TEST_CMD}; \
	fi

PLIST_FILE_LIST=	bin/bugpoint \
			bin/c-index-test \
			bin/ccc-analyzer \
			bin/clang* \
			bin/llc \
			bin/lli \
			bin/llvm* \
			bin/opt \
			bin/scan-build \
			bin/tblgen \
			lib/libCompilerDriver.a \
			lib/libEnhancedDisassembly.so \
			lib/libEnhancedDisassembly.a \
			lib/libLTO.* \
			lib/libLLVM* \
			lib/libUnitTestMain.a \
			lib/libclang* \
			lib/libplugin_llvmc* \
			lib/libprofile_rt.so
PLIST_DIR_LIST=		include/clang \
			include/clang-c \
			include/llvm-c \
			include/llvm \
			lib/clang
build-plist:
	${RM} -f ${PLIST}
	cd ${PREFIX} && \
	    (ls ${PLIST_FILE_LIST}; ${FIND} ${PLIST_DIR_LIST} -type f) | \
	    ${SORT} >> ${PLIST}
	${FIND} ${DATADIR} ${DOCSDIR} -type f | \
	    ${SED} -e 's|${DATADIR}|%%DATADIR%%|' \
	     -e 's|${DOCSDIR}|%%DOCSDIR%%|' | ${SORT} >> ${PLIST}
	cd ${PREFIX} && \
	    ${FIND} ${PLIST_DIR_LIST} -type d | \
	    ${SORT} -r | ${SED} -e 's|^|@dirrm |' >> ${PLIST}
	${FIND} ${DATADIR} ${DOCSDIR} -type d | ${SORT} -r | \
	    ${SED} -e 's|${DATADIR}|%%DATADIR%%|' \
	     -e 's|${DOCSDIR}|%%DOCSDIR%%|' \
	     -e 's|^|@dirrm |' >> ${PLIST}

.include <bsd.port.post.mk>
