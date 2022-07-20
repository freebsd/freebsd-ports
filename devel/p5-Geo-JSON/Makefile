PORTNAME=	Geo-JSON
PORTVERSION=	0.007
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl OO interface for geojson

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-JSON>=0:converters/p5-JSON \
		p5-Moo>=1.004003:devel/p5-Moo \
		p5-Type-Tiny>=0:devel/p5-Type-Tiny
TEST_DEPENDS=	p5-Class-Load>=0:devel/p5-Class-Load \
		p5-Path-Class>=0:devel/p5-Path-Class \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Most>=0:devel/p5-Test-Most

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	yes

.include <bsd.port.mk>
