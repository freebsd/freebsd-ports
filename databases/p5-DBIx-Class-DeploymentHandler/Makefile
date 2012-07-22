# New ports collection makefile for:	DBIx::Class::DeploymentHandler
# Date created:		10 Dec 2011
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Class-DeploymentHandler
PORTVERSION=	0.002115
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for extensible DBIx::Class deployment

RUN_DEPENDS=	\
	p5-Carp-Clan>0:${PORTSDIR}/devel/p5-Carp-Clan \
	p5-Context-Preserve>0:${PORTSDIR}/devel/p5-Context-Preserve \
	p5-DBD-SQLite>=1.35:${PORTSDIR}/databases/p5-DBD-SQLite \
	p5-DBIx-Class>=0.08121:${PORTSDIR}/databases/p5-DBIx-Class \
	p5-Log-Contextual>=0.00300:${PORTSDIR}/devel/p5-Log-Contextual \
	p5-Method-Signatures-Simple>=0.05:${PORTSDIR}/devel/p5-Method-Signatures-Simple \
	p5-Moose>=1.0:${PORTSDIR}/devel/p5-Moose \
	p5-MooseX-Role-Parameterized>=0.18:${PORTSDIR}/devel/p5-MooseX-Role-Parameterized \
	p5-SQL-Translator>=0.11005:${PORTSDIR}/databases/p5-SQL-Translator \
	p5-Try-Tiny>0:${PORTSDIR}/lang/p5-Try-Tiny \
	p5-aliased>0:${PORTSDIR}/devel/p5-aliased \
	p5-namespace-autoclean>0:${PORTSDIR}/devel/p5-namespace-autoclean \
	p5-parent>=0.225:${PORTSDIR}/devel/p5-parent
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
	p5-Test-Requires>=0.06:${PORTSDIR}/devel/p5-Test-Requires \
	p5-Test-Simple>0:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=	DBIx::Class::DeploymentHandler.3 \
	DBIx::Class::DeploymentHandler::Cookbook::CustomResultSource.3 \
	DBIx::Class::DeploymentHandler::Dad.3 \
	DBIx::Class::DeploymentHandler::DeployMethod::SQL::Translator.3 \
	DBIx::Class::DeploymentHandler::DeployMethod::SQL::Translator::Deprecated.3 \
	DBIx::Class::DeploymentHandler::DeployMethod::SQL::Translator::ScriptHelpers.3 \
	DBIx::Class::DeploymentHandler::Deprecated.3 \
	DBIx::Class::DeploymentHandler::HandlesDeploy.3 \
	DBIx::Class::DeploymentHandler::HandlesVersionStorage.3 \
	DBIx::Class::DeploymentHandler::HandlesVersioning.3 \
	DBIx::Class::DeploymentHandler::Logger.3 \
	DBIx::Class::DeploymentHandler::Manual::CatalystIntro.3 \
	DBIx::Class::DeploymentHandler::Manual::Intro.3 \
	DBIx::Class::DeploymentHandler::Types.3 \
	DBIx::Class::DeploymentHandler::VersionHandler::DatabaseToSchemaVersions.3 \
	DBIx::Class::DeploymentHandler::VersionHandler::ExplicitVersions.3 \
	DBIx::Class::DeploymentHandler::VersionHandler::Monotonic.3 \
	DBIx::Class::DeploymentHandler::VersionStorage::Deprecated.3 \
	DBIx::Class::DeploymentHandler::VersionStorage::Deprecated::Component.3 \
	DBIx::Class::DeploymentHandler::VersionStorage::Deprecated::VersionResult.3 \
	DBIx::Class::DeploymentHandler::VersionStorage::Deprecated::VersionResultSet.3 \
	DBIx::Class::DeploymentHandler::VersionStorage::Standard.3 \
	DBIx::Class::DeploymentHandler::VersionStorage::Standard::Component.3 \
	DBIx::Class::DeploymentHandler::VersionStorage::Standard::VersionResult.3 \
	DBIx::Class::DeploymentHandler::VersionStorage::Standard::VersionResultSet.3 \
	DBIx::Class::DeploymentHandler::WithApplicatorDumple.3 \
	DBIx::Class::DeploymentHandler::WithReasonableDefaults.3

.include <bsd.port.mk>
