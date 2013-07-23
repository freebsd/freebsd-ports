# Created by: Sergei Vyshenski <svysh@pn.sinp.msu.ru>
# $FreeBSD$

PORTNAME=	Sys-SigAction
PORTVERSION=	0.17
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Perl extension for Consistent Signal Handling

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

PERL_CONFIGURE=	yes

MAN3=		Sys::SigAction.3

post-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} test

.include <bsd.port.mk>
