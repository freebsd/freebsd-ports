# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	MooseX-Types-DateTime-ButMaintained
PORTVERSION=	0.16
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	DateTime related constraints and coercions for Moose

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DateTime>=0.43:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Locale>=0.40:${PORTSDIR}/devel/p5-DateTime-Locale \
		p5-DateTime-TimeZone>=0.96:${PORTSDIR}/devel/p5-DateTime-TimeZone \
		p5-Moose>=0.41:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Types>=0.04:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-Olson-Abbreviations>=0.03:${PORTSDIR}/devel/p5-Olson-Abbreviations \
		p5-namespace-clean>=0.08:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0.27:${PORTSDIR}/devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502200
TEST_DEPENDS+=	p5-Test-Simple>=1.001.014:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
