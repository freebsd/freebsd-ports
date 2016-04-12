# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MouseX-App-Cmd
PORTVERSION=	0.30
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Mashes up MouseX::Getopt and App::Cmd

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-App-Cmd>=0.321:devel/p5-App-Cmd \
		p5-Getopt-Long-Descriptive>=0.091:devel/p5-Getopt-Long-Descriptive \
		p5-Mouse>=0:devel/p5-Mouse \
		p5-MouseX-ConfigFromFile>=0:devel/p5-MouseX-ConfigFromFile \
		p5-MouseX-Getopt>=0:devel/p5-MouseX-Getopt \
		p5-YAML>=0:textproc/p5-YAML \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Output>=0:devel/p5-Test-Output

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
