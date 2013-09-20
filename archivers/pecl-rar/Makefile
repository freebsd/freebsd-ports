# Created by: Chin-San Huang <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	rar
PORTVERSION=	3.0.1
CATEGORIES=	archivers pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PECL extension to create and read RAR files

LICENSE=	PHP301

NO_STAGE=	yes
USE_PHP=	spl
USE_PHPEXT=	yes
USE_PHP_BUILD=	yes

CONFIGURE_ARGS=	--enable-rar

.include <bsd.port.mk>
