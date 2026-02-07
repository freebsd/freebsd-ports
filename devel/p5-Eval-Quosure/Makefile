PORTNAME=	Eval-Quosure
PORTVERSION=	0.001002
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SLOYD
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Evaluate within a caller environment
WWW=		https://metacpan.org/dist/Eval-Quosure

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-PadWalker>=2.3:devel/p5-PadWalker \
		p5-Safe-Isa>=1.000009:devel/p5-Safe-Isa \
		p5-Sub-Quote>=2.005:devel/p5-Sub-Quote \
		p5-Type-Tiny>=1.004004:devel/p5-Type-Tiny
TEST_DEPENDS=	p5-Test-Simple>=1.302200:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
