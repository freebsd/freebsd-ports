# New ports collection makefile for:	devele/p5-IPC-Run
# Date created:				12 July 2001
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IPC-Run
PORTVERSION=	0.79
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IPC
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	IPC::Run - Run subprocesses with piping and redirection

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/IO/Tty.pm:${PORTSDIR}/devel/p5-IO-Tty
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	IPC::Run.3 IPC::Run::IO.3 IPC::Run::Timer.3 IPC::Run::Debug.3 \
	IPC::Run::Win32IO.3 IPC::Run::Win32Helper.3 IPC::Run::Win32Pump.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/IO/Handle.pm:${PORTSDIR}/devel/p5-IO
.endif

.include <bsd.port.post.mk>
