# New ports collection makefile for:	p5-Goo
# Date created:				14 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Goo
PORTVERSION=	0.09
CATEGORIES=	deskutils sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/N/NI/NIGE
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Stick Things together with The Goo

BUILD_DEPENDS=	${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm \
		${SITE_PERL}/Config/Auto.pm:${PORTSDIR}/devel/p5-Config-Auto \
		${SITE_PERL}/Config/Tiny.pm:${PORTSDIR}/devel/p5-Config-Tiny \
		${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite \
		${SITE_PERL}/Devel/Symdump.pm:${PORTSDIR}/devel/p5-Devel-Symdump \
		${SITE_PERL}/File/Grep.pm:${PORTSDIR}/devel/p5-File-Grep \
		${SITE_PERL}/File/NCopy.pm:${PORTSDIR}/devel/p5-File-NCopy \
		${SITE_PERL}/LWP/ConnCache.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/${PERL_ARCH}/Pod/Coverage.pm:${PORTSDIR}/devel/p5-Pod-Coverage \
		${SITE_PERL}/Perl/Tidy.pm:${PORTSDIR}/devel/perltidy \
		${SITE_PERL}/Term/ANSIColor.pm:${PORTSDIR}/devel/p5-Term-ANSIColor \
		${SITE_PERL}/Term/ProgressBar.pm:${PORTSDIR}/devel/p5-Term-ProgressBar \
		${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/Text/FormatTable.pm:${PORTSDIR}/textproc/p5-Text-FormatTable \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes \
		${SITE_PERL}/Test/Pod.pm:${PORTSDIR}/devel/p5-Test-Pod \
		${SITE_PERL}/Test/Pod/Coverage.pm:${PORTSDIR}/devel/p5-Test-Pod-Coverage
RUN_DEPENDS=	${BUILD_DEPENDS}

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

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires at least Perl 5.6.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
