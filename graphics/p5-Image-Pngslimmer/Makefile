# New ports collection makefile for:	p5-Image-Pngslimmer
# Date Created:				2007/02/12
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	Image-Pngslimmer
PORTVERSION=	0.30
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Slims (dynamically created) PNGs

RUN_DEPENDS=	p5-Compress-Zlib>=2.003:${PORTSDIR}/archivers/p5-Compress-Zlib \
		p5-Compress-Raw-Zlib>=2.003:${PORTSDIR}/archivers/p5-Compress-Raw-Zlib
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Image::Pngslimmer.3

.include <bsd.port.mk>
