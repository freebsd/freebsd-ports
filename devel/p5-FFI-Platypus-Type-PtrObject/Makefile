PORTNAME=	FFI-Platypus-Type-PtrObject
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Platypus custom type for an object wrapped around an opaque pointer
WWW=		https://metacpan.org/dist/FFI-Platypus-Type-PtrObject

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-FFI-Platypus>=1.11:devel/p5-FFI-Platypus \
		p5-Ref-Util>=0:devel/p5-Ref-Util
TEST_DEPENDS=	p5-Test-Simple>=1.302200:devel/p5-Test-Simple \
		p5-Test2-Tools-FFI>=0:devel/p5-Test2-Tools-FFI

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
