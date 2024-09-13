PORTNAME=	camp
DISTVERSIONPREFIX=	v
DISTVERSION=	2024.07.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Compiler agnostic metaprogramming library
WWW=		https://github.com/LLNL/camp

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++17-lang

USE_GITHUB=	yes
GH_ACCOUNT=	LLNL
GH_TUPLE=	LLNL:blt:9ff7734:blt/extern/blt

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	CAMP_ENABLE_TESTS

.include <bsd.port.mk>
