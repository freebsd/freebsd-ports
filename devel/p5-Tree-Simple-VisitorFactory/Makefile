# Created by: Aaron Dalton <aaron@daltons.ca>
# $FreeBSD$

PORTNAME=	Tree-Simple-VisitorFactory
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Set of visitor objects for traversing Tree::Simple hierarchies

BUILD_DEPENDS=	p5-Tree-Simple>=0:${PORTSDIR}/devel/p5-Tree-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Exception>0:${PORTSDIR}/devel/p5-Test-Exception

MAN3=		Tree::Simple::Visitor::BreadthFirstTraversal.3 \
		Tree::Simple::Visitor::FindByPath.3 \
		Tree::Simple::Visitor::GetAllDescendents.3 \
		Tree::Simple::Visitor::PathToRoot.3 \
		Tree::Simple::Visitor::PostOrderTraversal.3 \
		Tree::Simple::VisitorFactory.3 \
		Tree::Simple::Visitor::CreateDirectoryTree.3 \
		Tree::Simple::Visitor::FindByNodeValue.3 \
		Tree::Simple::Visitor::FindByUID.3 \
		Tree::Simple::Visitor::FromNestedArray.3 \
		Tree::Simple::Visitor::FromNestedHash.3 \
		Tree::Simple::Visitor::LoadClassHierarchy.3 \
		Tree::Simple::Visitor::LoadDirectoryTree.3 \
		Tree::Simple::Visitor::PreOrderTraversal.3 \
		Tree::Simple::Visitor::Sort.3 \
		Tree::Simple::Visitor::ToNestedArray.3 \
		Tree::Simple::Visitor::ToNestedHash.3 \
		Tree::Simple::Visitor::VariableDepthClone.3

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
