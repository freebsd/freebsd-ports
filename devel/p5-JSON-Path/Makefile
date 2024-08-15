PORTNAME=	JSON-Path
PORTVERSION=	1.0.6
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Search nested hashref/arrayref structures using JSONPath
WWW=		https://metacpan.org/release/JSON-Path

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Carp-Assert>=0:devel/p5-Carp-Assert \
		p5-Exporter-Easy>=0:devel/p5-Exporter-Easy \
		p5-Exporter-Tiny>=0:devel/p5-Exporter-Tiny \
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-LV>=0:devel/p5-LV \
		p5-Readonly>=0:devel/p5-Readonly \
		p5-Tie-IxHash>=0:devel/p5-Tie-IxHash \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny
TEST_DEPENDS=	p5-JSON>=0:converters/p5-JSON \
		p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Most>=0:devel/p5-Test-Most \
		p5-Test-Simple>=1.302200:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
