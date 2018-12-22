# $FreeBSD$

PORTNAME=	xtl
DISTVERSION=	0.5.2
CATEGORIES=	devel
PKGNAMESUFFIX=	-quant-stack

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Template library that supports other quantstack projects

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json
RUN_DEPENDS=	nlohmann-json>0:devel/nlohmann-json
TEST_DEPENDS=	nlohmann-json>0:devel/nlohmann-json \
		googletest>0:devel/googletest

USES=		cmake:outsource
USE_GITHUB=	yes
GH_ACCOUNT=	QuantStack

NO_BUILD=	yes
NO_ARCH=	yes

do-test: # tests fail to build: https://github.com/QuantStack/xtl/issues/106
	@cd ${WRKSRC}/test && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -Dxtl_DIR:STRING=${STAGEDIR}${PREFIX}/lib/cmake/xtl && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} xtest

.include <bsd.port.mk>
