PORTNAME=	bioparser
DISTVERSION=	3.0.12-2
DISTVERSIONSUFFIX=	-g700e82a
CATEGORIES=	biology devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ header-only parsing library for several formats in bioinformatics

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	rvaser

CMAKE_OFF=	bioparser_build_tests

NO_BUILD=	yes
NO_ARCH=	yes

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -D${PORTNAME}_build_tests:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${BUILD_WRKSRC}/bin/${PORTNAME}_test

.include <bsd.port.mk>
