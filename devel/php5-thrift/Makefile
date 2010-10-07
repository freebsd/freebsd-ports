# New ports collection makefile for:	thrift
# Date created:	   Sat May  8 12:33:05 MSD 2010
# Whom:		   Ilya Bakulin <webmaster@kibab.com>
#
# $FreeBSD$
#

PORTNAME=	thrift
PORTVERSION=	0.2.0
CATEGORIES=	devel
PKGNAMEPREFIX=	php5-
DISTFILES=

MAINTAINER=	webmaster@kibab.com
COMMENT=	PHP interface to Thrift

EXTRACT_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/devel/thrift:extract

USE_PHP=yes
USE_PHPIZE=yes
USE_PHPEXT=yes
PHP_MODNAME=thrift_protocol

WRKSRC=${WRKDIR}/php/src/ext/thrift_protocol

post-extract:
	${LN} -sfh \
	`cd ${PORTSDIR}/devel/thrift && ${MAKE} -V WRKSRC`/lib/php ${WRKDIR}
.include <bsd.port.mk>
