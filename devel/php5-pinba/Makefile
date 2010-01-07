# New ports collection makefile for:	php5-pinba
# Date created:				24 Dec 2009
# Whom:					raven428 <raven428@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pinba
PORTVERSION=	2009.12.24
CATEGORIES=	devel
MASTER_SITES=	http://aston2.com/~raven/unix/pinba/ \
 		http://mks-chel.ru/~raven/FreeBSD/pinba/
PKGNAMEPREFIX=	php5-
DISTNAME=	pinba_extension-200912240755

MAINTAINER=	raven428@gmail.com
COMMENT=	PHP-extension part of statistics server for PHP

BUILD_DEPENDS=	${LOCALBASE}/include/google/protobuf/descriptor.h:${PORTSDIR}/devel/protobuf

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_PHP=	yes
USE_PHPEXT=	yes
DEFAULT_PHP_VER=5
BROKEN_WITH_PHP=4
PHP_MODNAME=	pinba

.include <bsd.port.mk>
