# New ports collection makefile for:	p5-Test-LeakTrace
# Date created:		2011-08-01
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-LeakTrace
PORTVERSION=	0.13
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Traces memory leaks

PERL_CONFIGURE=	5.8.3+

MAN3=		Test::LeakTrace.3 \
		Test::LeakTrace::JA.3 \
		Test::LeakTrace::Script.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500808
RUN_DEPENDS+=	p5-Test-Simple>=0.62:${PORTSDIR}/devel/p5-Test-Simple
TEST_DEPENDS+=	p5-Test-Simple>=0.62:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
