# New ports collection makefile for:	DBIx::Class::Migration
# Date created:		19 Mar 2012
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Class-Migration
PORTVERSION=	0.025
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to make migrating your DBIx::Class databases easier

RUN_DEPENDS=	\
	p5-Class-Load>0:${PORTSDIR}/devel/p5-Class-Load \
	p5-Config-MySQL>=0.02:${PORTSDIR}/devel/p5-Config-MySQL \
	p5-DBD-SQLite>=1.35:${PORTSDIR}/databases/p5-DBD-SQLite \
	p5-DBIx-Class-DeploymentHandler>=0.002100:${PORTSDIR}/databases/p5-DBIx-Class-DeploymentHandler \
	p5-DBIx-Class-Fixtures>=1.001014:${PORTSDIR}/databases/p5-DBIx-Class-Fixtures \
	p5-DBIx-Class-Schema-Loader>=0.07017:${PORTSDIR}/databases/p5-DBIx-Class-Schema-Loader \
	p5-Devel-PartialDump>0:${PORTSDIR}/devel/p5-Devel-PartialDump \
	p5-File-ShareDir-ProjectDistDir>=0.3.1:${PORTSDIR}/devel/p5-File-ShareDir-ProjectDistDir \
	p5-JSON-XS>=2.32:${PORTSDIR}/converters/p5-JSON-XS \
	p5-Moose>0:${PORTSDIR}/devel/p5-Moose \
	p5-MooseX-Attribute-ENV>=0.02:${PORTSDIR}/devel/p5-MooseX-Attribute-ENV \
	p5-MooseX-Getopt>0:${PORTSDIR}/devel/p5-MooseX-Getopt \
	p5-MooseX-Traits-Pluggable>0:${PORTSDIR}/devel/p5-MooseX-Traits-Pluggable \
	p5-MooseX-Types-LoadableClass>0:${PORTSDIR}/devel/p5-MooseX-Types-LoadableClass \
	p5-Pod-Parser>0:${PORTSDIR}/textproc/p5-Pod-Parser \
	p5-SQL-Translator>=0.11010:${PORTSDIR}/databases/p5-SQL-Translator
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-Most>0:${PORTSDIR}/devel/p5-Test-Most \
	p5-Test-Requires>0:${PORTSDIR}/devel/p5-Test-Requires

PERL_CONFIGURE=	yes

MAN1=	dbic-migration.1
MAN3=	Catalyst::TraitFor::Model::DBIC::Schema::FromMigration.3 \
	Catalyst::TraitFor::Model::DBIC::Schema::FromMigration::_MigrationHelper.3 \
	DBIx::Class::Migration.3 \
	DBIx::Class::Migration::FAQ.3 \
	DBIx::Class::Migration::Features.3 \
	DBIx::Class::Migration::MySQLSandbox.3 \
	DBIx::Class::Migration::Population.3 \
	DBIx::Class::Migration::PostgresqlSandbox.3 \
	DBIx::Class::Migration::RunScript.3 \
	DBIx::Class::Migration::RunScript::Trait::SchemaLoader.3 \
	DBIx::Class::Migration::Sandbox.3 \
	DBIx::Class::Migration::SchemaLoader.3 \
	DBIx::Class::Migration::Script.3 \
	DBIx::Class::Migration::ShareDirBuilder.3 \
	DBIx::Class::Migration::SqliteSandbox.3 \
	DBIx::Class::Migration::TargetDirSandboxBuilder.3 \
	DBIx::Class::Migration::TempDirBuilder.3 \
	DBIx::Class::Migration::TempDirSandboxBuilder.3 \
	DBIx::Class::Migration::Tutorial.3 \
	DBIx::Class::Migration::Tutorial::AddMySQL.3 \
	DBIx::Class::Migration::Tutorial::Catalyst.3 \
	DBIx::Class::Migration::Tutorial::Conclusion.3 \
	DBIx::Class::Migration::Tutorial::FirstMigration.3 \
	DBIx::Class::Migration::Tutorial::SecondMigration.3 \
	DBIx::Class::Migration::Tutorial::Setup.3 \
	DBIx::Class::Migration::Tutorial::Testing.3 \
	DBIx::Class::Migration::Tutorial::ThirdMigration.3 \
	Test::DBIx::Class::FixtureCommand::Population.3

.include <bsd.port.mk>
