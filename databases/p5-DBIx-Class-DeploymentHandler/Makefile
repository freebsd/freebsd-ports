PORTNAME=	DBIx-Class-DeploymentHandler
PORTVERSION=	0.002234
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for extensible DBIx::Class deployment
WWW=		https://metacpan.org/release/DBIx-Class-DeploymentHandler

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Carp-Clan>=0:devel/p5-Carp-Clan \
		p5-Context-Preserve>=0.01:devel/p5-Context-Preserve \
		p5-DBIx-Class>=0.081210:databases/p5-DBIx-Class \
		p5-Log-Contextual>=0.005005:devel/p5-Log-Contextual \
		p5-Moose>=1:devel/p5-Moose \
		p5-MooseX-Role-Parameterized>=0.18:devel/p5-MooseX-Role-Parameterized \
		p5-Path-Class>=0.26:devel/p5-Path-Class \
		p5-SQL-SplitStatement>=1.00020:databases/p5-SQL-SplitStatement \
		p5-SQL-Translator>=1.63:databases/p5-SQL-Translator \
		p5-Sub-Exporter-Progressive>=0:devel/p5-Sub-Exporter-Progressive \
		p5-Text-Brew>=0.02:textproc/p5-Text-Brew \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-YAML>=0.66:textproc/p5-YAML \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
TEST_DEPENDS=	p5-DBD-SQLite>=1.35:databases/p5-DBD-SQLite \
		p5-Test-Fatal>=0.006:devel/p5-Test-Fatal \
		p5-Test-Requires>=0.06:devel/p5-Test-Requires \
		p5-aliased>=0:devel/p5-aliased

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
