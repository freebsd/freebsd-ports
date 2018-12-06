# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	judy
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	devel
DISTNAME=	Judy-${PORTVERSION}

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	PHP Judy implements sparse dynamic arrays

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	PHP301

RUN_DEPENDS=	Judy>=0:devel/judy
BUILD_DEPENDS=	Judy>=0:devel/judy

CONFIGURE_ARGS=	--with-judy=${LOCALBASE}
USES=		php:pecl
IGNORE_WITH_PHP=	71 72 73

.include <bsd.port.mk>
