# $FreeBSD$

PORTNAME=	rrd
DISTVERSION=	1.1.3
CATEGORIES=	databases pear

MAINTAINER=	daniel@blodan.se
COMMENT=	PHP bindings to rrd tool system

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	PHP301

IGNORE_WITH_PHP=71 72 73
LIB_DEPENDS=	librrd.so:databases/rrdtool
USES=		php:pecl localbase pkgconfig

.include <bsd.port.mk>
