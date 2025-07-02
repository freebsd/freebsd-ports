PORTNAME=	Data-Dumper-Interp
PORTVERSION=	7.019
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Interpolate Data::Dumper output into strings for human consumption
WWW=		https://metacpan.org/release/Data-Dumper-Interp

LICENSE=	CC0-1.0

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Data-Dumper>=0:devel/p5-Data-Dumper \
		p5-Data-Structure-Util>=0:devel/p5-Data-Structure-Util \
		p5-Data-Visitor>=0.32:devel/p5-Data-Visitor \
		p5-Moose>=0:devel/p5-Moose \
		p5-Regexp-Common>=0:textproc/p5-Regexp-Common \
		p5-Term-ReadKey>=0:devel/p5-Term-ReadKey
TEST_DEPENDS=	p5-Data-Compare>=0:devel/p5-Data-Compare \
		p5-Guard>=0:devel/p5-Guard \
		p5-Math-BigInt>=2.000000:math/p5-Math-BigInt \
		p5-Test-Simple>=1.302200:devel/p5-Test-Simple \
		p5-autovivification>=0:devel/p5-autovivification \
		p5-bignum>=0:math/p5-bignum \
		p5-indirect>=0:devel/p5-indirect \
		p5-multidimensional>=0:devel/p5-multidimensional

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
