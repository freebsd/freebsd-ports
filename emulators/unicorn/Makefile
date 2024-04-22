PORTNAME=	unicorn
PORTVERSION=	2.0.1p1
CATEGORIES=	emulators

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Unicorn CPU emulator framework
WWW=		https://www.unicorn-engine.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	unicorn-engine
GH_TAGNAME=	2.0.1.post1

USES=		cmake:testing pkgconfig
USE_LDCONFIG=	yes
CMAKE_TESTING_ON=	UNICORN_BUILD_TESTS

.include <bsd.port.mk>
