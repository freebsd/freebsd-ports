# Created by: Jens Rehsack <rehsack@liwing.de>
# $FreeBSD$

PORTNAME=	xdebug
PORTVERSION=	2.5.0
CATEGORIES=	devel
MASTER_SITES=	https://xdebug.org/files/
PKGNAMEPREFIX=	php-

MAINTAINER=	freebsd-ports-maintainers@intermedix.com
COMMENT=	Xdebug extension for PHP

LICENSE=	PHP30
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFIGURE_ARGS=	--enable-xdebug
USES=		php:zend tar:tgz

SUB_FILES=	pkg-message

.include <bsd.port.mk>
