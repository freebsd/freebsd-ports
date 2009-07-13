# New ports collection makefile for:	p5-Sys-SigAction
# Date created:				18 Sep 2006
# Whom:					svysh
#
# $FreeBSD$
#

PORTNAME=	Sys-SigAction
PORTVERSION=	0.11
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh@pn.sinp.msu.ru
COMMENT=	Perl extension for Consistent Signal Handling

BUILD_DEPENDS=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=	Sys::SigAction.3

post-build:
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
