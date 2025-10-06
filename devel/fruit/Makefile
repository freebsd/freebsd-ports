PORTNAME=	fruit
PORTVERSION=	3.7.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

PATCH_SITES=	https://github.com/google/fruit/commit/
PATCHFILES=	dab5bdfe01eb9f90a2b688c7f3be177a9bd8d5c6.patch:-p1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Dependency injection framework for C++
WWW=		https://github.com/google/fruit/wiki \
		https://github.com/google/fruit

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang

CMAKE_OFF=	FRUIT_ENABLE_COVERAGE \
		FRUIT_TESTS_USE_PRECOMPILED_HEADERS \
		FRUIT_USES_BOOST
CMAKE_ON=	BUILD_SHARED_LIBS \
		FRUIT_ADD_WNO_UNKNOWN_WARNING_OPTION

USE_GITHUB=	yes
GH_ACCOUNT=	google

.include <bsd.port.mk>
