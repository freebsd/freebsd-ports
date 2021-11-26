PORTNAME=	functionalplus
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.17-p0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ header-only library that helps write concise and readable C++ code

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	doctest>0:devel/doctest

USES=		cmake compiler:c++14-lang

USE_GITHUB=	yes
GH_ACCOUNT=	Dobiasd
GH_PROJECT=	FunctionalPlus

NO_BUILD=	yes
NO_ARCH=	yes

do-test: # according to INSTALL.md tests are in a separate sub-project, build of tests fails: https://github.com/Dobiasd/FunctionalPlus/issues/250
	@${MKDIR} ${BUILD_WRKSRC}/test && cd ${BUILD_WRKSRC}/test && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} ${CMAKE_SOURCE_PATH}/test && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
