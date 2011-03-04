# New ports collection makefile for:    p5-Test-EOL
# Date created:				2011-02-15
# Whom:	      				milki@rescomp.berkeley.edu
#
# $FreeBSD$
#

PORTNAME=	Test-EOL
PORTVERSION=	0.9
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/F/FL/FLORA
PKGNAMEPREFIX=	p5-

MAINTAINER=	milki@rescomp.berkeley.edu
COMMENT=	Check the correct line endings in your project

RUN_DEPENDS=	p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple

TEST_DEPENDS=	p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple \
	p5-Pod-Coverage>=1.08:${PORTSDIR}/devel/p5-Pod-Coverage \
	p5-Pod-Coverage-TrustPod>=0:${PORTSDIR}/devel/p5-Pod-Coverage-TrustPod \
	p5-Test-Pod>=1.41:${PORTSDIR}/devel/p5-Test-Pod

PERL_CONFIGURE=	yes

MAN3=		Test::EOL.3

.include <bsd.port.mk>
