PORTNAME=	nanodbc
DISTVERSIONPREFIX=	v
DISTVERSION=	2.14.0
CATEGORIES=	databases devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Small C++ wrapper for the native C ODBC API
WWW=		https://nanodbc.github.io/nanodbc/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libodbc.so:databases/unixODBC

USES=		cmake:testing compiler:c++14-lang localbase:ldflags # pkgconfig python:build
USE_LDCONFIG=	yes

USE_GITHUB=	yes

CMAKE_ON=	BUILD_SHARED_LIBS \
		NANODBC_DISABLE_TESTS NANODBC_DISABLE_EXAMPLES
CMAKE_TESTING_ARGS=	-DNANODBC_DISABLE_TESTS=OFF # many tests fail: Data source name not found and no default

.include <bsd.port.mk>
