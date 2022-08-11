PORTNAME=	DBIx-Sunny
PORTVERSION=	0.9992
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple DBI wrapper supports SQLite and MySQL

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Accessor-Lite>=0.05:devel/p5-Class-Accessor-Lite \
		p5-Class-Data-Inheritable>=0:devel/p5-Class-Data-Inheritable \
		p5-DBI>=1.615:databases/p5-DBI \
		p5-DBIx-TransactionManager>=0.13:databases/p5-DBIx-TransactionManager \
		p5-Data-Validator>=0:devel/p5-Data-Validator \
		p5-SQL-Maker>=0:databases/p5-SQL-Maker \
		p5-SQL-NamedPlaceholder>=0.10:databases/p5-SQL-NamedPlaceholder
TEST_DEPENDS=	p5-Capture-Tiny>=0:devel/p5-Capture-Tiny \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Requires>=0:devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	yes

.include <bsd.port.mk>
