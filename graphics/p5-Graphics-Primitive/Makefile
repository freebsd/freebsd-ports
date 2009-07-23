# Ports collection makefile for:	p5-Graphics-Primitive
# Date created:			2008/08/30
# Whom:	      			chinsan
#
# $FreeBSD$
#

PORTNAME=	Graphics-Primitive
PORTVERSION=	0.44
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/G/GP/GPHAT
PKGNAMEPREFIX=	p5-

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Device and library agnostic graphic primitives

BUILD_DEPENDS=	p5-Geometry-Primitive>=0.13:${PORTSDIR}/graphics/p5-Geometry-Primitive \
		p5-Graphics-Color>=0.16:${PORTSDIR}/graphics/p5-Graphics-Color \
		p5-Moose>=0.54:${PORTSDIR}/devel/p5-Moose \
  		p5-MooseX-Clone>=0.03:${PORTSDIR}/devel/p5-MooseX-Clone \
  		p5-MooseX-AttributeHelpers>=0.12:${PORTSDIR}/devel/p5-MooseX-AttributeHelpers \
		p5-Module-Install>=0.64:${PORTSDIR}/devel/p5-Module-Install \
		p5-MooseX-Storage>=0.14:${PORTSDIR}/devel/p5-MooseX-Storage \
		p5-Forest>=0.04:${PORTSDIR}/devel/p5-Forest
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Graphics::Primitive.3 \
		Graphics::Primitive::Aligned.3 \
		Graphics::Primitive::Border.3 \
		Graphics::Primitive::Brush.3 \
		Graphics::Primitive::Canvas.3 \
		Graphics::Primitive::Component.3 \
		Graphics::Primitive::ComponentList.3 \
		Graphics::Primitive::Container.3 \
		Graphics::Primitive::Driver.3 \
		Graphics::Primitive::Driver::TextLayout.3 \
		Graphics::Primitive::Font.3 \
		Graphics::Primitive::Image.3 \
		Graphics::Primitive::Insets.3 \
		Graphics::Primitive::Operation.3 \
		Graphics::Primitive::Operation::Fill.3 \
		Graphics::Primitive::Operation::Stroke.3 \
		Graphics::Primitive::Oriented.3 \
		Graphics::Primitive::Paint.3 \
		Graphics::Primitive::Paint::Gradient.3 \
		Graphics::Primitive::Paint::Gradient::Linear.3 \
		Graphics::Primitive::Paint::Gradient::Radial.3 \
		Graphics::Primitive::Paint::Solid.3 \
		Graphics::Primitive::Path.3 \
		Graphics::Primitive::TextBox.3

.include <bsd.port.mk>
