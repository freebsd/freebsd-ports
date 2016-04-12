# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	MooseX-Method-Signatures
PORTVERSION=	0.49
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Method declarations with type constraints and no source filter

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-B-Hooks-EndOfScope>=0.10:devel/p5-B-Hooks-EndOfScope \
		p5-Devel-Declare>=0.005011:devel/p5-Devel-Declare \
		p5-Context-Preserve>=0:devel/p5-Context-Preserve \
		p5-Module-Runtime>=0.012:devel/p5-Module-Runtime \
		p5-Moose>=0.89:devel/p5-Moose \
		p5-MooseX-LazyRequire>=0.06:devel/p5-MooseX-LazyRequire \
		p5-MooseX-Meta-TypeConstraint-ForceCoercion>=0:devel/p5-MooseX-Meta-TypeConstraint-ForceCoercion \
		p5-MooseX-Types>=0.35:devel/p5-MooseX-Types \
		p5-MooseX-Types-Structured>=0.24:devel/p5-MooseX-Types-Structured \
		p5-Parse-Method-Signatures>=1.003014:devel/p5-Parse-Method-Signatures \
		p5-Sub-Name>=0:devel/p5-Sub-Name \
		p5-Task-Weaken>=0:devel/p5-Task-Weaken \
		p5-aliased>=0:devel/p5-aliased \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean \
		p5-namespace-clean>=0.19:devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Eval-Closure>=0:devel/p5-Eval-Closure \
		p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
