# $FreeBSD$

PORTNAME=	Dist-Zilla
PORTVERSION=	6.015
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Distribution builder

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-App-Cmd>=0.330:devel/p5-App-Cmd \
		p5-CPAN-Uploader>=0.103004:devel/p5-CPAN-Uploader \
		p5-Class-Load>=0.17:devel/p5-Class-Load \
		p5-Config-MVP>=2.200011:devel/p5-Config-MVP \
		p5-Config-MVP-Reader-INI>=2.101461:devel/p5-Config-MVP-Reader-INI \
		p5-Data-Section>=0.200002:devel/p5-Data-Section \
		p5-DateTime>=0.44:devel/p5-DateTime \
		p5-File-Copy-Recursive>=0.41:devel/p5-File-Copy-Recursive \
		p5-File-Find-Rule>=0:devel/p5-File-Find-Rule \
		p5-File-ShareDir>=0:devel/p5-File-ShareDir \
		p5-File-ShareDir-Install>=0.06:devel/p5-File-ShareDir-Install \
		p5-File-pushd>=0:devel/p5-File-pushd \
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-Log-Dispatchouli>=1.102220:devel/p5-Log-Dispatchouli \
		p5-Mixin-Linewise>=0.100:devel/p5-Mixin-Linewise \
		p5-Module-Runtime>=0:devel/p5-Module-Runtime \
		p5-Moose>=0.92:devel/p5-Moose \
		p5-MooseX-LazyRequire>=0:devel/p5-MooseX-LazyRequire \
		p5-MooseX-Role-Parameterized>=1.01:devel/p5-MooseX-Role-Parameterized \
		p5-MooseX-SetOnce>=0:devel/p5-MooseX-SetOnce \
		p5-MooseX-Types>=0:devel/p5-MooseX-Types \
		p5-MooseX-Types-Perl>=0:devel/p5-MooseX-Types-Perl \
		p5-PPI>=0:textproc/p5-PPI \
		p5-Params-Util>=0:devel/p5-Params-Util \
		p5-Path-Tiny>=0.052:devel/p5-Path-Tiny \
		p5-Perl-PrereqScanner>=1.006:devel/p5-Perl-PrereqScanner \
		p5-Software-License>=0.103014:misc/p5-Software-License \
		p5-String-Formatter>=0.100680:devel/p5-String-Formatter \
		p5-String-RewritePrefix>=0.006:textproc/p5-String-RewritePrefix \
		p5-Sub-Exporter>=0:devel/p5-Sub-Exporter \
		p5-Sub-Exporter-ForMethods>=0:devel/p5-Sub-Exporter-ForMethods \
		p5-Term-Encoding>=0:devel/p5-Term-Encoding \
		p5-Term-ReadKey>=0:devel/p5-Term-ReadKey \
		p5-Term-UI>=0:devel/p5-Term-UI \
		p5-Text-Glob>=0.08:textproc/p5-Text-Glob \
		p5-Text-Template>=0:textproc/p5-Text-Template \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-YAML-Tiny>=0:textproc/p5-YAML-Tiny \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
TEST_DEPENDS=	p5-CPAN-Meta-Check>=0.011:devel/p5-CPAN-Meta-Check \
		p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-FailWarnings>=0:devel/p5-Test-FailWarnings \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-File-ShareDir>=0:devel/p5-Test-File-ShareDir

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
