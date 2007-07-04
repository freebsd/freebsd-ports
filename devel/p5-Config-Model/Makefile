# ex:ts=8
# Ports collection makefile for:	Config::Model
# Date created:			Jan 29, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Config-Model
DISTVERSION=	0.611
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN SF
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Model to create configuration validation tool

RUN_DEPENDS=	p5-Error>0:${PORTSDIR}/lang/p5-Error \
		p5-Exception-Class>0:${PORTSDIR}/devel/p5-Exception-Class \
		p5-Log-Log4perl>0:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-Parse-RecDescent>=1.90:${PORTSDIR}/devel/p5-Parse-RecDescent
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		config-edit.1
MAN3=		Config::Model.3pm Config::Model::AnyId.3pm \
		Config::Model::AnyThing.3pm Config::Model::AutoRead.3pm \
		Config::Model::CheckList.3pm Config::Model::Describe.3pm \
		Config::Model::Dumper.3pm Config::Model::Exception.3pm \
		Config::Model::HashId.3pm \
		Config::Model::IdElementReference.3pm \
		Config::Model::Instance.3pm Config::Model::ListId.3pm \
		Config::Model::Loader.3pm Config::Model::Node.3pm \
		Config::Model::ObjTreeScanner.3pm Config::Model::Report.3pm \
		Config::Model::Searcher.3pm Config::Model::TermUI.3pm \
		Config::Model::Value.3pm Config::Model::ValueComputer.3pm \
		Config::Model::WarpedNode.3pm Config::Model::WarpedThing.3pm \
		Config::Model::WizardHelper.3pm

.include <bsd.port.mk>
