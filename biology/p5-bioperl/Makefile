# New ports collection makefile for:	p5-bioperl
# Date created:		28 July 2000
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	bioperl
PORTVERSION=	0.6.2
CATEGORIES=	biology perl5
MASTER_SITES=	ftp://bio.perl.org/pub/DIST/ \
		http://bio.perl.org/Core/Latest/ \
		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=Bio
PKGNAMEPREFIX=	p5-
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} bioperl-ext-0.6.tar.gz

MAINTAINER=	johann@egenetics.com

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/HTTP/Request/Common.pm:${PORTSDIR}/www/p5-libwww \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Ace.pm:${PORTSDIR}/biology/p5-AcePerl \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/IO/Scalar.pm:${PORTSDIR}/devel/p5-IO-stringy

PERL_CONFIGURE=	YES

MAN3=		Bio::Annotation.3 Bio::Annotation::Comment.3 \
		Bio::Annotation::DBLink.3 Bio::Annotation::Reference.3 \
		Bio::DB::Ace.3 Bio::DB::GenBank.3 Bio::DB::GenPept.3 \
		Bio::DB::RandomAccessI.3 Bio::DB::SeqI.3 \
		Bio::Index::Abstract.3 Bio::Index::AbstractSeq.3 \
		Bio::Index::EMBL.3 Bio::Index::Fasta.3 \
		Bio::Index::SwissPfam.3 Bio::LocatableSeq.3 \
		Bio::PrimarySeq.3 Bio::PrimarySeqI.3 Bio::Range.3 \
		Bio::RangeI.3 Bio::Root::Err.3 Bio::Root::Global.3 \
		Bio::Root::IOManager.3 Bio::Root::Object.3 \
		Bio::Root::RootI.3 Bio::Root::Utilities.3 \
		Bio::Root::Vector.3 Bio::Root::Xref.3 \
		Bio::Search::Hit::Fasta.3 Bio::Search::Hit::HitI.3 \
		Bio::Search::Processor.3 Bio::Search::Processor::Fasta.3 \
		Bio::Search::Processor::ProcessorI.3 \
		Bio::Search::Result::Fasta.3 \
		Bio::Search::Result::ResultI.3 Bio::SearchDist.3 \
		Bio::Seq.3 Bio::SeqFeature::FeaturePair.3 \
		Bio::SeqFeature::Generic.3 Bio::SeqFeatureI.3 Bio::SeqI.3 \
		Bio::SeqIO.3 Bio::SeqIO::FTHelper.3 \
		Bio::SeqIO::MultiFile.3 Bio::SeqIO::embl.3 \
		Bio::SeqIO::fasta.3 Bio::SeqIO::gcg.3 \
		Bio::SeqIO::genbank.3 Bio::SeqIO::pir.3 Bio::SeqIO::raw.3 \
		Bio::SeqIO::scf.3 Bio::SeqIO::swiss.3 Bio::SimpleAlign.3 \
		Bio::Species.3 Bio::Tools::AlignFactory.3 \
		Bio::Tools::Blast.3 Bio::Tools::Blast::HSP.3 \
		Bio::Tools::Blast::HTML.3 \
		Bio::Tools::Blast::Run::LocalBlast.3 \
		Bio::Tools::Blast::Run::Webblast.3 \
		Bio::Tools::Blast::Sbjct.3 Bio::Tools::CodonTable.3 \
		Bio::Tools::Fasta.3 Bio::Tools::HMMER::Domain.3 \
		Bio::Tools::HMMER::Results.3 Bio::Tools::HMMER::Set.3 \
		Bio::Tools::IUPAC.3 Bio::Tools::RestrictionEnzyme.3 \
		Bio::Tools::SeqAnal.3 Bio::Tools::SeqPattern.3 \
		Bio::Tools::SeqStats.3 Bio::Tools::SeqWords.3 \
		Bio::Tools::Sigcleave.3 Bio::Tools::WWW.3 \
		Bio::Tools::pSW.3 Bio::UnivAln.3 \
		bioback.3 biodesign.3 bioperl.3 biostart.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

EXT_WRKSRC=	${WRKDIR}/bioperl-ext-06/Bio/Ext/Align

post-configure:
	@ (cd ${EXT_WRKSRC} && \
	  ${SETENV} ${CONFIGURE_ENV} \
	  ${PERL5} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})

post-build:
	@ (cd ${EXT_WRKSRC} && \
	  ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

post-install:
	@ (cd ${EXT_WRKSRC} && \
	  ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
	  ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

.include <bsd.port.mk>
