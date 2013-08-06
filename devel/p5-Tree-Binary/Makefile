# Created by: Aaron Dalton <aaron@daltons.ca>
# $FreeBSD$

PORTNAME=	Tree-Binary
PORTVERSION=	1.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Object Oriented Binary Tree for Perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

MAN3=		Tree::Binary.3 Tree::Binary::Search.3 \
		Tree::Binary::Search::Node.3 \
		Tree::Binary::Visitor::Base.3 \
		Tree::Binary::Visitor::BreadthFirstTraversal.3 \
		Tree::Binary::Visitor::InOrderTraversal.3 \
		Tree::Binary::Visitor::PostOrderTraversal.3 \
		Tree::Binary::Visitor::PreOrderTraversal.3 \
		Tree::Binary::VisitorFactory.3

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
