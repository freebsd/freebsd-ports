# Created by: vanilla@
# $FreeBSD$

PORTNAME=	swoole
PORTVERSION=	1.7.8
CATEGORIES=	devel net
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Asynchronous & concurrent & distributed networking framework

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

CFLAGS+=	-I${LOCALBASE}/include
PHP_MODNAME=	${PORTNAME}
USE_PHP=	pcre
USE_PHPEXT=	yes

.include <bsd.port.mk>
