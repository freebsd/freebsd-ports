# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	MooseX-Types-DateTime-ButMaintained
PORTVERSION=	0.16
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DateTime related constraints and coercions for Moose

RUN_DEPENDS=	p5-DateTime>=0.43:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Locale>=0.40:${PORTSDIR}/devel/p5-DateTime-Locale \
		p5-DateTime-TimeZone>=0.96:${PORTSDIR}/devel/p5-DateTime-TimeZone \
		p5-Moose>=0.41:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Types>=0.04:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-Olson-Abbreviations>=0.03:${PORTSDIR}/devel/p5-Olson-Abbreviations \
		p5-namespace-clean>=0.08:${PORTSDIR}/devel/p5-namespace-clean
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0.27:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-use-ok>=0.02:${PORTSDIR}/devel/p5-Test-use-ok

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
