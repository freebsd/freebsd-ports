# Created by: Jens Rehsack <rehsack@liwing.de>
# $FreeBSD$

PORTNAME=	xdebug
PORTVERSION=	2.5.5
CATEGORIES=	devel
MASTER_SITES=	https://xdebug.org/files/
PKGNAMEPREFIX=	php-

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Xdebug extension for PHP

LICENSE=	PHP30
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFIGURE_ARGS=	--enable-xdebug
USES=		php:zend tar:tgz
IGNORE_WITH_PHP=	72

SUB_FILES=	pkg-message

.include <bsd.port.mk>
