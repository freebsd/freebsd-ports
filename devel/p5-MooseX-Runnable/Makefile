# New ports collection makefile for:	p5-MooseX-Runnable
# Date created:		2011-06-11
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Runnable
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tag a class as a runnable application

RUN_DEPENDS=	p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Getopt>=0:${PORTSDIR}/devel/p5-MooseX-Getopt \
		p5-MooseX-Types>=0:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-MooseX-Types-Path-Class>=0:${PORTSDIR}/devel/p5-MooseX-Types-Path-Class \
		p5-Params-Util>=0:${PORTSDIR}/devel/p5-Params-Util \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean

PERL_CONFIGURE=	yes

MAN1=		mx-run.1
MAN3=		MooseX::Runnable.3 \
		MooseX::Runnable::Invocation::Plugin::Debug.3 \
		MooseX::Runnable::Invocation::Scheme::MooseX::Getopt.3 \
		MooseX::Runnable::Run.3 \
		MooseX::Runnable::Util::ArgParser.3

.include <bsd.port.mk>
