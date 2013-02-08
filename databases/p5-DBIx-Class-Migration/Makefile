# $FreeBSD$

PORTNAME=	DBIx-Class-Migration
PORTVERSION=	0.037
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
	p5-DBIx-Class-Fixtures>=1.001016:${PORTSDIR}/databases/p5-DBIx-Class-Fixtures \
	p5-DBIx-Class-Schema-Loader>=0.07017:${PORTSDIR}/databases/p5-DBIx-Class-Schema-Loader \
	p5-Devel-PartialDump>0:${PORTSDIR}/devel/p5-Devel-PartialDump \
	p5-File-ShareDir-ProjectDistDir>=0.3.1:${PORTSDIR}/devel/p5-File-ShareDir-ProjectDistDir \
	p5-JSON-XS>=2.32:${PORTSDIR}/converters/p5-JSON-XS \
	p5-Moose>0:${PORTSDIR}/devel/p5-Moose \
	p5-MooseX-Attribute-ENV>=0.02:${PORTSDIR}/devel/p5-MooseX-Attribute-ENV \
	p5-MooseX-Getopt>=0.45:${PORTSDIR}/devel/p5-MooseX-Getopt \
	p5-MooseX-Traits-Pluggable>0:${PORTSDIR}/devel/p5-MooseX-Traits-Pluggable \
	p5-MooseX-Types>0:${PORTSDIR}/devel/p5-MooseX-Types \
	p5-MooseX-Types-LoadableClass>0:${PORTSDIR}/devel/p5-MooseX-Types-LoadableClass \
	p5-Pod-Parser>0:${PORTSDIR}/textproc/p5-Pod-Parser \
	p5-SQL-Translator>=0.11010:${PORTSDIR}/databases/p5-SQL-Translator \
	p5-Text-Brew>0:${PORTSDIR}/textproc/p5-Text-Brew
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-Most>0:${PORTSDIR}/devel/p5-Test-Most \
	p5-Test-Requires>0:${PORTSDIR}/devel/p5-Test-Requires \
	p5-Test-Trap>0:${PORTSDIR}/devel/p5-Test-Trap \
	p5-Capture-Tiny>0:${PORTSDIR}/devel/p5-Capture-Tiny

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
	DBIx::Class::Migration::RunScript::Trait::Dump.3 \
	DBIx::Class::Migration::RunScript::Trait::Populate.3 \
	DBIx::Class::Migration::RunScript::Trait::SchemaLoader.3 \
	DBIx::Class::Migration::RunScript::Trait::TargetPath.3 \
	DBIx::Class::Migration::Sandbox.3 \
	DBIx::Class::Migration::SchemaLoader.3 \
	DBIx::Class::Migration::Script.3 \
	DBIx::Class::Migration::Script::Help.3 \
	DBIx::Class::Migration::Script::Help::databases.3 \
	DBIx::Class::Migration::Script::Help::dbi_connect_attrs.3 \
	DBIx::Class::Migration::Script::Help::dbic_connect_attrs.3 \
	DBIx::Class::Migration::Script::Help::dbic_fixture_class.3 \
	DBIx::Class::Migration::Script::Help::dbic_fixtures_extra_args.3 \
	DBIx::Class::Migration::Script::Help::delete_named_sets.3 \
	DBIx::Class::Migration::Script::Help::delete_table_rows.3 \
	DBIx::Class::Migration::Script::Help::diagram.3 \
	DBIx::Class::Migration::Script::Help::downgrade.3 \
	DBIx::Class::Migration::Script::Help::drop_tables.3 \
	DBIx::Class::Migration::Script::Help::dsn.3 \
	DBIx::Class::Migration::Script::Help::dump_all_sets.3 \
	DBIx::Class::Migration::Script::Help::dump_named_sets.3 \
	DBIx::Class::Migration::Script::Help::extra_schemaloader_args.3 \
	DBIx::Class::Migration::Script::Help::fixture_sets.3 \
	DBIx::Class::Migration::Script::Help::force_overwrite.3 \
	DBIx::Class::Migration::Script::Help::help.3 \
	DBIx::Class::Migration::Script::Help::includes.3 \
	DBIx::Class::Migration::Script::Help::install.3 \
	DBIx::Class::Migration::Script::Help::install_if_needed.3 \
	DBIx::Class::Migration::Script::Help::install_version_storage.3 \
	DBIx::Class::Migration::Script::Help::make_schema.3 \
	DBIx::Class::Migration::Script::Help::password.3 \
	DBIx::Class::Migration::Script::Help::populate.3 \
	DBIx::Class::Migration::Script::Help::prepare.3 \
	DBIx::Class::Migration::Script::Help::sandbox_class.3 \
	DBIx::Class::Migration::Script::Help::schema_class.3 \
	DBIx::Class::Migration::Script::Help::status.3 \
	DBIx::Class::Migration::Script::Help::target_dir.3 \
	DBIx::Class::Migration::Script::Help::to_version.3 \
	DBIx::Class::Migration::Script::Help::upgrade.3 \
	DBIx::Class::Migration::Script::Help::username.3 \
	DBIx::Class::Migration::Script::Help::version.3 \
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
	DBIx::Class::Migration::Types.3 \
	Test::DBIx::Class::FixtureCommand::Population.3

.include <bsd.port.mk>
