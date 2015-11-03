# Created by: <mark@goodstorm.com>
# $FreeBSD$

PORTNAME=	magickwand
PORTVERSION=	1.0.9
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://www.magickwand.org/download/php/
PKGNAMEPREFIX=	php-
DISTNAME=	MagickWandForPHP-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP extension to manipulate images

BROKEN=		No public distfiles
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26

LIB_DEPENDS=	libMagickWand-6.so:${PORTSDIR}/graphics/ImageMagick

USES=		pkgconfig
USE_PHP=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS=	--with-magickwand=${LOCALBASE}

pre-configure:
	@${REINPLACE_CMD} -e 's|-lMagickWand|-lMagickWand-6|g' \
		-e 's|-lMagickCore|-lMagickCore-6|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
