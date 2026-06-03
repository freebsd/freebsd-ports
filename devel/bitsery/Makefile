PORTNAME=	bitsery
DISTVERSIONPREFIX=	v
DISTVERSION=	5.2.5
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Binary serialization library
WWW=		https://github.com/fraillt/bitsery

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++14-lang

USE_GITHUB=	yes
GH_ACCOUNT=	fraillt

CMAKE_TESTING_ON=	BITSERY_BUILD_TESTS # tests fail to compile, see https://github.com/fraillt/bitsery/issues/111

NO_ARCH=	yes

# tests as of 5.2.5: 100% tests passed, 0 tests failed out of 360

.include <bsd.port.mk>
