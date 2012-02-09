# New ports collection makefile for:	Bio-NEXUS
# Date created:				20 Sug, 2009
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Bio-NEXUS
PORTVERSION=	0.77
CATEGORIES=	biology perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	An object-oriented Perl API for the NEXUS file format

BUILD_DEPENDS=	p5-Clone-PP>=1.02:${PORTSDIR}/devel/p5-Clone-PP
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Test-Pod-Coverage \
		p5-Test-Deep>=0.106:${PORTSDIR}/devel/p5-Test-Deep

PERL_CONFIGURE=	yes

MAN1=		nextool.pl.1 nex2text_tree.pl.1 nexplot.pl.1
MAN3=		Bio::NEXUS::DataBlock.3 Bio::NEXUS::CodonsBlock.3 \
		Bio::NEXUS::NotesBlock.3 Bio::NEXUS::NHXCmd.3 \
		Bio::NEXUS::HistoryBlock.3 Bio::NEXUS::TaxUnit.3 \
		Bio::NEXUS::CharactersBlock.3 Bio::NEXUS::SpanBlock.3 \
		Bio::NEXUS::UnalignedBlock.3 Bio::NEXUS::TaxUnitSet.3 \
		Bio::NEXUS::DistancesBlock.3 Bio::NEXUS::UnknownBlock.3 \
		Bio::NEXUS::Node.3 Bio::NEXUS::Matrix.3 \
		Bio::NEXUS::Tree.3 Bio::NEXUS::WeightSet.3 \
		Bio::NEXUS::TreesBlock.3 Bio::NEXUS::Util::Exceptions.3 \
		Bio::NEXUS::SetsBlock.3 Bio::NEXUS::TaxaBlock.3 \
		Bio::NEXUS::Util::Logger.3 Bio::NEXUS::AssumptionsBlock.3 \
		Bio::NEXUS::Block.3 Bio::NEXUS::Functions.3 \
		Bio::NEXUS::Tools::GraphicsParams.3 \
		Bio::NEXUS::Tools::NexModifier.3 \
		Bio::NEXUS::Tools::NexPlotter.3 \
		Bio::NEXUS.3

.include <bsd.port.mk>
