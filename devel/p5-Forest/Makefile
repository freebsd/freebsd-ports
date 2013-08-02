# Created by: chinsan
# $FreeBSD$

PORTNAME=	Forest
PORTVERSION=	0.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:STEVAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Collection of n-ary tree related modules

RUN_DEPENDS=	p5-Moose>=0.90:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-AttributeHelpers>=0.17:${PORTSDIR}/devel/p5-MooseX-AttributeHelpers \
		p5-MooseX-Clone>=0.05:${PORTSDIR}/devel/p5-MooseX-Clone
BUILD_DEPENDS:=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

MAN3=		Forest.3 \
		Forest::Tree.3 \
		Forest::Tree::Builder.3 \
		Forest::Tree::Builder::Callback.3 \
		Forest::Tree::Builder::SimpleTextFile.3 \
		Forest::Tree::Constructor.3 \
		Forest::Tree::Pure.3 \
		Forest::Tree::Writer::SimpleHTML.3 \
		Forest::Tree::Roles::JSONable.3 \
		Forest::Tree::Writer::ASCIIWithBranches.3 \
		Forest::Tree::Indexer.3 \
		Forest::Tree::Roles::LoadWithMetaData.3 \
		Forest::Tree::Writer.3 \
		Forest::Tree::Roles::MetaData.3 \
		Forest::Tree::Loader.3 \
		Forest::Tree::Writer::SimpleASCII.3 \
		Forest::Tree::Reader.3 \
		Forest::Tree::Reader::SimpleTextFile.3 \
		Forest::Tree::Loader::SimpleUIDLoader.3 \
		Forest::Tree::Indexer::SimpleUIDIndexer.3 \
		Forest::Tree::Roles::HasNodeFormatter.3

.include <bsd.port.mk>
