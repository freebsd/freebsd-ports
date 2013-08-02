# Created by: Fernan Aguero <fernan@iib.unsam.edu.ar>
# $FreeBSD$

PORTNAME=	Data-Stag
PORTVERSION=	0.11
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Structured Tags datastructures

RUN_DEPENDS=	p5-IO-String>=0:${PORTSDIR}/devel/p5-IO-String
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=		stag-grep.pl.1 stag-filter.pl.1 stag-parse.pl.1 \
		stag-drawtree.pl.1 stag-autoschema.pl.1 stag-merge.pl.1 \
		stag-view.pl.1 stag-join.pl.1 stag-diff.pl.1 stag-db.pl.1 \
		stag-mogrify.pl.1 stag-splitter.pl.1 stag-handle.pl.1 \
		stag-flatten.pl.1 stag-findsubtree.pl.1 stag-query.pl.1

MAN3=		Data::Stag::GraphHandler.3 Data::Stag::PodParser.3 \
		Data::Stag::XSLHandler.3 Data::Stag::StagDB.3 \
		Data::Stag::ITextWriter.3 Data::Stag::null.3 \
		Data::Stag::StagImpl.3 Data::Stag::XMLWriter.3 \
		Data::Stag::Arr2HTML.3 Data::Stag::SxprParser.3 \
		Data::Stag::SAX2Stag.3 Data::Stag::Writer.3 \
		Data::Stag::ChainHandler.3 Data::Stag::SxprWriter.3 \
		Data::Stag::Simple.3 Data::Stag::HashDB.3 \
		Data::Stag::BaseHandler.3 Data::Stag::BaseGenerator.3 \
		Data::Stag::DTDWriter.3 Data::Stag::ITextParser.3 \
		Data::Stag::PerlWriter.3 Data::Stag::XMLParser.3 \
		Data::Stag::IndentParser.3 Data::Stag::IndentWriter.3 \
		Data::Stag.3 Data::Stag::XSLTHandler.3

.include <bsd.port.mk>
