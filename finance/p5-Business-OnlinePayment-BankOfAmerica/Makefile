# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Business-OnlinePayment-BankOfAmerica
PORTVERSION=	1.02
PORTREVISION=	1
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Business::OnlinePayment backend module for Bank of America eStores

BUILD_DEPENDS=	p5-Business-CreditCard>=0:${PORTSDIR}/finance/p5-Business-CreditCard \
		p5-Business-OnlinePayment>=0:${PORTSDIR}/finance/p5-Business-OnlinePayment
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
