# New ports collection makefile for:	p5-Bio-Graphics
# Date created:				30 Dec 2008
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Bio-Graphics
PORTVERSION=	1.982
CATEGORIES=	biology perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wenheping@gmail.com
COMMENT=	Generate GD Images of Bio::Seq Objects

BUILD_DEPENDS=	p5-GD>=2.3:${PORTSDIR}/graphics/p5-GD \
		p5-GD-SVG>=0.32:${PORTSDIR}/graphics/p5-GD-SVG \
		p5-Statistics-Descriptive>=2.6:${PORTSDIR}/math/p5-Statistics-Descriptive \
		p5-bioperl>=1.6.0:${PORTSDIR}/biology/p5-bioperl \
		p5-Text-ParseWords>=3.26:${PORTSDIR}/textproc/p5-Text-ParseWords \
		p5-Bio-SCF>=1.01:${PORTSDIR}/biology/p5-Bio-SCF \
		p5-ExtUtils-MakeMaker>=0:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	YES

MAN1=	contig_draw.pl.1 feature_draw.pl.1 \
	frend.pl.1 search_overview.pl.1

MAN3=	Bio::Graphics.3 \
	Bio::Graphics::Glyph::transcript2.3 \
	Bio::Graphics::Glyph::extending_arrow.3 \
	Bio::Graphics::Wiggle.3 \
	Bio::Graphics::ConfiguratorI.3 \
	Bio::Graphics::DrawTransmembrane.3 \
	Bio::Graphics::Feature.3 \
	Bio::Graphics::FeatureBase.3 \
	Bio::Graphics::FeatureDir.3 \
	Bio::Graphics::FeatureFile.3 \
	Bio::Graphics::FeatureFile::Iterator.3 \
	Bio::Graphics::Glyph.3 \
	Bio::Graphics::Glyph::Factory.3 \
	Bio::Graphics::Glyph::alignment.3 \
	Bio::Graphics::Glyph::anchored_arrow.3 \
	Bio::Graphics::Glyph::arrow.3 \
	Bio::Graphics::Glyph::box.3 \
	Bio::Graphics::Glyph::broken_line.3 \
	Bio::Graphics::Glyph::cds.3 \
	Bio::Graphics::Glyph::christmas_arrow.3 \
	Bio::Graphics::Glyph::crossbox.3 \
	Bio::Graphics::Glyph::dashed_line.3 \
	Bio::Graphics::Glyph::diamond.3 \
	Bio::Graphics::Glyph::dna.3 \
	Bio::Graphics::Glyph::dot.3 \
	Bio::Graphics::Glyph::dumbbell.3 \
	Bio::Graphics::Glyph::ellipse.3 \
	Bio::Graphics::Glyph::ex.3 \
	Bio::Graphics::Glyph::fixedwidth.3 \
	Bio::Graphics::Glyph::flag.3 \
	Bio::Graphics::Glyph::gene.3 \
	Bio::Graphics::Glyph::generic.3 \
	Bio::Graphics::Glyph::graded_segments.3 \
	Bio::Graphics::Glyph::group.3 \
	Bio::Graphics::Glyph::hat.3 \
	Bio::Graphics::Glyph::heat_map.3 \
	Bio::Graphics::Glyph::heat_map_ideogram.3 \
	Bio::Graphics::Glyph::heterogeneous_segments.3 \
	Bio::Graphics::Glyph::hidden.3 \
	Bio::Graphics::Glyph::hybrid_plot.3 \
	Bio::Graphics::Glyph::ideogram.3 \
	Bio::Graphics::Glyph::image.3 \
	Bio::Graphics::Glyph::lightning.3 \
	Bio::Graphics::Glyph::line.3 \
	Bio::Graphics::Glyph::merge_parts.3 \
	Bio::Graphics::Glyph::merged_alignment.3 \
	Bio::Graphics::Glyph::minmax.3 \
	Bio::Graphics::Glyph::oval.3 \
	Bio::Graphics::Glyph::pentagram.3 \
	Bio::Graphics::Glyph::pairplot.3 \
	Bio::Graphics::Glyph::phylo_align.3 \
	Bio::Graphics::Glyph::pinsertion.3 \
	Bio::Graphics::Glyph::primers.3 \
	Bio::Graphics::Glyph::processed_transcript.3 \
	Bio::Graphics::Glyph::protein.3 \
	Bio::Graphics::Glyph::ragged_ends.3 \
	Bio::Graphics::Glyph::rainbow_gene.3 \
	Bio::Graphics::Glyph::redgreen_box.3 \
	Bio::Graphics::Glyph::redgreen_segment.3 \
	Bio::Graphics::Glyph::repeating_shape.3 \
	Bio::Graphics::Glyph::rndrect.3 \
	Bio::Graphics::Glyph::ruler_arrow.3 \
	Bio::Graphics::Glyph::saw_teeth.3 \
	Bio::Graphics::Glyph::segmented_keyglyph.3 \
	Bio::Graphics::Glyph::segments.3 \
	Bio::Graphics::Glyph::so_transcript.3 \
	Bio::Graphics::Glyph::span.3 \
	Bio::Graphics::Glyph::spectrogram.3 \
	Bio::Graphics::Glyph::splice_site.3 \
	Bio::Graphics::Glyph::stackedplot.3 \
	Bio::Graphics::Glyph::ternary_plot.3 \
	Bio::Graphics::Glyph::text_in_box.3 \
	Bio::Graphics::Glyph::three_letters.3 \
	Bio::Graphics::Glyph::tic_tac_toe.3 \
	Bio::Graphics::Glyph::toomany.3 \
	Bio::Graphics::Glyph::trace.3 \
	Bio::Graphics::Glyph::track.3 \
	Bio::Graphics::Glyph::transcript.3 \
	Bio::Graphics::Glyph::translation.3 \
	Bio::Graphics::Glyph::triangle.3 \
	Bio::Graphics::Glyph::two_bolts.3 \
	Bio::Graphics::Glyph::wave.3 \
	Bio::Graphics::Glyph::weighted_arrow.3 \
	Bio::Graphics::Glyph::whiskerplot.3 \
	Bio::Graphics::Glyph::wiggle_box.3 \
	Bio::Graphics::Glyph::wiggle_density.3 \
	Bio::Graphics::Glyph::wiggle_xyplot.3 \
	Bio::Graphics::Glyph::xyplot.3 \
	Bio::Graphics::Panel.3 \
	Bio::Graphics::Pictogram.3 \
	Bio::Graphics::RendererI.3 \
	Bio::Graphics::Util.3 \
	Bio::Graphics::Wiggle::Loader.3

.include <bsd.port.mk>
