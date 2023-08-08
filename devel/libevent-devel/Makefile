PORTNAME=	libevent
DISTVERSION=	2.2.1
DISTVERSIONSUFFIX=	-alpha-dev
CATEGORIES=	devel
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/release-${DISTVERSION}-alpha/
PKGNAMESUFFIX=	-devel

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	API for executing callback functions on events or timeouts
WWW=		https://libevent.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe libtool pathfix pkgconfig python:env shebangfix
SHEBANG_FILES=	event_rpcgen.py
GNU_CONFIGURE=	yes
CPE_VENDOR=	libevent_project
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	${PORTNAME}

OPTIONS_DEFINE=	OPENSSL THREADS MBEDTLS
OPTIONS_DEFAULT=	OPENSSL THREADS
OPTIONS_SUB=	yes

MBEDTLS_LIB_DEPENDS=	libmbedtls.so:security/mbedtls
MBEDTLS_USES=	localbase:ldflags
MBEDTLS_CONFIGURE_OFF=	--disable-mbedtls

OPENSSL_USES=	ssl
OPENSSL_CONFIGURE_OFF=	--disable-openssl

THREADS_CONFIGURE_OFF=	--disable-thread-support

.include <bsd.port.mk>
