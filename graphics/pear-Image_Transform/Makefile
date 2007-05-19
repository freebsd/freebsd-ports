# Ports collection makefile for:  pear-Image_Transform
# Date created:			  01 Mai 2007
# Whom:				  Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Image_Transform
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	graphics www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A standard interface to manipulate images using different libraries.

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	gd

CATEGORY=	Image
FILES=		Transform.php Driver/ColorsDefs.php Driver/GD.php Driver/GD1.php \
		Driver/IM.php Driver/IMAGETYPE.php Driver/Imagick.php \
		Driver/Imagick2.php Driver/Imlib.php Driver/NetPBM.php \
		Driver/image_type_to_mime_type.php Driver/Imagick/ImageTypes.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
