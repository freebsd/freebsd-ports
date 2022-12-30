PORTNAME=	Convert-Color
PORTVERSION=	0.13
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for color space conversions and named lookups
WWW=		https://metacpan.org/release/Convert-Color

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-List-UtilsBy>=0:devel/p5-List-UtilsBy \
		p5-Module-Pluggable>=0:devel/p5-Module-Pluggable
TEST_DEPENDS=	p5-Test-Number-Delta>=0:devel/p5-Test-Number-Delta

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

.include <bsd.port.mk>
