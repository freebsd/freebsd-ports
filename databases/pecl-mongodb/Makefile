# $FreeBSD$

PORTNAME=	mongodb
PORTVERSION=	1.8.1
CATEGORIES=	databases pear

MAINTAINER=	pi@FreeBSD.org
COMMENT=	PECL classes for MongoDB

LICENSE=	APACHE20

USES=		php:pecl ssl
# 8.0 not yet supported, see
# https://github.com/mongodb/mongo-php-driver/issues/1161
# and https://jira.mongodb.org/browse/PHPC-1631
IGNORE_WITH_PHP=80
USE_PHP=	spl:build
CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
