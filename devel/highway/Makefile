PORTNAME=	highway
DISTVERSION=	1.4.0
CATEGORIES=	devel

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	2a8e177868e1.patch:-p1 # https://github.com/google/highway/pull/3013

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
