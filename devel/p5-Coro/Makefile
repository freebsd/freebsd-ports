# New ports collection makefile for:	Coro
# Date created:				27 Jan 2003
# Whom:					tobez
#
# $FreeBSD$
#

PORTNAME=	Coro
PORTVERSION=	1.0a
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Coro
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Coro - coroutine process abstraction for perl

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Event.pm:${PORTSDIR}/devel/p5-Event \
		${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${DISTNAME:S/a$//}

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	"This port requires perl 5.6 or newer"
.endif

MAN3=		Coro.3 \
		Coro::Channel.3 \
		Coro::Cont.3 \
		Coro::Event.3 \
		Coro::Handle.3 \
		Coro::MakeMaker.3 \
		Coro::RWLock.3 \
		Coro::Select.3 \
		Coro::Semaphore.3 \
		Coro::SemaphoreSet.3 \
		Coro::Signal.3 \
		Coro::Socket.3 \
		Coro::Specific.3 \
		Coro::State.3 \
		Coro::Timer.3 \
		Coro::Util.3

.include <bsd.port.post.mk>
