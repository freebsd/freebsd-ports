# Created by: Andreas Sommer <andreas.sommer87@googlemail.com>
# $FreeBSD$

PORTNAME=	hhdate
PORTVERSION=	2.2
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	andreas.sommer87@googlemail.com
COMMENT=	Date and time library based on the C++11 (and beyond) <chrono> header

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_GITHUB=	yes
GH_ACCOUNT=	HowardHinnant
GH_PROJECT=	date

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	include/hhdate/date.h

# TODO add timezone support when interest grows
OPTIONS_DEFINE=		TEST
TEST_DESC=		Build with minimal tests
TEST_ENV=		${MAKE_ENV} WRKDIR=${WRKDIR}
TEST_USES=		compiler:c++11-lib
TEST_TEST_TARGET=	test
USE_CXXSTD=		c++11

.include <bsd.port.options.mk>

post-extract-TEST-on:
	${INSTALL_DATA} ${FILESDIR}/Makefile.in ${WRKSRC}/Makefile
	${INSTALL_DATA} ${FILESDIR}/test-minimal.cpp ${WRKSRC}/test/test-minimal.cpp

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/hhdate
	${INSTALL_DATA} ${WRKSRC}/date.h ${STAGEDIR}${PREFIX}/include/hhdate/

.include <bsd.port.mk>
