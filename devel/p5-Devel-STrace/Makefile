# New ports collection makefile for:	Devel-STrace
# Date created:	   28 August 2006
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Devel-STrace
PORTVERSION=	0.31
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	strace(1)-like runtime call trace for Perl applications

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Devel/RingBuffer.pm:${PORTSDIR}/devel/p5-Devel-RingBuffer \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Devel::STrace.3 Devel::STrace::Monitor.3

post-patch:
	@${REINPLACE_CMD} -e 's!\.pl!!g' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
