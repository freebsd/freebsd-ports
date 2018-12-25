# $FreeBSD$

PORTNAME=	range-v3
DISTVERSION=	0.3.6
CATEGORIES=	devel

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Experimental range library for C++11/14/17

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	ericniebler
NO_BUILD=	yes
NO_ARCH=	yes

do-install: # workaround: delete when https://github.com/ericniebler/range-v3/issues/781 is fixed, otherwise cmake builds test executables during install
	cd ${WRKSRC}/include && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/
	@${RM} ${STAGEDIR}${PREFIX}/include/module.modulemap

do-test: # tests fail on 10: undefined reference to `operator delete(void*, unsigned int)' (c++14 destructor is missing)
	@cd ${CONFIGURE_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
