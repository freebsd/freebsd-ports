# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	IPC-Run
PORTVERSION=	0.92
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	IPC::Run - Run subprocesses with piping and redirection

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-IO-Tty>=1.08:${PORTSDIR}/devel/p5-IO-Tty
RUN_DEPENDS=	p5-IO-Tty>=1.08:${PORTSDIR}/devel/p5-IO-Tty

USES=		perl5
USE_PERL5=	configure

MAN3=		IPC::Run.3 \
		IPC::Run::Debug.3 \
		IPC::Run::IO.3 \
		IPC::Run::Timer.3 \
		IPC::Run::Win32Helper.3 \
		IPC::Run::Win32IO.3 \
		IPC::Run::Win32Pump.3

.include <bsd.port.mk>
