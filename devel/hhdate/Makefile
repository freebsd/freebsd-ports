# $FreeBSD$

PORTNAME=	hhdate
PORTVERSION=	3.0.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Date and time library based on the C++11 (and beyond) <chrono> header

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_GITHUB=	yes
GH_ACCOUNT=	HowardHinnant
GH_PROJECT=	date

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	include/hhdate/date.h \
		include/hhdate/tz.h

OPTIONS_DEFINE=		TEST
TEST_DESC=		Build with minimal tests
TEST_ENV=		${MAKE_ENV} WRKDIR=${WRKDIR}
TEST_USES=		compiler:c++11-lib
TEST_TEST_TARGET=	test
USE_CXXSTD=		c++11

post-extract-TEST-on:
	${INSTALL_DATA} ${FILESDIR}/test-minimal.cpp ${WRKSRC}/test/test-minimal.cpp

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/hhdate
	${INSTALL_DATA} ${WRKSRC}/include/date/date.h ${WRKSRC}/include/date/tz.h ${STAGEDIR}${PREFIX}/include/hhdate/

do-test:
	cd ${WRKSRC}/test && ${CXX} ${CXXFLAGS} test-minimal.cpp -o test-minimal && ./test-minimal > /dev/null

.include <bsd.port.mk>
