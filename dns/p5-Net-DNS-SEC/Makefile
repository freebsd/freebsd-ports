PORTNAME=	Net-DNS-SEC
PORTVERSION=	1.26
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	DNSSEC extensions to Net::DNS
WWW=		https://metacpan.org/release/Net-DNS-SEC

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Net-DNS>=1.08:dns/p5-Net-DNS

USES=		perl5 ssl
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Net/DNS/SEC/SEC.so

.include <bsd.port.mk>
