# Created by: Denis Pokataev <catone@cpan.org>
# $FreeBSD$

PORTNAME=	AnyEvent-Subprocess
PORTVERSION=	1.102912
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	catone@cpan.org
COMMENT=	Flexible, OO, asynchronous process spawning and management

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-AnyEvent>=5.2:${PORTSDIR}/devel/p5-AnyEvent \
		p5-EV>=4.0:${PORTSDIR}/devel/p5-EV \
		p5-Event-Join>=0.05:${PORTSDIR}/devel/p5-Event-Join \
		p5-IO-Tty>=0:${PORTSDIR}/devel/p5-IO-Tty \
		p5-JSON>=2:${PORTSDIR}/converters/p5-JSON \
		p5-Moose>=1.15:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Clone>=0:${PORTSDIR}/devel/p5-MooseX-Clone \
		p5-MooseX-Role-Parameterized>=0:${PORTSDIR}/devel/p5-MooseX-Role-Parameterized \
		p5-MooseX-StrictConstructor>=0:${PORTSDIR}/devel/p5-MooseX-StrictConstructor \
		p5-MooseX-Types>=0.19:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-MooseX-Types-Signal>=0:${PORTSDIR}/devel/p5-MooseX-Types-Signal \
		p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean \
		p5-namespace-clean>0:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Exception>0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-use-ok>0:${PORTSDIR}/devel/p5-Test-use-ok

USES=		perl5
USE_PERL5=	configure

MAN3=		AnyEvent::Subprocess.3 \
		AnyEvent::Subprocess::DefaultDelegates.3 \
		AnyEvent::Subprocess::Delegate.3 \
		AnyEvent::Subprocess::Done.3 \
		AnyEvent::Subprocess::Done::Delegate.3 \
		AnyEvent::Subprocess::Done::Delegate::CaptureHandle.3 \
		AnyEvent::Subprocess::Done::Delegate::Handle.3 \
		AnyEvent::Subprocess::Done::Delegate::State.3 \
		AnyEvent::Subprocess::Done::Delegate::Timeout.3 \
		AnyEvent::Subprocess::Easy.3 \
		AnyEvent::Subprocess::Handle.3 \
		AnyEvent::Subprocess::Job.3 \
		AnyEvent::Subprocess::Job::Delegate.3 \
		AnyEvent::Subprocess::Job::Delegate::Callback.3 \
		AnyEvent::Subprocess::Job::Delegate::CaptureHandle.3 \
		AnyEvent::Subprocess::Job::Delegate::CompletionCondvar.3 \
		AnyEvent::Subprocess::Job::Delegate::Handle.3 \
		AnyEvent::Subprocess::Job::Delegate::MonitorHandle.3 \
		AnyEvent::Subprocess::Job::Delegate::PrintError.3 \
		AnyEvent::Subprocess::Job::Delegate::Pty.3 \
		AnyEvent::Subprocess::Job::Delegate::Timeout.3 \
		AnyEvent::Subprocess::Role::WithDelegates.3 \
		AnyEvent::Subprocess::Role::WithDelegates::Manager.3 \
		AnyEvent::Subprocess::Running.3 \
		AnyEvent::Subprocess::Running::Delegate.3 \
		AnyEvent::Subprocess::Running::Delegate::Callback.3 \
		AnyEvent::Subprocess::Running::Delegate::CaptureHandle.3 \
		AnyEvent::Subprocess::Running::Delegate::CompletionCondvar.3 \
		AnyEvent::Subprocess::Running::Delegate::Handle.3 \
		AnyEvent::Subprocess::Running::Delegate::MonitorHandle.3 \
		AnyEvent::Subprocess::Running::Delegate::Timeout.3 \
		AnyEvent::Subprocess::Types.3

NO_STAGE=	yes
.include <bsd.port.mk>
