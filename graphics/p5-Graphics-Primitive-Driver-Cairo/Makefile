# Ports collection makefile for:	p5-Graphics-Primitive-Driver-Cairo
# Date created:			2008/08/30
# Whom:	      			chinsan
#
# $FreeBSD$
#

PORTNAME=	Graphics-Primitive-Driver-Cairo
PORTVERSION=	0.26
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Cairo backend for Graphics::Primitive

BUILD_DEPENDS=	p5-Moose>=0.54:${PORTSDIR}/devel/p5-Moose \
		p5-Module-Install>=0.64:${PORTSDIR}/devel/p5-Module-Install \
		p5-Cairo>=1.000:${PORTSDIR}/graphics/p5-Cairo \
		p5-Geometry-Primitive>=0.12:${PORTSDIR}/graphics/p5-Geometry-Primitive \
		p5-Graphics-Primitive>=0.31:${PORTSDIR}/graphics/p5-Graphics-Primitive
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Graphics::Primitive::Driver::Cairo.3 \
  		Graphics::Primitive::Driver::Cairo::TextLayout.3

.include <bsd.port.mk>
