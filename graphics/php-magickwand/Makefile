# New ports collection makefile for:	php-magickwand
# Date created:			05 Jan 2005
# Whom:				<mark@goodstorm.com>
#
# $FreeBSD$
#

PORTNAME=	magickwand
PORTVERSION=	1.0.8
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.magickwand.org/download/php/
PKGNAMEPREFIX=	php-
DISTNAME=	MagickWandForPHP-${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A PHP extension to manipulate images

LIB_DEPENDS=	MagickWand.2:${PORTSDIR}/graphics/ImageMagick

USE_PHP=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS=	--with-magickwand=${LOCALBASE}

.include <bsd.port.mk>
