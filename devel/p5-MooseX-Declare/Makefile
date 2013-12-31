# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	MooseX-Declare
PORTVERSION=	0.38
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Declarative syntax for Moose

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Moose>=0.90:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Method-Signatures>=0.36:${PORTSDIR}/devel/p5-MooseX-Method-Signatures \
		p5-MooseX-Role-Parameterized>=0.12:${PORTSDIR}/devel/p5-MooseX-Role-Parameterized \
		p5-MooseX-Types>=0.20:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-Devel-Declare>=0.005011:${PORTSDIR}/devel/p5-Devel-Declare \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Module-Runtime>=0:${PORTSDIR}/devel/p5-Module-Runtime \
		p5-Parse-Method-Signatures>=0:${PORTSDIR}/devel/p5-Parse-Method-Signatures \
		p5-aliased>=0:${PORTSDIR}/devel/p5-aliased \
		p5-namespace-clean>=0.11:${PORTSDIR}/devel/p5-namespace-clean \
		p5-namespace-autoclean>=0.09:${PORTSDIR}/devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
