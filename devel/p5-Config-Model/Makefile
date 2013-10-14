# Created by: ijliao
# $FreeBSD$

PORTNAME=	Config-Model
PORTVERSION=	2.044
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DDUMONT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Model to create configuration validation tool

LICENSE=	LGPL21

BUILD_DEPENDS=	p5-AnyEvent>=0:${PORTSDIR}/devel/p5-AnyEvent \
		p5-AnyEvent-HTTP>=0:${PORTSDIR}/www/p5-AnyEvent-HTTP \
		p5-Carp-Assert-More>=0:${PORTSDIR}/devel/p5-Carp-Assert-More \
		p5-Exception-Class>=0:${PORTSDIR}/devel/p5-Exception-Class \
		p5-File-HomeDir>=0:${PORTSDIR}/devel/p5-File-HomeDir \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-Hash-Merge>=0.12:${PORTSDIR}/textproc/p5-Hash-Merge \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Log-Log4perl>=1.11:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-Mouse>=0:${PORTSDIR}/devel/p5-Mouse \
		p5-MouseX-NativeTraits>=0:${PORTSDIR}/devel/p5-MouseX-NativeTraits \
		p5-MouseX-StrictConstructor>=0:${PORTSDIR}/devel/p5-MouseX-StrictConstructor \
		p5-Parse-RecDescent>=1.90.0:${PORTSDIR}/devel/p5-Parse-RecDescent \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		p5-Pod-POM>=0:${PORTSDIR}/textproc/p5-Pod-POM \
		p5-Text-Autoformat>=0:${PORTSDIR}/textproc/p5-Text-Autoformat \
		p5-Text-Diff>=0:${PORTSDIR}/textproc/p5-Text-Diff \
		p5-YAML>=0.30.3:${PORTSDIR}/textproc/p5-YAML \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Config-Model-Tester>=2.044:${PORTSDIR}/devel/p5-Config-Model-Tester \
		p5-Probe-Perl>=0:${PORTSDIR}/sysutils/p5-Probe-Perl \
		p5-Test-Command>=0:${PORTSDIR}/devel/p5-Test-Command \
		p5-Test-Differences>=0:${PORTSDIR}/devel/p5-Test-Differences \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-File-Contents>=0:${PORTSDIR}/devel/p5-Test-File-Contents \
		p5-Test-Memory-Cycle>=0:${PORTSDIR}/devel/p5-Test-Memory-Cycle \
		p5-Test-Warn>=0:${PORTSDIR}/devel/p5-Test-Warn

NO_STAGE=	yes
USES=		perl5
USE_PERL5=	modbuild

MAN1=		cme.1 \
		config-edit.1
MAN3=		Config::Model.3 \
		Config::Model::Annotation.3 \
		Config::Model::AnyId.3 \
		Config::Model::AnyThing.3 \
		Config::Model::Backend::Any.3 \
		Config::Model::Backend::Fstab.3 \
		Config::Model::Backend::IniFile.3 \
		Config::Model::Backend::Json.3 \
		Config::Model::Backend::PlainFile.3 \
		Config::Model::Backend::ShellVar.3 \
		Config::Model::Backend::Yaml.3 \
		Config::Model::BackendMgr.3 \
		Config::Model::CheckList.3 \
		Config::Model::Cookbook::CreateModelFromDoc.3 \
		Config::Model::Describe.3 \
		Config::Model::DumpAsData.3 \
		Config::Model::Dumper.3 \
		Config::Model::Exception.3 \
		Config::Model::FuseUI.3 \
		Config::Model::HashId.3 \
		Config::Model::IdElementReference.3 \
		Config::Model::Instance.3 \
		Config::Model::Iterator.3 \
		Config::Model::ListId.3 \
		Config::Model::Lister.3 \
		Config::Model::Loader.3 \
		Config::Model::Manual::ModelCreationAdvanced.3 \
		Config::Model::Manual::ModelCreationIntroduction.3 \
		Config::Model::Node.3 \
		Config::Model::ObjTreeScanner.3 \
		Config::Model::Report.3 \
		Config::Model::SearchElement.3 \
		Config::Model::SimpleUI.3 \
		Config::Model::TermUI.3 \
		Config::Model::TreeSearcher.3 \
		Config::Model::Value.3 \
		Config::Model::Value::LayeredInclude.3 \
		Config::Model::ValueComputer.3 \
		Config::Model::WarpedNode.3 \
		Config::Model::Warper.3 \
		Config::Model::models::Fstab.3 \
		Config::Model::models::Fstab::FsLine.3 \
		Config::Model::models::Multistrap.3 \
		Config::Model::models::Multistrap::Section.3 \
		Config::Model::models::PopCon.3

.include <bsd.port.mk>
