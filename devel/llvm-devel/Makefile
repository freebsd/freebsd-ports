# New ports collection makefile for:	llvm
# Date created:		20 Nov 2005
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	llvm
DISTVERSION=	2.6.r${SVN_REV}
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brooks
PKGNAMESUFFIX=	-devel

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Low Level Virtual Machine

.if defined(PACKAGE_BUILDING) || defined(MAINTAINER_MODE)
BUILD_DEPENDS=	runtest:${PORTSDIR}/misc/dejagnu
.endif
.if defined(MAINTAINER_MODE)
BUILD_DEPENDS+=	f2c:${PORTSDIR}/lang/f2c
.endif

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_PERL5=	yes
USE_PYTHON_RUN=	yes
MAKE_JOBS_SAFE=	yes

.if defined(MAINTAINER_MODE)
CONFIGURE_ARGS+=	--with-f2c=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--enable-optimized
.endif

MAN1=		bugpoint.1 clang.1 llc.1 lli.1 llvmc.1 llvm-ar.1 \
		llvm-as.1 llvm-bcanalyzer.1 llvm-config.1 llvm-db.1 \
		llvm-dis.1 llvm-extract.1 llvm-ld.1 llvm-link.1 llvm-nm.1 \
		llvm-prof.1 llvm-ranlib.1 llvmgcc.1 \
		llvmgxx.1 opt.1 tblgen.1

.include <bsd.port.pre.mk>

.if defined(BOOTSTRAP)
SVN_REV!=	svn info http://llvm.org/svn/llvm-project/ | ${GREP} Revision | cut -d' ' -f2
.else
.include "Makefile.svn_rev"
.endif

.if ${OSVERSION} < 700000 && ${ARCH} == "amd64"
BROKEN=		does not compile
.elif ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
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
		${WRKSRC}/tools/clang/utils/scan-build
	${REINPLACE_CMD} -e 's|/usr/bin/env perl|${PERL}|' \
	    ${WRKSRC}/tools/clang/utils/ccc-analyzer \
	    ${WRKSRC}/tools/clang/utils/scan-build

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/tools/clang/utils/ccc-analyzer \
	    ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/tools/clang/utils/scan-build \
	    ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/tools/clang/utils/scanview.css ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/tools/clang/utils/sorttable.js ${DATADIR}

TEST_CMD=	'(cd ${WRKSRC}/test; ${SETENV} ${MAKE_ENV} ${GMAKE} check)'
regression-test: ${BUILD_COOKIE}
	if [ `${ID} -u` = 0 ]; then \
		${CHOWN} -R nobody ${WRKSRC}/test; \
		su -m nobody -c ${TEST_CMD}; \
	else \
		${SH} -c ${TEST_CMD}; \
	fi

PLIST_FILE_LIST=	bin/bugpoint \
			bin/ccc-analyzer \
			bin/clang* \
			bin/gccas \
			bin/gccld \
			bin/llc \
			bin/lli \
			bin/llvm* \
			bin/opt \
			bin/scan-build \
			lib/CompilerDriver.o \
			lib/LLVM* \
			lib/libLTO.so \
			lib/libLLVM* \
			lib/libclang* \
			lib/plugin_llvm* \
			libexec/clang-cc
PLIST_DIR_LIST=		include/llvm-c \
			include/llvm \
			lib/clang
build-plist:
	${RM} ${PLIST}
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
