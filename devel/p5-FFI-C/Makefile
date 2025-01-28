PORTNAME=	FFI-C
PORTVERSION=	0.15
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C data types for FFI
WWW=		https://metacpan.org/dist/FFI-C

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Inspector>=0:devel/p5-Class-Inspector \
		p5-FFI-Platypus>=1.24:devel/p5-FFI-Platypus \
		p5-FFI-Platypus-Type-Enum>=0.03:devel/p5-FFI-Platypus-Type-Enum \
		p5-Ref-Util>=0:devel/p5-Ref-Util \
		p5-Sub-Identify>=0.05:devel/p5-Sub-Identify \
		p5-Sub-Install>=0:devel/p5-Sub-Install
TEST_DEPENDS=	p5-Capture-Tiny>=0:devel/p5-Capture-Tiny \
		p5-Path-Tiny>=0:devel/p5-Path-Tiny \
		p5-Test-Simple>=1.302200:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
