PORTNAME=	sobjectizer
PORTVERSION=	5.7.4.1
DISTVERSIONPREFIX=	v.
CATEGORIES=	devel

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Cross-platform C++ actor framework

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

USES=		cmake compiler:c++17-lang
USE_GITHUB=	yes
GH_ACCOUNT=	Stiffstream

CMAKE_ON=	BUILD_TESTS

WRKSRC_SUBDIR=	dev

do-test:
	@cd ${TEST_WRKSRC} && ctest -C ${CMAKE_BUILD_TYPE} ${_MAKE_JOBS}

.include <bsd.port.mk>
