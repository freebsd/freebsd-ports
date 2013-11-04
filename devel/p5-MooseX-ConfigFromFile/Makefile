# $FreeBSD$

PORTNAME=	MooseX-ConfigFromFile
PORTVERSION=	0.12
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to abstract Moose role attribute setting from file

RUN_DEPENDS=	\
	p5-Moose>0:${PORTSDIR}/devel/p5-Moose \
	p5-MooseX-Types>=0.19:${PORTSDIR}/devel/p5-MooseX-Types \
	p5-MooseX-Types-Path-Tiny>=0.005:${PORTSDIR}/devel/p5-MooseX-Types-Path-Tiny \
	p5-namespace-autoclean>0:${PORTSDIR}/devel/p5-namespace-autoclean
BUILD_DEPENDS:=	${RUN_DEPENDS} \
	p5-Module-Build-Tiny>0:${PORTSDIR}/devel/p5-Module-Build-Tiny
TEST_DEPENDS=	\
	p5-Test-CheckDeps>=0.006:${PORTSDIR}/devel/p5-Test-CheckDeps \
	p5-Test-Requires>0:${PORTSDIR}/devel/p5-Test-Requires \
	p5-Test-Fatal>0:${PORTSDIR}/devel/p5-Test-Fatal \
	p5-Test-NoWarnings>=1.04:${PORTSDIR}/devel/p5-Test-NoWarnings \
	p5-Test-Without-Module>0:${PORTSDIR}/devel/p5-Test-Without-Module \
	p5-Test-Deep>0:${PORTSDIR}/devel/p5-Test-Deep

USES=	perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
