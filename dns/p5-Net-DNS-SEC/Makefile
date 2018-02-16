# $FreeBSD$

PORTNAME=	Net-DNS-SEC
PORTVERSION=	1.04
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN \
		http://www.ripe.net/ripencc/pub-services/np/DISI/SRC/
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DNSSEC extensions to Net::DNS

LICENSE=	MIT

BUILD_DEPENDS=	p5-Crypt-OpenSSL-Bignum>=0.05:security/p5-Crypt-OpenSSL-Bignum \
		p5-Crypt-OpenSSL-EC>=1.01:security/p5-Crypt-OpenSSL-EC \
		p5-Crypt-OpenSSL-ECDSA>=0.06:security/p5-Crypt-OpenSSL-ECDSA \
		p5-Crypt-OpenSSL-RSA>=0.28:security/p5-Crypt-OpenSSL-RSA \
		p5-Crypt-OpenSSL-Random>=0.10:security/p5-Crypt-OpenSSL-Random \
		p5-Net-DNS>=1.01:dns/p5-Net-DNS
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 ssl
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Net/DNS/SEC/SEC.so

.include <bsd.port.mk>
