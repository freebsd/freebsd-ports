# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	jsonnet
PORTVERSION=	1.1.1
CATEGORIES=	devel
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DISTNAME=	JsonNet-${PORTVERSION}
DIST_SUBDIR=	PECL

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Google JsonNet for PHP

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjsonnet.so:devel/jsonnet

BROKEN_powerpc64=	does not build

USES=		php:ext tar:tgz
USE_PHP=	json:build
CONFIGURE_ARGS=	--with-jsonnet=${LOCALBASE}
IGNORE_WITH_PHP=	70

.include <bsd.port.mk>
