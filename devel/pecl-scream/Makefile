# Created by: Volodymyr Kostyrko <c.kworr@gmail.com>
# $FreeBSD$

PORTNAME=	scream
DISTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	c.kworr@gmail.com
COMMENT=	Break the silence operator

LICENSE=	PHP301

USES=		php:pecl
IGNORE_WITH_PHP=	70 71 72

test: build
	@(cd ${WRKSRC} && ${MAKE} test)

.include <bsd.port.mk>
