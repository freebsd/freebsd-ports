# New ports collection makefile for:	php5-thrift
# Date created:	   Sat May  8 12:33:05 MSD 2010
# Whom:		   Ilya Bakulin <webmaster@kibab.com>
#
# $FreeBSD$
#

PORTNAME=	thrift
PORTVERSION=	${THRIFT_PORTVERSION}
CATEGORIES=	devel
PKGNAMEPREFIX=	php5-
DISTFILES=	# empty

MAINTAINER=	webmaster@kibab.com
COMMENT=	PHP interface to Thrift

EXTRACT_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/devel/thrift:extract

USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	thrift_protocol

WRKSRC=		${WRKDIR}/php/src/ext/thrift_protocol

post-extract:
	${LN} -sfh \
		`${MAKE} -C ${PORTSDIR}/devel/thrift -V WRKSRC`/lib/php \
		${WRKDIR}

.include "../thrift/bsd.thrift.mk"
.include <bsd.port.mk>
