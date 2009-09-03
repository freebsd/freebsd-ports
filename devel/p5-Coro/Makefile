# New ports collection makefile for:	Coro
# Date created:				27 Jan 2003
# Whom:					tobez
#
# $FreeBSD$
#

PORTNAME=	Coro
PORTVERSION=	5.170
DISTVERSION=	${PORTVERSION:C/0$//}
PORTEPOCH=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Coroutine process abstraction for perl

RUN_DEPENDS=	p5-Event>=1.08:${PORTSDIR}/devel/p5-Event \
		p5-Guard>=0.5:${PORTSDIR}/devel/p5-Guard \
		p5-AnyEvent>=5.0:${PORTSDIR}/devel/p5-AnyEvent \
		p5-AnyEvent-AIO>=1.0:${PORTSDIR}/devel/p5-AnyEvent-AIO \
		p5-EV>=3.3:${PORTSDIR}/devel/p5-EV \
		p5-Storable>=2.15:${PORTSDIR}/devel/p5-Storable \
		p5-common-sense>=0:${PORTSDIR}/devel/p5-common-sense \
		p5-IO-AIO>=3.1:${PORTSDIR}/devel/p5-IO-AIO
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.2+

MAN3=		Coro.3 Coro::AIO.3 Coro::AnyEvent.3 Coro::Channel.3 \
		Coro::Handle.3 Coro::BDB.3 Coro::Debug.3 \
		Coro::LWP.3 Coro::MakeMaker.3 Coro::RWLock.3 Coro::Select.3 \
		Coro::Semaphore.3 Coro::SemaphoreSet.3 Coro::Signal.3 \
		Coro::Socket.3 Coro::Specific.3 Coro::State.3 Coro::Storable.3 \
		Coro::Timer.3 Coro::Util.3 Coro::Event.3 \
		Coro::Intro.3 Coro::EV.3

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/eg/* ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/cede-vs-schedule ${DOCSDIR}
.endif

.include <bsd.port.mk>
