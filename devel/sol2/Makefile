PORTNAME=	sol2
DISTVERSIONPREFIX=	v
DISTVERSION=	4.0.0-alpha
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ header-only library binding to Lua

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake:testing compiler:c++17-lang lua:run

USE_GITHUB=	yes
GH_ACCOUNT=	ThePhD

CMAKE_TESTING_ON=	SOL2_TESTS

NO_ARCH=	yes

.include <bsd.port.mk>
