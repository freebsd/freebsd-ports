PORTNAME=	entt
DISTVERSIONPREFIX=	v
DISTVERSION=	3.12.1
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

.include <bsd.port.mk>
