# New ports collection makefile for:	p5-Sys-SigAction
# Date created:				18 Sep 2006
# Whom:					svysh
#
# $FreeBSD$
#

PORTNAME=	Sys-SigAction
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Sys
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh@cryptocom.ru
COMMENT=	Perl extension for Consistent Signal Handling

BUILD_DEPENDS=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Sys::SigAction.3

.include <bsd.port.mk>
