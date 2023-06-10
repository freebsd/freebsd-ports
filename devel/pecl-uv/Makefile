PORTNAME=	uv
PORTVERSION=	0.2.4
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	PHP wrapper for libuv
WWW=		https://pecl.php.net/package/uv

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Requires php80 which is set to expire on 2023-11-26
EXPIRATION_DATE=	2023-12-31

LIB_DEPENDS=	libuv.so:devel/libuv

USES=		php:pecl
IGNORE_WITH_PHP=	81 82 83

.include <bsd.port.mk>
