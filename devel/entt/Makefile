PORTNAME=	entt
DISTVERSIONPREFIX=	v
DISTVERSION=	3.9.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast and reliable entity-component system (ECS) and much more

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++17-lang python:test

USE_GITHUB=	yes
GH_ACCOUNT=	skypjack

CMAKE_TESTING_ON=	ENTT_BUILD_TESTING
CMAKE_ARGS=		-DPython_EXECUTABLE=${PYTHON_CMD}

NO_BUILD=	yes
NO_ARCH=	yes

.include <bsd.port.mk>
