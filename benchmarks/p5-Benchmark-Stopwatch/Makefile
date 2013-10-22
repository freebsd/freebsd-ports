# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

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

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
