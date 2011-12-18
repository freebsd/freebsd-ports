# New ports collection makefile for:	p5-Prophet
# Date created:		2011-04-05
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Prophet
PORTVERSION=	0.750
PORTREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SPANG
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

PERL_CONFIGURE=	yes

MAN3=	Prophet::Web::Result.3 \
	Prophet::Replica::prophet.3 \
	Prophet::CLI::Command::Merge.3 \
	Prophet::CLI::TextEditorCommand.3 \
	Prophet::UUIDGenerator.3 \
	Prophet::CLI::Command::Pull.3 \
	Prophet.3 \
	Prophet::ChangeSet.3 \
	Prophet::Test::Editor.3 \
	Prophet::Collection.3 \
	Prophet::CLI::RecordCommand.3 \
	Prophet::CLI::Command::Show.3 \
	Prophet::CLI.3 \
	Prophet::Server::ViewHelpers::Function.3 \
	Prophet::Server.3 \
	Prophet::Resolver::IdenticalChanges.3 \
	Prophet::Record.3 \
	Prophet::Manual.3 \
	Prophet::Util.3 \
	Prophet::Server::ViewHelpers::ParamFromFunction.3 \
	Prophet::Config.3 \
	Prophet::Web::Menu.3 \
	Prophet::ConflictingPropChange.3 \
	Prophet::CLI::Command::Search.3 \
	Prophet::App.3 \
	Prophet::Server::Controller.3 \
	Prophet::Change.3 \
	Prophet::ForeignReplica.3 \
	Prophet::ConflictingChange.3 \
	Prophet::CLI::Command::Clone.3 \
	Prophet::Replica.3 \
	Prophet::CLI::Command.3 \
	Prophet::FilesystemReplica.3 \
	Prophet::Server::ViewHelpers::Widget.3 \
	Prophet::PropChange.3 \
	Prophet::ReplicaExporter.3 \
	Prophet::Conflict.3 \
	Prophet::CLI::Command::Log.3 \
	Prophet::Test.3 \
	Prophet::Web::FunctionResult.3 \
	Prophet::CLIContext.3 \
	Prophet::Replica::sqlite.3 \
	Prophet::Meta::Types.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
BUILD_DEPENDS+=	p5-Digest-SHA>=0:${PORTSDIR}/security/p5-Digest-SHA
RUN_DEPENDS+=	p5-Digest-SHA>=0:${PORTSDIR}/security/p5-Digest-SHA
.endif

.include <bsd.port.post.mk>
