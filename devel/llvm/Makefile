# New ports collection makefile for:	llvm
# Date created:		20 Nov 2005
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	llvm
PORTVERSION=	2.8
PORTREVISION=	3
CATEGORIES=	devel lang
MASTER_SITES=	http://llvm.org/releases/${PORTVERSION}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Low Level Virtual Machine

.if defined(PACKAGE_BUILDING) || defined(MAINTAINER_MODE)
USE_PYTHON_BUILD=	yes
BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
.endif
.if defined(MAINTAINER_MODE)
BUILD_DEPENDS+=	f2c:${PORTSDIR}/lang/f2c
.endif

CONFLICTS=	llvm-devel-2.[0-9]*

GNU_CONFIGURE=	yes
USE_GCC=	4.2+
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_PERL5=	yes
MAKE_JOBS_SAFE=	yes

.if defined(MAINTAINER_MODE)
CONFIGURE_ARGS+=	--with-f2c=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--enable-optimized
.endif

CONFIGURE_ARGS+=	--enable-bindings=none

OPTIONS=	ASSERTS	"Enable assertions (thread unsafe)" off

.if defined(NOPORTDOCS)
DOCSRCDIR=
.else
DOCSRCDIR=	docs
.endif

MAN1=		bugpoint.1 lit.1 llc.1 lli.1 llvm-ar.1 \
		llvm-as.1 llvm-bcanalyzer.1 llvm-config.1 llvm-diff.1 \
		llvm-dis.1 llvm-extract.1 llvm-ld.1 llvm-link.1 llvm-nm.1 \
		llvm-prof.1 llvm-ranlib.1 llvmc.1 llvmgcc.1 \
		llvmgxx.1 opt.1 tblgen.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		does not compile on sparc64
.endif

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CONFIGURE_ARGS+=	--enable-pic --with-pic
.endif

.if ${ARCH} == "i386"
CONFIGURE_ARGS+=	--with-optimize-option=-O2
.endif

.ifdef(WITH_ASSERTS)
CONFIGURE_ARGS+=	--enable-assertions
.else
CONFIGURE_ARGS+=	--disable-assertions
.endif

post-patch:
	${REINPLACE_CMD} -e 's|\(PROJ_docsdir.*:=\).*$$|\1${DOCSDIR}|g' \
	    ${WRKSRC}/Makefile.config.in
	${REINPLACE_CMD} -e 's|\(PROJ_mandir.*:=\).*$$|\1${MANPREFIX}/man|g' \
	    ${WRKSRC}/Makefile.config.in
	${REINPLACE_CMD} -e 's|%%DOCSRCDIR%%|${DOCSRCDIR}|' \
	    ${WRKSRC}/Makefile

.if defined(NOPORTDOCS)
post-build:
	@cd ${WRKSRC}/docs/CommandGuide && ${GMAKE} ${MAN1}

post-install:
.for man in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/docs/CommandGuide/${man} \
	     ${MANPREFIX}/man/man1/
.endfor
.endif

TEST_CMD=	'(cd ${WRKSRC}/test; ${SETENV} ${MAKE_ENV} ${GMAKE} check-local-lit)'
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
			bin/opt \
			bin/tblgen \
			lib/libBugpointPasses.so \
			lib/libCompilerDriver.a \
			lib/libEnhancedDisassembly.so \
			lib/libEnhancedDisassembly.a \
			lib/libLTO.* \
			lib/libLLVM* \
			lib/libUnitTestMain.a \
			lib/libprofile_rt.so
PLIST_DIR_LIST=		include/llvm-c \
			include/llvm
build-plist:
	${RM} -f ${PLIST}
	cd ${PREFIX} && \
	    (ls ${PLIST_FILE_LIST}; ${FIND} ${PLIST_DIR_LIST} -type f) | \
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
