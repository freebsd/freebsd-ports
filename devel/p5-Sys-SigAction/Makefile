# New ports collection makefile for:	p5-Sys-SigAction
# Date created:				18 Sep 2006
# Whom:					svysh
#
# $FreeBSD$
#

PORTNAME=	Sys-SigAction
PORTVERSION=	0.13
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh@pn.sinp.msu.ru
COMMENT=	Perl extension for Consistent Signal Handling

LICENSE_COMB=	dual
LICENSE=	ART10 GPLv1

PERL_CONFIGURE=	yes

MAN3=		Sys::SigAction.3

post-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} test

.include <bsd.port.mk>
