# Created by: Andreas Sommer <andreas.sommer87@googlemail.com>
# $FreeBSD$

PORTNAME=	hhdate
# New versions aren't released often, so using the number of commits since
# last release as a.b.c.NUMCOMMITS (see `git describe --tags ${GH_TAGNAME}`).
# 35 = commit a little after 2.1.0 to have LICENSE file and fixed unit tests.
PORTVERSION=	2.1.0.35
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	andreas.sommer87@googlemail.com
COMMENT=	Date and time library based on the C++11 (and beyond) <chrono> header

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_GITHUB=	yes
GH_ACCOUNT=	HowardHinnant
GH_PROJECT=	date
GH_TAGNAME=	3ab6510cab764c1a20926b1e8442af4c9e8a16b2

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
