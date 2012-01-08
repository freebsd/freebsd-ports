# New ports collection makefile for:	php5-msgpack
# Date created:				2012-01-02
# Whom:					Valery Komarov <komarov@valerka.net>
#
# $FreeBSD$
#

PORTNAME=	msgpack
PORTVERSION=	0.5.3
CATEGORIES=	devel
MASTER_SITES=	http://php-msgpack.googlecode.com/files/
PKGNAMEPREFIX=	php5-
DISTNAME=	php-msgpack-${PORTVERSION}

MAINTAINER=	komarov@valerka.net
COMMENT=	PHP extension for interfacing with MessagePack

WRKSRC=		${WRKDIR}/php-msgpack

USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	msgpack

BUILD_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/session.so:${PORTSDIR}/www/php5-session
RUN_DEPENDS:=	${BUILD_DEPENDS}

.include <bsd.port.mk>
