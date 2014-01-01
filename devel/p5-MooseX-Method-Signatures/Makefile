# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	MooseX-Method-Signatures
PORTVERSION=	0.47
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Method declarations with type constraints and no source filter

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-B-Hooks-EndOfScope>=0.10:${PORTSDIR}/devel/p5-B-Hooks-EndOfScope \
		p5-Devel-Declare>=0.005011:${PORTSDIR}/devel/p5-Devel-Declare \
		p5-Context-Preserve>=0:${PORTSDIR}/devel/p5-Context-Preserve \
		p5-Module-Runtime>=0.012:${PORTSDIR}/devel/p5-Module-Runtime \
		p5-Moose>=0.89:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-LazyRequire>=0.06:${PORTSDIR}/devel/p5-MooseX-LazyRequire \
		p5-MooseX-Meta-TypeConstraint-ForceCoercion>=0:${PORTSDIR}/devel/p5-MooseX-Meta-TypeConstraint-ForceCoercion \
		p5-MooseX-Types>=0.35:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-MooseX-Types-Structured>=0.24:${PORTSDIR}/devel/p5-MooseX-Types-Structured \
		p5-Parse-Method-Signatures>=1.003014:${PORTSDIR}/devel/p5-Parse-Method-Signatures \
		p5-Sub-Name>=0:${PORTSDIR}/devel/p5-Sub-Name \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken \
		p5-aliased>=0:${PORTSDIR}/devel/p5-aliased \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean \
		p5-namespace-clean>=0:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Eval-Closure>=0:${PORTSDIR}/devel/p5-Eval-Closure \
		p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
