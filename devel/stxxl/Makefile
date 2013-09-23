# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	stxxl
PORTVERSION=	1.3.1
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Standard Template Library for Extra Large Data Sets

USE_GMAKE=	yes
ALL_TARGET=	library_g++

MAKE_ENV+=	COMPILER_GCC="${CXX}" OPT="${CXXFLAGS}" \
		PTHREAD_FLAG="${PTHREAD_LIBS}"

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=OPTIMIZED_CFLAGS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CXXFLAGS+=	-O3
.endif

.if ${OSVERSION} >= 1000000
post-patch:
	@${REINPLACE_CMD} -i '' -e 's|std::tr1::|std::|' \
		${WRKSRC}/include/stxxl/bits/compat/type_traits.h \
		${WRKSRC}/include/stxxl/bits/compat/shared_ptr.h \
		${WRKSRC}/include/stxxl/bits/compat_hash_map.h
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/lib${PORTNAME}.a ${STAGEDIR}${PREFIX}/lib
	@cd ${WRKSRC}/include && ${COPYTREE_SHARE} "${PORTNAME} ${PORTNAME}.h" \
		${STAGEDIR}${PREFIX}/include
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

regression-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} tests_g++
	cd ${WRKSRC}/misc && ${SH} run-all-tests

.include <bsd.port.mk>
