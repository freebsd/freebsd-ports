# Created by: Mike McGaughey <mmcg@cs.monash.edu.au>
# $FreeBSD$

PORTNAME=	gc
PORTVERSION=	7.2e
PORTREVISION?=	0
CATEGORIES=	devel
MASTER_SITES=	http://www.hpl.hp.com/personal/Hans_Boehm/gc/gc_source/
PKGNAMEPREFIX=	boehm-
.ifdef GC_VARIANT
PKGNAMESUFFIX=	-${GC_VARIANT}
.endif

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Garbage collection and memory leak detection for C and C++

LICENSE=	BDWGC
LICENSE_NAME=	Boehm-Demers-Weiser Garbage Collector License
LICENSE_FILE=	${WRKSRC}/doc/README
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

GNU_CONFIGURE=	yes
USES=		pathfix
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-cplusplus --disable-static
MAKE_JOBS_UNSAFE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME:C/[a-z]$//}

OPTIONS_DEFINE=	DEBUG

.ifdef GC_VARIANT
INSTLIBS=	cord gc gccpp
PLIST=		${NONEXISTENT}
PLIST_FILES=	${INSTLIBS:S,^,lib/lib,g:S,$,-${GC_VARIANT}.so.${SOVER},g} \
		${INSTLIBS:S,^,lib/lib,g:S,$,-${GC_VARIANT}.so,g} \
		libdata/pkgconfig/bdw-gc-${GC_VARIANT}.pc
RUN_DEPENDS+=	${LOCALBASE}/include/gc/gc.h:${PORTSDIR}/devel/boehm-gc
SOVER=		1
. if ${GC_VARIANT} == "redirect"
CONFIGURE_ARGS+=--disable-threads --enable-redirect-malloc
. endif
. if ${GC_VARIANT} == "threaded"
CONFIGURE_ARGS+=--enable-threads=posix --disable-redirect-malloc
OPTIONS_DEFINE+=PARALLEL_MARK
PARALLEL_MARK_DESC=	Parallel-thread marking (faster for SMP)
. endif
.else
CONFIGURE_ARGS+=--disable-threads --disable-redirect-malloc
OPTIONS_DEFINE+=DOCS
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>

NOT_FOR_ARCHS=	ia64

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-gc-debug
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}+fulldebug
.endif

.if ! ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=--datarootdir=${WRKDIR}/doc
.endif

.if defined(GC_VARIANT) && ${GC_VARIANT} == "threaded"
. if ${PORT_OPTIONS:MPARALLEL_MARK}
CONFIGURE_ARGS+=--enable-parallel-mark
. endif
.endif

.ifdef GC_VARIANT
post-patch:
	@${REINPLACE_CMD} -e \
		's,libgc\.la,libgc-${GC_VARIANT}.la,g ; \
		s,libgccpp\.la,libgccpp-${GC_VARIANT}.la,g ; \
		s,libcord\.la,libcord-${GC_VARIANT}.la,g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's,-lgc,-lgc-${GC_VARIANT},' ${WRKSRC}/bdw-gc.pc.in

do-install:
.for LIB in ${INSTLIBS}
	${INSTALL_DATA} ${WRKSRC}/.libs/lib${LIB}-${GC_VARIANT}.so.${SOVER} \
		${STAGEDIR}${PREFIX}/lib/lib${LIB}-${GC_VARIANT}.so.${SOVER}
	${LN} -sf lib${LIB}-${GC_VARIANT}.so.${SOVER} \
		${STAGEDIR}${PREFIX}/lib/lib${LIB}-${GC_VARIANT}.so
.endfor
	${INSTALL_DATA} ${WRKSRC}/bdw-gc.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/bdw-gc-${GC_VARIANT}.pc

.else # ! GC_VARIANT
post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/doc/gc.man
	@${REINPLACE_CMD} \
		-e "s|(datadir)/@PACKAGE@|(datadir)/doc/@PACKAGE@|" \
		${WRKSRC}/Makefile.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/gc.man ${STAGEDIR}${MAN3PREFIX}/man/man3/gc.3

.endif

# Get rid of .la and static library files
#
post-configure:
	@${REINPLACE_CMD} -E -e \
	'/Install the pseudo-library/,/staticlibs=/s,^,#,' ${WRKSRC}/libtool

regression-test: build
	cd ${WRKSRC} && ${MAKE} check

.include <bsd.port.post.mk>
