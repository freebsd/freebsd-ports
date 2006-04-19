# New ports collection makefile for:	graphics/p5-Graph-Easy
# Date created:				22 October 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Graph-Easy
PORTVERSION=	0.44
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Graph
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Render graphs as ASCII, HTML, SVG or Graphviz

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		${SITE_PERL}/Heap.pm:${PORTSDIR}/devel/p5-Heap
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Graph::Easy.3 \
	Graph::Easy::As_ascii.3 \
	Graph::Easy::As_graphviz.3 \
	Graph::Easy::As_txt.3 \
	Graph::Easy::Attributes.3 \
	Graph::Easy::Base.3 \
	Graph::Easy::Edge.3 \
	Graph::Easy::Edge::Cell.3 \
	Graph::Easy::Group.3 \
	Graph::Easy::Group::Cell.3 \
	Graph::Easy::Layout.3 \
	Graph::Easy::Layout::Chain.3 \
	Graph::Easy::Layout::Grid.3 \
	Graph::Easy::Layout::Path.3 \
	Graph::Easy::Layout::Repair.3 \
	Graph::Easy::Layout::Scout.3 \
	Graph::Easy::Node.3 \
	Graph::Easy::Node::Anon.3 \
	Graph::Easy::Node::Cell.3 \
	Graph::Easy::Node::Empty.3 \
	Graph::Easy::Parser.3 \
	Graph::Easy::Parser::Graphviz.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		requires perl 5.8.0 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
