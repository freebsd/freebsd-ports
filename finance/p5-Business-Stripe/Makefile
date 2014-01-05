# Created by: Vick Khera <vivek@khera.org>
# $FreeBSD$

PORTNAME=	Business-Stripe
PORTVERSION=	0.04
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vivek@khera.org
COMMENT=	Perl5 module interface for the Stripe.com payment system

RUN_DEPENDS=	p5-HTTP-Message>=0.0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-JSON>=0.0:${PORTSDIR}/converters/p5-JSON \
		p5-libwww>0.0:${PORTSDIR}/www/p5-libwww \
		p5-MIME-Base64>=0.0:${PORTSDIR}/converters/p5-MIME-Base64

WRKSRC=		${WRKDIR}/aquaron-Business-Stripe-c067843

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
