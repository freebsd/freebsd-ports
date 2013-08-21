# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MouseX-App-Cmd
PORTVERSION=	0.11
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Mashes up MouseX::Getopt and App::Cmd

BUILD_DEPENDS=	p5-App-Cmd>=0.300:${PORTSDIR}/devel/p5-App-Cmd \
		p5-Getopt-Long-Descriptive>=0.091:${PORTSDIR}/devel/p5-Getopt-Long-Descriptive \
		p5-Mouse>=0.86:${PORTSDIR}/devel/p5-Mouse \
		p5-MouseX-ConfigFromFile>=0:${PORTSDIR}/devel/p5-MouseX-ConfigFromFile \
		p5-MouseX-Getopt>=0.1800:${PORTSDIR}/devel/p5-MouseX-Getopt \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Output>=0:${PORTSDIR}/devel/p5-Test-Output \
		p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires \
		p5-Test-use-ok>=0:${PORTSDIR}/devel/p5-Test-use-ok

USE_PERL5=	configure
USES=		perl5

MAN3=		MouseX::App::Cmd.3 \
		MouseX::App::Cmd::Command.3

.include <bsd.port.mk>
