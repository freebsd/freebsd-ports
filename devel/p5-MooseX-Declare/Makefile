# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	MooseX-Declare
PORTVERSION=	0.43
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Declarative syntax for Moose

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Devel-Declare>=0.005011:devel/p5-Devel-Declare \
		p5-Module-Runtime>=0:devel/p5-Module-Runtime \
		p5-Moose>=0.90:devel/p5-Moose \
		p5-MooseX-Method-Signatures>=0.36:devel/p5-MooseX-Method-Signatures \
		p5-MooseX-Role-Parameterized>=0.12:devel/p5-MooseX-Role-Parameterized \
		p5-MooseX-Types>=0.20:devel/p5-MooseX-Types \
		p5-Parse-Method-Signatures>=0:devel/p5-Parse-Method-Signatures \
		p5-Sub-Exporter>=0:devel/p5-Sub-Exporter \
		p5-Sub-Install>=0:devel/p5-Sub-Install \
		p5-aliased>=0:devel/p5-aliased \
		p5-namespace-autoclean>=0.16:devel/p5-namespace-autoclean \
		p5-namespace-clean>=0.19:devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0:devel/p5-Test-Fatal

DEPRECATED=	Deprecated by upstream
EXPIRATION_DATE=	2017-03-01

USES=		perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
