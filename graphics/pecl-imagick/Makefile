# Created by: Andrey Slusar <anray@FreeBSD.org>
# $FreeBSD$

PORTNAME=	imagick
DISTVERSION=	3.1.0RC2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Provides a wrapper to the ImageMagick/GraphicsMagick library

.if !defined(WITHOUT_X11)
LIB_DEPENDS=	MagickWand:${PORTSDIR}/graphics/ImageMagick
.else
LIB_DEPENDS=	MagickWand:${PORTSDIR}/graphics/ImageMagick-nox11
.endif

LICENSE=	PHP301

USE_PHP=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS=	--with-imagick=${LOCALBASE}

NO_STAGE=	yes
.include <bsd.port.mk>
