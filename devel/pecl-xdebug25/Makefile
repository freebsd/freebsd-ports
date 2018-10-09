# Created by: Jens Rehsack <rehsack@liwing.de>
# $FreeBSD$

PORTNAME=	xdebug
PORTVERSION=	2.5.5
PORTREVISION=	1
CATEGORIES=	devel pear
PKGNAMESUFFIX=	25

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Xdebug extension for PHP

LICENSE=	PHP30
LICENSE_FILE=	${WRKSRC}/LICENSE

IGNORE_WITH_PHP=	72 73

CONFIGURE_ARGS=	--enable-xdebug
USES=		php:pecl,zend

SUB_FILES=	pkg-message

.include <bsd.port.mk>
