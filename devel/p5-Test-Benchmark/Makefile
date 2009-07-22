# New ports collection makefile for:	p5-Test-Benchmark
# Date created:		2006-07-13
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Benchmark
PORTVERSION=	0.004
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Make sure something really is faster

BUILD_DEPENDS=	${SITE_PERL}/Test/Tester.pm:${PORTSDIR}/devel/p5-Test-Tester \
		${SITE_PERL}/Test/NoWarnings.pm:${PORTSDIR}/devel/p5-Test-NoWarnings
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Test::Benchmark.3

.include <bsd.port.mk>
