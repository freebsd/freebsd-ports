# Ports collection makefile for:	p5-Graphics-Color
# Date created:				2008/08/30
# Whom:	      				chinsan
#
# $FreeBSD$
#

PORTNAME=	Graphics-Color
PORTVERSION=	0.24
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Device and library agnostic color spaces

BUILD_DEPENDS=	p5-Moose>=0.54:${PORTSDIR}/devel/p5-Moose \
  		p5-MooseX-Aliases>=0.03:${PORTSDIR}/devel/p5-MooseX-Aliases \
  		p5-MooseX-Clone>=0.03:${PORTSDIR}/devel/p5-MooseX-Clone \
		p5-Module-Install>=0.64:${PORTSDIR}/devel/p5-Module-Install \
		p5-MooseX-Storage>=0.14:${PORTSDIR}/devel/p5-MooseX-Storage \
  		p5-MooseX-Types>=0.19:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-Color-Library>=0.02:${PORTSDIR}/graphics/p5-Color-Library
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Graphics::Color.3 \
		Graphics::Color::CMYK.3 \
		Graphics::Color::Equal.3 \
		Graphics::Color::HSL.3 \
		Graphics::Color::HSV.3 \
		Graphics::Color::RGB.3 \
		Graphics::Color::YIQ.3 \
		Graphics::Color::YUV.3

.include <bsd.port.mk>
