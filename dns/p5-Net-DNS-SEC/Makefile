# Created by: Kimura Fuyuki <fuyuki@hadaly.org>
# $FreeBSD$

PORTNAME=	Net-DNS-SEC
PORTVERSION=	0.16
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN \
		http://www.ripe.net/ripencc/pub-services/np/DISI/SRC/
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DNSSEC extensions to Net::DNS

BUILD_DEPENDS=	p5-Crypt-OpenSSL-Bignum>=0.03:${PORTSDIR}/security/p5-Crypt-OpenSSL-Bignum \
		p5-Crypt-OpenSSL-DSA>=0.1:${PORTSDIR}/security/p5-Crypt-OpenSSL-DSA \
		p5-Crypt-OpenSSL-RSA>=0.19:${PORTSDIR}/security/p5-Crypt-OpenSSL-RSA \
		p5-Digest-BubbleBabble>=0.01:${PORTSDIR}/security/p5-Digest-BubbleBabble \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-MIME-Base32>=0:${PORTSDIR}/converters/p5-MIME-Base32 \
		p5-Net-DNS>=0.64:${PORTSDIR}/dns/p5-Net-DNS
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::DNS::Keyset.3 Net::DNS::RR::DS.3 Net::DNS::RR::KEY.3 \
		Net::DNS::RR::NXT.3 Net::DNS::RR::SIG.3 \
		Net::DNS::SEC.3 Net::DNS::RR::DLV.3 \
		Net::DNS::SEC::Private.3 Net::DNS::RR::RRSIG.3 \
		Net::DNS::RR::NSEC.3 Net::DNS::RR::DNSKEY.3 \
		Net::DNS::RR::NSEC3.3 Net::DNS::RR::NSEC3PARAM.3

.include <bsd.port.mk>
