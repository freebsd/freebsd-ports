# Created by: Luca Pizzamiglio <luca.pizzamiglio@trivago.com>
# $FreeBSD$

PORTNAME=	xdebug
DISTVERSION=	2.7.2
CATEGORIES=	devel pear

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Xdebug extension for PHP

LICENSE=	PHP30
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFIGURE_ARGS=	--enable-xdebug
USES=		php:pecl,zend tar:tgz
IGNORE_WITH_PHP=	74

SUB_FILES=	pkg-message

.include <bsd.port.mk>
