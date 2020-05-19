# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	image_processing
PORTVERSION=	1.11.0
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	High-level wrapper for processing images for the web with ImageMagick or libvips

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-mini_magick>=4.9.5<5:graphics/rubygem-mini_magick \
		rubygem-ruby-vips>=2.0.17<3:graphics/rubygem-ruby-vips

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
