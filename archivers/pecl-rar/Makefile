PORTNAME=	rar
PORTVERSION=	4.2.0
PORTREVISION=	1
CATEGORIES=	archivers pear

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	PECL extension to create and read RAR files
WWW=		https://pecl.php.net/package/rar

LICENSE=	PHP301

DEPRECATED=	Requires php80 which is set to expire on 2023-11-26
EXPIRATION_DATE=	2023-12-31

USES=		compiler:c11 php:build,pecl
IGNORE_WITH_PHP=	81 82 83

CONFIGURE_ARGS=	--enable-rar

.include <bsd.port.mk>
