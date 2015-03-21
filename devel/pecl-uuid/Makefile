# Created by: Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	uuid
PORTVERSION=	1.0.2
CATEGORIES=	devel
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	UUID extension

DEPRECATED=	requires php53, security EOL reached 14 Aug 2014
EXPIRATION_DATE=	2015-04-15

LIB_DEPENDS=	libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid

CONFIGURE_ARGS=	--with-uuid=${LOCALBASE} CFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib
PHP_MODNAME=	${PORTNAME}
USE_PHP=	yes
USE_PHPEXT=	yes
IGNORE_WITH_PHP=5 55 56

.include <bsd.port.mk>
