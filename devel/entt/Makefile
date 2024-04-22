PORTNAME=	entt
DISTVERSIONPREFIX=	v
DISTVERSION=	3.13.2
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast and reliable entity-component system (ECS) and much more
WWW=		https://github.com/skypjack/entt/wiki

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++17-lang

USE_GITHUB=	yes
GH_ACCOUNT=	skypjack

CMAKE_TESTING_ON=	ENTT_BUILD_TESTING ENTT_FIND_GTEST_PACKAGE

NO_BUILD=	yes
NO_ARCH=	yes

post-install: # https://github.com/skypjack/entt/issues/1104
	@${RM} ${STAGEDIR}${PREFIX}/include/BUILD.bazel

.include <bsd.port.mk>
