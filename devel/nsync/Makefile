PORTNAME=	nsync
DISTVERSION=	1.21.0
CATEGORIES=	devel

MAINTAINER=	amzo1337@gmail.com
COMMENT=	C library that exports various synchronization primitives like mutexes

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	google
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
