PORTNAME=	Archive-Zip-SimpleZip
DISTVERSION=	1.002
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	dgeo@centrale-med.fr
COMMENT=	Create Zip Archives
WWW=		https://metacpan.org/pod/Archive::Zip::SimpleZip \
		https://github.com/pmqs/Archive-Zip-SimpleZip

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

# 1 test dependency is currently not in the tree:
# t/meta-json.t ... skipped: Test::CPAN::Meta::JSON required for testing META.json
TEST_DEPENDS=	p5-Test-CPAN-Meta>0:devel/p5-Test-CPAN-Meta \
		p5-Test-Pod>0:devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
