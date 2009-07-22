# New ports collection makefile for:    p5-Test-Deep
# Date created:				May 12th 2004
# Whom:	      				Alex Kapranoff <alex@kapranoff.ru>
#
# $FreeBSD$
#

PORTNAME=	Test-Deep
PORTVERSION=	0.104
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	az@FreeBSD.org
COMMENT=	Test data structures for differences deeply

BUILD_DEPENDS=	${SITE_PERL}/Test/NoWarnings.pm:${PORTSDIR}/devel/p5-Test-NoWarnings \
		${SITE_PERL}/Test/Tester.pm:${PORTSDIR}/devel/p5-Test-Tester
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Test::Deep.3 Test::Deep::NoTest.3

.include <bsd.port.mk>

