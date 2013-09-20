# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	id3
PORTVERSION=	0.2
CATEGORIES=	audio pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Extension to read and write ID3 tags in MP3 files

USE_PHP=	yes
NO_STAGE=	yes
USE_PHPEXT=	yes
DEFAULT_PHP_VER=53
IGNORE_WITH_PHP=5

CONFIGURE_ARGS=	--enable-id3

.include <bsd.port.mk>
