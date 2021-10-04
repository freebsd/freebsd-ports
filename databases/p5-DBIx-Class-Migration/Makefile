PORTNAME=	DBIx-Class-Migration
PORTVERSION=	0.073
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to make migrating your DBIx::Class databases easier

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Class-Load>0.22:devel/p5-Class-Load \
	p5-Config-MySQL>=0.02:devel/p5-Config-MySQL \
	p5-DBD-SQLite>=1.46:databases/p5-DBD-SQLite \
	p5-DBIx-Class-DeploymentHandler>=0.002223:databases/p5-DBIx-Class-DeploymentHandler \
	p5-DBIx-Class-Fixtures>=1.001039:databases/p5-DBIx-Class-Fixtures \
	p5-DBIx-Class-Schema-Loader>=0.07042:databases/p5-DBIx-Class-Schema-Loader \
	p5-Devel-PartialDump>=0.17:devel/p5-Devel-PartialDump \
	p5-File-ShareDir-ProjectDistDir>=1.0.4:devel/p5-File-ShareDir-ProjectDistDir \
	p5-JSON-MaybeXS>0:converters/p5-JSON-MaybeXS \
	p5-Log-Any>=1.707:devel/p5-Log-Any \
	p5-Moo>=2:devel/p5-Moo \
	p5-MooX-Attribute-ENV>=0.02:devel/p5-MooX-Attribute-ENV \
	p5-MooX-Options>=4.103:devel/p5-MooX-Options \
	p5-MooX-Traits>=0.005:devel/p5-MooX-Traits \
	${P5_POD_PARSER} \
	p5-SQL-Translator>=0.11021:databases/p5-SQL-Translator \
	p5-Text-Brew>=0.02:textproc/p5-Text-Brew \
	p5-version>=0.9924:devel/p5-version
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-Most>=0.34:devel/p5-Test-Most \
	p5-Test-Requires>=0.10:devel/p5-Test-Requires

USES=	perl5
USE_PERL5=	configure
NO_ARCH=	YES

post-patch:
	${FIND} ${WRKSRC} -name .DS_Store -delete

.include <bsd.port.mk>
