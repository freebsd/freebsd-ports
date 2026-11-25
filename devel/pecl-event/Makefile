PORTNAME=	event
PORTVERSION=	3.2.0
CATEGORIES=	devel

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Provides interface to libevent library
WWW=		https://pecl.php.net/package/event

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libevent.so:devel/libevent

USES=		pkgconfig php:pecl ssl
CONFIGURE_ARGS=	--with-openssl-dir=${OPENSSLBASE}
CONFIGURE_ENV+=	OPENSSL_CFLAGS="-I${OPENSSLINC}" OPENSSL_LIBS="-lssl -lcrypto"
USE_PHP=	sockets:build
IGNORE_WITH_PHP=	86

post-patch:
	@${REINPLACE_CMD} -e 's|/lib/pkgconfig|/libdata/pkgconfig|g' \
		${WRKSRC}/config.m4

.include <bsd.port.mk>
