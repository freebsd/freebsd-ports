# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-Timer
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Perl test module to test/assert response times

BUILD_DEPENDS=	p5-Error>=0:${PORTSDIR}/lang/p5-Error
RUN_DEPENDS=	p5-Error>=0:${PORTSDIR}/lang/p5-Error

TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Tester>=0:${PORTSDIR}/devel/p5-Test-Tester

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
