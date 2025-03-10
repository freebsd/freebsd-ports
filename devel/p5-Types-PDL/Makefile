PORTNAME=	Types-PDL
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DJERIUS
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PDL types using Type::Tiny
WWW=		https://metacpan.org/dist/Types-PDL

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-String-Errf>=0:devel/p5-String-Errf \
		p5-Type-Tiny>=0:devel/p5-Type-Tiny \
		p5-Type-TinyX-Facets>=0:devel/p5-Type-TinyX-Facets
TEST_DEPENDS=	p5-PDL>=0:math/p5-PDL \
		p5-Test-Simple>=1.302200:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
