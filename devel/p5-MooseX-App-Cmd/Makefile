# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	MooseX-App-Cmd
PORTVERSION=	0.32
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Mashes up MooseX::Getopt and App::Cmd

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-App-Cmd>=0.321:devel/p5-App-Cmd \
		p5-Getopt-Long-Descriptive>=0.091:devel/p5-Getopt-Long-Descriptive \
		p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-Getopt>=0:devel/p5-MooseX-Getopt \
		p5-MooseX-NonMoose>=0:devel/p5-MooseX-NonMoose \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-MooseX-ConfigFromFile>=0:devel/p5-MooseX-ConfigFromFile \
		p5-Test-Output>=0:devel/p5-Test-Output \
		p5-YAML>=0:textproc/p5-YAML

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
