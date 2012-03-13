# New ports collection makefile for:	p5-MouseX-App-Cmd
# Date created:		2011-12-12
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MouseX-App-Cmd
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MJGARDNER
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Mashes up MouseX::Getopt and App::Cmd

BUILD_DEPENDS=	p5-App-Cmd>=0.300:${PORTSDIR}/devel/p5-App-Cmd \
		p5-Getopt-Long-Descriptive>=0:${PORTSDIR}/devel/p5-Getopt-Long-Descriptive \
		p5-Mouse>=0.86:${PORTSDIR}/devel/p5-Mouse \
		p5-MouseX-ConfigFromFile>=0:${PORTSDIR}/devel/p5-MouseX-ConfigFromFile \
		p5-MouseX-Getopt>=0.1800:${PORTSDIR}/devel/p5-MouseX-Getopt \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Output>=0:${PORTSDIR}/devel/p5-Test-Output \
		p5-Test-use-ok>=0:${PORTSDIR}/devel/p5-Test-use-ok

PERL_CONFIGURE=	yes

MAN3=		MouseX::App::Cmd.3 \
		MouseX::App::Cmd::Command.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501200
TEST_DEPENDS+=	p5-Test-Simple>=0.94:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
