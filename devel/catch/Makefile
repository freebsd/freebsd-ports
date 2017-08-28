# Created by: gahr
# $FreeBSD$

PORTNAME=	catch
DISTVERSIONPREFIX=	v
DISTVERSION=	1.10.0
CATEGORIES=	devel

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Header-only test framework for C++

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

TEST_DEPENDS=	cmake:devel/cmake

TEST_TARGET=	do-test

USE_GITHUB=	yes
GH_ACCOUNT=	philsquared
GH_PROJECT=	Catch

NO_BUILD=	yes
NO_ARCH=	yes

REPORTERS=	catch_reporter_automake.hpp \
		catch_reporter_tap.hpp \
		catch_reporter_teamcity.hpp

PLIST_FILES=	include/catch.hpp \
		${REPORTERS:S/^/include\//g}

do-install:
	${INSTALL_DATA} ${WRKSRC}/single_include/catch.hpp \
	    ${STAGEDIR}${PREFIX}/include
.for r in ${REPORTERS}
	${INSTALL_DATA} ${WRKSRC}/include/reporters/${r} \
	    ${STAGEDIR}${PREFIX}/include
.endfor

do-test:
	cd ${WRKSRC} && \
	    ${LOCALBASE}/bin/cmake . && ${MAKE_CMD} && ./SelfTest

.include <bsd.port.mk>
