PORTNAME=	libzip
PORTVERSION=	1.9.2
CATEGORIES=	archivers devel
MASTER_SITES=	https://github.com/nih-at/${PORTNAME}/releases/download/v${DISTVERSION}/ \
		https://libzip.org/download/

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	C library for reading, creating, and modifying ZIP archives

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cmake cpe perl5 ssl tar:xz
CPE_VENDOR=	nih
USE_LDCONFIG=	yes
USE_PERL5=	test

TEST_TARGET=	test

CMAKE_OFF=	ENABLE_COMMONCRYPTO ENABLE_GNUTLS ENABLE_MBEDTLS

.include <bsd.port.mk>
