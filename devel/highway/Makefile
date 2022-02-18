PORTNAME=	highway
DISTVERSION=	0.16.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Performance-portable, length-agnostic SIMD with runtime dispatch

LICENSE=	APACHE20

TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++11-lib
USE_GITHUB=	yes
GH_ACCOUNT=	google
CMAKE_ON=	BUILD_SHARED_LIBS HWY_SYSTEM_GTEST
CMAKE_OFF+=	${CMAKE_TESTING_ON}

.include <bsd.port.mk>
