PORTNAME=	libmcfp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.2
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ header only library to parse command line arguments
WWW=		https://github.com/mhekkel/libmcfp

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	catch2>0:devel/catch2 \
		${LOCALBASE}/include/boost/test/included/unit_test.hpp:devel/boost-libs

USES=		cmake:testing localbase

USE_GITHUB=	yes
GH_ACCOUNT=	mhekkel

CMAKE_OFF=	BUILD_TESTING

NO_ARCH=	yes

PORTSCOUT=	limit:^.*[0-9]\.[0-9].*

# tests as of 1.4.2: 100% tests passed, 0 tests failed out of 1

.include <bsd.port.mk>
