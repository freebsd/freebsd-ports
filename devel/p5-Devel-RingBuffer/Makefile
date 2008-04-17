# New ports collection makefile for:	Devel-RingBuffer
# Date created:	   28 August 2006
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Devel-RingBuffer
PORTVERSION=	0.31
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Shared memory ring buffers for Perl scripts diagnosis/debug

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/IPC/Mmap.pm:${PORTSDIR}/devel/p5-IPC-Mmap
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Devel::RingBuffer.3 Devel::RingBuffer::Ring.3

.include <bsd.port.mk>
