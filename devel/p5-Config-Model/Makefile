# Ports collection makefile for:	Config::Model
# Date created:			Jan 29, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Config-Model
PORTVERSION=	1.259
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DDUMONT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Model to create configuration validation tool

LICENSE=	LGPL21

BUILD_DEPENDS=	p5-File-Copy-Recursive>=0:${PORTSDIR}/devel/p5-File-Copy-Recursive \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-Log-Log4perl>=1.11:${PORTSDIR}/devel/p5-Log-Log4perl
RUN_DEPENDS=	p5-Any-Moose>=0:${PORTSDIR}/devel/p5-Any-Moose \
		p5-Carp-Assert-More>=0:${PORTSDIR}/devel/p5-Carp-Assert-More \
		p5-Exception-Class>=0:${PORTSDIR}/devel/p5-Exception-Class \
		p5-File-HomeDir>=0:${PORTSDIR}/devel/p5-File-HomeDir \
		p5-Hash-Merge>=0.12:${PORTSDIR}/textproc/p5-Hash-Merge \
		p5-Log-Log4perl>=1.11:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-MouseX-NativeTraits>=0:${PORTSDIR}/devel/p5-MouseX-NativeTraits \
		p5-MouseX-StrictConstructor>=0:${PORTSDIR}/devel/p5-MouseX-StrictConstructor \
		p5-Parse-RecDescent>=1.90.0:${PORTSDIR}/devel/p5-Parse-RecDescent \
		p5-Pod-POM>=0:${PORTSDIR}/textproc/p5-Pod-POM \
		p5-Text-Autoformat>=0:${PORTSDIR}/textproc/p5-Text-Autoformat \
		p5-YAML>=0.68:${PORTSDIR}/textproc/p5-YAML \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

TEST_DEPENDS=	p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		p5-Probe-Perl>=0:${PORTSDIR}/sysutils/p5-Probe-Perl \
		p5-Test-Differences>=0:${PORTSDIR}/devel/p5-Test-Differences

PERL_MODBUILD=	yes

MAN1=		config-edit.1
MAN3=		Config::Model.3 \
		Config::Model::Annotation.3 \
		Config::Model::AnyId.3 \
		Config::Model::AnyThing.3 \
		Config::Model::Backend::Any.3 \
		Config::Model::Backend::Debian::Dpkg.3 \
		Config::Model::Backend::Debian::Dpkg::Control.3 \
		Config::Model::Backend::Debian::Dpkg::Copyright.3 \
		Config::Model::Backend::Debian::Dpkg::Patch.3 \
		Config::Model::Backend::Debian::DpkgSyntax.3 \
		Config::Model::Backend::Fstab.3 \
		Config::Model::Backend::IniFile.3 \
		Config::Model::Backend::PlainFile.3 \
		Config::Model::Backend::ShellVar.3 \
		Config::Model::Backend::Yaml.3 \
		Config::Model::BackendMgr.3 \
		Config::Model::CheckList.3 \
		Config::Model::Cookbook::CreateModelFromDoc.3 \
		Config::Model::Debian::Dependency.3 \
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
		Config::Model::ValueComputer.3 \
		Config::Model::WarpedNode.3 \
		Config::Model::Warper.3 \
		Config::Model::models::Debian::Dpkg.3 \
		Config::Model::models::Debian::Dpkg::Control.3 \
		Config::Model::models::Debian::Dpkg::Control::Binary.3 \
		Config::Model::models::Debian::Dpkg::Control::Source.3 \
		Config::Model::models::Debian::Dpkg::Copyright.3 \
		Config::Model::models::Debian::Dpkg::Copyright::Content.3 \
		Config::Model::models::Debian::Dpkg::Copyright::FileLicense.3 \
		Config::Model::models::Debian::Dpkg::Copyright::GlobalLicense.3 \
		Config::Model::models::Debian::Dpkg::Copyright::License.3 \
		Config::Model::models::Debian::Dpkg::Copyright::LicenseSpec.3 \
		Config::Model::models::Debian::Dpkg::Meta.3 \
		Config::Model::models::Debian::Dpkg::Patch.3 \
		Config::Model::models::Debian::Dpkg::Source.3 \
		Config::Model::models::Debian::Dpkg::Source::Options.3 \
		Config::Model::models::Fstab.3 \
		Config::Model::models::Fstab::FsLine.3 \
		Config::Model::models::LCDd.3 \
		Config::Model::models::LCDd::CFontz.3 \
		Config::Model::models::LCDd::CFontz633.3 \
		Config::Model::models::LCDd::CFontzPacket.3 \
		Config::Model::models::LCDd::CwLnx.3 \
		Config::Model::models::LCDd::EyeboxOne.3 \
		Config::Model::models::LCDd::IOWarrior.3 \
		Config::Model::models::LCDd::IrMan.3 \
		Config::Model::models::LCDd::MD8800.3 \
		Config::Model::models::LCDd::MtxOrb.3 \
		Config::Model::models::LCDd::NoritakeVFD.3 \
		Config::Model::models::LCDd::SureElec.3 \
		Config::Model::models::LCDd::bayrad.3 \
		Config::Model::models::LCDd::curses.3 \
		Config::Model::models::LCDd::ea65.3 \
		Config::Model::models::LCDd::g15.3 \
		Config::Model::models::LCDd::glcdlib.3 \
		Config::Model::models::LCDd::glk.3 \
		Config::Model::models::LCDd::hd44780.3 \
		Config::Model::models::LCDd::icp_a106.3 \
		Config::Model::models::LCDd::imon.3 \
		Config::Model::models::LCDd::imonlcd.3 \
		Config::Model::models::LCDd::irtrans.3 \
		Config::Model::models::LCDd::joy.3 \
		Config::Model::models::LCDd::lb216.3 \
		Config::Model::models::LCDd::lcdm001.3 \
		Config::Model::models::LCDd::lcterm.3 \
		Config::Model::models::LCDd::lirc.3 \
		Config::Model::models::LCDd::lis.3 \
		Config::Model::models::LCDd::mdm166a.3 \
		Config::Model::models::LCDd::menu.3 \
		Config::Model::models::LCDd::ms6931.3 \
		Config::Model::models::LCDd::mtc_s16209x.3 \
		Config::Model::models::LCDd::mx5000.3 \
		Config::Model::models::LCDd::picolcd.3 \
		Config::Model::models::LCDd::pyramid.3 \
		Config::Model::models::LCDd::sed1330.3 \
		Config::Model::models::LCDd::sed1520.3 \
		Config::Model::models::LCDd::serialPOS.3 \
		Config::Model::models::LCDd::serialVFD.3 \
		Config::Model::models::LCDd::server.3 \
		Config::Model::models::LCDd::shuttleVFD.3 \
		Config::Model::models::LCDd::sli.3 \
		Config::Model::models::LCDd::stv5730.3 \
		Config::Model::models::LCDd::svga.3 \
		Config::Model::models::LCDd::t6963.3 \
		Config::Model::models::LCDd::text.3 \
		Config::Model::models::LCDd::tyan.3 \
		Config::Model::models::LCDd::ula200.3 \
		Config::Model::models::LCDd::xosd.3 \
		Config::Model::models::PopCon.3

.include <bsd.port.mk>
