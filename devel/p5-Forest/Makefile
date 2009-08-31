# New ports collection makefile for:	p5-Forest
# Date created:				2008/08/30
# Whom:	      				chinsan
#
# $FreeBSD$
#

PORTNAME=	Forest
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/S/ST/STEVAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A collection of n-ary tree related modules

RUN_DEPENDS=	p5-Moose>=0.45:${PORTSDIR}/devel/p5-Moose \
  		p5-MooseX-AttributeHelpers>=0:${PORTSDIR}/devel/p5-MooseX-AttributeHelpers \
  		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
  		p5-Sub-Current>=0:${PORTSDIR}/devel/p5-Sub-Current \
  		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Forest.3 \
		Forest::Tree.3 \
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
