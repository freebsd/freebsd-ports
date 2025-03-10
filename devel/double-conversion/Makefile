PORTNAME=	double-conversion
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3.1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Binary-decimal and decimal-binary routines for IEEE doubles
WWW=		https://github.com/google/double-conversion

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	google

CMAKE_ON=	BUILD_SHARED_LIBS

# tests as of 3.3.1: 100% tests passed, 0 tests failed out of 9

.include <bsd.port.mk>
