# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	jsonc
PORTVERSION=	1.3.1
CATEGORIES=	devel
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	PECL extension for JSON manipulation

LICENSE=	PHP301

CONFLICTS_INSTALL=	php54-json-5* php55-json-5* php5-json-5*

CONFIGURE_ARGS=	--with-jsonc
USE_PHP=	yes
USE_PHPEXT=	yes
IGNORE_WITH_PHP=52 53

.include <bsd.port.mk>
