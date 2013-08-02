# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MooseX-Getopt
PORTVERSION=	0.56
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ETHER
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Moose role for processing command line options

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Getopt-Long-Descriptive>=0.081:${PORTSDIR}/devel/p5-Getopt-Long-Descriptive \
		p5-Moose>=0.56:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Role-Parameterized>=0:${PORTSDIR}/devel/p5-MooseX-Role-Parameterized
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-MooseX-ConfigFromFile>=0:${PORTSDIR}/devel/p5-MooseX-ConfigFromFile \
		p5-MooseX-SimpleConfig>=0.07:${PORTSDIR}/devel/p5-MooseX-SimpleConfig \
		p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-CheckDeps>=0:${PORTSDIR}/devel/p5-Test-CheckDeps \
		p5-Test-Fatal>=0.003:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-Requires>=0.05:${PORTSDIR}/devel/p5-Test-Requires \
		p5-Test-Trap>=0:${PORTSDIR}/devel/p5-Test-Trap \
		p5-Test-Warn>=0.21:${PORTSDIR}/devel/p5-Test-Warn \
		p5-Path-Tiny>=0:${PORTSDIR}/devel/p5-Path-Tiny

USES=		perl5
USE_PERL5=	configure

MAN3=	MooseX::Getopt.3 \
	MooseX::Getopt::Basic.3 \
	MooseX::Getopt::Dashes.3 \
	MooseX::Getopt::GLD.3 \
	MooseX::Getopt::Meta::Attribute.3 \
	MooseX::Getopt::Meta::Attribute::NoGetopt.3 \
	MooseX::Getopt::Meta::Attribute::Trait.3 \
	MooseX::Getopt::Meta::Attribute::Trait::NoGetopt.3 \
	MooseX::Getopt::OptionTypeMap.3 \
	MooseX::Getopt::ProcessedArgv.3 \
	MooseX::Getopt::Strict.3

.include <bsd.port.mk>
