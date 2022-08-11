PORTNAME=	parallel-hashmap
DISTVERSION=	1.35
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Set of excellent hash map implementations (a C++ header-only library)

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing

USE_GITHUB=	yes
GH_ACCOUNT=	greg7mdp

CMAKE_OFF=	PHMAP_BUILD_TESTS PHMAP_BUILD_EXAMPLES
CMAKE_TESTING_ON=	PHMAP_BUILD_TESTS

NO_BUILD=	yes
NO_ARCH=	yes

.include <bsd.port.mk>
