# ex:ts=8
# Ports collection makefile for:	Algorithm::Evolutionary
# Date created:			Oct 24, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Algorithm-Evolutionary
PORTVERSION=	0.71
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A library for doing evolutionary computation in Perl

COMMON_DEPENDS=	p5-XML-LibXML>=1.5:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-Algorithm-Permute>=0.01:${PORTSDIR}/devel/p5-Algorithm-Permute \
		p5-Bit-Vector>0:${PORTSDIR}/math/p5-Bit-Vector \
		p5-Clone-Fast>0:${PORTSDIR}/devel/p5-Clone-Fast \
		p5-GD>=2.17:${PORTSDIR}/graphics/p5-GD \
		p5-Math-Random>=0.63:${PORTSDIR}/math/p5-Math-Random \
		p5-Statistics-Basic>=1.6:${PORTSDIR}/math/p5-Statistics-Basic \
		p5-String-Random>0:${PORTSDIR}/devel/p5-String-Random \
		p5-Object-Array>0:${PORTSDIR}/devel/p5-Object-Array \
		p5-Tree-DAG_Node>=1.04:${PORTSDIR}/devel/p5-Tree-DAG_Node \
		p5-XML-Parser>0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-XML-Parser-Style-EasyTree>=0.01:${PORTSDIR}/textproc/p5-XML-Parser-Style-EasyTree \
		p5-YAML>0:${PORTSDIR}/textproc/p5-YAML \
		p5-version>0:${PORTSDIR}/devel/p5-version
BUILD_DEPENDS=	${COMMON_DEPENDS}
RUN_DEPENDS=	${COMMON_DEPENDS}
BUILD_DEPENDS+=	p5-Test-Pod>0:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Pod-Escapes>0:${PORTSDIR}/textproc/p5-Pod-Escapes

PERL_CONFIGURE=	yes

MAN1=	tide_bitstring.pl.1 tide_float.pl.1 \
	canonical-genetic-algorithm.pl.1 rectangle-coverage.pl.1
MAN3=	Algorithm::Evolutionary.3 \
	Algorithm::Evolutionary::Experiment.3 \
	Algorithm::Evolutionary::Fitness::Any.3 \
	Algorithm::Evolutionary::Fitness::Base.3 \
	Algorithm::Evolutionary::Fitness::ECC.3 \
	Algorithm::Evolutionary::Fitness::Knapsack.3 \
	Algorithm::Evolutionary::Fitness::MMDP.3 \
	Algorithm::Evolutionary::Fitness::ONEMAX.3 \
	Algorithm::Evolutionary::Fitness::P_Peaks.3 \
	Algorithm::Evolutionary::Fitness::Royal_Road.3 \
	Algorithm::Evolutionary::Fitness::String.3 \
	Algorithm::Evolutionary::Fitness::Trap.3 \
	Algorithm::Evolutionary::Fitness::ZDT1.3 \
	Algorithm::Evolutionary::Fitness::wP_Peaks.3 \
	Algorithm::Evolutionary::Hash_Wheel.3 \
	Algorithm::Evolutionary::Individual::Any.3 \
	Algorithm::Evolutionary::Individual::Base.3 \
	Algorithm::Evolutionary::Individual::BitString.3 \
	Algorithm::Evolutionary::Individual::Bit_Vector.3 \
	Algorithm::Evolutionary::Individual::String.3 \
	Algorithm::Evolutionary::Individual::Tree.3 \
	Algorithm::Evolutionary::Individual::Vector.3 \
	Algorithm::Evolutionary::Op::Animated_GIF_Output.3 \
	Algorithm::Evolutionary::Op::ArithCrossover.3 \
	Algorithm::Evolutionary::Op::Base.3 \
	Algorithm::Evolutionary::Op::Bitflip.3 \
	Algorithm::Evolutionary::Op::CX.3 \
	Algorithm::Evolutionary::Op::CanonicalGA.3 \
	Algorithm::Evolutionary::Op::ChangeLengthMutation.3 \
	Algorithm::Evolutionary::Op::Convergence_Terminator.3 \
	Algorithm::Evolutionary::Op::Creator.3 \
	Algorithm::Evolutionary::Op::Crossover.3 \
	Algorithm::Evolutionary::Op::DeltaTerm.3 \
	Algorithm::Evolutionary::Op::EDA_step.3 \
	Algorithm::Evolutionary::Op::Easy.3 \
	Algorithm::Evolutionary::Op::Easy_MO.3 \
	Algorithm::Evolutionary::Op::Eval::General.3 \
	Algorithm::Evolutionary::Op::Eval::MO_Rank.3 \
	Algorithm::Evolutionary::Op::FullAlgorithm.3 \
	Algorithm::Evolutionary::Op::GaussianMutation.3 \
	Algorithm::Evolutionary::Op::Gene_Boundary_Crossover.3 \
	Algorithm::Evolutionary::Op::GeneralGeneration.3 \
	Algorithm::Evolutionary::Op::Generation_Skeleton.3 \
	Algorithm::Evolutionary::Op::GenerationalTerm.3 \
	Algorithm::Evolutionary::Op::IncMutation.3 \
	Algorithm::Evolutionary::Op::Inverover.3 \
	Algorithm::Evolutionary::Op::LinearFreezer.3 \
	Algorithm::Evolutionary::Op::Mutation.3 \
	Algorithm::Evolutionary::Op::NoChangeTerm.3 \
	Algorithm::Evolutionary::Op::Novelty_Mutation.3 \
	Algorithm::Evolutionary::Op::Permutation.3 \
	Algorithm::Evolutionary::Op::Population_Output.3 \
	Algorithm::Evolutionary::Op::QuadXOver.3 \
	Algorithm::Evolutionary::Op::Replace_Worst.3 \
	Algorithm::Evolutionary::Op::RouletteWheel.3 \
	Algorithm::Evolutionary::Op::Selector.3 \
	Algorithm::Evolutionary::Op::SimulatedAnnealing.3 \
	Algorithm::Evolutionary::Op::Storing.3 \
	Algorithm::Evolutionary::Op::StringRand.3 \
	Algorithm::Evolutionary::Op::TournamentSelect.3 \
	Algorithm::Evolutionary::Op::TreeMutation.3 \
	Algorithm::Evolutionary::Op::Uniform_Crossover.3 \
	Algorithm::Evolutionary::Op::VectorCrossover.3 \
	Algorithm::Evolutionary::Run.3 \
	Algorithm::Evolutionary::Utils.3 \
	Algorithm::Evolutionary::Wheel.3 \
	Algorithm::Evolutionary::XML.3

post-patch:
	${PERL} -pi -e 's/(.*?(\S+::Wheel).*)/use \2;\1/' ${WRKSRC}/lib/Algorithm/Evolutionary/Op/GeneralGeneration.pm

.include <bsd.port.mk>
