# Created by: Mike McGaughey <mmcg@cs.monash.edu.au>
# $FreeBSD$

PORTNAME=	gc
PORTVERSION=	8.0.4
CATEGORIES=	devel
MASTER_SITES=	http://www.hboehm.info/gc/gc_source/ \
		https://github.com/ivmai/bdwgc/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	boehm-
.ifdef GC_VARIANT
PKGNAMESUFFIX=	-${GC_VARIANT}
.endif

MAINTAINER=	yasu@utahime.org
COMMENT=	Garbage collection and memory leak detection for C and C++

LICENSE=	BDWGC
LICENSE_NAME=	Boehm-Demers-Weiser Garbage Collector License
LICENSE_TEXT=	License can be found at http://www.hboehm.info/gc/license.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${LOCALBASE}/lib/libatomic_ops.a:devel/libatomic_ops

USES=		cpe libtool pathfix pkgconfig
USE_LDCONFIG=	yes

CPE_VENDOR=	boehm-demers-weiser
CPE_PRODUCT=	garbage_collector
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
# NOTE: do not --disable-static, static is useful for e.g. lang/crystal
CONFIGURE_ARGS=	--enable-cplusplus --enable-static
MAKE_JOBS_UNSAFE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME:C/[a-z]$//}

OPTIONS_DEFINE=	DEBUG

.ifdef GC_VARIANT
INSTALL_TARGET=	install-exec install-pkgconfigDATA
CORDLIBS=	cord
GCLIBS=		gc
GCCPPLIBS=	gccpp
PLIST=		${NONEXISTENT}
PLIST_FILES=	${CORDLIBS:S,^,lib/lib,:S,$,-${GC_VARIANT}.a,} \
		${CORDLIBS:S,^,lib/lib,:S,$,-${GC_VARIANT}.so,} \
		${CORDLIBS:S,^,lib/lib,:S,$,-${GC_VARIANT}.so.1,} \
		${CORDLIBS:S,^,lib/lib,:S,$,-${GC_VARIANT}.so.1.4.0,} \
		${GCLIBS:S,^,lib/lib,:S,$,-${GC_VARIANT}.a,} \
		${GCLIBS:S,^,lib/lib,:S,$,-${GC_VARIANT}.so,} \
		${GCLIBS:S,^,lib/lib,:S,$,-${GC_VARIANT}.so.1,} \
		${GCLIBS:S,^,lib/lib,:S,$,-${GC_VARIANT}.so.1.4.3,} \
		${GCCPPLIBS:S,^,lib/lib,:S,$,-${GC_VARIANT}.a,} \
		${GCCPPLIBS:S,^,lib/lib,:S,$,-${GC_VARIANT}.so,} \
		${GCCPPLIBS:S,^,lib/lib,:S,$,-${GC_VARIANT}.so.1,} \
		${GCCPPLIBS:S,^,lib/lib,:S,$,-${GC_VARIANT}.so.1.4.0,} \
		libdata/pkgconfig/bdw-gc-${GC_VARIANT}.pc
RUN_DEPENDS+=	${LOCALBASE}/include/gc/gc.h:devel/boehm-gc
. if ${GC_VARIANT} == "redirect"
CONFIGURE_ARGS+=	--disable-threads --enable-redirect-malloc
. endif
. if ${GC_VARIANT} == "threaded"
CONFIGURE_ARGS+=	--enable-threads=posix --disable-redirect-malloc
OPTIONS_DEFINE+=	PARALLEL_MARK
PARALLEL_MARK_DESC=	Parallel-thread marking (faster for SMP)
USES+=		compiler:c11
. endif
.else
CONFIGURE_ARGS+=	--disable-threads --disable-redirect-malloc
OPTIONS_DEFINE+=	DOCS
PORTDOCS=	*
.endif

DEBUG_CONFIGURE_WITH=	--enable-gc-debug

.if defined(GC_VARIANT) && ${GC_VARIANT} == "threaded"
PARALLEL_MARK_CONFIGURE_WITH=	--enable-parallel-mark
.endif

.ifdef GC_VARIANT
post-patch:
	@${REINPLACE_CMD} -e \
		's,libgc\.la,libgc-${GC_VARIANT}.la,g ; \
		s,libgccpp\.la,libgccpp-${GC_VARIANT}.la,g ; \
		s,libcord\.la,libcord-${GC_VARIANT}.la,g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's,-lgc,-lgc-${GC_VARIANT},' ${WRKSRC}/bdw-gc.pc.in

post-install:
	${MV} ${STAGEDIR}${PREFIX}/libdata/pkgconfig/bdw-gc.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/bdw-gc-${GC_VARIANT}.pc

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
