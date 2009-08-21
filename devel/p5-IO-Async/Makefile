# New ports collection makefile for:	p5-IO-Async
# Date created:		2007-06-10
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	IO-Async
PORTVERSION=	0.23
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl modules that implement asynchronous filehandle IO

RUN_DEPENDS=	p5-Heap>=0:${PORTSDIR}/devel/p5-Heap
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		IO::Async.3 \
		IO::Async::ChildManager.3 \
		IO::Async::Connector.3 \
		IO::Async::DetachedCode.3 \
		IO::Async::Handle.3 \
		IO::Async::Listener.3 \
		IO::Async::Loop.3 \
		IO::Async::Loop::IO_Poll.3 \
		IO::Async::Loop::Poll.3 \
		IO::Async::Loop::Select.3 \
		IO::Async::MergePoint.3 \
		IO::Async::Notifier.3 \
		IO::Async::Resolver.3 \
		IO::Async::Sequencer.3 \
		IO::Async::Signal.3 \
		IO::Async::Stream.3 \
		IO::Async::Test.3 \
		IO::Async::Timer.3

.include <bsd.port.mk>
