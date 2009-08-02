# New ports collection makefile for:	p5-bioperl-run
# Date created:		21 February 2006
# Whom:	      		Mauricio Herrera Cuadra <mauricio@arareko.net>
#
# $FreeBSD$
#

PORTNAME=	bioperl-run
PORTVERSION=	1.6.1
PORTREVISION=	1
CATEGORIES=	biology perl5
MASTER_SITES=	http://bioperl.org/DIST/ \
		CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	BioPerl-run-${PORTVERSION}

MAINTAINER=	mauricio@arareko.net
COMMENT=	Wrapper modules for common bioinformatics tools

BUILD_DEPENDS=	p5-bioperl>=1.6.0:${PORTSDIR}/biology/p5-bioperl \
		${SITE_PERL}/IPC/Run.pm:${PORTSDIR}/devel/p5-IPC-Run \
		${SITE_PERL}/Algorithm/Diff.pm:${PORTSDIR}/devel/p5-Algorithm-Diff
RUN_DEPENDS=	${BUILD_DEPENDS}

CONFLICTS=	p5-bioperl-run-1.[13579]*

PERL_MODBUILD=	YES
WRKSRC=		${WRKDIR}/BioPerl-run-1.6.0

MAN1=	bp_bioperl_application_installer.pl.1 \
	bp_multi_hmmsearch.pl.1 \
	bp_panalysis.pl.1 \
	bp_papplmaker.pl.1 \
	bp_run_neighbor.pl.1 \
	bp_run_protdist.pl.1

MAN3=	Bio::Tools::Run::Phylo::Phylip::DrawGram.3 \
	Bio::Tools::Run::Simprot.3 \
	Bio::Tools::Run::Phylo::Phyml.3 \
	Bio::Tools::Run::Phylo::LVB.3 \
	Bio::Tools::Run::Alignment::Amap.3 \
	Bio::Tools::Run::Tmhmm.3 \
	Bio::Tools::Run::TigrAssembler.3 \
	Bio::Tools::Run::Phylo::PAML::Baseml.3 \
	Bio::Installer::Probcons.3 \
	Bio::Tools::Run::Phylo::Phylip::Base.3 \
	Bio::Tools::Run::Alignment::Exonerate.3 \
	Bio::Tools::Run::Alignment::MAFFT.3 \
	Bio::Tools::Run::Alignment::TCoffee.3 \
	Bio::Tools::Run::Alignment::Sim4.3 \
	Bio::Tools::Run::Analysis.3 \
	Bio::Tools::Run::Phylo::PAML::Yn00.3 \
	Bio::Tools::Run::Alignment::Clustalw.3 \
	Bio::Tools::Run::Phylo::Molphy::ProtML.3 \
	Bio::Tools::Run::Phylo::Hyphy::Base.3 \
	Bio::Tools::Run::Meme.3 \
	Bio::Tools::Run::MCS.3 \
	Bio::Tools::Run::Eponine.3 \
	Bio::Tools::Run::Alignment::Kalign.3 \
	Bio::Tools::Run::TribeMCL.3 \
	Bio::Tools::Run::Analysis::soap.3 \
	Bio::Factory::EMBOSS.3 \
	Bio::Installer::Clustalw.3 \
	Bio::Tools::Run::Seg.3 \
	Bio::Tools::Run::Alignment::Probcons.3 \
	Bio::Tools::Run::RepeatMasker.3 \
	Bio::Installer::TCoffee.3 \
	Bio::Tools::Run::AnalysisFactory.3 \
	Bio::Tools::Run::Cap3.3 \
	Bio::Tools::Run::Alignment::Blat.3 \
	Bio::Tools::Run::Phylo::PhyloBase.3 \
	Bio::Tools::Run::Coil.3 \
	Bio::Tools::Run::Promoterwise.3 \
	Bio::Tools::Run::Alignment::Pal2Nal.3 \
	Bio::Tools::Run::ERPIN.3 \
	Bio::Tools::Run::Phylo::PAML::Evolver.3 \
	Bio::Tools::Run::Phylo::Hyphy::REL.3 \
	Bio::Tools::Run::Genscan.3 \
	Bio::Tools::Run::EMBOSSApplication.3 \
	Bio::Tools::Run::Phylo::Hyphy::Modeltest.3 \
	Bio::Tools::Run::Match.3 \
	Bio::Tools::Run::Phylo::Gumby.3 \
	Bio::Tools::Run::Vista.3 \
	Bio::Tools::Run::Phylo::Hyphy::SLAC.3 \
	Bio::Tools::Run::Mdust.3 \
	Bio::Tools::Run::Alignment::Proda.3 \
	Bio::Installer::SLR.3 \
	Bio::Tools::Run::Primate.3 \
	Bio::Tools::Run::Infernal.3 \
	Bio::Tools::Run::Genemark.3 \
	Bio::Tools::Run::Phylo::Phylip::PhylipConf.3 \
	Bio::Tools::Run::EMBOSSacd.3 \
	Bio::Tools::Run::Hmmer.3 \
	Bio::Tools::Run::AnalysisFactory::soap.3 \
	Bio::Tools::Run::Alignment::Lagan.3 \
	Bio::Installer::EMBOSS.3 \
	Bio::Tools::Run::Phrap.3 \
	Bio::Tools::Run::Alignment::Muscle.3 \
	Bio::Tools::Run::tRNAscanSE.3 \
	Bio::Tools::Run::Glimmer.3 \
	Bio::Tools::Run::Phylo::Phylip::SeqBoot.3 \
	Bio::Installer::PAML.3 \
	Bio::Tools::Run::Phylo::Phylip::Neighbor.3 \
	Bio::Tools::Run::Phylo::Phast::PhyloFit.3 \
	Bio::Installer::Hyphy.3 \
	Bio::Tools::Run::Phylo::Phast::PhastCons.3 \
	Bio::Tools::Run::Signalp.3 \
	Bio::Tools::Run::Phylo::Phylip::ProtDist.3 \
	Bio::Installer::Generic.3 \
	Bio::Tools::Run::Phylo::Phylip::DrawTree.3 \
	Bio::Tools::Run::Phylo::SLR.3 \
	Bio::Tools::Run::FootPrinter.3 \
	Bio::Tools::Run::Genewise.3 \
	Bio::Tools::Run::Phylo::Phylip::ProtPars.3 \
	Bio::Tools::Run::RNAMotif.3 \
	Bio::Tools::Run::Alignment::StandAloneFasta.3 \
	Bio::Tools::Run::Alignment::Probalign.3 \
	Bio::Tools::Run::Primer3.3 \
	Bio::Tools::Run::Profile.3 \
	Bio::Tools::Run::Phylo::Njtree::Best.3 \
	Bio::Tools::Run::Phylo::QuickTree.3 \
	Bio::Tools::Run::Pseudowise.3 \
	Bio::Tools::Run::Alignment::DBA.3 \
	Bio::Tools::Run::Phylo::Phylip::Consense.3 \
	Bio::Tools::Run::Phylo::Semphy.3 \
	Bio::Tools::Run::Ensembl.3 \
	Bio::Tools::Run::Phylo::Gerp.3 \
	Bio::Tools::Run::Phylo::PAML::Codeml.3 \
	Bio::Installer::Muscle.3 \
	Bio::Tools::Run::Prints.3 \
	Bio::Tools::Run::Phylo::Hyphy::FEL.3

# now install all extra stuff (docs, examples, scripts)
post-install:
	${MKDIR} ${DATADIR}
	@${CP} -Rv ${WRKSRC}/scripts ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for doc in AUTHORS Changes INSTALL.PROGRAMS README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
