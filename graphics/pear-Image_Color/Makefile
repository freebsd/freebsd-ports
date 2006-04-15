# Ports collection makefile for:  pear-Image_Color
# Date created:			  01 June 2004
# Whom:				  Gerrit Beine (<tux@pinguru.net>)
#
# $FreeBSD$
#

PORTNAME=	Image_Color
PORTVERSION=	1.0.2
CATEGORIES=	graphics www pear

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	PEAR::Image_Color manages and handles color data and conversions

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	gd

CATEGORY=	Image
FILES=		Color.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
