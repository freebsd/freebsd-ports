# New ports collection makefile for:	xdebug
# Date created:				Thu Apr  3 12:44:57 GMT 2003
# Whom:					Jens Rehsack <rehsack@liwing.de>
#
# $FreeBSD$
#

PORTNAME=	xdebug
PORTVERSION=	1.3.0
CATEGORIES=	devel
MASTER_SITES=	http://files.derickrethans.nl/
PKGNAMEPREFIX=	php-
EXTRACT_SUFX=	.tgz

MAINTAINER=	rehsack@liwing.de
COMMENT=	Xdebug extension for PHP

USE_PHP=	yes
USE_PHPIZE=	yes
CONFIGURE_ARGS=	--enable-xdebug --with-php-config=${PREFIX}/bin/php-config
PKGMESSAGE=	${WRKDIR}/pkg-message

post-build:
	@${SED} "s|%%PREFIX%%|${PREFIX}|g;s|%%PHP_EXT_DIR%%|${PHP_EXT_DIR}|g" \
		< ${.CURDIR}/pkg-message > ${PKGMESSAGE}

do-install:
	@${MKDIR} ${PREFIX}/lib/php/${PHP_EXT_DIR}
	@${INSTALL_DATA} ${WRKSRC}/modules/xdebug.so \
		${PREFIX}/lib/php/${PHP_EXT_DIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
