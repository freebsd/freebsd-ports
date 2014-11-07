# Created by: <mark@goodstorm.com>
# $FreeBSD$

PORTNAME=	magickwand
PORTVERSION=	1.0.9
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.magickwand.org/download/php/
PKGNAMEPREFIX=	php-
DISTNAME=	MagickWandForPHP-${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PHP extension to manipulate images

LIB_DEPENDS=	libMagickWand-6.Q16.so:${PORTSDIR}/graphics/ImageMagick

USES=		pkgconfig
USE_PHP=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS=	--with-magickwand=${LOCALBASE}

pre-configure:
	@${REINPLACE_CMD} -e 's|-lMagickWand|-lMagickWand-6.Q16|g' \
		-e 's|-lMagickCore|-lMagickCore-6.Q16|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
