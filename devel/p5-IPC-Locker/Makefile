# New ports collection makefile for:	devel/p5-IPC-Locker
# Date created:				11 September 2002
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IPC-Locker
PORTVERSION=	1.451
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IPC
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provide a server for locks and clients to access that server

PERL_CONFIGURE=	yes

MAN1=	lockerd.1 lockersh.1 pidstatd.1 pidwatch.1
MAN3=	IPC::Locker.3 IPC::Locker::Server.3 \
	IPC::PidStat.3 IPC::PidStat::PidServer.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.0 or later. Install lang/perl5.8 and try again
.endif

.if ${PERL_LEVEL} < 500800
EXTRA_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes \
		p5-Pod-Parser>0:${PORTSDIR}/textproc/p5-Pod-Parser
BUILD_DEPENDS+=	${EXTRA_DEPENDS}
RUN_DEPENDS+=	${EXTRA_DEPENDS}
.endif

.include <bsd.port.post.mk>
