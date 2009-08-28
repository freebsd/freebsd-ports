# Ports collection makefile for:	p5-Graphics-Primitive-Driver-Cairo
# Date created:			2008/08/30
# Whom:	      			chinsan
#
# $FreeBSD$
#

PORTNAME=	Graphics-Primitive-Driver-Cairo
PORTVERSION=	0.39
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Cairo backend for Graphics::Primitive

BUILD_DEPENDS=	p5-Moose>=0.57:${PORTSDIR}/devel/p5-Moose \
		p5-Module-Install>=0.64:${PORTSDIR}/devel/p5-Module-Install \
		p5-Cairo>=1.060:${PORTSDIR}/graphics/p5-Cairo \
		p5-Geometry-Primitive>=0.13:${PORTSDIR}/graphics/p5-Geometry-Primitive \
		p5-Graphics-Primitive>=0.35:${PORTSDIR}/graphics/p5-Graphics-Primitive \
		p5-Math-Complex>=1.54:${PORTSDIR}/math/p5-Math-Complex \
		p5-Text-Flow>=0.01:${PORTSDIR}/textproc/p5-Text-Flow
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Graphics::Primitive::Driver::Cairo.3 \
  		Graphics::Primitive::Driver::Cairo::TextLayout.3

.include <bsd.port.mk>
