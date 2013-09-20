# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Test-Benchmark
PORTVERSION=	0.004
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Make sure something really is faster

BUILD_DEPENDS=	p5-Test-Tester>=0:${PORTSDIR}/devel/p5-Test-Tester \
		p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Test::Benchmark.3

NO_STAGE=	yes
.include <bsd.port.mk>
