# Created by: vanilla@
# $FreeBSD$

PORTNAME=	swoole
PORTVERSION=	1.7.22
CATEGORIES=	devel net
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Asynchronous & concurrent & distributed networking framework

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		tar:tgz
CFLAGS+=	-I${LOCALBASE}/include
PHP_MODNAME=	${PORTNAME}
USE_PHP=	pcre
USE_PHPEXT=	yes

.include <bsd.port.mk>
