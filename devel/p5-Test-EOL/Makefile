# Created by: milki@rescomp.berkeley.edu
# $FreeBSD$

PORTNAME=	Test-EOL
PORTVERSION=	1.5
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BOBTFISH
PKGNAMEPREFIX=	p5-

MAINTAINER=	milki@rescomp.berkeley.edu
COMMENT=	Check the correct line endings in your project

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Pod-Coverage>=1.08:${PORTSDIR}/devel/p5-Pod-Coverage \
		p5-Pod-Coverage-TrustPod>=0:${PORTSDIR}/devel/p5-Pod-Coverage-TrustPod \
		p5-Test-Pod>=1.41:${PORTSDIR}/devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
