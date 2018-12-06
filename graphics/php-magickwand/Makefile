# Created by: <mark@goodstorm.com>
# $FreeBSD$

PORTNAME=	magickwand
PORTVERSION=	1.0.9
PORTREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	http://www.magickwand.org/download/php/
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}
DISTNAME=	MagickWandForPHP-${PORTVERSION}-2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP extension to manipulate images

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LIB_DEPENDS=	libMagickWand-6.so:graphics/ImageMagick6

USES=		php:ext pkgconfig
IGNORE_WITH_PHP=	71 72 73

CONFIGURE_ARGS=	--with-magickwand=${LOCALBASE}

WRKSRC=		${WRKDIR}/MagickWandForPHP-${PORTVERSION}

pre-configure:
	@${REINPLACE_CMD} -e 's|-lMagickWand|-lMagickWand-6|g' \
		-e 's|-lMagickCore|-lMagickCore-6|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
