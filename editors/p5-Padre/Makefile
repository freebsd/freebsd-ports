# New ports collection makefile for:	p5-Padre
# Date created:				March 8th 2009
# Whom:	      				Cezary Morga <cm@therek.net>
#
# $FreeBSD$
#

PORTNAME=	Padre
PORTVERSION=	0.45
CATEGORIES=	editors perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cm@therek.net
COMMENT=	Perl Application Development and Refactoring Environment

BUILD_DEPENDS=	${SITE_PERL}/App/Ack.pm:${PORTSDIR}/textproc/p5-ack \
		p5-Capture-Tiny>=0.06:${PORTSDIR}/devel/p5-Capture-Tiny \
		${SITE_PERL}/Class/Adapter.pm:${PORTSDIR}/devel/p5-Class-Adapter \
		${SITE_PERL}/Class/Unload.pm:${PORTSDIR}/devel/p5-Class-Unload \
		${SITE_PERL}/Devel/Dumpvar.pm:${PORTSDIR}/devel/p5-Devel-Dumpvar \
		${SITE_PERL}/File/Copy/Recursive.pm:${PORTSDIR}/devel/p5-File-Copy-Recursive \
		${SITE_PERL}/File/Find/Rule.pm:${PORTSDIR}/devel/p5-File-Find-Rule \
		${SITE_PERL}/File/HomeDir.pm:${PORTSDIR}/devel/p5-File-HomeDir \
		p5-File-Path>=2.07:${PORTSDIR}/devel/p5-File-Path \
		${SITE_PERL}/File/ShareDir.pm:${PORTSDIR}/devel/p5-File-ShareDir \
		${SITE_PERL}/File/ShareDir/PAR.pm:${PORTSDIR}/devel/p5-File-ShareDir-PAR \
		${SITE_PERL}/File/Which.pm:${PORTSDIR}/sysutils/p5-File-Which \
		${SITE_PERL}/IO/Scalar.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${SITE_PERL}/IO/String.pm:${PORTSDIR}/devel/p5-IO-String \
		p5-List-MoreUtils>=0.22:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Locale-Msgfmt>=0.14:${PORTSDIR}/devel/p5-Locale-Msgfmt \
		${SITE_PERL}/Module/Refresh.pm:${PORTSDIR}/devel/p5-Module-Refresh \
		${SITE_PERL}/Module/Starter.pm:${PORTSDIR}/devel/p5-Module-Starter \
		${SITE_PERL}/ORLite.pm:${PORTSDIR}/databases/p5-ORLite \
		${SITE_PERL}/ORLite/Migrate.pm:${PORTSDIR}/databases/p5-ORLite-Migrate \
		${SITE_PERL}/PAR.pm:${PORTSDIR}/devel/p5-PAR \
		${SITE_PERL}/PPI.pm:${PORTSDIR}/textproc/p5-PPI \
		${SITE_PERL}/Parse/ErrorString/Perl.pm:${PORTSDIR}/devel/p5-Parse-ErrorString-Perl \
		p5-Parse-ExuberantCTags>=1.00:${PORTSDIR}/devel/p5-Parse-ExuberantCTags \
		p5-Pod-Abstract>=0.16:${PORTSDIR}/textproc/p5-Pod-Abstract \
		${SITE_PERL}/Pod/POM.pm:${PORTSDIR}/textproc/p5-Pod-POM \
		${SITE_PERL}/Pod/Simple.pm:${PORTSDIR}/textproc/p5-Pod-Simple \
		${SITE_PERL}/Pod/Simple/XHTML.pm:${PORTSDIR}/textproc/p5-Pod-Simple \
		${SITE_PERL}/Probe/Perl.pm:${PORTSDIR}/sysutils/p5-Probe-Perl \
		${SITE_PERL}/Test/Exception.pm:${PORTSDIR}/devel/p5-Test-Exception \
		${SITE_PERL}/Test/Most.pm:${PORTSDIR}/devel/p5-Test-Most \
		${SITE_PERL}/Test/NoWarnings.pm:${PORTSDIR}/devel/p5-Test-NoWarnings \
		${SITE_PERL}/Test/Script.pm:${PORTSDIR}/devel/p5-Test-Script \
		${SITE_PERL}/Text/Diff.pm:${PORTSDIR}/textproc/p5-Text-Diff \
		${SITE_PERL}/Text/FindIndent.pm:${PORTSDIR}/textproc/p5-Text-FindIndent \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/Wx/Perl/ProcessStream.pm:${PORTSDIR}/x11-toolkits/p5-Wx-Perl-ProcessStream \
		${SITE_PERL}/YAML/Tiny.pm:${PORTSDIR}/textproc/p5-YAML-Tiny \
		p5-Class-XSAccessor>=1.02:${PORTSDIR}/devel/p5-Class-XSAccessor \
		p5-Class-XSAccessor-Array>=1.02:${PORTSDIR}/devel/p5-Class-XSAccessor-Array \
		${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/${PERL_ARCH}/HTML/Entities.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/${PERL_ARCH}/Params/Util.pm:${PORTSDIR}/devel/p5-Params-Util \
		p5-PPIx-EditorTools>=0.08:${PORTSDIR}/textproc/p5-PPIx-EditorTools \
		p5-ExtUtils-Manifest>=1.56:${PORTSDIR}/devel/p5-ExtUtils-Manifest \
		p5-Wx>=0.91:${PORTSDIR}/x11-toolkits/p5-Wx
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_WX=		2.8+
WX_COMPS=	wx contrib
WX_UNICODE=	yes
USE_DISPLAY=	yes
PERL_CONFIGURE=	yes
USE_PERL5=	5.8.5+
USE_GETTEXT=	yes
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.pre.mk>

.if exists(${PERL})
PERL_THREADS!=	${PERL} -V::usethreads
.if ${PERL_THREADS}!="'define';"
IGNORE=		needs a threaded Perl, build with WITH_THREADS=yes flag and try again
.endif
.else
IGNORE=		needs an existing installation of Perl built with WITH_THREADS=yes
.endif

.if ${PERL_LEVEL} >= 501000
BUILD_DEPENDS+=	p5-Encode>=2.26:${PORTSDIR}/converters/p5-Encode \
		p5-Thread-Queue>=2.11:${PORTSDIR}/devel/p5-Thread-Queue \
		p5-threads>=1.71:${PORTSDIR}/devel/p5-threads \
		p5-threads-shared>=1.26:${PORTSDIR}/devel/p5-threads-shared
.endif

MAN3=		Padre.3 \
		Padre::Action.3 \
		Padre::Autosave.3 \
		Padre::Config.3 \
		Padre::Config::Host.3 \
		Padre::Config::Human.3 \
		Padre::Constant.3 \
		Padre::Current.3 \
		Padre::DB.3 \
		Padre::DB::Bookmark.3 \
		Padre::DB::History.3 \
		Padre::DB::HostConfig.3 \
		Padre::DB::LastPositionInFile.3 \
		Padre::DB::Plugin.3 \
		Padre::DB::RecentlyUsed.3 \
		Padre::DB::Session.3 \
		Padre::DB::SessionFile.3 \
		Padre::DB::Snippets.3 \
		Padre::DB::SyntaxHighlight.3 \
		Padre::DocBrowser.3 \
		Padre::DocBrowser::document.3 \
		Padre::Document.3 \
		Padre::Document::Perl::Beginner.3 \
		Padre::HelpProvider.3 \
		Padre::HelpProvider::Perl.3 \
		Padre::Locale.3 \
		Padre::Log.3 \
		Padre::Manual.3 \
		Padre::Manual::Hacking.3 \
		Padre::MimeTypes.3 \
		Padre::Perl.3 \
		Padre::Plugin.3 \
		Padre::Plugin::Devel.3 \
		Padre::Plugin::My.3 \
		Padre::Plugin::PopularityContest.3 \
		Padre::PluginBuilder.3 \
		Padre::PluginManager.3 \
		Padre::Pod2HTML.3 \
		Padre::QuickFixProvider.3 \
		Padre::QuickFixProvider::Perl.3 \
		Padre::QuickFixProvider::Perl::StrictWarnings.3 \
		Padre::QuickFixProvider::Perl::IncludeModule.3 \
		Padre::Search.3 \
		Padre::Service.3 \
		Padre::Task.3 \
		Padre::Task::HTTPClient.3 \
		Padre::Task::LWP.3 \
		Padre::Task::OpenResource::SearchTask.3 \
		Padre::Task::Outline.3 \
		Padre::Task::Outline::Perl.3 \
		Padre::Task::PPI.3 \
		Padre::Task::PPI::FindUnmatchedBrace.3 \
		Padre::Task::PPI::FindVariableDeclaration.3 \
		Padre::Task::PPI::IntroduceTemporaryVariable.3 \
		Padre::Task::PPI::LexicalReplaceVariable.3 \
		Padre::Task::SyntaxChecker.3 \
		Padre::Task::SyntaxChecker::Perl.3 \
		Padre::TaskManager.3 \
		Padre::Transform.3 \
		Padre::Transform::Perl::UpdateCopyright.3 \
		Padre::Util.3 \
		Padre::Wx.3 \
		Padre::Wx::Ack.3 \
		Padre::Wx::App.3 \
		Padre::Wx::CPAN.3 \
		Padre::Wx::Dialog.3 \
		Padre::Wx::Dialog::Find.3 \
		Padre::Wx::Dialog::OpenResource.3 \
		Padre::Wx::Dialog::PluginManager.3 \
		Padre::Wx::Dialog::Preferences.3 \
		Padre::Wx::Dialog::QuickMenuAccess.3 \
		Padre::Wx::Dialog::Replace.3 \
		Padre::Wx::Dialog::SessionManager.3 \
		Padre::Wx::Dialog::SessionSave.3 \
		Padre::Wx::Dialog::HelpSearch.3 \
		Padre::Wx::Directory::OpenInFileBrowserAction.3 \
		Padre::Wx::DocBrowser.3 \
		Padre::Wx::HtmlWindow.3 \
		Padre::Wx::Main.3 \
		Padre::Wx::PodFrame.3 \
		Padre::Wx::Role::MainChild.3 \
		Padre::Wx::StatusBar.3 \
		Wx::Perl::Dialog.3 \
		Wx::Perl::Dialog::Simple.3 \
		Wx::Perl::Dialog::SingleChoice.3

post-patch:
	${FIND} ${WRKSRC} -type f -name '*.orig' |${XARGS} ${RM} -f

.include <bsd.port.post.mk>
