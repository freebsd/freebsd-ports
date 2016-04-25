# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	json_post
PORTVERSION=	1.0.1
CATEGORIES=	devel
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	JSON POST handler in PHP

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	Does not build

USES=		tar:tgz
USE_PHP=	json
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes

.include <bsd.port.mk>
