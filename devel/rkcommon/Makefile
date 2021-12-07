PORTNAME=	rkcommon
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Intel RenderKit common C++/CMake infrastructure

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libtbb.so:devel/onetbb

USES=		cmake:testing compiler:c++11-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ospray

CMAKE_OFF=	BUILD_TESTING
CXXFLAGS_i386=	-msse2 # workaround for error: '_mm_setcsr' needs target feature sse
CMAKE_TESTING_ON=	BUILD_TESTING

.include <bsd.port.mk>
