# Created by: Rong-En Fan <rafan@infor.org>
# $FreeBSD$

PORTNAME=	Encode
PORTVERSION=	2.55
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DANKOGAI
PKGNAMEPREFIX=	p5-

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Provides interfaces between strings and the rest of the system

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

MAN3=		Encode.3 \
		Encode::Alias.3 \
		Encode::CJKConstants.3 \
		Encode::CN::HZ.3 \
		Encode::Config.3 \
		Encode::Encoder.3 \
		Encode::Encoding.3 \
		Encode::GSM0338.3 \
		Encode::Guess.3 \
		Encode::JP::H2Z.3 \
		Encode::JP::JIS7.3 \
		Encode::KR::2022_KR.3 \
		Encode::MIME::Header.3 \
		Encode::MIME::Name.3 \
		Encode::PerlIO.3 \
		Encode::Supported.3 \
		Encode::Unicode::UTF7.3 \
		encoding.3

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|bin/enc2xs||; s|bin/piconv||' ${WRKSRC}/Makefile.PL

regression-test:
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
