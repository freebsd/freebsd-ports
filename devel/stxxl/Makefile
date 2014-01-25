# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	stxxl
PORTVERSION=	1.3.1
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Standard Template Library for Extra Large Data Sets

USES=		gmake
ALL_TARGET=	library_g++

MAKE_ENV+=	COMPILER_GCC="${CXX}" OPT="${CXXFLAGS}" \
		PTHREAD_FLAG="${PTHREAD_LIBS}"

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=OPTIMIZED_CFLAGS

OPTIMIZED_CFLAGS_CXXFLAGS=	-O3

.include <bsd.port.options.mk>

post-patch:
.if ${OSVERSION} >= 1000000
	@${REINPLACE_CMD} -i '' -e 's|std::tr1::|std::|' \
		${WRKSRC}/include/stxxl/bits/compat/type_traits.h \
		${WRKSRC}/include/stxxl/bits/compat/shared_ptr.h \
		${WRKSRC}/include/stxxl/bits/compat_hash_map.h
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/lib${PORTNAME}.a ${STAGEDIR}${PREFIX}/lib
	cd ${WRKSRC}/include && ${COPYTREE_SHARE} "${PORTNAME} ${PORTNAME}.h" \
		${STAGEDIR}${PREFIX}/include
	${RM} -f ${STAGEDIR}${PREFIX}/include/stxxl/bits/mng/config.h.orig
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

regression-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} tests_g++
	cd ${WRKSRC}/misc && ${SH} run-all-tests

.include <bsd.port.mk>
