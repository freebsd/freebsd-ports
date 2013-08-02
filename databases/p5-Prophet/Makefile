# Created by: Baptiste Daroussin <bapt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Prophet
PORTVERSION=	0.751
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:IOANR
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Prophet is a distributed database system

LICENSE=	MIT

BUILD_DEPENDS=	p5-Any-Moose>=0.04:${PORTSDIR}/devel/p5-Any-Moose \
		p5-Config-GitLike>=1.02:${PORTSDIR}/devel/p5-Config-GitLike \
		p5-DBD-SQLite>=1:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-DBI>=1:${PORTSDIR}/databases/p5-DBI \
		p5-Exporter-Lite>=0:${PORTSDIR}/devel/p5-Exporter-Lite \
		p5-File-ShareDir>=1.00:${PORTSDIR}/devel/p5-File-ShareDir \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-HTTP-Server-Simple>=0.40:${PORTSDIR}/www/p5-HTTP-Server-Simple \
		p5-IPC-Run3>=0:${PORTSDIR}/devel/p5-IPC-Run3 \
		p5-JSON>=2.00:${PORTSDIR}/converters/p5-JSON \
		p5-JSON-XS>=2.22:${PORTSDIR}/converters/p5-JSON-XS \
		p5-MIME-Base64-URLSafe>=0:${PORTSDIR}/converters/p5-MIME-Base64-URLSafe \
		p5-Module-Refresh>=0:${PORTSDIR}/devel/p5-Module-Refresh \
		p5-Mouse>=0.21:${PORTSDIR}/devel/p5-Mouse \
		p5-Net-Bonjour>=0:${PORTSDIR}/dns/p5-Net-Bonjour \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Path-Dispatcher>=0.14:${PORTSDIR}/devel/p5-Path-Dispatcher \
		p5-Path-Dispatcher-Declarative>=0:${PORTSDIR}/devel/p5-Path-Dispatcher-Declarative \
		p5-Proc-InvokeEditor>=0:${PORTSDIR}/editors/p5-Proc-InvokeEditor \
		p5-Template-Declare>=0.35:${PORTSDIR}/textproc/p5-Template-Declare \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-ReadLine-Perl>=0:${PORTSDIR}/devel/p5-ReadLine-Perl \
		p5-Time-Progress>=0:${PORTSDIR}/devel/p5-Time-Progress \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-UUID-Tiny>=1.02:${PORTSDIR}/devel/p5-UUID-Tiny \
		p5-XML-Atom-SimpleFeed>=0:${PORTSDIR}/textproc/p5-XML-Atom-SimpleFeed \
		p5-YAML-Syck>=0:${PORTSDIR}/textproc/p5-YAML-Syck
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Exception>=0.26:${PORTSDIR}/devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	modbuild

MAN1=	prophet.1
MAN3=	Prophet.3 \
	Prophet::App.3 \
	Prophet::CLI.3 \
	Prophet::CLI::CollectionCommand.3 \
	Prophet::CLI::Command.3 \
	Prophet::CLI::Command::Aliases.3 \
	Prophet::CLI::Command::Clone.3 \
	Prophet::CLI::Command::Config.3 \
	Prophet::CLI::Command::Create.3 \
	Prophet::CLI::Command::Delete.3 \
	Prophet::CLI::Command::Export.3 \
	Prophet::CLI::Command::History.3 \
	Prophet::CLI::Command::Info.3 \
	Prophet::CLI::Command::Init.3 \
	Prophet::CLI::Command::Log.3 \
	Prophet::CLI::Command::Merge.3 \
	Prophet::CLI::Command::Mirror.3 \
	Prophet::CLI::Command::Publish.3 \
	Prophet::CLI::Command::Pull.3 \
	Prophet::CLI::Command::Push.3 \
	Prophet::CLI::Command::Search.3 \
	Prophet::CLI::Command::Server.3 \
	Prophet::CLI::Command::Settings.3 \
	Prophet::CLI::Command::Shell.3 \
	Prophet::CLI::Command::Show.3 \
	Prophet::CLI::Command::Update.3 \
	Prophet::CLI::Dispatcher.3 \
	Prophet::CLI::Dispatcher::Rule.3 \
	Prophet::CLI::Dispatcher::Rule::RecordId.3 \
	Prophet::CLI::MirrorCommand.3 \
	Prophet::CLI::Parameters.3 \
	Prophet::CLI::ProgressBar.3 \
	Prophet::CLI::PublishCommand.3 \
	Prophet::CLI::RecordCommand.3 \
	Prophet::CLI::TextEditorCommand.3 \
	Prophet::CLIContext.3 \
	Prophet::Change.3 \
	Prophet::ChangeSet.3 \
	Prophet::Collection.3 \
	Prophet::Config.3 \
	Prophet::Conflict.3 \
	Prophet::ConflictingChange.3 \
	Prophet::ConflictingPropChange.3 \
	Prophet::ContentAddressedStore.3 \
	Prophet::DatabaseSetting.3 \
	Prophet::FilesystemReplica.3 \
	Prophet::ForeignReplica.3 \
	Prophet::Manual.3 \
	Prophet::Meta::Types.3 \
	Prophet::PropChange.3 \
	Prophet::Record.3 \
	Prophet::Replica.3 \
	Prophet::Replica::FS::Backend::File.3 \
	Prophet::Replica::FS::Backend::LWP.3 \
	Prophet::Replica::FS::Backend::SSH.3 \
	Prophet::Replica::file.3 \
	Prophet::Replica::http.3 \
	Prophet::Replica::prophet.3 \
	Prophet::Replica::prophet_cache.3 \
	Prophet::Replica::sqlite.3 \
	Prophet::ReplicaExporter.3 \
	Prophet::ReplicaFeedExporter.3 \
	Prophet::Resolver.3 \
	Prophet::Resolver::AlwaysSource.3 \
	Prophet::Resolver::AlwaysTarget.3 \
	Prophet::Resolver::Failed.3 \
	Prophet::Resolver::Fixup::MissingSourceOldValues.3 \
	Prophet::Resolver::FromResolutionDB.3 \
	Prophet::Resolver::IdenticalChanges.3 \
	Prophet::Resolver::Prompt.3 \
	Prophet::Server.3 \
	Prophet::Server::Controller.3 \
	Prophet::Server::Dispatcher.3 \
	Prophet::Server::View.3 \
	Prophet::Server::ViewHelpers.3 \
	Prophet::Server::ViewHelpers::Function.3 \
	Prophet::Server::ViewHelpers::HiddenParam.3 \
	Prophet::Server::ViewHelpers::ParamFromFunction.3 \
	Prophet::Server::ViewHelpers::Widget.3 \
	Prophet::Test.3 \
	Prophet::Test::Arena.3 \
	Prophet::Test::Editor.3 \
	Prophet::Test::Participant.3 \
	Prophet::UUIDGenerator.3 \
	Prophet::Util.3 \
	Prophet::Web::Field.3 \
	Prophet::Web::FunctionResult.3 \
	Prophet::Web::Menu.3 \
	Prophet::Web::Result.3

.include <bsd.port.mk>
