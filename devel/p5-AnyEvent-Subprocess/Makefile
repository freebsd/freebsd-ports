# New ports collection makefile for:	p5-AnyEvent-Subprocess
# Date created:	   24 Mar 2010
# Whom:		   Denis Pokataev <catone@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	AnyEvent-Subprocess
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	catone@cpan.org
COMMENT=	Flexible, OO, asynchronous process spawning and management

RUN_DEPENDS=	p5-AnyEvent>=5.2:${PORTSDIR}/devel/p5-AnyEvent \
		p5-Event-Join>=0.04:${PORTSDIR}/devel/p5-Event-Join \
		p5-IO-Tty>=0:${PORTSDIR}/devel/p5-IO-Tty \
		p5-Moose>=0.91:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Clone>=0:${PORTSDIR}/devel/p5-MooseX-Clone \
		p5-MooseX-Role-Parameterized>=0:${PORTSDIR}/devel/p5-MooseX-Role-Parameterized \
		p5-MooseX-StrictConstructor>=0:${PORTSDIR}/devel/p5-MooseX-StrictConstructor \
		p5-MooseX-Types>=0.19:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		AnyEvent::Subprocess.3 \
		AnyEvent::Subprocess::DefaultDelegates.3 \
		AnyEvent::Subprocess::Delegate.3 \
		AnyEvent::Subprocess::Done.3 \
		AnyEvent::Subprocess::Done::Delegate.3 \
		AnyEvent::Subprocess::Done::Delegate::CaptureHandle.3 \
		AnyEvent::Subprocess::Done::Delegate::State.3 \
		AnyEvent::Subprocess::Easy.3 \
		AnyEvent::Subprocess::Handle.3 \
		AnyEvent::Subprocess::Job.3 \
		AnyEvent::Subprocess::Job::Delegate.3 \
		AnyEvent::Subprocess::Job::Delegate::CaptureHandle.3 \
		AnyEvent::Subprocess::Job::Delegate::Handle.3 \
		AnyEvent::Subprocess::Job::Delegate::MonitorHandle.3 \
		AnyEvent::Subprocess::Job::Delegate::Pty.3 \
		AnyEvent::Subprocess::Role::WithDelegates.3 \
		AnyEvent::Subprocess::Role::WithDelegates::Manager.3 \
		AnyEvent::Subprocess::Running.3 \
		AnyEvent::Subprocess::Running::Delegate.3 \
		AnyEvent::Subprocess::Types.3

.include <bsd.port.mk>
