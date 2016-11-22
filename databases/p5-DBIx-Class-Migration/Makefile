# $FreeBSD$

PORTNAME=	DBIx-Class-Migration
PORTVERSION=	0.058
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to make migrating your DBIx::Class databases easier

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Class-Load>0:devel/p5-Class-Load \
	p5-Config-MySQL>=0.02:devel/p5-Config-MySQL \
	p5-DBD-SQLite>=1.46:databases/p5-DBD-SQLite \
	p5-DBIx-Class-DeploymentHandler>=0.002215:databases/p5-DBIx-Class-DeploymentHandler \
	p5-DBIx-Class-Fixtures>=1.001028:databases/p5-DBIx-Class-Fixtures \
	p5-DBIx-Class-Schema-Loader>=0.07042:databases/p5-DBIx-Class-Schema-Loader \
	p5-Devel-PartialDump>=0.17:devel/p5-Devel-PartialDump \
	p5-File-ShareDir-ProjectDistDir>=1.0.4:devel/p5-File-ShareDir-ProjectDistDir \
	p5-JSON-MaybeXS>0:converters/p5-JSON-MaybeXS \
	p5-Moose>=2.1403:devel/p5-Moose \
	p5-MooseX-Attribute-ENV>=0.02:devel/p5-MooseX-Attribute-ENV \
	p5-MooseX-Getopt>=0.68:devel/p5-MooseX-Getopt \
	p5-MooseX-Traits-Pluggable>=0.12:devel/p5-MooseX-Traits-Pluggable \
	p5-MooseX-Types>=0.45:devel/p5-MooseX-Types \
	p5-MooseX-Types-LoadableClass>=0.013:devel/p5-MooseX-Types-LoadableClass \
	p5-Pod-Parser>=1.63:textproc/p5-Pod-Parser \
	p5-SQL-Translator>=0.11021:databases/p5-SQL-Translator \
	p5-Text-Brew>=0.02:textproc/p5-Text-Brew
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-Most>=0.34:devel/p5-Test-Most \
	p5-Test-Requires>=0.08:devel/p5-Test-Requires

USES=	perl5
USE_PERL5=	configure
NO_ARCH=	YES

post-patch:
	${FIND} ${WRKSRC} -name .DS_Store -delete

.include <bsd.port.mk>
