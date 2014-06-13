# Created by: <mark@goodstorm.com>
# $FreeBSD$

PORTNAME=	magickwand
PORTVERSION=	1.0.9
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.magickwand.org/download/php/
PKGNAMEPREFIX=	php-
DISTNAME=	MagickWandForPHP-${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PHP extension to manipulate images

LIB_DEPENDS=	MagickWand:${PORTSDIR}/graphics/ImageMagick

USE_PHP=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS=	--with-magickwand=${LOCALBASE}

.include <bsd.port.mk>
