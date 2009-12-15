# Ports collection makefile for:	Chart-Clicker
# Date created:			2006/08/15
# Whom:	      			chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Chart-Clicker
PORTVERSION=	2.52
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Powerful, extensible charting

RUN_DEPENDS=	p5-Color-Palette>=0.091400:${PORTSDIR}/graphics/p5-Color-Palette \
		p5-Color-Scheme>=1.02:${PORTSDIR}/graphics/p5-Color-Scheme \
		p5-Moose>=0.76:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-AttributeHelpers>=0.17:${PORTSDIR}/devel/p5-MooseX-AttributeHelpers \
		p5-DateTime>=0.47:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Set>=0.27:${PORTSDIR}/devel/p5-DateTime-Set \
		p5-Geometry-Primitive>=0.13:${PORTSDIR}/graphics/p5-Geometry-Primitive \
		p5-Graphics-Color>=0.20:${PORTSDIR}/graphics/p5-Graphics-Color \
		p5-Graphics-Primitive>=0.42:${PORTSDIR}/graphics/p5-Graphics-Primitive \
		p5-Graphics-Primitive-Driver-Cairo>=0.39:${PORTSDIR}/graphics/p5-Graphics-Primitive-Driver-Cairo \
		p5-Layout-Manager>=0.29:${PORTSDIR}/graphics/p5-Layout-Manager
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Chart::Clicker.3 \
		Chart::Clicker::Axis.3 \
		Chart::Clicker::Axis::DateTime.3 \
		Chart::Clicker::Component.3 \
		Chart::Clicker::Container.3 \
		Chart::Clicker::Context.3 \
		Chart::Clicker::Data::DataSet.3 \
		Chart::Clicker::Data::Marker.3 \
		Chart::Clicker::Data::Range.3 \
		Chart::Clicker::Data::Series.3 \
		Chart::Clicker::Data::Series::HighLow.3 \
		Chart::Clicker::Data::Series::Size.3 \
		Chart::Clicker::Decoration.3 \
		Chart::Clicker::Decoration::Glass.3 \
		Chart::Clicker::Decoration::Grid.3 \
		Chart::Clicker::Decoration::Legend.3 \
		Chart::Clicker::Decoration::Legend::Tabular.3 \
		Chart::Clicker::Decoration::MarkerOverlay.3 \
		Chart::Clicker::Decoration::OverAxis.3 \
		Chart::Clicker::Decoration::Plot.3 \
		Chart::Clicker::Drawing::ColorAllocator.3 \
		Chart::Clicker::Positioned.3 \
		Chart::Clicker::Renderer.3 \
		Chart::Clicker::Renderer::Area.3 \
		Chart::Clicker::Renderer::Bar.3 \
		Chart::Clicker::Renderer::Bubble.3 \
		Chart::Clicker::Renderer::CandleStick.3 \
		Chart::Clicker::Renderer::Line.3 \
		Chart::Clicker::Renderer::Pie.3 \
		Chart::Clicker::Renderer::Point.3 \
		Chart::Clicker::Renderer::StackedArea.3 \
		Chart::Clicker::Renderer::StackedBar.3 \
		Chart::Clicker::Tutorial.3

.include <bsd.port.mk>
