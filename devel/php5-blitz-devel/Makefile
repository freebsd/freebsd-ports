# Created by: Valery Komarov <komarov@valerka.net>
# $FreeBSD$

PORTNAME=	blitz-devel
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://alexeyrybak.com/blitz/
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}
DISTNAME=	blitz-${PORTVERSION}-devel

MAINTAINER=	komarov@valerka.net
COMMENT=	PHP templating engine

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

CONFLICTS=	php5-blitz-0.6*

USES=		php:ext
PHP_MODNAME=	blitz
IGNORE_WITH_PHP=	71 72 73

.include <bsd.port.mk>
