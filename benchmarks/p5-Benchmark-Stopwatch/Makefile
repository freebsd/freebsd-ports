# New ports collection makefile for:	p5-Benchmark-Stopwatch
# Date created:		2006-08-24
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Benchmark-Stopwatch
PORTVERSION=	0.05
CATEGORIES=	benchmarks perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Benchmark
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple timing of stages of your code

RUN_DEPENDS=	p5-Clone>=0:${PORTSDIR}/devel/p5-Clone
BUILD_DEPENDS:=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-Test-LongString>=0:${PORTSDIR}/devel/p5-Test-LongString

PERL_CONFIGURE=	yes

MAN3=		Benchmark::Stopwatch.3

.include <bsd.port.mk>
