# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	mcve
PORTVERSION=	7.0.3
PORTREVISION=	1
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PECL Extension for Interface the MCVE/Monetra API

LICENSE=	PHP30

LIB_DEPENDS=	libmonetra.so:devel/libmonetra

USES=		tar:tgz
USE_OPENSSL=	yes
USE_PHP=	yes
USE_PHPEXT=	yes
IGNORE_WITH_PHP=	56 70
CONFIGURE_ARGS+=	--with-mcve="${LOCALBASE}"

post-patch:
	${REINPLACE_CMD} -e '/SEARCH_PATH/ s,=",="${LOCALBASE} ${PREFIX} ,' \
		${WRKSRC}/config.m4

.include <bsd.port.mk>
