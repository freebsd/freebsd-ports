# $FreeBSD$

PORTNAME=	Sereal-Encoder
PORTVERSION=	3.014
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:YVES
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for fast, compact, powerful binary serialization

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	\
	p5-Test-Deep>0:devel/p5-Test-Deep \
	p5-Test-LongString>0:devel/p5-Test-LongString \
	p5-Test-Warn>0:devel/p5-Test-Warn \
	p5-Sereal-Decoder>=3.00:converters/p5-Sereal-Decoder

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Sereal/Encoder/Encoder.so

.include <bsd.port.mk>
