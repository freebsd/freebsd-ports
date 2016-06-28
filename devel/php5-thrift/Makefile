# Created by: Ilya Bakulin <webmaster@kibab.com>
# $FreeBSD$

PORTNAME=	thrift
PORTVERSION=	${THRIFT_PORTVERSION}
CATEGORIES=	devel
MASTER_SITES=	APACHE/thrift/${PORTVERSION}
PKGNAMEPREFIX=	php5-

MAINTAINER=	webmaster@kibab.com
COMMENT=	PHP interface to Thrift

USES=		php:ext
PHP_MODNAME=	thrift_protocol
IGNORE_WITH_PHP=	70

DISTINFO_FILE=	${.CURDIR}/../thrift/distinfo
WRKSRC_SUBDIR=	lib/php/src/ext/thrift_protocol

.include "${.CURDIR}/../thrift/bsd.thrift.mk"
.include <bsd.port.mk>
