# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Module-CPANTS-Analyse
PORTVERSION=	0.90.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generate Kwalitee ratings for a distribution

BUILD_DEPENDS=	p5-Archive-Any-Lite>=0.06:${PORTSDIR}/archivers/p5-Archive-Any-Lite \
		p5-Array-Diff>=0.04:${PORTSDIR}/misc/p5-Array-Diff \
		p5-CPAN-DistnameInfo>=0.06:${PORTSDIR}/devel/p5-CPAN-DistnameInfo \
		p5-CPAN-Meta>=2.131490:${PORTSDIR}/devel/p5-CPAN-Meta \
		p5-CPAN-Meta-YAML>=0.008:${PORTSDIR}/devel/p5-CPAN-Meta-YAML \
		p5-Class-Accessor>=0.19:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-File-Find-Rule-VCS>=0:${PORTSDIR}/devel/p5-File-Find-Rule-VCS \
		p5-IO-Capture>=0.05:${PORTSDIR}/devel/p5-IO-Capture \
		p5-Module-ExtractUse>=0.30:${PORTSDIR}/devel/p5-Module-ExtractUse \
		p5-Set-Scalar>=0:${PORTSDIR}/devel/p5-Set-Scalar \
		p5-Software-License>=0.003000:${PORTSDIR}/misc/p5-Software-License \
		p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings \
		p5-Test-Warn>=0.11:${PORTSDIR}/devel/p5-Test-Warn \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Warn>=0.11:${PORTSDIR}/devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	modbuild

MAN1=		cpants_lint.pl.1
MAN3=		Module::CPANTS::Analyse.3 \
		Module::CPANTS::Kwalitee.3 \
		Module::CPANTS::Kwalitee::BrokenInstaller.3 \
		Module::CPANTS::Kwalitee::CpantsErrors.3 \
		Module::CPANTS::Kwalitee::Distname.3 \
		Module::CPANTS::Kwalitee::Distros.3 \
		Module::CPANTS::Kwalitee::Files.3 \
		Module::CPANTS::Kwalitee::FindModules.3 \
		Module::CPANTS::Kwalitee::License.3 \
		Module::CPANTS::Kwalitee::Manifest.3 \
		Module::CPANTS::Kwalitee::MetaYML.3 \
		Module::CPANTS::Kwalitee::NeedsCompiler.3 \
		Module::CPANTS::Kwalitee::Pod.3 \
		Module::CPANTS::Kwalitee::Prereq.3 \
		Module::CPANTS::Kwalitee::Repackageable.3 \
		Module::CPANTS::Kwalitee::Signature.3 \
		Module::CPANTS::Kwalitee::Uses.3 \
		Module::CPANTS::Kwalitee::Version.3

.include <bsd.port.mk>
