# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	qb
PORTVERSION=	2.4.0
PORTREVISION=	4
CATEGORIES=	devel

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	PHP Accelerator designed mainly for graphic work

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	PHP301

BROKEN_powerpc64=	fails to build: Killing runaway build after 7200 seconds with no output

USES=		php:pecl
IGNORE_WITH_PHP=	71 72 73

.include <bsd.port.mk>
