# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	spread
PORTVERSION=	2.1.0
PORTREVISION=	2
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Php Interface to the Spread Toolkit API

LICENSE=	PHP301

BUILD_DEPENDS=	${LOCALBASE}/include/sp.h:net/spread4
RUN_DEPENDS=	${LOCALBASE}/include/sp.h:net/spread4

USES=		php:ext tar:tgz
IGNORE_WITH_PHP=	56 70

CONFIGURE_ARGS+=	--with-spread=${LOCALBASE}

.include <bsd.port.mk>
