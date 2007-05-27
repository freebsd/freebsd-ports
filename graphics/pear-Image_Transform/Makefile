# Ports collection makefile for:  pear-Image_Transform
# Date created:			  01 Mai 2007
# Whom:				  Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Image_Transform
PORTVERSION=	0.9.1
PORTREVISION=	2
CATEGORIES=	graphics www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A standard interface to manipulate images using different libraries.

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	gd

CATEGORY=	Image
FILES=		Transform.php Transform/Driver/ColorsDefs.php \
		Transform/Driver/GD.php Transform/Driver/GD1.php \
		Transform/Driver/IM.php Transform/Driver/IMAGETYPE.php \
		Transform/Driver/Imagick.php Transform/Driver/Imagick2.php \
		Transform/Driver/Imlib.php Transform/Driver/NetPBM.php \
		Transform/Driver/image_type_to_mime_type.php \
		Transform/Driver/Imagick/ImageTypes.php

post-extract:
	@${MKDIR} ${WRKSRC}/Transform
	@${MV} ${WRKSRC}/Driver ${WRKSRC}/Transform/

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
