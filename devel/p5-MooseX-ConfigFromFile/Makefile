# $FreeBSD$

PORTNAME=	MooseX-ConfigFromFile
PORTVERSION=	0.14
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to abstract Moose role attribute setting from file

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Moose>0:devel/p5-Moose \
	p5-MooseX-Types>=0.19:devel/p5-MooseX-Types \
	p5-MooseX-Types-Path-Tiny>=0.005:devel/p5-MooseX-Types-Path-Tiny \
	p5-namespace-autoclean>0:devel/p5-namespace-autoclean
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-CheckDeps>=0.006:devel/p5-Test-CheckDeps \
	p5-Test-Requires>0:devel/p5-Test-Requires \
	p5-Test-Fatal>0:devel/p5-Test-Fatal \
	p5-Test-NoWarnings>=1.04:devel/p5-Test-NoWarnings \
	p5-Test-Without-Module>0:devel/p5-Test-Without-Module \
	p5-Test-Deep>0:devel/p5-Test-Deep

USES=	perl5
USE_PERL5=	modbuildtiny
NO_ARCH=	YES

.include <bsd.port.mk>
