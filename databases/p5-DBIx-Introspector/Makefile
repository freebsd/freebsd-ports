PORTNAME=	DBIx-Introspector
PORTVERSION=	0.001005
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Detect what database you are connected to

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DBI>=1.628:databases/p5-DBI \
		p5-Moo>=1.003001:devel/p5-Moo
TEST_DEPENDS=	p5-DBD-SQLite>=1.4:databases/p5-DBD-SQLite \
		p5-Test-Roo>=1.002:devel/p5-Test-Roo

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
