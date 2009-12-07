# New ports collection makefile for:	llvm
# Date created:		20 Nov 2005
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	llvm
PORTVERSION=	2.6
PORTREVISION=	2
CATEGORIES=	devel lang
MASTER_SITES=	http://llvm.org/releases/${PORTVERSION}/

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Low Level Virtual Machine

.if defined(PACKAGE_BUILDING) || defined(MAINTAINER_MODE)
BUILD_DEPENDS=	runtest:${PORTSDIR}/misc/dejagnu
.endif
.if defined(MAINTAINER_MODE)
BUILD_DEPENDS+=	f2c:${PORTSDIR}/lang/f2c
.endif

CONFLICTS=	llvm-devel-2.[0-9]*

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_PERL5_BUILD=yes
MAKE_JOBS_SAFE=	yes

.if defined(MAINTAINER_MODE)
CONFIGURE_ARGS+=	--with-f2c=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--enable-optimized
.endif

CONFIGURE_ARGS+=	--enable-bindings=none

OPTIONS=	NO_ASSERTS	"Disable assertions (needed by graphics/opengtl)" off

.if defined(NOPORTDOCS)
DOCSRCDIR=
.else
DOCSRCDIR=	docs
.endif

.if !defined(NOPORTDOCS)
MAN1=		bugpoint.1 llc.1 lli.1 llvm-ar.1 \
		llvm-as.1 llvm-bcanalyzer.1 llvm-config.1 llvm-db.1 \
		llvm-dis.1 llvm-extract.1 llvm-ld.1 llvm-link.1 llvm-nm.1 \
		llvm-prof.1 llvm-ranlib.1 llvmc.1 llvmgcc.1 \
		llvmgxx.1 opt.1 tblgen.1
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CONFIGURE_ARGS+=	--enable-pic --with-pic
.endif

.ifdef(WITH_NO_ASSERTS)
CONFIGURE_ARGS+=	--disable-assertions
.else
CONFIGURE_ARGS+=	--enable-assertions
.endif

post-patch:
	${REINPLACE_CMD} -e 's|\(PROJ_docsdir.*:=\).*$$|\1${DOCSDIR}|g' \
	    ${WRKSRC}/Makefile.config.in
	${REINPLACE_CMD} -e 's|\(PROJ_mandir.*:=\).*$$|\1${MANPREFIX}/man|g' \
	    ${WRKSRC}/Makefile.config.in
	${REINPLACE_CMD} -e 's|%%DOCSRCDIR%%|${DOCSRCDIR}|' \
	    ${WRKSRC}/Makefile

TEST_CMD=	'(cd ${WRKSRC}/test; ${SETENV} ${MAKE_ENV} ${GMAKE} check)'
regression-test: ${BUILD_COOKIE}
	if [ `${ID} -u` = 0 ]; then \
		${CHOWN} -R nobody ${WRKSRC}/test; \
		su -m nobody -c ${TEST_CMD}; \
	else \
		${SH} -c ${TEST_CMD}; \
	fi

PLIST_FILE_LIST=	bin/bugpoint \
			bin/gccas \
			bin/gccld \
			bin/llc \
			bin/lli \
			bin/llvm* \
			bin/opt \
			bin/tblgen \
			lib/libCompilerDriver.a \
			lib/libLTO.* \
			lib/libLLVM* \
			lib/libplugin_llvmc* \
			lib/libprofile_rt.so
PLIST_DIR_LIST=		include/llvm-c \
			include/llvm
build-plist:
	${RM} -f ${PLIST}
	cd ${PREFIX} && \
	    (ls ${PLIST_FILE_LIST}; ${FIND} ${PLIST_DIR_LIST} -type f) | \
	    ${SORT} >> ${PLIST}
	${FIND} ${DATADIR} ${DOCSDIR} -type f | \
	    ${SED} -e 's|${DATADIR}|%%DATADIR%%|' \
	     -e 's|${DOCSDIR}|%%PORTDOCS%%%%DOCSDIR%%|' | ${SORT} >> ${PLIST}
	cd ${PREFIX} && \
	    ${FIND} ${PLIST_DIR_LIST} -type d | \
	    ${SORT} -r | ${SED} -e 's|^|@dirrm |' >> ${PLIST}
	${FIND} ${DOCSDIR} -type d | ${SORT} -r | \
	    ${SED} -e 's|${DATADIR}|%%DATADIR%%|' \
	     -e 's|${DOCSDIR}|%%DOCSDIR%%|' \
	     -e 's|^|%%PORTDOCS%%@dirrm |' >> ${PLIST}

.include <bsd.port.post.mk>
