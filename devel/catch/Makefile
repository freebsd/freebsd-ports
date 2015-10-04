# Created by: gahr
# $FreeBSD$

PORTNAME=	catch
DISTVERSION=	1.2.1-develop.14
CATEGORIES=	devel

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Header-only test framework for C++

LICENSE=	BSL

USE_GITHUB=	yes
GH_ACCOUNT=	philsquared
GH_PROJECT=	Catch

NO_BUILD=	yes
TEST_DEPENDS=	cmake:${PORTSDIR}/devel/cmake

PLIST_FILES=	include/catch.hpp

do-install:
	${INSTALL_DATA} ${WRKSRC}/single_include/catch.hpp \
	    ${STAGEDIR}${PREFIX}/include

do-test:
	cd ${WRKSRC}/projects/CMake && \
	    ${LOCALBASE}/bin/cmake . && ${MAKE_CMD} && ./SelfTest

.include <bsd.port.mk>
