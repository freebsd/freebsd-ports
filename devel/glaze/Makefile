PORTNAME=	glaze
DISTVERSIONPREFIX=	v
DISTVERSION=	8.4.0
CATEGORIES=	devel textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast, in memory, JSON and interface library for modern C++
WWW=		https://github.com/stephenberry/glaze

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/asio.hpp:net/asio
#TEST_DEPENDS=	ut>0:devel/ut # the old version 0.3.0 is used

USES=		cmake:testing compiler:c++23-lang eigen:3 localbase

USE_GITHUB=	yes
GH_ACCOUNT=	stephenberry

CMAKE_OFF=	BUILD_TESTING \
		glaze_ENABLE_AVX2 \
		glaze_DEVELOPER_MODE
CMAKE_ARGS=	-DFETCHCONTENT_TRY_FIND_PACKAGE_MODE=ALWAYS
CMAKE_TESTING_ON=	BUILD_TESTING glaze_DEVELOPER_MODE
CMAKE_TESTING_ARGS=	-DFREEBSD_STAGEDIR_PREFIX=${STAGEDIR}${DATADIR} \
			-DFETCHCONTENT_FULLY_DISCONNECTED:BOOL=OFF

LDFLAGS+=	-pthread

NO_ARCH=	yes

# tests as of 8.4.0: 99% tests passed, 1 tests failed out of 123

.include <bsd.port.mk>
