PORTNAME=	FFI-Platypus-Type-Enum
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Custom platypus type for dealing with C enumerated types
WWW=		https://metacpan.org/dist/FFI-Platypus-Type-Enum

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Ref-Util>=0:devel/p5-Ref-Util
TEST_DEPENDS=	p5-FFI-Platypus>=1.00:devel/p5-FFI-Platypus \
		p5-Test-Simple>=1.302200:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
