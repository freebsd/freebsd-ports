PORTNAME=	APCu_bc
PORTVERSION=	1.0.5
CATEGORIES=	devel
DISTNAME=	${PORTNAME:tl}-${PORTVERSION}

MAINTAINER=	me@skylord.ru
COMMENT=	APCu Backwards Compatibility Module

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Requires php 7.4 which is set to expire on 2022-11-29
EXPIRATION_DATE=2022-11-28

BUILD_DEPENDS=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/apcu.so:devel/pecl-APCu@${PHP_FLAVOR}

USES=		localbase php:pecl

IGNORE_WITH_PHP=	80 81
PHP_MODNAME=	apc
PHP_MOD_PRIO=30

CONFLICTS_INSTALL=	pecl-APC

.include <bsd.port.mk>
