PORTNAME=	Sereal-Encoder
PORTVERSION=	4.025
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:YVES
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for fast, powerful binary serialization (encoder)

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

LIB_DEPENDS=	libzstd.so:archivers/zstd
TEST_DEPENDS=	p5-Sereal-Decoder>=4.002:converters/p5-Sereal-Decoder \
		p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Differences>=0,1:devel/p5-Test-Differences \
		p5-Test-LongString>=0:devel/p5-Test-LongString \
		p5-Test-Warn>=0:devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	configure

MAKE_ENV=	PASTHRU_DEFINE="-I${LOCALBASE}/include"
MAKE_JOBS_UNSAFE=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Sereal/Encoder/Encoder.so

.include <bsd.port.mk>
