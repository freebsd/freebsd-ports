# New ports collection makefile for:	p5-Parse-ErrorString-Perl
# Date created:				March 8th 2009
# Whom:	      				Cezary Morga <cm@therek.net>
#
# $FreeBSD$
#

PORTNAME=	Parse-ErrorString-Perl
PORTVERSION=	0.13
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cm@therek.net
COMMENT=	Parse error messages from the Perl interpreter

BUILD_DEPENDS=	${SITE_PERL}/Pod/POM.pm:${PORTSDIR}/textproc/p5-Pod-POM \
		${SITE_PERL}/Test/Differences.pm:${PORTSDIR}/devel/p5-Test-Differences \
		${SITE_PERL}/${PERL_ARCH}/Class/XSAccessor.pm:${PORTSDIR}/devel/p5-Class-XSAccessor
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN1=		check_perldiag.1
MAN3=		Parse::ErrorString::Perl.3

.include <bsd.port.mk>
