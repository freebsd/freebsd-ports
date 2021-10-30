# Created by: Gea-Suan Lin <gslin@gslin.org>

PORTNAME=	Image-Magick-Iterator
PORTVERSION=	0.01
PORTREVISION=	9
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sequentially read Image::Magick object from a filehandle

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Image-PBMlib>=1.05:graphics/p5-Image-PBMlib

USES=		magick:6,build,run perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
