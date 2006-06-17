# New ports collection makefile for:	magickwand
# Date created:			04 Apr 2006
# Whom:				Rick van der Zwet <rick@wzoeterwoude.net>
#
# $FreeBSD$
#

PORTNAME=	magickwand
PORTVERSION=	0.1.8
CATEGORIES=	graphics www
MASTER_SITES=	http://www.magickwand.org/download/php/
MASTER_SITES=+	http://imagemagick.linux-mirror.org/download/php/

MAINTAINER=	rick@wzoeterwoude.net
COMMENT=	A php extension to manipulate images using MagickWand API

LIB_DEPENDS=	Magick.10:${PORTSDIR}/graphics/ImageMagick

USE_PHP=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS=	--with-imagick=${LOCALBASE}

WRKSRC=	${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
