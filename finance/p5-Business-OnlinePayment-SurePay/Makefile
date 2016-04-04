# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Business-OnlinePayment-SurePay
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Business::OnlinePayment backend module for SurePay authorization service

BUILD_DEPENDS=	p5-Business-CreditCard>=0:finance/p5-Business-CreditCard \
		p5-Business-OnlinePayment>=0:finance/p5-Business-OnlinePayment
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure patch

post-patch:
	${PERL} -pi -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1);$$1/;' \
		-e '$$_="" if /use 5/;' \
		-e '$$_="" if /use warnings/;' \
		${WRKSRC}/SurePay.pm

.include <bsd.port.mk>
