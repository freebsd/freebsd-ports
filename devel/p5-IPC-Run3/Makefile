# New ports collection makefile for:	devel/p5-IPC-Run3
# Date created:				Apr 27 2004
# Whom:					Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$

PORTNAME=	IPC-Run3
PORTVERSION=	0.043
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Run a subprocess in batch mode

PERL_CONFIGURE=	yes

MAN3=		IPC::Run3.3 \
		IPC::Run3::ProfArrayBuffer.3 \
		IPC::Run3::ProfLogger.3 \
		IPC::Run3::ProfLogReader.3 \
		IPC::Run3::ProfPP.3 \
		IPC::Run3::ProfReporter.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703
BUILD_DEPENDS+=	p5-Time-HiRes>=0:${PORTSDIR}/devel/p5-Time-HiRes
RUN_DEPENDS+=	p5-Time-HiRes>=0:${PORTSDIR}/devel/p5-Time-HiRes
.endif

.include <bsd.port.post.mk>
