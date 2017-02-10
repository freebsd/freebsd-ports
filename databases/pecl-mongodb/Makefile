# $FreeBSD$

PORTNAME=	mongodb
PORTVERSION=	1.2.3
CATEGORIES=	databases pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	pi@FreeBSD.org
COMMENT=	PECL classes for MongoDB

LICENSE=	APACHE20

USES=		php:ext ssl tar:tgz
USE_PHP=	spl:build
CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT:Mlibressl*}
IGNORE=		LibreSSL not supported until version 1.3.x
.endif

.include <bsd.port.post.mk>
