# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	jsonnet
PORTVERSION=	1.1.1
CATEGORIES=	devel
DISTNAME=	JsonNet-${PORTVERSION}

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Google JsonNet for PHP

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjsonnet.so:devel/jsonnet

USES=		php:pecl
USE_PHP=	json:build
CONFIGURE_ARGS=	--with-jsonnet=${LOCALBASE}
IGNORE_WITH_PHP=	71 72 73

.include <bsd.port.mk>
