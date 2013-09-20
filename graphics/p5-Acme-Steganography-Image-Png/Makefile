# Created by: Tsung-Han Yeh <snowfly@yuntech.edu.tw>
# $FreeBSD$

PORTNAME=	Acme-Steganography-Image-Png
PORTVERSION=	0.06
PORTREVISION=	5
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	Hide data (badly) in Png images

BUILD_DEPENDS=	p5-Imager>=0:${PORTSDIR}/graphics/p5-Imager \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Acme::Steganography::Image::Png.3

NO_STAGE=	yes
.include <bsd.port.mk>
