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

WRKSRC=		${WRKDIR}/${GH_PROJECT}-${GH_TAGNAME_EXTRACT}/extension
USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes
USES=		tar:tgz
IGNORE_WITH_PHP=	70

.include <bsd.port.mk>
