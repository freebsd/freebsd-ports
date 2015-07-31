# $FreeBSD$

PORTNAME=	Net-DNS-SEC
PORTVERSION=	0.22
PORTREVISION=	1
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN \
		http://www.ripe.net/ripencc/pub-services/np/DISI/SRC/
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DNSSEC extensions to Net::DNS

LICENSE=	MIT

BUILD_DEPENDS=	p5-Crypt-OpenSSL-Bignum>=0.04:${PORTSDIR}/security/p5-Crypt-OpenSSL-Bignum \
		p5-Crypt-OpenSSL-DSA>=0.1:${PORTSDIR}/security/p5-Crypt-OpenSSL-DSA \
		p5-Crypt-OpenSSL-EC>=1.01:${PORTSDIR}/security/p5-Crypt-OpenSSL-EC \
		p5-Crypt-OpenSSL-ECDSA>=0.6:${PORTSDIR}/security/p5-Crypt-OpenSSL-ECDSA \
		p5-Crypt-OpenSSL-RSA>=0.19:${PORTSDIR}/security/p5-Crypt-OpenSSL-RSA \
		p5-Crypt-OpenSSL-Random>=0.06:${PORTSDIR}/security/p5-Crypt-OpenSSL-Random \
		p5-Digest-BubbleBabble>=0.01:${PORTSDIR}/security/p5-Digest-BubbleBabble \
		p5-MIME-Base32>=0:${PORTSDIR}/converters/p5-MIME-Base32 \
		p5-Net-DNS>=1.01:${PORTSDIR}/dns/p5-Net-DNS
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

post-patch:
	@${RM} -fr ${WRKSRC}/RR/
	@${REINPLACE_CMD} -e '/RR\//d' ${WRKSRC}/MANIFEST ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
