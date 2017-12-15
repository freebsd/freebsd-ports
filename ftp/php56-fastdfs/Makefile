# $FreeBSD$

PORTNAME=	fastdfs
DISTVERSION=	5.0.11
CATEGORIES=	ftp
PKGNAMEPREFIX?=	php56-
IGNORE_WITH_PHP?=	70 71 72

MAINTAINER=	daniel@blodan.se
COMMENT?=	PHP 5.6 module for accessing a FastDFS cluster

LICENSE=	GPLv3+

LIB_DEPENDS=	libfastcommon.so:devel/libfastcommon \
		libfdfsclient.so:ftp/fastdfs

USE_GITHUB=	yes
GH_ACCOUNT=	happyfish100
GH_PROJECT=	fastdfs
GH_TAGNAME=	1e50b4f

USES=			php:ext
PHP_VER?=		56

WRKSRC_SUBDIR=	php_client
CONFIGURE_ENV=	ROOT=${LOCALBASE}

PHP_MODNAME=	fastdfs_client

.include <bsd.port.mk>
