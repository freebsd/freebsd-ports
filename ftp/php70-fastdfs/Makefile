# $FreeBSD$

PORTNAME=	fastdfs
PORTVERSION=	5.0.11
CATEGORIES=	ftp
PKGNAMEPREFIX=	php70-

MAINTAINER=	daniel@blodan.se
COMMENT=	PHP 7 module for accessing a FastDFS cluster

LICENSE=	GPLv3+

LIB_DEPENDS=	libfastcommon.so:devel/libfastcommon \
		libfdfsclient.so:ftp/fastdfs

USE_GITHUB=	yes
GH_ACCOUNT=	happyfish100
GH_PROJECT=	fastdfs
GH_TAGNAME=	1e50b4f

USES=			php:ext
IGNORE_WITH_PHP=	56 71
PHP_VER=		70

WRKSRC_SUBDIR=	php_client

PHP_MODNAME=	fastdfs_client

.include <bsd.port.mk>
