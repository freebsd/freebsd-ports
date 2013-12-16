# Created by: Ditesh Shashikant Gathani <ditesh@gathani.org>
# $FreeBSD$

PORTNAME=	spl_types
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DISTNAME=	SPL_Types-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A PECL extension of a collection of special typehandling classes

LICENSE=	PHP301

USE_PHP=	spl
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	spl_types
DEFAULT_PHP_VER=53
IGNORE_WITH_PHP=5

CONFIGURE_ARGS=	--enable-spl-types
CFLAGS+=	-I${LOCALBASE}/include

NO_STAGE=	yes
.include <bsd.port.mk>
