PORTNAME=	libzippp
DISTVERSIONPREFIX=	${PORTNAME}-v
DISTVERSION=	6.0-1.9.2
CATEGORIES=	archivers devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ wrapper for libzip
WWW=		https://github.com/ctabin/libzippp

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENCE

LIB_DEPENDS=	libzip.so:archivers/libzip

USES=		cmake:testing

USE_GITHUB=	yes
GH_ACCOUNT=	ctabin

CMAKE_ON=		BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	LIBZIPPP_BUILD_TESTS

.include <bsd.port.mk>
