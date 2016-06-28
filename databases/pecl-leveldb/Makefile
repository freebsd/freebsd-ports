# Created by: johnpupu <johnpupu@gmail.com>
# $FreeBSD$

PORTNAME=	leveldb
PORTVERSION=	0.1.5
CATEGORIES=	databases
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	johnpupu@gmail.com
COMMENT=	This extension is a PHP binding for Google LevelDB

LICENSE=	PHP301

LIB_DEPENDS=	libleveldb.so:databases/leveldb

USES=		php:ext tar:tgz
IGNORE_WITH_PHP=	70

.include <bsd.port.mk>
