# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	mcve
PORTVERSION=	7.0.3
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PECL Extension for Interface the MCVE/Monetra API

LIB_DEPENDS=	monetra.7:${PORTSDIR}/devel/libmonetra

LICENSE=	PHP30

USE_PHP=	yes
USE_PHPEXT=	yes
DEFAULT_PHP_VER=53
IGNORE_WITH_PHP=5
CONFIGURE_ARGS+=--with-mcve="${LOCALBASE}"

post-patch:
	${REINPLACE_CMD} -e '/SEARCH_PATH/ s,=",="${LOCALBASE} ${PREFIX} ,' \
		${WRKSRC}/config.m4

.include <bsd.port.mk>
