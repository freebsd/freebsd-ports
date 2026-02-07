PORTNAME=	highway
DISTVERSION=	1.3.0
CATEGORIES=	devel

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	232b3ee08919.patch:-p1 # https://github.com/google/highway/pull/2670
PATCHFILES+=	c00492256d71.patch:-p1 # https://github.com/google/highway/pull/2672

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Performance-portable, length-agnostic SIMD with runtime dispatch
WWW=		https://github.com/google/highway

LICENSE=	APACHE20

TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++11-lib
USE_GITHUB=	yes
GH_ACCOUNT=	google
CMAKE_ON=	BUILD_SHARED_LIBS HWY_SYSTEM_GTEST
CMAKE_OFF+=	${CMAKE_TESTING_ON}

.include <bsd.port.mk>
