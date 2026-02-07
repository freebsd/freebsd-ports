PORTNAME=	Type-TinyX-Facets
PORTVERSION=	1.3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DJERIUS
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Easily create a facet parameterized Type::Tiny type
WWW=		https://metacpan.org/dist/Type-TinyX-Facets

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Exporter-Tiny>=0:devel/p5-Exporter-Tiny \
		p5-Safe-Isa>=0:devel/p5-Safe-Isa \
		p5-Type-Tiny>=0:devel/p5-Type-Tiny
TEST_DEPENDS=	p5-Test-Lib>=0:devel/p5-Test-Lib \
		p5-Test-Simple>=1.302200:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	yes

.include <bsd.port.mk>
