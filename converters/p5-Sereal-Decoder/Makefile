# $FreeBSD$

PORTNAME=	Sereal-Decoder
PORTVERSION=	3.014
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:YVES
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for fast, compact, powerful binary deserialization

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	\
	p5-Sereal-Encoder>=3.001:converters/p5-Sereal-Encoder \
	p5-Test-LongString>0:devel/p5-Test-LongString \
	p5-Test-Warn>=0:devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Sereal/Decoder/Decoder.so

.include <bsd.port.mk>
