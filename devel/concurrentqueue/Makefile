PORTNAME=	concurrentqueue
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.4
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast C++11 multi-producer multi-consumer lock-free concurrent queue
WWW=		https://github.com/cameron314/concurrentqueue

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cmake compiler:c++11-lang dos2unix

USE_GITHUB=	yes
GH_ACCOUNT=	cameron314

DOS2UNIX_FILES=	tests/common/systemtime.cpp

NO_ARCH=	yes

BINARY_ALIAS=	g++=${CXX} # only for tests

xdo-test:
	@cd ${WRKSRC}/tests/unittests && \
		${SETENV} ${TEST_ENV} ${GMAKE} && \
		${WRKSRC}/build/bin/unittests

do-test:
	@${SETENV} ${TEST_ENV} ${GMAKE} -C ${WRKSRC}/tests/unittests
	@${WRKSRC}/build/bin/unittests

.include <bsd.port.mk>
