PORTNAME=	image_processing
PORTVERSION=	1.14.0
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	High-level wrapper for processing images for the web with ImageMagick or libvips
WWW=		https://github.com/janko/image_processing

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-mini_magick4${PKGNAMESUFFIX}>=4.9.5<6:graphics/rubygem-mini_magick4 \
		rubygem-ruby-vips${PKGNAMESUFFIX}>=2.0.17<3:graphics/rubygem-ruby-vips

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
