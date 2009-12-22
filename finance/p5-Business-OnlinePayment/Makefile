# New ports collection makefile for:	Business::OnlinePayment
# Date created:				24 October 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Business-OnlinePayment
PORTVERSION=	3.00
PORTREVISION=	1
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN/../by-authors/id/I/IV/IVAN/
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}_08

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A generic interface for processing online credit card payments

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/SSLeay.pm:${PORTSDIR}/security/p5-Net-SSLeay \
		${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/Tie/IxHash.pm:${PORTSDIR}/devel/p5-Tie-IxHash \
		${SITE_PERL}/${PERL_ARCH}/Crypt/SSLeay.pm:${PORTSDIR}/security/p5-Crypt-SSLeay \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Business::OnlinePayment.3 \
		Business::FraudDetect.3 \
		Business::FraudDetect::preCharge.3 \
		Business::OnlinePayment::HTTPS.3

.include <bsd.port.mk>
