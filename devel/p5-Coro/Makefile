# New ports collection makefile for:	Coro
# Date created:				27 Jan 2003
# Whom:					tobez
#
# $FreeBSD$
#

PORTNAME=	Coro
PORTVERSION=	3.5.5
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Coro
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(.)$/\1/}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Coro - coroutine process abstraction for perl

RUN_DEPENDS=	p5-Event>=0.89:${PORTSDIR}/devel/p5-Event \
		${SITE_PERL}/AnyEvent.pm:${PORTSDIR}/devel/p5-AnyEvent \
		${SITE_PERL}/${PERL_ARCH}/IO/AIO.pm:${PORTSDIR}/devel/p5-IO-AIO
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Coro.3 Coro::AIO.3 Coro::Channel.3 Coro::Handle.3 \
		Coro::LWP.3 Coro::MakeMaker.3 Coro::RWLock.3 Coro::Select.3 \
		Coro::Semaphore.3 Coro::SemaphoreSet.3 Coro::Signal.3 \
		Coro::Socket.3 Coro::Specific.3 Coro::State.3 Coro::Timer.3 \
		Coro::Util.3 Coro::Event.3

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		this port is for FreeBSD 5 or above
.endif

.if ${PERL_LEVEL} < 500800
IGNORE=		requires perl 5.8.0 or later. Install lang/perl5.8 and try again
.endif

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/eg/* ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/cede-vs-schedule ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
