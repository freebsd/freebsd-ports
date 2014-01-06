# Created by: johnpupu <johnpupu@gmail.com>
# $FreeBSD$

PORTNAME=	leveldb
PORTVERSION=	0.1.4
CATEGORIES=	databases
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	johnpupu@gmail.com
COMMENT=	This extension is a PHP binding for Google LevelDB

LICENSE=	PHP301

LIB_DEPENDS=	libleveldb.so:${PORTSDIR}/databases/leveldb

USE_PHP=	yes
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes
USE_PHPIZE=	yes

.include <bsd.port.mk>
