# New ports collection makefile for:	p5-Acme-Steganography-Image-Png
# Date created:		2006-07-23
# Whom:			Tsung-Han Yeh <snowfly@yuntech.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Acme-Steganography-Image-Png
PORTVERSION=	0.06
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Acme
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	Hide data (badly) in Png images

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Imager.pm:${PORTSDIR}/graphics/p5-Imager \
		${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Acme::Steganography::Image::Png.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires at least Perl 5.6 due to dependencies.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
