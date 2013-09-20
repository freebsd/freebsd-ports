# Created by: chinsan <chinsan@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bcompiler
PORTVERSION=	1.0.2
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A bytecode compiler extension

USE_PHP=	bz2
USE_PHPEXT=	yes
DEFAULT_PHP_VER=53
IGNORE_WITH_PHP=5

CONFIGURE_ARGS=	--enable-bcompiler

NO_STAGE=	yes
.include <bsd.port.mk>
