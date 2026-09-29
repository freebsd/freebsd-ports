PORTNAME=	transwarp
DISTVERSION=	2.2.3
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ header-only library for task concurrency
WWW=		https://github.com/bloomen/transwarp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cmake:testing compiler:c++17-lang

USE_GITHUB=	yes
GH_ACCOUNT=	bloomen

CMAKE_TESTING_ON=	transwarp_build_tests
CMAKE_ARGS=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5 # CMake 4 compatibility, see https://github.com/bloomen/transwarp/issues/41

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/transwarp.h

.include <bsd.port.mk>
