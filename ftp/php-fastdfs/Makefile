PORTNAME=	fastdfs
DISTVERSION=	6.0.6
CATEGORIES=	ftp
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	daniel@blodan.se
COMMENT=	PHP module for accessing a FastDFS cluster

LICENSE=	GPLv3+

DEPRECATED=	Requires php 7.4 which is set to expire on 2022-11-29
EXPIRATION_DATE=2022-11-28

LIB_DEPENDS=	libfastcommon.so:devel/libfastcommon \
		libfdfsclient.so:ftp/fastdfs

USES=		php:ext

USE_GITHUB=	yes
GH_ACCOUNT=	happyfish100
GH_PROJECT=	fastdfs
GH_TAGNAME=	V6.06
IGNORE_WITH_PHP=	80 81

WRKSRC_SUBDIR=	php_client
CONFIGURE_ENV=	ROOT=${LOCALBASE}

PHP_MODNAME=	fastdfs_client

.include <bsd.port.mk>
