PORTNAME=	libmcfp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.4
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ header only library to parse command line arguments
WWW=		https://github.com/mhekkel/libmcfp

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${LOCALBASE}/include/boost/test/included/unit_test.hpp:devel/boost-libs

USES=		cmake:testing localbase

USE_GITHUB=	yes
GH_ACCOUNT=	mhekkel

CMAKE_TESTING_ON=	ENABLE_TESTING

NO_ARCH=	yes

PORTSCOUT=	limit:^.*[0-9]\.[0-9].*

.include <bsd.port.mk>
