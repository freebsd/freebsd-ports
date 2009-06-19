# vim:ts=8
# New ports collection makefile for:	p5-SVG-Graph
# Date created:				25 November 2004
# Whom:					Fernan Aguero <fernan@iib.unsam.edu.ar>
#
# $FreeBSD$
#

PORTNAME=	SVG-Graph
PORTVERSION=	0.02
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	Visualize your data in Scalable Vector Graphics (SVG) format

BUILD_DEPENDS=	${SITE_PERL}/SVG.pm:${PORTSDIR}/textproc/p5-SVG \
		${SITE_PERL}/Statistics/Descriptive.pm:${PORTSDIR}/math/p5-Statistics-Descriptive \
		${SITE_PERL}/Tree/DAG_Node.pm:${PORTSDIR}/devel/p5-Tree-DAG_Node \
		${SITE_PERL}/Math/Spline.pm:${PORTSDIR}/math/p5-Math-Spline \
		${SITE_PERL}/Math/Derivative.pm:${PORTSDIR}/math/p5-Math-Derivative

PERL_CONFIGURE=	yes

MAN3=		SVG::Graph.3 \
		SVG::Frame.3 \
		SVG::Graph::Data.3 \
		SVG::Graph::Data::Datum.3 \
		SVG::Graph::Data::Node.3 \
		SVG::Graph::Data::Tree.3 \
		SVG::Graph::File.3 \
		SVG::Graph::Frame.3 \
		SVG::Graph::Glyph.3 \
		SVG::Graph::Glyph::axis.3 \
		SVG::Graph::Glyph::bar.3 \
		SVG::Graph::Glyph::barflex.3 \
		SVG::Graph::Glyph::bezier.3 \
		SVG::Graph::Glyph::bubble.3 \
		SVG::Graph::Glyph::heatmap.3 \
		SVG::Graph::Glyph::line.3 \
		SVG::Graph::Glyph::pictogram.3 \
		SVG::Graph::Glyph::scatter.3 \
		SVG::Graph::Glyph::tree.3 \
		SVG::Graph::Glyph::wedge.3

.include <bsd.port.mk>
