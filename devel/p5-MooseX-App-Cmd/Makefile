# New ports collection makefile for:	p5-MooseX-App-Cmd
# Date created:		2010-11-12
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	MooseX-App-Cmd
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Mashes up MooseX::Getopt and App::Cmd

RUN_DEPENDS=	p5-App-Cmd>=0.3:${PORTSDIR}/devel/p5-App-Cmd \
		p5-Getopt-Long-Descriptive>=0:${PORTSDIR}/devel/p5-Getopt-Long-Descriptive \
		p5-Moose>=0.86:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Getopt>=0.18:${PORTSDIR}/devel/p5-MooseX-Getopt

PERL_CONFIGURE=	yes

MAN3=		MooseX::App::Cmd.3 \
		MooseX::App::Cmd::Command.3

.include <bsd.port.mk>
