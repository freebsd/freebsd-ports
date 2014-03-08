# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ExtUtils-Helpers
PORTVERSION=	0.022
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Various portability utilities for module builders

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USE_PERL5=	configure
USES=		perl5

post-patch:
	@${SED} -i '' -e 's|3pm|3|' ${WRKSRC}/lib/ExtUtils/Helpers.pm ${WRKSRC}/t/man_pagename.t

.include <bsd.port.mk>
