# New ports collection makefile for:	Bio-Phylo
# Date created:				12 Mar 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Bio-Phylo
PORTVERSION=	0.26
CATEGORIES=	biology perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Phylogenetic analysis using perl

BUILD_DEPENDS=	p5-Exception-Class>1.22:${PORTSDIR}/devel/p5-Exception-Class \
		p5-Math-Random>=0.67:${PORTSDIR}/math/p5-Math-Random \
		p5-IO-String>=1.05:${PORTSDIR}/devel/p5-IO-String \
		p5-bioperl>=0:${PORTSDIR}/biology/p5-bioperl \
		p5-SVG>=1.07:${PORTSDIR}/textproc/p5-SVG
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Bio::Phylo.3 \
	Bio::Phylo::EvolutionaryModels.3 \
	Bio::Phylo::Factory.3 \
	Bio::Phylo::Forest::DrawNode.3 \
	Bio::Phylo::Forest::DrawTree.3 \
	Bio::Phylo::Forest.3 \
	Bio::Phylo::Forest::Node.3 \
	Bio::Phylo::Forest::Tree.3 \
	Bio::Phylo::Generator.3 \
	Bio::Phylo::IO.3 \
	Bio::Phylo::Listable.3 \
	Bio::Phylo::Manual.3 \
	Bio::Phylo::Matrices.3 \
	Bio::Phylo::Matrices::Datum.3 \
	Bio::Phylo::Matrices::Datatype.3 \
	Bio::Phylo::Matrices::Matrix.3 \
	Bio::Phylo::Matrices::TypeSafeData.3 \
	Bio::Phylo::Matrices::Datatype::Custom.3 \
	Bio::Phylo::Matrices::Datatype::Dna.3 \
	Bio::Phylo::Matrices::Datatype::Rna.3 \
	Bio::Phylo::Matrices::Datatype::Restriction.3 \
	Bio::Phylo::Matrices::Datatype::Protein.3 \
	Bio::Phylo::Matrices::Datatype::Continuous.3 \
	Bio::Phylo::Matrices::Datatype::Standard.3 \
	Bio::Phylo::Matrices::Datatype::Mixed.3 \
	Bio::Phylo::Mediators::TaxaMediator.3 \
	Bio::Phylo::NeXML::DOM::Element::Twig.3 \
	Bio::Phylo::NeXML::DOM::Document::Twig.3 \
	Bio::Phylo::NeXML::DOM::Document::Libxml.3 \
	Bio::Phylo::NeXML::DOM.3 \
	Bio::Phylo::NeXML::Meta.3 \
	Bio::Phylo::NeXML::Writable.3 \
	Bio::Phylo::NeXML::DOM::Document.3 \
	Bio::Phylo::NeXML::DOM::Element::Libxml.3 \
	Bio::Phylo::NeXML::DOM::Element.3 \
	Bio::Phylo::NeXML::Meta::XMLLiteral.3 \
	Bio::Phylo::Parsers::Newick.3 \
	Bio::Phylo::Parsers::Nexml.3 \
	Bio::Phylo::Parsers::Nexus.3 \
	Bio::Phylo::Parsers::Table.3 \
	Bio::Phylo::Parsers::Taxlist.3 \
	Bio::Phylo::Parsers::Tolweb.3 \
	Bio::Phylo::Project.3 \
	Bio::Phylo::Set.3 \
	Bio::Phylo::Taxa.3 \
	Bio::Phylo::Taxa::TaxaLinker.3 \
	Bio::Phylo::Taxa::Taxon.3 \
	Bio::Phylo::Taxa::TaxonLinker.3 \
	Bio::Phylo::Treedrawer.3 \
	Bio::Phylo::Treedrawer::Abstract.3 \
	Bio::Phylo::Treedrawer::Canvas.3 \
	Bio::Phylo::Treedrawer::Gif.3 \
	Bio::Phylo::Treedrawer::Jpeg.3 \
	Bio::Phylo::Treedrawer::Pdf.3 \
	Bio::Phylo::Treedrawer::Png.3 \
	Bio::Phylo::Treedrawer::Swf.3 \
	Bio::Phylo::Treedrawer::Svg.3 \
	Bio::Phylo::Unparsers::Mrp.3 \
	Bio::Phylo::Unparsers::Newick.3 \
	Bio::Phylo::Unparsers::Nexml.3 \
	Bio::Phylo::Unparsers::Nexus.3 \
	Bio::Phylo::Unparsers::Pagel.3 \
	Bio::Phylo::Util::CONSTANT.3 \
	Bio::Phylo::Util::Logger.3 \
	Bio::Phylo::Util::IDPool.3 \
	Bio::Phylo::Util::Exceptions.3 \
	Bio::Phylo::Util::StackTrace.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
