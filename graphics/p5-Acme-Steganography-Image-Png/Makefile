# New ports collection makefile for:	p5-Acme-Steganography-Image-Png
# Date created:		2006-07-23
# Whom:			Tsung-Han Yeh <snowfly@yuntech.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Acme-Steganography-Image-Png
PORTVERSION=	0.06
PORTREVISION=	2
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	Hide data (badly) in Png images

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Imager.pm:${PORTSDIR}/graphics/p5-Imager \
		${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Acme::Steganography::Image::Png.3

.include <bsd.port.mk>
