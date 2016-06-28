# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	uprofiler
PORTVERSION=	0.11.0.20150219
CATEGORIES=	devel
PKGNAMEPREFIX=	php-

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Lightweight profiler for PHP

LICENSE=	APACHE20

BROKEN_powerpc64=	Does not build

USE_GITHUB=	yes
GH_ACCOUNT=	FriendsOfPHP
GH_TAGNAME=	483c1e5

WRKSRC_SUBDIR=	extension
USES=		php:ext tar:tgz
IGNORE_WITH_PHP=	70

.include <bsd.port.mk>
