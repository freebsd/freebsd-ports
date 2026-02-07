PORTNAME=	Test-Fixture-DBIC-Schema
PORTVERSION=	0.051
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Fixture data loader for DBIx::Class::Schema
WWW=		https://metacpan.org/release/Test-Fixture-DBIC-Schema

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Kwalify>=0:textproc/p5-Kwalify \
		p5-Params-Validate>=0:devel/p5-Params-Validate \
		p5-YAML-Syck>=0:textproc/p5-YAML-Syck
TEST_DEPENDS=	p5-DBIx-Class>=0:databases/p5-DBIx-Class \
		p5-Test-Requires>=0:devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
