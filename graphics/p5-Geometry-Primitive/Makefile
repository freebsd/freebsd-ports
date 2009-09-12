# Ports collection makefile for:	Geometry-Primitive
# Date created:			2008/08/30
# Whom:	      			chinsan
#
# $FreeBSD$
#

PORTNAME=	Geometry-Primitive
PORTVERSION=	0.17
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/G/GP/GPHAT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Primitive Geometry Entities

BUILD_DEPENDS=	p5-Moose>=0.57:${PORTSDIR}/devel/p5-Moose \
  		p5-MooseX-AttributeHelpers>=0.13:${PORTSDIR}/devel/p5-MooseX-AttributeHelpers \
  		p5-MooseX-Clone>=0.03:${PORTSDIR}/devel/p5-MooseX-Clone \
		p5-Module-Install>=0.64:${PORTSDIR}/devel/p5-Module-Install \
		p5-DateTime-Set>=0.25:${PORTSDIR}/devel/p5-DateTime-Set \
		p5-Math-Complex>=1.54:${PORTSDIR}/math/p5-Math-Complex \
		p5-MooseX-Storage>=0.14:${PORTSDIR}/devel/p5-MooseX-Storage \
		p5-Check-ISA>=0.04:${PORTSDIR}/devel/p5-Check-ISA
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Geometry::Primitive.3 \
		Geometry::Primitive::Arc.3 \
		Geometry::Primitive::Bezier.3 \
		Geometry::Primitive::Circle.3 \
		Geometry::Primitive::Ellipse.3 \
		Geometry::Primitive::Equal.3 \
		Geometry::Primitive::Line.3 \
		Geometry::Primitive::Point.3 \
		Geometry::Primitive::Polygon.3 \
		Geometry::Primitive::Rectangle.3 \
		Geometry::Primitive::Shape.3

.include <bsd.port.mk>
