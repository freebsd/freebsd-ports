# New ports collection makefile for:	Bio-Phylo
# Date created:				12 Mar 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Bio-Phylo
PORTVERSION=	0.35
CATEGORIES=	biology perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/R/RV/RVOSA
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Phylogenetic analysis using perl

RUN_DEPENDS=	p5-Math-CDF>=0:${PORTSDIR}/math/p5-Math-CDF \
		p5-Math-Random>=0.67:${PORTSDIR}/math/p5-Math-Random \
		p5-SVG>=1.07:${PORTSDIR}/textproc/p5-SVG \
		p5-SWF-Builder>=0:${PORTSDIR}/graphics/p5-SWF-Builder \
		p5-XML-Twig>=0:${PORTSDIR}/textproc/p5-XML-Twig \
		p5-bioperl>=0:${PORTSDIR}/biology/p5-bioperl \
		p5-libxml>=0:${PORTSDIR}/textproc/p5-libxml

PERL_CONFIGURE=	yes

MAN3=		Bio::Phylo.3 \
		Bio::Phylo::EvolutionaryModels.3 \
		Bio::Phylo::Factory.3 \
		Bio::Phylo::Forest::DrawNode.3 \
		Bio::Phylo::Forest::DrawTree.3 \
		Bio::Phylo::Forest.3 \
		Bio::Phylo::Forest::Node.3 \
		Bio::Phylo::Forest::Tree.3 \
		Bio::Phylo::Generator.3 \
		Bio::Phylo::Identifiable.3 \
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
		Bio::Phylo::Parsers::Abstract.3 \
		Bio::Phylo::Parsers::Fasta.3 \
		Bio::Phylo::Parsers::Newick.3 \
		Bio::Phylo::Parsers::Nexml.3 \
		Bio::Phylo::Parsers::Nexus.3 \
		Bio::Phylo::Parsers::Phylip.3 \
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
		Bio::Phylo::Unparsers::Abstract.3 \
		Bio::Phylo::Unparsers::Mrp.3 \
		Bio::Phylo::Unparsers::Newick.3 \
		Bio::Phylo::Unparsers::Nexml.3 \
		Bio::Phylo::Unparsers::Nexus.3 \
		Bio::Phylo::Unparsers::Pagel.3 \
		Bio::Phylo::Unparsers::Phylip.3 \
		Bio::Phylo::Util::CONSTANT.3 \
		Bio::Phylo::Util::Logger.3 \
		Bio::Phylo::Util::IDPool.3 \
		Bio::Phylo::Util::Exceptions.3 \
		Bio::Phylo::Util::StackTrace.3

.include <bsd.port.mk>
