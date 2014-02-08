# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	horde_lz4
PORTVERSION=	1.0.0
CATEGORIES=	archivers pear
MASTER_SITES=	http://pear.horde.org/get/
PKGNAMEPREFIX=	php-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Horde LZ4 Compression Extension for php

USE_PHP=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS=	--enable-horde_lz4

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/php/20100525/horde_lz4.so

.include <bsd.port.mk>
