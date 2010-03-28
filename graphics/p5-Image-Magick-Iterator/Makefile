# New ports collection makefile for:	p5-Image-Magick-Iterator
# Date created:		2006-11-12
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Image-Magick-Iterator
PORTVERSION=	0.01
PORTREVISION=	3
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Image
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Sequentially read Image::Magick object from a filehandle

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Image/Magick.pm:${PORTSDIR}/graphics/ImageMagick \
		${SITE_PERL}/Image/PBMlib.pm:${PORTSDIR}/graphics/p5-Image-PBMlib

PERL_CONFIGURE=	yes

MAN3=		Image::Magick::Iterator.3 Image::Magick::Iterator::PPM.3

.include <bsd.port.mk>
