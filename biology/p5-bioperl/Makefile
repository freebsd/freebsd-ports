# New ports collection makefile for:	p5-bioperl
# Date created:		28 July 2000
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	bioperl
PORTVERSION=	0.7.2
CATEGORIES=	biology perl5
MASTER_SITES=	ftp://bioperl.org/pub/DIST/ \
		http://bioperl.org/Core/Latest/ \
		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Bio
PKGNAMEPREFIX=	p5-
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	wjv@FreeBSD.org

# These are all run-time dependencies, but listing them in ${BUILD_DEPENDS}
# prevents a flood of build-time warnings.
BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Ace.pm:${PORTSDIR}/biology/p5-AcePerl \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/HTTP/Request/Common.pm:${PORTSDIR}/www/p5-libwww \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/IO/Scalar.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/IO/String.pm:${PORTSDIR}/devel/p5-IO-String \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/XML/Node.pm:${PORTSDIR}/textproc/p5-XML-Node \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/XML/Parser/PerlSAX.pm:${PORTSDIR}/textproc/p5-libxml \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/XML/Writer.pm:${PORTSDIR}/textproc/p5-XML-Writer
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

.if defined(WITH_CORBA)
WITH_CORBA_CLIENT=	YES
WITH_CORBA_SERVER=	YES
.endif

EXT_VERSION=	0.6
CORBA_CLIENT_VERSION=	0.2
CORBA_SERVER_VERSION=	0.2
GUI_VERSION=	0.7
DISTFILES+=	bioperl-ext-${EXT_VERSION}${EXTRACT_SUFX}
EXT_WRKSRC=	${WRKDIR}/bioperl-ext-06/Bio/Ext/Align

.if defined(WITH_CORBA_CLIENT)
BUILD_DEPENDS+=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/CORBA/ORBit.pm:${PORTSDIR}/devel/p5-ORBit
RUN_DEPENDS+=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/CORBA/ORBit.pm:${PORTSDIR}/devel/p5-ORBit
.endif
.if defined(WITH_CORBA_SERVER)
BUILD_DEPENDS+=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/CORBA/ORBit.pm:${PORTSDIR}/devel/p5-ORBit
RUN_DEPENDS+=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/CORBA/ORBit.pm:${PORTSDIR}/devel/p5-ORBit
.endif
.if defined(WITH_GUI)
RUN_DEPENDS+=	ptksh:${PORTSDIR}/x11-toolkits/p5-Tk
.endif

.for ext in CORBA_CLIENT CORBA_SERVER GUI
.if defined(WITH_${ext})
EXTLIST+=	${ext}
DISTFILES+=	bioperl-${ext:L:S/_/-/}-${${ext}_VERSION}${EXTRACT_SUFX}
${ext}_WRKSRC=	${WRKDIR}/bioperl-${ext:L:S/_/-/}
PLIST_${ext}=	""
.else
PLIST_${ext}=	"@comment "
.endif
PLIST_SUB+=	PLIST_${ext}=${PLIST_${ext}}
.endfor

