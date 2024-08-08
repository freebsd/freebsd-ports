PORTNAME=	fcppt
DISTVERSION=	4.5.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Freundlich's C++ toolkit
WWW=		https://fcppt.org/

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

BUILD_DEPENDS=	${LOCALBASE}/include/boost/format.hpp:devel/boost-libs \
		catch2>0:devel/catch2
TEST_DEPENDS=	catch2>0:devel/catch2

USES=		cmake:testing compiler:c++20-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	cpreh

CMAKE_OFF=		ENABLE_EXAMPLES
CMAKE_TESTING_ON=	ENABLE_TEST ENABLE_CATCH

.include <bsd.port.mk>
