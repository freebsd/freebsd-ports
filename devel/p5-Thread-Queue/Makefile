# New ports collection makefile for:	p5-Thread-Queue
# Date created:				June 2nd 2009
# Whom:	      				Cezary Morga <cm@therek.net>
#
# $FreeBSD$
#

PORTNAME=	Thread-Queue
PORTVERSION=	2.11
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cm@therek.net
COMMENT=	Perl5 thread-safe queues

BUILD_DEPENDS=	p5-Scalar-List-Utils>=1.10:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-threads-shared>=1.26:${PORTSDIR}/devel/p5-threads-shared
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Thread::Queue.3

.include <bsd.port.mk>
