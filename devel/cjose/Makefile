PORTNAME=	cjose
DISTVERSION=	0.8.0.20260912
CATEGORIES=	devel

MAINTAINER=	jamie@chair6.net
COMMENT=	C library implementing JavaScript Object Signing and Encryption (JOSE)
WWW=		https://github.com/cisco/cjose

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjansson.so:devel/jansson
TEST_DEPENDS=	checkmk:devel/check

USES=		cmake:testing compiler:c17 pathfix ssl
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	cisco
GH_TAGNAME=	a12e7c5

CMAKE_TESTING_ON=	CJOSE_BUILD_TESTS

CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_Doxygen
CMAKE_OFF=	CJOSE_BUILD_STATIC \
		CJOSE_BUILD_TESTS

.include <bsd.port.mk>
