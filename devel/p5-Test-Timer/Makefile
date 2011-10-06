# New ports collection makefile for:	p5-Test-Timer
# Date created:		2011-10-06
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Timer
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN

MAINTAINER=	swills@FreeBSD.org
COMMENT=	A test module to test/assert response times

BUILD_DEPENDS=	p5-Error>=0:${PORTSDIR}/lang/p5-Error
RUN_DEPENDS=	p5-Error>=0:${PORTSDIR}/lang/p5-Error

TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Tester>=0:${PORTSDIR}/devel/p5-Test-Tester

PERL_CONFIGURE=	yes

MAN3=	Test::Timer.3 Test::Timer::TimeoutException.3

.include <bsd.port.mk>
