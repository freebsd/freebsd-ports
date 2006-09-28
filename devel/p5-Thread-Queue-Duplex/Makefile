# New ports collection makefile for:	p5-Thread-Queue-Duplex
# Date created:		2006-08-29
# Whom:			Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Thread-Queue-Duplex
PORTVERSION=	0.92
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Thread
PKGNAMEPREFIX=	p5-

MAINTAINER=	tjs@cdpa.nsysu.edu.tw
COMMENT=	Thread-safe request/response queue with identifiable elements

PERL_CONFIGURE=	yes

MAN3=	Thread::Queue::Duplex.3 Thread::Queue::Queueable.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	requires perl 5.8.0 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
