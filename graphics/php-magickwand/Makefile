# Created by: <mark@goodstorm.com>
# $FreeBSD$

PORTNAME=	magickwand
PORTVERSION=	1.0.9
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://www.magickwand.org/download/php/
PKGNAMEPREFIX=	php-
DISTNAME=	MagickWandForPHP-${PORTVERSION}-2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP extension to manipulate images

LIB_DEPENDS=	libMagickWand-6.so:graphics/ImageMagick

USES=		php:ext pkgconfig
IGNORE_WITH_PHP=	70

CONFIGURE_ARGS=	--with-magickwand=${LOCALBASE}

WRKSRC=		${WRKDIR}/MagickWandForPHP-${PORTVERSION}

pre-configure:
	@${REINPLACE_CMD} -e 's|-lMagickWand|-lMagickWand-6|g' \
		-e 's|-lMagickCore|-lMagickCore-6|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