MAN3=		Bio::AlignIO.3 Bio::AlignIO::bl2seq.3 \
		Bio::AlignIO::clustalw.3 Bio::AlignIO::fasta.3 \
		Bio::AlignIO::mase.3 Bio::AlignIO::msf.3 Bio::AlignIO::pfam.3 \
		Bio::AlignIO::prodom.3 Bio::AlignIO::selex.3 \
		Bio::AlignIO::stockholm.3 Bio::Annotation.3 \
		Bio::Annotation::Comment.3 Bio::Annotation::DBLink.3 \
		Bio::Annotation::Reference.3 Bio::DB::Ace.3 Bio::DB::GDB.3 \
		Bio::DB::GenBank.3 Bio::DB::GenPept.3 Bio::DB::NCBIHelper.3 \
		Bio::DB::RandomAccessI.3 Bio::DB::SeqI.3 Bio::DB::SwissProt.3 \
		Bio::DB::UpdateableSeqI.3 Bio::DB::WebDBSeqI.3 \
		Bio::DBLinkContainerI.3 Bio::Factory::DriverFactory.3 \
		Bio::Factory::SeqAnalysisParserFactory.3 \
		Bio::Factory::SeqAnalysisParserFactoryI.3 \
		Bio::Index::Abstract.3 Bio::Index::AbstractSeq.3 \
		Bio::Index::EMBL.3 Bio::Index::Fasta.3 Bio::Index::GenBank.3 \
		Bio::Index::SwissPfam.3 Bio::Index::Swissprot.3 \
		Bio::LiveSeq::AARange.3 Bio::LiveSeq::Chain.3 \
		Bio::LiveSeq::ChainI.3 Bio::LiveSeq::DNA.3 \
		Bio::LiveSeq::Exon.3 Bio::LiveSeq::Gene.3 \
		Bio::LiveSeq::IO::BioPerl.3 Bio::LiveSeq::IO::Loader.3 \
		Bio::LiveSeq::IO::SRS.3 Bio::LiveSeq::Intron.3 \
		Bio::LiveSeq::Mutation.3 Bio::LiveSeq::Mutator.3 \
		Bio::LiveSeq::Prim_Transcript.3 Bio::LiveSeq::Range.3 \
		Bio::LiveSeq::Repeat_Region.3 Bio::LiveSeq::Repeat_Unit.3 \
		Bio::LiveSeq::SeqI.3 Bio::LiveSeq::Transcript.3 \
		Bio::LiveSeq::Translation.3 Bio::LocatableSeq.3 \
		Bio::Location::AvWithinCoordPolicy.3 \
		Bio::Location::CoordinatePolicyI.3 Bio::Location::Fuzzy.3 \
		Bio::Location::FuzzyLocationI.3 \
		Bio::Location::NarrowestCoordPolicy.3 Bio::Location::Simple.3 \
		Bio::Location::Split.3 Bio::Location::SplitLocationI.3 \
		Bio::Location::WidestCoordPolicy.3 Bio::LocationI.3 \
		Bio::PrimarySeq.3 Bio::PrimarySeqI.3 Bio::Range.3 \
		Bio::RangeI.3 Bio::Root::Err.3 Bio::Root::Global.3 \
		Bio::Root::IO.3 Bio::Root::IOManager.3 Bio::Root::Object.3 \
		Bio::Root::RootI.3 Bio::Root::Utilities.3 Bio::Root::Vector.3 \
		Bio::Root::Xref.3 Bio::SearchDist.3 Bio::Seq.3 \
		Bio::Seq::LargePrimarySeq.3 Bio::Seq::LargeSeq.3 \
		Bio::Seq::RichSeq.3 Bio::Seq::RichSeqI.3 \
		Bio::SeqAnalysisParserI.3 Bio::SeqFeature::FeaturePair.3 \
		Bio::SeqFeature::Gene::Exon.3 Bio::SeqFeature::Gene::ExonI.3 \
		Bio::SeqFeature::Gene::GeneStructure.3 \
		Bio::SeqFeature::Gene::GeneStructureI.3 \
		Bio::SeqFeature::Gene::Transcript.3 \
		Bio::SeqFeature::Gene::TranscriptI.3 \
		Bio::SeqFeature::Generic.3 Bio::SeqFeature::Similarity.3 \
		Bio::SeqFeature::SimilarityPair.3 Bio::SeqFeatureI.3 \
		Bio::SeqI.3 Bio::SeqIO.3 Bio::SeqIO::FTHelper.3 \
		Bio::SeqIO::MultiFile.3 Bio::SeqIO::ace.3 Bio::SeqIO::embl.3 \
		Bio::SeqIO::fasta.3 Bio::SeqIO::game.3 Bio::SeqIO::gcg.3 \
		Bio::SeqIO::genbank.3 Bio::SeqIO::largefasta.3 \
		Bio::SeqIO::raw.3 Bio::SeqIO::scf.3 Bio::SeqIO::swiss.3 \
		Bio::SeqUtils.3 Bio::SimpleAlign.3 Bio::Species.3 \
		Bio::Tools::AlignFactory.3 Bio::Tools::AnalysisResult.3 \
		Bio::Tools::BPbl2seq.3 Bio::Tools::BPlite.3 \
		Bio::Tools::BPlite::Iteration.3 Bio::Tools::BPpsilite.3 \
		Bio::Tools::Blast.3 Bio::Tools::Blast::HSP.3 \
		Bio::Tools::Blast::HTML.3 \
		Bio::Tools::Blast::Run::LocalBlast.3 \
		Bio::Tools::Blast::Run::Webblast.3 Bio::Tools::Blast::Sbjct.3 \
		Bio::Tools::CodonTable.3 Bio::Tools::ESTScan.3 \
		Bio::Tools::Fasta.3 Bio::Tools::GFF.3 Bio::Tools::Genscan.3 \
		Bio::Tools::HMMER::Domain.3 Bio::Tools::HMMER::Results.3 \
		Bio::Tools::HMMER::Set.3 Bio::Tools::IUPAC.3 \
		Bio::Tools::MZEF.3 Bio::Tools::OddCodes.3 \
		Bio::Tools::Prediction::Exon.3 Bio::Tools::Prediction::Gene.3 \
		Bio::Tools::RestrictionEnzyme.3 \
		Bio::Tools::Run::Alignment::Clustalw.3 \
		Bio::Tools::Run::Alignment::TCoffee.3 \
		Bio::Tools::Run::StandAloneBlast.3 Bio::Tools::SeqAnal.3 \
		Bio::Tools::SeqPattern.3 Bio::Tools::SeqStats.3 \
		Bio::Tools::SeqWords.3 Bio::Tools::Sigcleave.3 \
		Bio::Tools::Sim4::Exon.3 Bio::Tools::Sim4::Results.3 \
		Bio::Tools::WWW.3 Bio::Tools::pSW.3 Bio::UnivAln.3 \
		Bio::Variation::AAChange.3 Bio::Variation::AAReverseMutate.3 \
		Bio::Variation::Allele.3 Bio::Variation::DNAMutation.3 \
		Bio::Variation::IO.3 Bio::Variation::IO::flat.3 \
		Bio::Variation::IO::xml.3 Bio::Variation::RNAChange.3 \
		Bio::Variation::SeqDiff.3 Bio::Variation::VariantI.3 \
		bioback.3 biodesign.3 bioperl.3 biostart.3 bptutorial.3
