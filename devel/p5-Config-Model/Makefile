# ex:ts=8
# Ports collection makefile for:	Config::Model
# Date created:			Jan 29, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Config-Model
PORTVERSION=	0.640
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Model to create configuration validation tool

RUN_DEPENDS=	p5-Carp-Assert-More>=0:${PORTSDIR}/devel/p5-Carp-Assert-More \
		p5-Exception-Class>=0:${PORTSDIR}/devel/p5-Exception-Class \
		p5-Log-Log4perl>=1.11:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-Parse-RecDescent>=1.90.0:${PORTSDIR}/devel/p5-Parse-RecDescent
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-Config-Tiny>=0:${PORTSDIR}/devel/p5-Config-Tiny \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Warn>=0.11:${PORTSDIR}/devel/p5-Test-Warn

PERL_MODBUILD=	5.8.0+

MAN1=		config-edit.1
MAN3=		Config::Model.3 Config::Model::AnyId.3 \
		Config::Model::AnyThing.3 Config::Model::AutoRead.3 \
		Config::Model::CheckList.3 Config::Model::Describe.3 \
		Config::Model::DumpAsData.3 Config::Model::Dumper.3 \
		Config::Model::Exception.3 Config::Model::HashId.3 \
		Config::Model::IdElementReference.3 Config::Model::Instance.3 \
		Config::Model::ListId.3 Config::Model::Loader.3 \
		Config::Model::Node.3 Config::Model::ObjTreeScanner.3 \
		Config::Model::Report.3 Config::Model::Searcher.3 \
		Config::Model::SimpleUI.3 Config::Model::TermUI.3 \
		Config::Model::Value.3 Config::Model::ValueComputer.3 \
		Config::Model::WarpedNode.3 Config::Model::WarpedThing.3 \
		Config::Model::WizardHelper.3

.include <bsd.port.mk>
