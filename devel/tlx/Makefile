PORTNAME=	tlx
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of C++ data structures, algorithms, miscellaneous helpers
WWW=		https://github.com/tlx/tlx

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++20-lang
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_ON=	TLX_BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	TLX_BUILD_TESTS # 1 test fails, see https://github.com/tlx/tlx/issues/46

.include <bsd.port.mk>
