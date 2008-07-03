# New ports collection makefile for:	devel/p5-IPC-DirQueue
# Date created:				28 December 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IPC-DirQueue
PORTVERSION=	1.0
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	IPC::DirQueue - disk-based many-to-many task queue

BUILD_DEPENDS=	p5-POE>0:${PORTSDIR}/devel/p5-POE
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN1=	dq-deque.1 dq-indexd.1 dq-list.1 dq-server.1 dq-submit.1
MAN3=	IPC::DirQueue.3 IPC::DirQueue::Job.3 \
	IPC::DirQueue::IndexClient.3 IPC::DirQueue::IndexServer.3

.include <bsd.port.mk>
