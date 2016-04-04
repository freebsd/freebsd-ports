# $FreeBSD$

PORTNAME=	Dist-Zilla
PORTVERSION=	4.300030
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Distribution builder

BUILD_DEPENDS=	p5-App-Cmd>=0.309:devel/p5-App-Cmd \
		p5-CPAN-Meta-Requirements>=2.121:devel/p5-CPAN-Meta-Requirements \
		p5-CPAN-Uploader>=0.101550:devel/p5-CPAN-Uploader \
		p5-Class-Load>=0.17:devel/p5-Class-Load \
		p5-Config-MVP-Reader-INI>=2:devel/p5-Config-MVP-Reader-INI \
		p5-Config-MVP>=2.200002:devel/p5-Config-MVP \
		p5-Data-Section>=0.004:devel/p5-Data-Section \
		p5-DateTime>=0.44:devel/p5-DateTime \
		p5-File-Copy-Recursive>=0:devel/p5-File-Copy-Recursive \
		p5-File-Find-Rule>=0:devel/p5-File-Find-Rule \
		p5-File-HomeDir>=0:devel/p5-File-HomeDir \
		p5-File-ShareDir-Install>=0.03:devel/p5-File-ShareDir-Install \
		p5-File-ShareDir>=0:devel/p5-File-ShareDir \
		p5-File-pushd>=0:devel/p5-File-pushd \
		p5-Hash-Merge-Simple>=0:devel/p5-Hash-Merge-Simple \
		p5-JSON>=2:converters/p5-JSON \
		p5-List-AllUtils>=0:devel/p5-List-AllUtils \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Log-Dispatchouli>=1.102220:devel/p5-Log-Dispatchouli \
		p5-Moose-Autobox>=0.10:devel/p5-Moose-Autobox \
		p5-Moose>=0.92:devel/p5-Moose \
		p5-MooseX-LazyRequire>=0:devel/p5-MooseX-LazyRequire \
		p5-MooseX-Role-Parameterized>=0:devel/p5-MooseX-Role-Parameterized \
		p5-MooseX-SetOnce>=0:devel/p5-MooseX-SetOnce \
		p5-MooseX-Types-Path-Class>=0:devel/p5-MooseX-Types-Path-Class \
		p5-MooseX-Types-Perl>=0:devel/p5-MooseX-Types-Perl \
		p5-MooseX-Types>=0:devel/p5-MooseX-Types \
		p5-PPI>=0:textproc/p5-PPI \
		p5-Params-Util>=0:devel/p5-Params-Util \
		p5-Path-Class>=0:devel/p5-Path-Class \
		p5-Perl-PrereqScanner>=1.005:devel/p5-Perl-PrereqScanner \
		p5-Perl-Version>=0:devel/p5-Perl-Version \
		p5-Pod-Eventual>=0.091480:textproc/p5-Pod-Eventual \
		p5-Software-License>=0.101370:misc/p5-Software-License \
		p5-String-Formatter>=0.100680:devel/p5-String-Formatter \
		p5-String-RewritePrefix>=0.005:textproc/p5-String-RewritePrefix \
		p5-Sub-Exporter-ForMethods>=0:devel/p5-Sub-Exporter-ForMethods \
		p5-Sub-Exporter>=0:devel/p5-Sub-Exporter \
		p5-Term-ReadKey>=0:devel/p5-Term-ReadKey \
		p5-Text-Glob>=0.08:textproc/p5-Text-Glob \
		p5-Text-Template>=0:textproc/p5-Text-Template \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-YAML-Tiny>=0:textproc/p5-YAML-Tiny \
		p5-autobox>=2.53:devel/p5-autobox \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep

USES=		perl5
USE_PERL5=	configure

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} test

.include <bsd.port.mk>
