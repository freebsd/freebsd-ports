PORTNAME=	Thrift-XS
PORTVERSION=	1.11
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TIMLEGGE
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Faster Thrift binary protocol encoding and decoding
WWW=		https://metacpan.org/release/Thrift-XS

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Bit-Vector>=0:math/p5-Bit-Vector \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-IO-String>=0:devel/p5-IO-String \
		p5-Thrift>=0.22.0,1:devel/p5-Thrift \
		p5-libwww>=0:www/p5-libwww
TEST_DEPENDS=	p5-Test-BinaryData>=0:devel/p5-Test-BinaryData

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Thrift/XS/XS.so

.include <bsd.port.mk>
