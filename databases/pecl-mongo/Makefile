# Created by: wen
# $FreeBSD$

PORTNAME=	mongo
PORTVERSION=	1.6.16
CATEGORIES=	databases pear

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	PECL classes for Mongo Database Driver

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	APACHE20

BUILD_DEPENDS=	re2c>=0.13.4:devel/re2c

USES=		php:pecl
USE_PHP=	spl:build
CONFIGURE_ARGS=	--enable-mongo
SUB_FILES=	pkg-message
IGNORE_WITH_PHP=	71 72 73

.include <bsd.port.mk>
