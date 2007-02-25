# Ports collection makefile for:	Chart-Clicker
# Date created:			2006/08/15
# Whom:	      			chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Chart-Clicker
PORTVERSION=	1.1.5
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Chart
PKGNAMEPREFIX=	p5-

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Powerful, extensible charting

BUILD_DEPENDS=	p5-Class-Accessor>=0.25:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Cairo>=1.000:${PORTSDIR}/graphics/p5-Cairo
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Chart::Clicker.3 Chart::Clicker::Axis.3 \
    		Chart::Clicker::Axis::DateTime.3 \
		Chart::Clicker::Data::DataSet.3 \
		Chart::Clicker::Data::Marker.3 \
		Chart::Clicker::Data::Range.3 \
		Chart::Clicker::Data::Series.3 \
		Chart::Clicker::Decoration.3 \
		Chart::Clicker::Decoration::Glass.3 \
		Chart::Clicker::Decoration::Grid.3 \
		Chart::Clicker::Decoration::Label.3 \
		Chart::Clicker::Decoration::Legend.3 \
		Chart::Clicker::Decoration::LegendItem.3 \
		Chart::Clicker::Decoration::MarkerOverlay.3 \
		Chart::Clicker::Decoration::Plot.3 \
		Chart::Clicker::Drawing.3 \
		Chart::Clicker::Drawing::Border.3 \
		Chart::Clicker::Drawing::Color.3 \
		Chart::Clicker::Drawing::ColorAllocator.3 \
		Chart::Clicker::Drawing::Component.3 \
		Chart::Clicker::Drawing::Container.3 \
		Chart::Clicker::Drawing::Dimension.3 \
		Chart::Clicker::Drawing::Font.3 \
		Chart::Clicker::Drawing::Insets.3 \
		Chart::Clicker::Drawing::Point.3 \
		Chart::Clicker::Drawing::Stroke.3 \
		Chart::Clicker::Renderer::Area.3 \
		Chart::Clicker::Renderer::Bar.3 \
		Chart::Clicker::Renderer::Base.3 \
		Chart::Clicker::Renderer::Line.3 \
		Chart::Clicker::Renderer::Measurement.3 \
		Chart::Clicker::Renderer::Point.3 \
		Chart::Clicker::Simple.3 \
		Chart::Clicker::Shape.3 \
		Chart::Clicker::Shape::Arc.3 \
		Chart::Clicker::Shape::Rectangle.3

.include <bsd.port.mk>
