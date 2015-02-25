# Created by: Elias Mandouvalos <ocean@mail.gr>
# $FreeBSD$

PORTNAME=	runkit
PORTVERSION=	0.9
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PECL extension to modify constants, user-defined functions, and classes

LICENSE=	PHP30

USES=		tar:tgz
USE_PHP=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	runkit
IGNORE_WITH_PHP=	54 55 56

CONFIGURE_ARGS=	--enable-runkit=classkit

.include <bsd.port.mk>
