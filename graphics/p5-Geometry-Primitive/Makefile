# Ports collection makefile for:	Geometry-Primitive
# Date created:			2008/08/30
# Whom:	      			chinsan
#
# $FreeBSD$
#

PORTNAME=	Geometry-Primitive
PORTVERSION=	0.09
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/G/GP/GPHAT
PKGNAMEPREFIX=	p5-

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Primitive Geometry Entities

BUILD_DEPENDS=	p5-Moose>=0.25:${PORTSDIR}/devel/p5-Moose \
		p5-Pod-Coverage-Moose>=0:${PORTSDIR}/devel/p5-Pod-Coverage-Moose \
  		p5-MooseX-AttributeHelpers>=0:${PORTSDIR}/devel/p5-MooseX-AttributeHelpers \
  		p5-MooseX-Clone>=0:${PORTSDIR}/devel/p5-MooseX-Clone \
		p5-Module-Install>=0.64:${PORTSDIR}/devel/p5-Module-Install \
		p5-Cairo>=1.000:${PORTSDIR}/graphics/p5-Cairo \
		p5-DateTime-Set>=0.25:${PORTSDIR}/devel/p5-DateTime-Set \
		p5-Math-Complex>=0:${PORTSDIR}/math/p5-Math-Complex
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Geometry::Primitive.3 \
		Geometry::Primitive::Polygon.3 \
		Geometry::Primitive::Shape.3 \
		Geometry::Primitive::Arc.3 \
		Geometry::Primitive::Line.3 \
		Geometry::Primitive::Rectangle.3 \
		Geometry::Primitive::Circle.3 \
		Geometry::Primitive::Equal.3 \
		Geometry::Primitive::Point.3 \
		Geometry::Primitive::Bezier.3

.include <bsd.port.mk>
