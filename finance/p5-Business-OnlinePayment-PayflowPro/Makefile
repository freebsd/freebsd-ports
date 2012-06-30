# New ports collection makefile for:	Business::OnlinePayment::PayflowPro
# Date created:				13 June 2006
# Whom:					Alexandr Kovalenko <never@nevermind.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	Business-OnlinePayment-PayflowPro
PORTVERSION=	0.03
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	never@nevermind.kiev.ua
COMMENT=	A Business::OnlinePayment backend module for PayflowPro

BUILD_DEPENDS=	p5-Business-OnlinePayment>=0:${PORTSDIR}/finance/p5-Business-OnlinePayment \
		p5-PFProAPI>=0:${PORTSDIR}/finance/p5-PFProAPI
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Business::OnlinePayment::PayflowPro.3

.include <bsd.port.mk>
