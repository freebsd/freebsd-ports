# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Graph-Easy
PORTVERSION=	0.73
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Render graphs as ASCII, HTML, SVG, or Graphviz

BUILD_DEPENDS=	p5-Heap>0:${PORTSDIR}/devel/p5-Heap
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=	graph-easy.1

MAN3=	Graph::Easy.3 \
	Graph::Easy::As_ascii.3 \
	Graph::Easy::As_graphml.3 \
	Graph::Easy::As_graphviz.3 \
	Graph::Easy::As_txt.3 \
	Graph::Easy::As_vcg.3 \
	Graph::Easy::Attributes.3 \
	Graph::Easy::Base.3 \
	Graph::Easy::Edge.3 \
	Graph::Easy::Edge::Cell.3 \
	Graph::Easy::Group.3 \
	Graph::Easy::Group::Anon.3 \
	Graph::Easy::Group::Cell.3 \
	Graph::Easy::Layout.3 \
	Graph::Easy::Layout::Chain.3 \
	Graph::Easy::Layout::Force.3 \
	Graph::Easy::Layout::Grid.3 \
	Graph::Easy::Layout::Path.3 \
	Graph::Easy::Layout::Repair.3 \
	Graph::Easy::Layout::Scout.3 \
	Graph::Easy::Node.3 \
	Graph::Easy::Node::Anon.3 \
	Graph::Easy::Node::Cell.3 \
	Graph::Easy::Node::Empty.3 \
	Graph::Easy::Parser.3 \
	Graph::Easy::Parser::Graphviz.3 \
	Graph::Easy::Parser::VCG.3 \
	Graph::Easy::Util.3

NO_STAGE=	yes
.include <bsd.port.mk>
