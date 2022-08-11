PORTNAME=	Business-OnlinePayment-TCLink
PORTVERSION=	1.03
PORTREVISION=	2
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Business::OnlinePayment backend module for TrustCommerce

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Business-CreditCard>=0:finance/p5-Business-CreditCard \
		p5-Business-OnlinePayment>=0:finance/p5-Business-OnlinePayment \
		p5-Net-TCLink>=0:net/p5-Net-TCLink

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
