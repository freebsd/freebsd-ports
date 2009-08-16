# New ports collection makefile for:	devel/p5-MooseX-Daemonize
# Date created:				28 Jul 2008
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Daemonize
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Role for daemonizing your Moose based application

RUN_DEPENDS=	p5-Moose>=0.33:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Getopt>=0.07:${PORTSDIR}/devel/p5-MooseX-Getopt \
		p5-MooseX-Types-Path-Class>=0:${PORTSDIR}/devel/p5-MooseX-Types-Path-Class
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	MooseX::Daemonize.3 \
	MooseX::Daemonize::Core.3 \
	MooseX::Daemonize::Pid.3 \
	MooseX::Daemonize::Pid::File.3 \
	MooseX::Daemonize::WithPidFile.3 \
	Test::MooseX::Daemonize.3

.include <bsd.port.mk>
