# New ports collection makefile for:	p5-Test-Distribution
# Date created:		2008-02-11
# Whom:			Felippe de Meirelles Motta <lippemail@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Test-Distribution
PORTVERSION=	2.00
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lippemail@gmail.com
COMMENT=	Test::Distribution - Perform tests on all modules of a distribution

BUILD_DEPENDS+=	${SITE_PERL}/ExtUtils/Manifest.pm:${PORTSDIR}/devel/p5-ExtUtils-Manifest \
		${SITE_PERL}/File/Find/Rule.pm:${PORTSDIR}/devel/p5-File-Find-Rule \
		${SITE_PERL}/Module/CoreList.pm:${PORTSDIR}/devel/p5-Module-CoreList \
		${SITE_PERL}/Pod/Coverage.pm:${PORTSDIR}/devel/p5-Pod-Coverage \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/Test/Pod.pm:${PORTSDIR}/devel/p5-Test-Pod \
		${SITE_PERL}/Test/Pod/Coverage.pm:${PORTSDIR}/devel/p5-Test-Pod-Coverage
RUN_DEPENDS+=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Test::Distribution.3

.include <bsd.port.mk>
