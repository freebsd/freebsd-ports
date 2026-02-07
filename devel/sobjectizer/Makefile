PORTNAME=	sobjectizer
PORTVERSION=	5.8.3
CATEGORIES=	devel
MASTER_SITES=	https://github.com/Stiffstream/${PORTNAME}/releases/download/v.${PORTVERSION}/
DISTNAME=	so-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Cross-platform C++ actor framework
WWW=		https://stiffstream.com/en/products/sobjectizer.html

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

USES=		cmake compiler:c++17-lang tar:xz
CMAKE_ON=	BUILD_TESTS

WRKSRC_SUBDIR=	dev

do-test:
	@cd ${TEST_WRKSRC} && ctest -C ${CMAKE_BUILD_TYPE} ${_MAKE_JOBS}

.include <bsd.port.mk>
