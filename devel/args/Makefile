PORTNAME=	args
DISTVERSION=	6.2.2
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Header-only C++ argument parser library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	Taywee

CMAKE_OFF=	ARGS_BUILD_EXAMPLE ARGS_BUILD_UNITTESTS

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/args.hxx

do-install: # https://github.com/reconquest/args/issues/1
	${INSTALL_DATA} ${WRKSRC}/args.hxx ${STAGEDIR}${PREFIX}/include

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DARGS_BUILD_UNITTESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
