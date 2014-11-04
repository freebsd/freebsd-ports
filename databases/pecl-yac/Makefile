# Created by: John Chen <johnpupu@gmail.com>
# $FreeBSD$

PORTNAME=	yac
PORTVERSION=	0.9.2
CATEGORIES=	databases
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	johnpupu@gmail.com
COMMENT=	Shared and lockless memory user data cache for PHP

LICENSE=	PHP301

SUB_FILES=	pkg-message
USE_PHP=	yes
USE_PHPEXT=	yes
USE_PHPIZE=	yes
USE_PHP_BUILD=	yes
USES=		tar:tgz

CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--with-php-config=${PREFIX}/bin/php-config

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}/yac.so

.include <bsd.port.mk>
