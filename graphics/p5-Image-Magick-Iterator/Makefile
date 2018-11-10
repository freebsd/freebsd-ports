# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Image-Magick-Iterator
PORTVERSION=	0.01
PORTREVISION=	9
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sequentially read Image::Magick object from a filehandle

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	ImageMagick6>=0:graphics/ImageMagick6 \
		p5-Image-PBMlib>=1.05:graphics/p5-Image-PBMlib

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
