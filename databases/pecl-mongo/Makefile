# Ports collection makefile for:  pear-mongo
# Date created:			  23 Nov, 2009
# Whom:				  wen
#
# $FreeBSD$
#

PORTNAME=	mongo
PORTVERSION=	1.0.2
CATEGORIES=	databases pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PECL classes for Mongo Database Driver

BUILD_DEPENDS+=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/spl.so:${PORTSDIR}/devel/php5-spl

USE_PHP=	yes
USE_PHP_BUILD=	spl
USE_PHPIZE=	yes
USE_PHPEXT=	yes

.include <bsd.port.mk>
