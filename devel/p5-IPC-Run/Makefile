# New ports collection makefile for:	devele/p5-IPC-Run
# Date created:				12 July 2001
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IPC-Run
PORTVERSION=	0.84
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	IPC::Run - Run subprocesses with piping and redirection

RUN_DEPENDS=	p5-IO-Tty>=1.00:${PORTSDIR}/devel/p5-IO-Tty
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	IPC::Run.3 IPC::Run::IO.3 IPC::Run::Timer.3 IPC::Run::Debug.3 \
	IPC::Run::Win32IO.3 IPC::Run::Win32Helper.3 IPC::Run::Win32Pump.3

.include <bsd.port.mk>
