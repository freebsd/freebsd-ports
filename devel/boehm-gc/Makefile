PORTNAME=	gc
DISTVERSION=	8.2.8
CATEGORIES=	devel
MASTER_SITES=	https://www.hboehm.info/gc/gc_source/ \
		https://github.com/bdwgc/bdwgc/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	boehm-
.ifdef GC_VARIANT
PKGNAMESUFFIX=	-${GC_VARIANT}
.endif

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	Garbage collection and memory leak detection for C and C++
WWW=		https://www.hboehm.info/gc/

LICENSE=	BDWGC
LICENSE_NAME=	Boehm-Demers-Weiser Garbage Collector License
LICENSE_TEXT=	License can be found at http://www.hboehm.info/gc/license.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${LOCALBASE}/lib/libatomic_ops.a:devel/libatomic_ops

USES=		cpe libtool pathfix pkgconfig
CPE_VENDOR=	boehm-demers-weiser
CPE_PRODUCT=	garbage_collector
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
# NOTE: do not --disable-static, static is useful for e.g. lang/crystal
CONFIGURE_ARGS=	--enable-cplusplus \
		--enable-mmap \
		--enable-static

MAKE_JOBS_UNSAFE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

WRKSRC=		${WRKDIR}/${DISTNAME:C/[a-z]$//}

OPTIONS_DEFINE=	DEBUG

.ifdef GC_VARIANT
INSTALL_TARGET=		install-exec install-pkgconfigDATA
CORDLIBS=		cord
GCCPPLIBS=		gccpp
GCLIBS=			gc
GCTBALIBS=		gctba
PLIST=			${NONEXISTENT}
PLIST_FILES=		${CORDLIBS:S,^,lib/lib,:S,$,-${GC_VARIANT}.a,} \
			${CORDLIBS:S,^,lib/lib,:S,$,-${GC_VARIANT}.so,} \
			${CORDLIBS:S,^,lib/lib,:S,$,-${GC_VARIANT}.so.1,} \
			${CORDLIBS:S,^,lib/lib,:S,$,-${GC_VARIANT}.so.1.5.1,} \
			${GCCPPLIBS:S,^,lib/lib,:S,$,-${GC_VARIANT}.a,} \
			${GCCPPLIBS:S,^,lib/lib,:S,$,-${GC_VARIANT}.so,} \
			${GCCPPLIBS:S,^,lib/lib,:S,$,-${GC_VARIANT}.so.1,} \
			${GCCPPLIBS:S,^,lib/lib,:S,$,-${GC_VARIANT}.so.1.5.0,} \
			${GCLIBS:S,^,lib/lib,:S,$,-${GC_VARIANT}.a,} \
			${GCLIBS:S,^,lib/lib,:S,$,-${GC_VARIANT}.so,} \
			${GCLIBS:S,^,lib/lib,:S,$,-${GC_VARIANT}.so.1,} \
			${GCLIBS:S,^,lib/lib,:S,$,-${GC_VARIANT}.so.1.5.4,} \
			${GCTBALIBS:S,^,lib/lib,:S,$,-${GC_VARIANT}.a,} \
			${GCTBALIBS:S,^,lib/lib,:S,$,-${GC_VARIANT}.so,} \
			${GCTBALIBS:S,^,lib/lib,:S,$,-${GC_VARIANT}.so.1,} \
			${GCTBALIBS:S,^,lib/lib,:S,$,-${GC_VARIANT}.so.1.5.0,} \
			libdata/pkgconfig/bdw-gc-${GC_VARIANT}.pc
RUN_DEPENDS+=		${LOCALBASE}/include/gc/gc.h:devel/boehm-gc
. if ${GC_VARIANT} == "threaded"
CONFIGURE_ARGS+=	--disable-redirect-malloc \
			--enable-threads=posix
OPTIONS_DEFINE+=	PARALLEL_MARK
PARALLEL_MARK_DESC=	Parallel-thread marking (faster for SMP)
USES+=			compiler:c11
PLIST_FILES+=		include/gc/gc_pthread_redirects.h
. endif
.else
CONFIGURE_ARGS+=	--disable-redirect-malloc \
			--disable-threads
OPTIONS_DEFINE+=	DOCS
PORTDOCS=		*
.endif

DEBUG_CONFIGURE_WITH=	--enable-gc-debug

.if defined(GC_VARIANT) && ${GC_VARIANT} == "threaded"
PARALLEL_MARK_CONFIGURE_WITH=	--enable-parallel-mark
.endif

.ifdef GC_VARIANT
post-patch:
	@${REINPLACE_CMD} -e \
		's,libcord\.la,libcord-${GC_VARIANT}.la,g ; \
		s,libgc\.la,libgc-${GC_VARIANT}.la,g ; \
		s,libgccpp\.la,libgccpp-${GC_VARIANT}.la,g ; \
		s,libgctba\.la,libgctba-${GC_VARIANT}.la,g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's,-lgc,-lgc-${GC_VARIANT},' ${WRKSRC}/bdw-gc.pc.in

post-install:
	${MV} ${STAGEDIR}${PREFIX}/libdata/pkgconfig/bdw-gc.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/bdw-gc-${GC_VARIANT}.pc
. if ${GC_VARIANT} == "threaded"
	${MKDIR} ${STAGEDIR}${PREFIX}/include/gc
	${INSTALL_DATA} ${WRKSRC}/include/gc_pthread_redirects.h \
		${STAGEDIR}${PREFIX}/include/gc
. endif
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcord-${GC_VARIANT}.so.1.5.1
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgc-${GC_VARIANT}.so.1.5.4
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgccpp-${GC_VARIANT}.so.1.5.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgctba-${GC_VARIANT}.so.1.5.0

.else # ! GC_VARIANT
post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/doc/gc.man
	@${REINPLACE_CMD} \
		-e "s|(datadir)/@PACKAGE@|(datadir)/doc/@PACKAGE@|" \
		${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.endif

.include <bsd.port.mk>
