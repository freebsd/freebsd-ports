PORTNAME=	xdebug
DISTVERSION=	3.4.4
CATEGORIES=	devel pear

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Xdebug extension for PHP
WWW=		https://www.xdebug.org/

LICENSE=	PHP30
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		php:pecl,zend tar:tgz

IGNORE_WITH_PHP=	85

CONFIGURE_ARGS=	--enable-xdebug

SUB_FILES=	pkg-message

.include <bsd.port.mk>
