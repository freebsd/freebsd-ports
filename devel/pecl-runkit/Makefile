# Created by: Elias Mandouvalos <ocean@mail.gr>
# $FreeBSD$

PORTNAME=	runkit
PORTVERSION=	0.9
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DISTNAME=	runkit-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PECL extension to modify constants, user-defined functions, and classes

USE_PHP=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	runkit
DEFAULT_PHP_VER=53

CONFIGURE_ARGS=	--enable-runkit=classkit

NO_STAGE=	yes
.include <bsd.port.mk>
