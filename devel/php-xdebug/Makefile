# New ports collection makefile for:	xdebug
# Date created:				Thu Apr  3 12:44:57 GMT 2003
# Whom:					Jens Rehsack <rehsack@liwing.de>
#
# $FreeBSD$
#

PORTNAME=	xdebug
PORTVERSION=	2.1.2
CATEGORIES=	devel
MASTER_SITES=	http://www.xdebug.org/files/
PKGNAMEPREFIX=	php-
EXTRACT_SUFX=	.tgz

MAINTAINER=	wmoran@collaborativefusion.com
COMMENT=	Xdebug extension for PHP

USE_PHP=	yes
USE_PHPIZE=	yes
CONFIGURE_ARGS=	--enable-xdebug --with-php-config=${PREFIX}/bin/php-config
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_LIST=	PHP_EXT_DIR=${PHP_EXT_DIR}

do-install:
	@${MKDIR} ${PREFIX}/lib/php/${PHP_EXT_DIR}
	@${INSTALL_DATA} ${WRKSRC}/modules/xdebug.so \
		${PREFIX}/lib/php/${PHP_EXT_DIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
