# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Business-OnlinePayment-Cardstream
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Business::OnlinePayment backend module for Cardstream

BUILD_DEPENDS=	p5-Business-CreditCard>=0:finance/p5-Business-CreditCard \
		p5-Business-OnlinePayment>=0:finance/p5-Business-OnlinePayment
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
