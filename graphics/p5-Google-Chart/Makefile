# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Google-Chart
PORTVERSION=	0.05014
PORTREVISION=	3
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Perl Interface to Google Charts API

RUN_DEPENDS=	p5-libwww>0:${PORTSDIR}/www/p5-libwww \
		p5-Moose>=2:${PORTSDIR}/devel/p5-Moose \
		p5-URI>0:${PORTSDIR}/net/p5-URI

MAN3=		Google::Chart.3 Google::Chart::Axis.3 \
		Google::Chart::Axis::Item.3 Google::Chart::Axis::Style.3 \
		Google::Chart::Color.3 Google::Chart::Data.3 \
		Google::Chart::Data::Extended.3 Google::Chart::Data::Simple.3 \
		Google::Chart::Data::Text.3 Google::Chart::Fill.3 \
		Google::Chart::Fill::LinearGradient.3 \
		Google::Chart::Fill::LinearStripes.3 \
		Google::Chart::Fill::Solid.3 Google::Chart::Grid.3 \
		Google::Chart::Legend.3 Google::Chart::Marker.3 \
		Google::Chart::QueryComponent.3 \
		Google::Chart::QueryComponent::Simple.3 \
		Google::Chart::Size.3 Google::Chart::Title.3 \
		Google::Chart::Type.3 Google::Chart::Type::Bar.3 \
		Google::Chart::Type::Line.3 Google::Chart::Type::Pie.3 \
		Google::Chart::Type::QRcode.3 Google::Chart::Type::Radar.3 \
		Google::Chart::Type::ScatterPlot.3 Google::Chart::Type::Simple.3 \
		Google::Chart::Type::SparkLine.3 Google::Chart::Type::Venn.3 \
		Google::Chart::Type::XY.3 \
		Google::Chart::Margin.3 \
		Google::Chart::Types.3

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
