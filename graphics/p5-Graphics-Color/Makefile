# Ports collection makefile for:	p5-Graphics-Color
# Created by: chinsan
# $FreeBSD$

PORTNAME=	Graphics-Color
PORTVERSION=	0.29
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Device and library agnostic color spaces

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
BUILD_DEPENDS=	p5-Color-Library>=0.02:${PORTSDIR}/graphics/p5-Color-Library \
		p5-Moose>=0.74:${PORTSDIR}/devel/p5-Moose \
  		p5-MooseX-Aliases>=0.03:${PORTSDIR}/devel/p5-MooseX-Aliases \
  		p5-MooseX-Clone>=0.03:${PORTSDIR}/devel/p5-MooseX-Clone \
  		p5-MooseX-Storage>=0.23:${PORTSDIR}/devel/p5-MooseX-Storage \
  		p5-MooseX-Types>=0.19:${PORTSDIR}/devel/p5-MooseX-Types
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Number-Delta>=0:${PORTSDIR}/devel/p5-Test-Number-Delta

USES=		perl5
USE_PERL5=	configure

MAN3=		Graphics::Color.3 \
		Graphics::Color::CMYK.3 \
		Graphics::Color::Equal.3 \
		Graphics::Color::HSL.3 \
		Graphics::Color::HSV.3 \
		Graphics::Color::RGB.3 \
		Graphics::Color::Types.3 \
		Graphics::Color::YIQ.3 \
		Graphics::Color::YUV.3

.include <bsd.port.mk>
