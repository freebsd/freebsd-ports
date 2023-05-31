PORTNAME=	libcuckoo
PORTVERSION=	0.3.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Performant hash table implementation
WWW=		https://github.com/efficient/libcuckoo

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	efficient

NO_ARCH=	yes

OPTIONS_DEFINE=		TEST

TEST_CMAKE_BOOL=	BUILD_TESTS BUILD_STRESS_TESTS BUILD_UNIT_TESTS
TEST_TARGET=		test

.include <bsd.port.mk>
