# New ports collection makefile for:	Tree::Simple::VisitorFactory
# Date created:				13 August 2004
# Whom:					Aaron Dalton <aaron@daltons.ca>
#
# $FreeBSD$
#

PORTNAME=	Tree-Simple-VisitorFactory
PORTVERSION=	0.01
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tree
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@daltons.ca
COMMENT=	A set of visitor objects for traversing Tree::Simple hierarchies

BUILD_DEPENDS=	${SITE_PERL}/Tree/Simple.pm:${PORTSDIR}/devel/p5-Tree-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=		Tree::Simple::Visitor::BreadthFirstTraversal.3 \
		Tree::Simple::Visitor::FindByPath.3 \
		Tree::Simple::Visitor::GetAllDescendents.3 \
		Tree::Simple::Visitor::PathToRoot.3 \
		Tree::Simple::Visitor::PostOrderTraversal.3 \
		Tree::Simple::VisitorFactory.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		"This port requires perl 5.6 or above."
.endif

.include <bsd.port.post.mk>
