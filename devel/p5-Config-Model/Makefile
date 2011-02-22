# ex:ts=8
# Ports collection makefile for:	Config::Model
# Date created:			Jan 29, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Config-Model
PORTVERSION=	1.234
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/D/DD/DDUMONT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Model to create configuration validation tool

RUN_DEPENDS=	p5-Carp-Assert-More>=0:${PORTSDIR}/devel/p5-Carp-Assert-More \
		p5-Exception-Class>=0:${PORTSDIR}/devel/p5-Exception-Class \
		p5-Log-Log4perl>=1.11:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Parse-RecDescent>=v1.90.0:${PORTSDIR}/devel/p5-Parse-RecDescent \
		p5-Text-Autoformat>=0:${PORTSDIR}/textproc/p5-Text-Autoformat \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML

PERL_MODBUILD=	5.8.0+

MAN1=		config-edit.1

MAN3=		Config::Model.3 \
		Config::Model::Annotation.3 \
		Config::Model::AnyId.3 \
		Config::Model::AnyThing.3 Config::Model::AutoRead.3 \
		Config::Model::Backend::Any.3 \
		Config::Model::Backend::Debian::Dpkg::Control.3 \
		Config::Model::Backend::Debian::Dpkg::Copyright.3 \
		Config::Model::Backend::Debian::DpkgSyntax.3 \
		Config::Model::Backend::Fstab.3 \
		Config::Model::Backend::IniFile.3 \
		Config::Model::Backend::PlainFile.3 \
		Config::Model::Backend::ShellVar.3 \
		Config::Model::Backend::Yaml.3 \
		Config::Model::CheckList.3 Config::Model::Describe.3 \
		Config::Model::Cookbook::CreateModelFromDoc.3 \
		Config::Model::Debian::Dependency.3 \
		Config::Model::DumpAsData.3 Config::Model::Dumper.3 \
		Config::Model::Exception.3 Config::Model::HashId.3 \
		Config::Model::FuseUI.3 \
		Config::Model::IdElementReference.3 Config::Model::Instance.3 \
		Config::Model::ListId.3 Config::Model::Loader.3 \
		Config::Model::Manual::ModelCreationAdvanced.3 \
		Config::Model::Manual::ModelCreationIntroduction.3 \
		Config::Model::Iterator.3 \
		Config::Model::Node.3 Config::Model::ObjTreeScanner.3 \
		Config::Model::Report.3 Config::Model::Searcher.3 \
		Config::Model::SimpleUI.3 Config::Model::TermUI.3 \
		Config::Model::Value.3 Config::Model::ValueComputer.3 \
		Config::Model::WarpedNode.3 Config::Model::WarpedThing.3

.include <bsd.port.mk>
