PORTNAME=	pcov
PORTVERSION=	1.0.12
CATEGORIES=	devel

MAINTAINER=	einar@isnic.is
COMMENT=	Self contained php-code-coverage compatible driver for PHP
WWW=		https://pecl.php.net/package/pcov \
		https://github.com/krakjoe/pcov

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpcre2-8.so:devel/pcre2

USES=		php:phpize,pecl pkgconfig
IGNORE_WITH_PHP=	86

CFLAGS+=	-I${PREFIX}/include
CONFIGURE_ARGS=	--enable-pcov

.include <bsd.port.mk>
