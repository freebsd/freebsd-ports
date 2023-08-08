PORTNAME=	highway
DISTVERSION=	1.0.5
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Performance-portable, length-agnostic SIMD with runtime dispatch
WWW=		https://github.com/google/highway

LICENSE=	APACHE20

TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++11-lib
USE_GITHUB=	yes
GH_ACCOUNT=	google
CFLAGS_powerpc64=	-DHWY_DISABLE_PPC8_CRYPTO
CFLAGS_powerpc=	-DHWY_DISABLE_PPC8_CRYPTO
CMAKE_ON=	BUILD_SHARED_LIBS HWY_SYSTEM_GTEST
CMAKE_OFF+=	${CMAKE_TESTING_ON}

.include <bsd.port.mk>
