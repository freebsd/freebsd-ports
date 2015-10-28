# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	jsonnet
PORTVERSION=	1.0.0
CATEGORIES=	devel
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DISTNAME=	JsonNet-${PORTVERSION}
DIST_SUBDIR=	PECL

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Google JsonNet for PHP

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjsonnet.so:${PORTSDIR}/devel/jsonnet

USES=		tar:tgz
USE_PHP=	json
USE_PHPEXT=	yes
USE_PHP_BUILD=	yes
CONFIGURE_ARGS=	--with-jsonnet=${LOCALBASE}

.include <bsd.port.mk>
