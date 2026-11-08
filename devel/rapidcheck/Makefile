PORTNAME=	rapidcheck
PORTVERSION=	g20260806
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	QuickCheck clone for C++
WWW=		https://github.com/emil-e/rapidcheck

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

TEST_DEPENDS=	catch>0:devel/catch

USES=		cmake compiler:c++11-lang localbase
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	emil-e
GH_TAGNAME=	6e8dadf

CMAKE_ON=	BUILD_SHARED_LIBS

CXXFLAGS+=	-Wno-error
CXXFLAGS+=	-I${WRKSRC}/extras/catch/include # only to fix tests (rapidcheck/catch.h)

do-test: # tests fail to compile, see https://github.com/emil-e/rapidcheck/issues/349
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DRC_ENABLE_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
