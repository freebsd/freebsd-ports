# New ports collection makefile for:	p5-Net-DNS-SEC
# Date created:			21 July 2002
# Whom:				Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	Net-DNS-SEC
PORTVERSION=	0.12
CATEGORIES=	dns perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		http://www.ripe.net/ripencc/pub-services/np/DISI/SRC/
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	DNSSEC extensions to Net::DNS

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS \
		${SITE_PERL}/${PERL_ARCH}/Crypt/OpenSSL/RSA.pm:${PORTSDIR}/security/p5-Crypt-OpenSSL-RSA \
		${SITE_PERL}/${PERL_ARCH}/Crypt/OpenSSL/DSA.pm:${PORTSDIR}/security/p5-Crypt-OpenSSL-DSA \
		${SITE_PERL}/${PERL_ARCH}/Crypt/OpenSSL/Bignum.pm:${PORTSDIR}/security/p5-Crypt-OpenSSL-Bignum \
		${SITE_PERL}/Digest/BubbleBabble.pm:${PORTSDIR}/security/p5-Digest-BubbleBabble
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::DNS::Keyset.3 Net::DNS::RR::DS.3 Net::DNS::RR::KEY.3 \
		Net::DNS::RR::NXT.3 Net::DNS::RR::SIG.3 \
		Net::DNS::RR::SIG::Private.3 Net::DNS::SEC.3 \
		Net::DNS::SEC::Private.3 Net::DNS::RR::RRSIG.3 \
		Net::DNS::RR::NSEC.3 Net::DNS::RR::DNSKEY.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64
RUN_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64
.endif

.include <bsd.port.post.mk>
