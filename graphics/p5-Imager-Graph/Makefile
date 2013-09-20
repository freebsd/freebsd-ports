# Created by: Yuan-Chung Hsiao <ychsiao@ychsiao.org>
# $FreeBSD$

PORTNAME=	Imager-Graph
PORTVERSION=	0.10
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Perl extension for producing Graphs using the Imager library

BUILD_DEPENDS=	p5-Imager>=0.75:${PORTSDIR}/graphics/p5-Imager
RUN_DEPENDS=	p5-Imager>=0.75:${PORTSDIR}/graphics/p5-Imager

USES=		perl5
USE_PERL5=	configure

MAN3=		Imager::Graph.3 \
		Imager::Graph::Area.3 \
		Imager::Graph::Bar.3 \
		Imager::Graph::Column.3 \
		Imager::Graph::Horizontal.3 \
		Imager::Graph::Line.3 \
		Imager::Graph::Pie.3 \
		Imager::Graph::StackedColumn.3 \
		Imager::Graph::Util.3 \
		Imager::Graph::Vertical.3

NO_STAGE=	yes
.include <bsd.port.mk>
