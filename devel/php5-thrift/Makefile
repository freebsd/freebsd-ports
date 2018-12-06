# Created by: Ilya Bakulin <webmaster@kibab.com>
# $FreeBSD$

PORTNAME=	thrift
PORTVERSION=	${THRIFT_PORTVERSION}
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	APACHE/thrift/${PORTVERSION}
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	webmaster@kibab.com
COMMENT=	PHP interface to Thrift

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

USES=		php:ext
PHP_MODNAME=	thrift_protocol
IGNORE_WITH_PHP=	71 72 73

DISTINFO_FILE=	${.CURDIR}/../thrift/distinfo
WRKSRC_SUBDIR=	lib/php/src/ext/thrift_protocol

.include "${.CURDIR}/../thrift/bsd.thrift.mk"
.include <bsd.port.mk>
