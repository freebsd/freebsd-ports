# $FreeBSD$

PORTNAME=	Benchmark-Timer
PORTVERSION=	0.7107
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Code benchmarking tool

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-Module-Install>0:${PORTSDIR}/devel/p5-Module-Install \
		p5-URI>=0:${PORTSDIR}/net/p5-URI

OPTIONS_DEFINE=	SAMPLE
OPTIONS_DEFAULT=	SAMPLE
SAMPLE_DESC=	Statistical Sampling Support
SAMPLE_BUILD_DEPENDS=	p5-Statistics-TTest>1:${PORTSDIR}/math/p5-Statistics-TTest

USES=		perl5
USE_PERL5=	configure
.include <bsd.port.mk>