.if defined(WITH_CORBA_CLIENT)
MAN3+=		Bio::CorbaClient::PrimarySeq.3 Bio::CorbaClient::Seq.3 \
		Bio::CorbaClient::SeqFeature.3 Bio::CorbaClient::Base.3 \
		Bio::SeqIO::biocorba.3 Bio::DB::Biocorba.3 \
		Bio::CorbaClient::Client.3 Bio::CorbaClient::ORB.3
.endif
.if defined(WITH_CORBA_SERVER)
MAN3+=		Bio::CorbaServer::BioEnv.3 Bio::CorbaServer::AnonymousSeq.3 \
		Bio::CorbaServer::PrimarySeq.3 Bio::CorbaServer::SeqFeature.3 \
		Bio::CorbaServer::PrimarySeqDB.3 \
		Bio::CorbaServer::PrimarySeqIterator.3 \
		Bio::CorbaServer::PrimarySeqVector.3 \
		Bio::CorbaServer::Seq.3 \
		Bio::CorbaServer::SeqDB.3 Bio::CorbaServer::Base.3 \
		Bio::CorbaServer::SeqFeatureIterator.3 \
		Bio::CorbaServer::SeqFeatureVector.3 \
		Bio::CorbaServer::Server.3
.endif
.if defined(WITH_GUI)
MAN3+=		Bio::Tk::HitDisplay.3 Bio::Tk::SeqCanvas.3
.endif
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

pre-fetch:
.if !defined(BATCH) && (!defined(WITH_CORBA_CLIENT) || \
    !defined(WITH_CORBA_SERVER) || !defined(WITH_GUI))
	@ ${CAT} ${FILESDIR}/ext.msg
.endif

post-configure:
	@ cd ${EXT_WRKSRC} && \
	  ${SETENV} ${CONFIGURE_ENV} \
	  ${PERL5} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}

.for ext in ${EXTLIST}
	@ cd ${${ext}_WRKSRC} && \
	  ${PERL5} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}
.endfor

post-build:
	@ cd ${EXT_WRKSRC} && \
	  ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}
.for ext in ${EXTLIST}
	@ cd ${${ext}_WRKSRC} && ${SETENV} ${MAKE_ENV} \
	  ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}
.endfor

post-install:
	@ cd ${EXT_WRKSRC} && \
	  ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
	  ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}
.for ext in ${EXTLIST}
	@ cd ${${ext}_WRKSRC} && \
	  ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
	  ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}
.endfor

.include <bsd.port.mk>
