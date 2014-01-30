# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Image-Magick-Iterator
PORTVERSION=	0.01
PORTREVISION=	4
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Image
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Sequentially read Image::Magick object from a filehandle

RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick \
		p5-Image-PBMlib>=0:${PORTSDIR}/graphics/p5-Image-PBMlib

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
