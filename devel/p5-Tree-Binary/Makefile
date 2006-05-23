# New ports collection makefile for:	Tree::Binary
# Date created:				1 September 2004
# Whom:					Aaron Dalton <aaron@daltons.ca>
#
# $FreeBSD$
#

PORTNAME=	Tree-Binary
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tree
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	An Object Oriented Binary Tree for Perl

MAN3=		Tree::Binary.3 Tree::Binary::Search.3 \
		Tree::Binary::Search::Node.3 \
		Tree::Binary::Visitor::Base.3 \
		Tree::Binary::Visitor::BreadthFirstTraversal.3 \
		Tree::Binary::Visitor::InOrderTraversal.3 \
		Tree::Binary::Visitor::PostOrderTraversal.3 \
		Tree::Binary::Visitor::PreOrderTraversal.3 \
		Tree::Binary::VisitorFactory.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
