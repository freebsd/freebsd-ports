# Created by: milki <milki@rescomp.berkeley.edu>
# $FreeBSD$

PORTNAME=	Pod-Coverage-TrustPod
PORTVERSION=	0.100003
PORTREVISION=	1
CATEGORIES=	devel textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RJBS
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Declare trusted symbol names in POD

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Pod-Coverage>=0:devel/p5-Pod-Coverage \
		p5-Pod-Eventual>=0:textproc/p5-Pod-Eventual
TEST_DEPENDS=	p5-Test-Pod>=1.41:devel/p5-Test-Pod
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
