# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	Thread-Queue
PORTVERSION=	2.12
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl5 thread-safe queues

BUILD_DEPENDS=	p5-threads-shared>=1.26:${PORTSDIR}/devel/p5-threads-shared
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Thread::Queue.3

.include <bsd.port.mk>
