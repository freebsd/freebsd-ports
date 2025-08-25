PORTNAME=	nanodbc
DISTVERSIONPREFIX=	v
DISTVERSION=	2.14.0
CATEGORIES=	databases devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Small C++ wrapper for the native C ODBC API
WWW=		https://nanodbc.github.io/nanodbc/ \
		https://github.com/nanodbc/nanodbc

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_13=	compilation fails with clang-19, see https://github.com/nanodbc/nanodbc/issues/421
BROKEN_FreeBSD_15=	compilation fails with clang-19, see https://github.com/nanodbc/nanodbc/issues/421

LIB_DEPENDS=	libodbc.so:databases/unixODBC

USES=		cmake:testing compiler:c++14-lang localbase:ldflags # pkgconfig python:build
USE_LDCONFIG=	yes
USE_CXXSTD=	c++14 # fix build broken by deprecated feature std::char_traits, see https://github.com/nanodbc/nanodbc/issues/387

USE_GITHUB=	yes

CMAKE_ON=	BUILD_SHARED_LIBS \
		NANODBC_DISABLE_TESTS NANODBC_DISABLE_EXAMPLES
CMAKE_TESTING_ARGS=	-DNANODBC_DISABLE_TESTS=OFF # many tests fail: Data source name not found and no default

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=deprecated-declarations -Wno-error=unused-command-line-argument
.endif

.include <bsd.port.mk>
