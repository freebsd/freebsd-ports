# ex:ts=8
# Ports collection Makefile for:	ale
# Date created:			Dec 17, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ale
PORTVERSION=	0.5.1
CATEGORIES=	graphics
MASTER_SITES=	http://auricle.dyndns.org/ALE/download/
PATCH_SITES=	http://auricle.dyndns.org/ALE/bugs/
PATCHFILES=	0.5.1.patch1 0.5.1.patch2
PATCH_DIST_ARGS=	-p1 -d ${PATCH_WRKSRC}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Anti-Lamenessing Engine

USE_GCC=	3.1
USE_GMAKE=	yes

.if !defined(WITHOUT_IMAGEMAGICK)
LIB_DEPENDS=	Magick.6:${PORTSDIR}/graphics/ImageMagick
MAKE_ARGS=	IMAGEMAGICK=1
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ale ${PREFIX}/bin

.include <bsd.port.mk>
