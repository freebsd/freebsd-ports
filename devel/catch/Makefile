# Created by: gahr
# $FreeBSD$

PORTNAME=	catch
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
CATEGORIES=	devel

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Header-only test framework for C++

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

TEST_DEPENDS=	cmake:devel/cmake

USE_GITHUB=	yes
GH_ACCOUNT=	philsquared
GH_PROJECT=	Catch

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/catch.hpp

do-install:
	${INSTALL_DATA} ${WRKSRC}/single_include/catch.hpp \
	    ${STAGEDIR}${PREFIX}/include

do-test:
	cd ${WRKSRC}/projects/CMake && \
	    ${LOCALBASE}/bin/cmake . && ${MAKE_CMD} && ./SelfTest

.include <bsd.port.mk>
