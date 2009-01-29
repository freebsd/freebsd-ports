# New ports collection makefile for:	Business::OnlinePayment::TCLink
# Date created:				24 October 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Business-OnlinePayment-TCLink
PORTVERSION=	1.03
PORTREVISION=	1
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A Business::OnlinePayment backend module for TrustCommerce

BUILD_DEPENDS=	${SITE_PERL}/Business/CreditCard.pm:${PORTSDIR}/finance/p5-Business-CreditCard \
		${SITE_PERL}/Business/OnlinePayment.pm:${PORTSDIR}/finance/p5-Business-OnlinePayment \
		${SITE_PERL}/${PERL_ARCH}/Net/TCLink.pm:${PORTSDIR}/net/p5-Net-TCLink
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Business::OnlinePayment::TCLink.3

.include <bsd.port.mk>
