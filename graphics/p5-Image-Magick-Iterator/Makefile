PORTNAME=	Image-Magick-Iterator
PORTVERSION=	0.01
PORTREVISION=	11
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sequentially read Image::Magick object from a filehandle
WWW=		https://metacpan.org/release/Image-Magick-Iterator

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Image-PBMlib>=1.05:graphics/p5-Image-PBMlib

USES=		magick:build,run perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
