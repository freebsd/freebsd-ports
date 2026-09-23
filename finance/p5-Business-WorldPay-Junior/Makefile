PORTNAME=	Business-WorldPay-Junior
DISTVERSION=	1.07
PORTREVISION=	2
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Perl module to handle WorldPay Junior for payment services
WWW=		https://metacpan.org/release/Business-WorldPay-Junior

LICENSE=	GPLv2

DEPRECATED=	Upstream module withdrawn by its author on CPAN
EXPIRATION_DATE=	2026-10-23

BUILD_RUN_DEPENDS=	p5-Business-CreditCard>=0:finance/p5-Business-CreditCard \
		p5-Business-OnlinePayment>=0:finance/p5-Business-OnlinePayment \
		p5-DBI>=0:databases/p5-DBI

USES=		perl5
USE_PERL5=	configure patch

post-patch:
	@${PERL} -pi -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1);$$1/;' \
		-e '$$_="" if /use 5/;' \
		-e '$$_="" if /use warnings/;' \
		${WRKSRC}/Junior.pm

.include <bsd.port.mk>
