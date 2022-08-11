PORTNAME=	Thrift-XS
PORTVERSION=	1.04
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AGRUNDMA
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Faster Thrift binary protocol encoding and decoding

LICENSE=	APACHE20

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Bit-Vector>=0:math/p5-Bit-Vector \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-IO-String>=0:devel/p5-IO-String \
		p5-libwww>=0:www/p5-libwww
TEST_DEPENDS=	p5-Proc-ProcessTable>=0:devel/p5-Proc-ProcessTable \
		p5-Test-BinaryData>=0:devel/p5-Test-BinaryData \
		p5-Test-Pod>=1.14:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1.04:devel/p5-Test-Pod-Coverage

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Thrift/XS/XS.so

.include <bsd.port.mk>
