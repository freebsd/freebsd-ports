# New ports collection makefile for:	devel/p5-IPC-Locker
# Date created:				11 September 2002
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IPC-Locker
PORTVERSION=	1.484
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provide a server for locks and clients to access that server

PERL_CONFIGURE=	yes

MAN1=	lockerd.1 lockersh.1 pidstat.1 pidstatd.1 pidwatch.1 \
	uriexec.1
MAN3=	IPC::Locker.3 IPC::Locker::Server.3 \
	IPC::PidStat.3 IPC::PidStat::PidServer.3

.include <bsd.port.mk>
