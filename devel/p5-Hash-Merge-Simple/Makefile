PORTNAME=	Hash-Merge-Simple
PORTVERSION=	0.052
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Recursively merge two or more hashes, simply
WWW=		https://metacpan.org/release/Hash-Merge-Simple

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

# Do not add p5-Clone to BUILD_DEPENDS and RUN_DEPENDS.
# See r403626 (b728ebe2d4a3703ff58242140020904394d4fa9a) for details.
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Most>=0:devel/p5-Test-Most

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
