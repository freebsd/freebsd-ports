PORTNAME=	actor-framework
DISTVERSION=	0.19.0-rc.1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open Source implementation of the Actor Model in C++
WWW=		https://www.actor-framework.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++17-lang ssl
USE_LDCONFIG=	yes

USE_GITHUB=	yes

CMAKE_OFF=	CAF_ENABLE_TESTING
CMAKE_TESTING_ON=	CAF_ENABLE_TESTING

.include <bsd.port.mk>
