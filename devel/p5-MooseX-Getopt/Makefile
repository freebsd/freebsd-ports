# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MooseX-Getopt
PORTVERSION=	0.62
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
		p5-MooseX-ConfigFromFile>=0:${PORTSDIR}/devel/p5-MooseX-ConfigFromFile \
		p5-MooseX-Role-Parameterized>=0:${PORTSDIR}/devel/p5-MooseX-Role-Parameterized \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-MooseX-SimpleConfig>=0.07:${PORTSDIR}/devel/p5-MooseX-SimpleConfig \
		p5-Module-Runtime>=0:${PORTSDIR}/devel/p5-Module-Runtime \
		p5-Path-Tiny>=0.009:${PORTSDIR}/devel/p5-Path-Tiny \
		p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Fatal>=0.003:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires \
		p5-Test-Trap>=0:${PORTSDIR}/devel/p5-Test-Trap \
		p5-Test-Warnings>=0:${PORTSDIR}/devel/p5-Test-Warnings

USES=		perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
