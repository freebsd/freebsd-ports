PORTNAME=	Business-OnlinePayment-SurePay
DISTVERSION=	0.01
PORTREVISION=	2
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AKHOBOV
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Business::OnlinePayment backend module for SurePay authorization service
WWW=		https://metacpan.org/release/AKHOBOV/Business-OnlinePayment-SurePay-0.01

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

DEPRECATED=	Backend for the defunct Pure Payments SurePay gateway
EXPIRATION_DATE=	2026-10-23

BUILD_RUN_DEPENDS=	p5-Business-CreditCard>=0:finance/p5-Business-CreditCard \
		p5-Business-OnlinePayment>=0:finance/p5-Business-OnlinePayment

USES=		perl5
USE_PERL5=	configure patch

NO_ARCH=	yes

post-patch:
	${PERL} -pi -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1);$$1/;' \
		-e '$$_="" if /use 5/;' \
		-e '$$_="" if /use warnings/;' \
		${WRKSRC}/SurePay.pm

.include <bsd.port.mk>
