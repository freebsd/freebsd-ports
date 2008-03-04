# ex:ts=8
# Ports collection makefile for:	Algorithm::Evolutionary
# Date created:			Oct 24, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Algorithm-Evolutionary
PORTVERSION=	0.54
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A library for doing evolutionary computation in Perl

BUILD_DEPENDS=	p5-XML-LibXML>=1.5:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS=	p5-Algorithm-Permute>=0.01:${PORTSDIR}/devel/p5-Algorithm-Permute \
		p5-Math-Random>=0.63:${PORTSDIR}/math/p5-Math-Random \
		p5-Tree-DAG_Node>=1.04:${PORTSDIR}/devel/p5-Tree-DAG_Node \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-XML-Parser-EasyTree>=0.01:${PORTSDIR}/textproc/p5-XML-Parser-EasyTree

PERL_CONFIGURE=	yes

MAN3=	Algorithm::Evolutionary.3 \
	Algorithm::Evolutionary::Experiment.3 \
	Algorithm::Evolutionary::Individual::Base.3 \
	Algorithm::Evolutionary::Individual::BitString.3 \
	Algorithm::Evolutionary::Individual::String.3 \
	Algorithm::Evolutionary::Individual::Tree.3 \
	Algorithm::Evolutionary::Individual::Vector.3 \
	Algorithm::Evolutionary::Op::ArithCrossover.3 \
	Algorithm::Evolutionary::Op::Base.3 \
	Algorithm::Evolutionary::Op::Bitflip.3 \
	Algorithm::Evolutionary::Op::CX.3 \
	Algorithm::Evolutionary::Op::CanonicalGA.3 \
	Algorithm::Evolutionary::Op::ChangeLengthMutation.3 \
	Algorithm::Evolutionary::Op::Creator.3 \
	Algorithm::Evolutionary::Op::Crossover.3 \
	Algorithm::Evolutionary::Op::DeltaTerm.3 \
	Algorithm::Evolutionary::Op::Easy.3 \
	Algorithm::Evolutionary::Op::FullAlgorithm.3 \
	Algorithm::Evolutionary::Op::GaussianMutation.3 \
	Algorithm::Evolutionary::Op::GeneralGeneration.3 \
	Algorithm::Evolutionary::Op::GenerationalTerm.3 \
	Algorithm::Evolutionary::Op::IncMutation.3 \
	Algorithm::Evolutionary::Op::Inverover.3 \
	Algorithm::Evolutionary::Op::LinearFreezer.3 \
	Algorithm::Evolutionary::Op::Mutation.3 \
	Algorithm::Evolutionary::Op::NoChangeTerm.3 \
	Algorithm::Evolutionary::Op::Permutation.3 \
	Algorithm::Evolutionary::Op::QuadXOver.3 \
	Algorithm::Evolutionary::Op::RouletteWheel.3 \
	Algorithm::Evolutionary::Op::SimulatedAnnealing.3 \
	Algorithm::Evolutionary::Op::TournamentSelect.3 \
	Algorithm::Evolutionary::Op::TreeMutation.3 \
	Algorithm::Evolutionary::Op::VectorCrossover.3 \
	Algorithm::Evolutionary::Wheel.3 \
	Algorithm::Evolutionary::XML.3

.include <bsd.port.mk>
