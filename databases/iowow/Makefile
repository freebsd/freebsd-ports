# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	iowow
PORTVERSION=	1.3.27
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Persistent key-value database engine

LICENSE=	MIT

USES=		cmake compiler:c11
USE_GITHUB=	yes
GH_ACCOUNT=	Softmotions
USE_LDCONFIG=	yes

PLIST_SUB+=	VERSION=${PORTVERSION}
PORTDOCS=	Changelog README

OPTIONS_DEFINE=	DOCS TEST

TEST_BUILD_DEPENDS=	${LOCALBASE}/include/CUnit/Basic.h:devel/cunit
TEST_CMAKE_ON=	-DBUILD_TESTS:BOOL=ON

do-test-TEST-on:
	@cd ${TEST_WRKSRC} && ctest -C ${CMAKE_BUILD_TYPE} ${_MAKE_JOBS}

.include <bsd.port.mk>
