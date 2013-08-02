# New ports collection makefile for:	p5-Goo
# Date created:				14 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Goo
PORTVERSION=	0.09
PORTREVISION=	1
CATEGORIES=	deskutils sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Stick Things together with The Goo

BUILD_DEPENDS=	p5-Config-Auto>=0:${PORTSDIR}/devel/p5-Config-Auto \
		p5-Config-Tiny>=0:${PORTSDIR}/devel/p5-Config-Tiny \
		p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-Devel-Symdump>=0:${PORTSDIR}/devel/p5-Devel-Symdump \
		p5-File-Grep>=0:${PORTSDIR}/devel/p5-File-Grep \
		p5-File-NCopy>=0:${PORTSDIR}/devel/p5-File-NCopy \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		perltidy>=0:${PORTSDIR}/devel/perltidy \
		p5-Term-ProgressBar>=0:${PORTSDIR}/devel/p5-Term-ProgressBar \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-Text-FormatTable>=0:${PORTSDIR}/textproc/p5-Text-FormatTable
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN1=	goo.1 goo.pl.1
MAN3=	Goo.3 \
	Goo::Action.3 \
	Goo::BackLinkFinder.3 \
	Goo::BackLinkManager.3 \
	Goo::CareOMeter.3 \
	Goo::CommandLineManager.3 \
	Goo::CompressWhitespace.3 \
	Goo::ConfigFile.3 \
	Goo::Database.3 \
	Goo::DatabaseInfo.3 \
	Goo::DatabaseObject.3 \
	Goo::DatabaseProfileOption.3 \
	Goo::DatabaseThing.3 \
	Goo::DatabaseThing::Deleter.3 \
	Goo::DatabaseThing::Editor.3 \
	Goo::DatabaseThing::Maker.3 \
	Goo::DatabaseThing::Profiler.3 \
	Goo::Date.3 \
	Goo::Differ.3 \
	Goo::Editor.3 \
	Goo::Emailer.3 \
	Goo::Environment.3 \
	Goo::Exiter.3 \
	Goo::FileThing.3 \
	Goo::FileThing::Cloner.3 \
	Goo::FileThing::Deleter.3 \
	Goo::FileThing::Finder.3 \
	Goo::FileUtilities.3 \
	Goo::Grepper.3 \
	Goo::Header.3 \
	Goo::JumpManager.3 \
	Goo::JumpProfileOption.3 \
	Goo::List.3 \
	Goo::Lister.3 \
	Goo::LiteDatabase.3 \
	Goo::Loader.3 \
	Goo::Logger.3 \
	Goo::Object.3 \
	Goo::OptionIndexTable.3 \
	Goo::Profile.3 \
	Goo::ProfileOption.3 \
	Goo::Profiler.3 \
	Goo::Prompter.3 \
	Goo::Shell.3 \
	Goo::ShellCommander.3 \
	Goo::SimpleEmailer.3 \
	Goo::TabAwareEditor.3 \
	Goo::TabConverter.3 \
	Goo::TableInfo.3 \
	Goo::TeamManager.3 \
	Goo::Template.3 \
	Goo::TemplateProfileOption.3 \
	Goo::Test.3 \
	Goo::TextEditor.3 \
	Goo::TextTable.3 \
	Goo::TextUtilities.3 \
	Goo::ThereDocManager.3 \
	Goo::Thing.3 \
	Goo::Thing::bug::Fixer.3 \
	Goo::Thing::bug::Lister.3 \
	Goo::Thing::bug::Maker.3 \
	Goo::Thing::conf::ConfigProfiler.3 \
	Goo::Thing::conf::studly-method-remover.3 \
	Goo::Thing::gml::Profiler.3 \
	Goo::Thing::gml::Reader.3 \
	Goo::Thing::gml::Writer.3 \
	Goo::Thing::goo::Maker.3 \
	Goo::Thing::js::JSFunctionProfileOption.3 \
	Goo::Thing::js::JavascriptProfiler.3 \
	Goo::Thing::log::Profiler.3 \
	Goo::Thing::pl::ScriptMaker.3 \
	Goo::Thing::pm::Adder.3 \
	Goo::Thing::pm::Compiler.3 \
	Goo::Thing::pm::Editor.3 \
	Goo::Thing::pm::ExecDocManager.3 \
	Goo::Thing::pm::Maker.3 \
	Goo::Thing::pm::Method.3 \
	Goo::Thing::pm::MethodMaker.3 \
	Goo::Thing::pm::MethodMatcher.3 \
	Goo::Thing::pm::MethodProfileOption.3 \
	Goo::Thing::pm::PackageProfileOption.3 \
	Goo::Thing::pm::Perl5.3 \
	Goo::Thing::pm::Perl5Adder.3 \
	Goo::Thing::pm::Perl5Compiler.3 \
	Goo::Thing::pm::Perl5Editor.3 \
	Goo::Thing::pm::Perl5ModuleInspector.3 \
	Goo::Thing::pm::Perl5ModuleMaker.3 \
	Goo::Thing::pm::Perl5Profiler.3 \
	Goo::Thing::pm::Perl5Runner.3 \
	Goo::Thing::pm::Perl5ThereDocManager.3 \
	Goo::Thing::pm::Perl6Adder.3 \
	Goo::Thing::pm::Perl6Compiler.3 \
	Goo::Thing::pm::Perl6Editor.3 \
	Goo::Thing::pm::Perl6ModuleInspector.3 \
	Goo::Thing::pm::Perl6ModuleMaker.3 \
	Goo::Thing::pm::Perl6Profiler.3 \
	Goo::Thing::pm::Perl6Runner.3 \
	Goo::Thing::pm::PerlCoder.3 \
	Goo::Thing::pm::PerlTidyManager.3 \
	Goo::Thing::pm::Profiler.3 \
	Goo::Thing::pm::ProgramCloner.3 \
	Goo::Thing::pm::ProgramDeleter.3 \
	Goo::Thing::pm::Runner.3 \
	Goo::Thing::pm::ScopeMatcher.3 \
	Goo::Thing::pm::ThereDocManager.3 \
	Goo::Thing::pm::TypeChecker.3 \
	Goo::Thing::pm::TypeLessTranslator.3 \
	Goo::Thing::task::Finisher.3 \
	Goo::Thing::task::Maker.3 \
	Goo::Thing::task::TaskEditor.3 \
	Goo::Thing::task::TaskLister.3 \
	Goo::Thing::task::edittask.3 \
	Goo::Thing::task::savetask.3 \
	Goo::Thing::task::tasklist.3 \
	Goo::Thing::tpm::TestLoader.3 \
	Goo::Thing::tpm::TestMaker.3 \
	Goo::Thing::tpm::TestRunner.3 \
	Goo::Thing::tpm::Tester.3 \
	Goo::ThingFinder.3 \
	Goo::ThingProfileOption.3 \
	Goo::TrailGoBack.3 \
	Goo::TrailGoBackOne.3 \
	Goo::TrailGoForward.3 \
	Goo::TrailManager.3 \
	Goo::TrailProfiler.3 \
	Goo::TypeManager.3 \
	Goo::WebDBLite.3 \
	Goo::Zone.3

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
