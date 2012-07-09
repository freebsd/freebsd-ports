# New ports collection makefile for:	p5-IO-Async
# Date created:		2007-06-10
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	IO-Async
PORTVERSION=	0.52
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PEVANS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl modules that implement asynchronous filehandle IO

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Async-MergePoint>=0.03:${PORTSDIR}/devel/p5-Async-MergePoint \
		p5-CPS>=0.15:${PORTSDIR}/devel/p5-CPS \
		p5-Socket>=1.95:${PORTSDIR}/net/p5-Socket
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-Identity>=0:${PORTSDIR}/devel/p5-Test-Identity \
		p5-Test-Pod>=1:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Refcount>=0:${PORTSDIR}/devel/p5-Test-Refcount

PERL_CONFIGURE=	5.10.0+

MAN3=		IO::Async.3 \
		IO::Async::Channel.3 \
		IO::Async::ChildManager.3 \
		IO::Async::Connector.3 \
		IO::Async::File.3 \
		IO::Async::FileStream.3 \
		IO::Async::Function.3 \
		IO::Async::Handle.3 \
		IO::Async::Listener.3 \
		IO::Async::Loop.3 \
		IO::Async::Loop::Poll.3 \
		IO::Async::Loop::Select.3 \
		IO::Async::LoopTests.3 \
		IO::Async::MergePoint.3 \
		IO::Async::Notifier.3 \
		IO::Async::OS.3 \
		IO::Async::OS::MSWin32.3 \
		IO::Async::PID.3 \
		IO::Async::Protocol.3 \
		IO::Async::Protocol::LineStream.3 \
		IO::Async::Protocol::Stream.3 \
		IO::Async::Process.3 \
		IO::Async::Resolver.3 \
		IO::Async::Routine.3 \
		IO::Async::Sequencer.3 \
		IO::Async::Signal.3 \
		IO::Async::Socket.3 \
		IO::Async::Stream.3 \
		IO::Async::Test.3 \
		IO::Async::Timer.3 \
		IO::Async::Timer::Absolute.3 \
		IO::Async::Timer::Countdown.3 \
		IO::Async::Timer::Periodic.3

.include <bsd.port.mk>
