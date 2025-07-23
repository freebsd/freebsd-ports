PORTNAME=	libzip
DISTVERSION=	1.11.2
CATEGORIES=	archivers devel
MASTER_SITES=	https://github.com/nih-at/${PORTNAME}/releases/download/v${DISTVERSION}/ \
		https://libzip.org/download/

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	C library for reading, creating, and modifying ZIP archives
WWW=		https://libzip.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cmake cpe ssl tar:xz
CPE_VENDOR=	nih
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_OSSFUZZ \
		BUILD_REGRESS \
		ENABLE_COMMONCRYPTO \
		ENABLE_GNUTLS \
		ENABLE_MBEDTLS
CMAKE_ON=	CMAKE_SKIP_RPATH

.include <bsd.port.mk>
