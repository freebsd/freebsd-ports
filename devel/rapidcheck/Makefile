# $FreeBSD$

PORTNAME=	rapidcheck
PORTVERSION=	g20190815
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	QuickCheck clone for C++

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cmake compiler:c++11-lang localbase
USE_GITHUB=	yes
GH_ACCOUNT=	emil-e
GH_TAGNAME=	d9482c6
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

post-install:
	@${MV} ${STAGEDIR}${DATADIR}/cmake ${STAGEDIR}${PREFIX}/lib/
	@${RMDIR} ${STAGEDIR}${DATADIR}

do-test: # broken: https://github.com/emil-e/rapidcheck/issues/242
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DRC_ENABLE_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
