# New ports collection makefile for:	p5-Test-Output
# Date created:		2006-07-19
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Output
PORTVERSION=	0.10
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Utilities to test STDOUT and STDERR messages

RUN_DEPENDS=	${SITE_PERL}/Sub/Exporter.pm:${PORTSDIR}/devel/p5-Sub-Exporter \
		${SITE_PERL}/Test/Tester.pm:${PORTSDIR}/devel/p5-Test-Tester

PERL_CONFIGURE=	5.8.0+

MAN3=		Test::Output::Tie.3 Test::Output.3

.include <bsd.port.mk>
