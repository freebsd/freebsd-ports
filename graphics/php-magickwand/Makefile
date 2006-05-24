# New ports collection makefile for:	php-magickwand
# Date created:			05 Jan 2005
# Whom:				<mark@goodstorm.com>
#
# $FreeBSD$
#

PORTNAME=	magickwand
PORTVERSION=	0.1.8
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.magickwand.org/download/php/
PKGNAMEPREFIX=	php-

MAINTAINER=	mark@goodstorm.com
COMMENT=	A PHP extension to manipulate images

LIB_DEPENDS=	Magick.10:${PORTSDIR}/graphics/ImageMagick

USE_PHP=	yes
USE_PHPEXT=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

CONFIGURE_ARGS=	--with-magickwand=${LOCALBASE}

.include <bsd.port.mk>
