PORTNAME=	event
PORTVERSION=	3.1.4
CATEGORIES=	devel

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Provides interface to libevent library
WWW=		https://pecl.php.net/package/event

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libevent.so:devel/libevent

USES=		php:pecl ssl
CONFIGURE_ARGS=	--with-openssl-dir=${OPENSSLBASE}
CONFIGURE_ENV+=	OPENSSL_CFLAGS="-I${OPENSSLINC}" OPENSSL_LIBS="-lssl -lcrypto"
USE_PHP=	sockets:build

.include <bsd.port.mk>
