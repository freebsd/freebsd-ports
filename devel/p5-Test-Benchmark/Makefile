# New ports collection makefile for:	p5-Test-Benchmark
# Date created:		2006-07-13
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Benchmark
PORTVERSION=	0.004
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Make sure something really is faster

BUILD_DEPENDS=	${SITE_PERL}/Test/Tester.pm:${PORTSDIR}/devel/p5-Test-Tester \
		${SITE_PERL}/Test/NoWarnings.pm:${PORTSDIR}/devel/p5-Test-NoWarnings
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Test::Benchmark.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703 && ${PERL_LEVEL} != 500602
BUILD_DEPENDS+=	${SITE_PERL}/Test/Builder.pm:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
