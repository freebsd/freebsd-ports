# Created by: Volodymyr Kostyrko <c.kworr@gmail.com>
# $FreeBSD$

PORTNAME=	scream
DISTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	c.kworr@gmail.com
COMMENT=	Break the silence operator

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	PHP301

USES=		php:pecl
IGNORE_WITH_PHP=	71 72 73

test: build
	@(cd ${WRKSRC} && ${MAKE} test)

.include <bsd.port.mk>
