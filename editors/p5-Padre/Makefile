# New ports collection makefile for:	p5-Padre
# Date created:				March 8th 2009
# Whom:	      				Cezary Morga <cm@therek.net>
#
# $FreeBSD$
#

PORTNAME=	Padre
PORTVERSION=	0.62
CATEGORIES=	editors perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cm@therek.net
COMMENT=	Perl Application Development and Refactoring Environment

BUILD_DEPENDS=	p5-ack>=1.86:${PORTSDIR}/textproc/p5-ack \
		p5-Class-Adapter>=1.05:${PORTSDIR}/devel/p5-Class-Adapter \
		p5-Class-Unload>=0.03:${PORTSDIR}/devel/p5-Class-Unload \
		p5-Devel-Dumpvar>=0.04:${PORTSDIR}/devel/p5-Devel-Dumpvar \
		p5-Devel-Refactor>=0.05:${PORTSDIR}/devel/p5-Devel-Refactor \
		p5-File-Copy-Recursive>=0.37:${PORTSDIR}/devel/p5-File-Copy-Recursive \
		p5-File-Find-Rule>=0.30:${PORTSDIR}/devel/p5-File-Find-Rule \
		p5-File-HomeDir>=0.84:${PORTSDIR}/devel/p5-File-HomeDir \
		p5-File-Next>=1.06:${PORTSDIR}/sysutils/p5-File-Next \
		p5-File-Remove>=1.42:${PORTSDIR}/devel/p5-File-Remove \
		p5-File-ShareDir>=1.00:${PORTSDIR}/devel/p5-File-ShareDir \
		p5-File-Which>=1.08:${PORTSDIR}/sysutils/p5-File-Which \
		p5-Format-Human-Bytes>=0.04:${PORTSDIR}/converters/p5-Format-Human-Bytes \
		p5-IO-stringy>=2.110:${PORTSDIR}/devel/p5-IO-stringy \
		p5-IO-String>=1.08:${PORTSDIR}/devel/p5-IO-String \
		p5-List-MoreUtils>=0.22:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Locale-Msgfmt>=0.14:${PORTSDIR}/devel/p5-Locale-Msgfmt \
		p5-Module-Refresh>=0.13:${PORTSDIR}/devel/p5-Module-Refresh \
		p5-Module-Starter>=1.50:${PORTSDIR}/devel/p5-Module-Starter \
		p5-ORLite>=1.41:${PORTSDIR}/databases/p5-ORLite \
		p5-PPI>=1.205:${PORTSDIR}/textproc/p5-PPI \
		p5-Parse-ErrorString-Perl>=0.11:${PORTSDIR}/devel/p5-Parse-ErrorString-Perl \
		p5-Parse-ExuberantCTags>=1.00:${PORTSDIR}/devel/p5-Parse-ExuberantCTags \
		p5-Pod-Abstract>=0.16:${PORTSDIR}/textproc/p5-Pod-Abstract \
		p5-Pod-POM>=0.17:${PORTSDIR}/textproc/p5-Pod-POM \
		${SITE_PERL}/Probe/Perl.pm:${PORTSDIR}/sysutils/p5-Probe-Perl \
		${SITE_PERL}/Test/Exception.pm:${PORTSDIR}/devel/p5-Test-Exception \
		${SITE_PERL}/Test/NoWarnings.pm:${PORTSDIR}/devel/p5-Test-NoWarnings \
		${SITE_PERL}/Test/Script.pm:${PORTSDIR}/devel/p5-Test-Script \
		p5-Text-Diff>=0.35:${PORTSDIR}/textproc/p5-Text-Diff \
		p5-Text-FindIndent>=0.06:${PORTSDIR}/textproc/p5-Text-FindIndent \
		p5-URI>0:${PORTSDIR}/net/p5-URI \
		p5-YAML-Tiny>=1.32:${PORTSDIR}/textproc/p5-YAML-Tiny \
		p5-Class-XSAccessor>=1.05:${PORTSDIR}/devel/p5-Class-XSAccessor \
		${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-DBI>=1.58:${PORTSDIR}/databases/p5-DBI \
		p5-HTML-Parser>=3.65:${PORTSDIR}/www/p5-HTML-Parser \
		p5-Params-Util>=0.33:${PORTSDIR}/devel/p5-Params-Util \
		p5-pip>=0.13:${PORTSDIR}/devel/p5-pip \
		p5-PPIx-EditorTools>=0.09:${PORTSDIR}/textproc/p5-PPIx-EditorTools \
		p5-Wx>=0.97:${PORTSDIR}/x11-toolkits/p5-Wx \
		p5-Wx-Perl-ProcessStream>=0.25:${PORTSDIR}/x11-toolkits/p5-Wx-Perl-ProcessStream \
		p5-Debug-Client>=0.11:${PORTSDIR}/devel/p5-Debug-Client \
		p5-Template-Tiny>=0.11:${PORTSDIR}/textproc/p5-Template-Tiny \
		p5-Module-Build>=0.3603:${PORTSDIR}/devel/p5-Module-Build \
		p5-Pod-Perldoc>=3.15:${PORTSDIR}/textproc/p5-Pod-Perldoc \
		p5-App-cpanminus>=0.9923:${PORTSDIR}/devel/p5-App-cpanminus \
		p5-Readonly>=1.03:${PORTSDIR}/devel/p5-Readonly \
		p5-Test-MockObject>=1.09:${PORTSDIR}/devel/p5-Test-MockObject \
		p5-PPIx-Regexp>=0.005:${PORTSDIR}/textproc/p5-PPIx-Regexp \
		p5-POD2-Base>=0.043:${PORTSDIR}/textproc/p5-POD2-Base \
		p5-File-Path>=2.07:${PORTSDIR}/devel/p5-File-Path \
		p5-File-Temp>0:${PORTSDIR}/devel/p5-File-Temp \
		p5-File-pushd>=1.00:${PORTSDIR}/devel/p5-File-pushd \
		p5-Storable>=2.15:${PORTSDIR}/devel/p5-Storable \
		p5-version>=0.80:${PORTSDIR}/devel/p5-version

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

.if ${PERL_LEVEL} < 501000
BUILD_DEPENDS+=	p5-Pod-Simple>=3.07:${PORTSDIR}/textproc/p5-Pod-Simple
.endif

.if ${PERL_LEVEL} >= 501000 && ${PERL_LEVEL} < 501001
BUILD_DEPENDS+=	p5-Encode>=2.26:${PORTSDIR}/converters/p5-Encode \
		p5-Thread-Queue>=2.11:${PORTSDIR}/devel/p5-Thread-Queue \
		p5-threads>=1.71:${PORTSDIR}/devel/p5-threads \
		p5-threads-shared>=1.26:${PORTSDIR}/devel/p5-threads-shared
RUN_DEPENDS+=	p5-Encode>=2.26:${PORTSDIR}/converters/p5-Encode \
		p5-Thread-Queue>=2.11:${PORTSDIR}/devel/p5-Thread-Queue \
		p5-threads>=1.71:${PORTSDIR}/devel/p5-threads \
		p5-threads-shared>=1.26:${PORTSDIR}/devel/p5-threads-shared
.endif

.if ${PERL_LEVEL} < 501001
BUILD_DEPENDS+=	p5-ExtUtils-Manifest>=1.56:${PORTSDIR}/devel/p5-ExtUtils-Manifest
RUN_DEPENDS+=	p5-ExtUtils-Manifest>=1.56:${PORTSDIR}/devel/p5-ExtUtils-Manifest
.endif

MAN3=		Padre.3 \
		Padre::Action.3 \
		Padre::Action::Debug.3 \
		Padre::Action::Internal.3 \
		Padre::Action::Perl.3 \
		Padre::Action::Queue.3 \
		Padre::Action::Refactor.3 \
		Padre::Action::Run.3 \
		Padre::Autosave.3 \
		Padre::Config.3 \
		Padre::Config::Host.3 \
		Padre::Config::Human.3 \
		Padre::Config::Upgrade.3 \
		Padre::Constant.3 \
		Padre::Current.3 \
		Padre::DB.3 \
		Padre::DB::Bookmark.3 \
		Padre::DB::History.3 \
		Padre::DB::HostConfig.3 \
		Padre::DB::LastPositionInFile.3 \
		Padre::DB::Migrate.3 \
		Padre::DB::Plugin.3 \
		Padre::DB::RecentlyUsed.3 \
		Padre::DB::Session.3 \
		Padre::DB::SessionFile.3 \
		Padre::DB::Snippets.3 \
		Padre::DB::SyntaxHighlight.3 \
		Padre::Desktop.3 \
		Padre::DocBrowser.3 \
		Padre::DocBrowser::document.3 \
		Padre::Document.3 \
		Padre::Document::Perl.3 \
		Padre::Document::Perl::Beginner.3 \
		Padre::Document::Perl::Help.3 \
		Padre::Document::Perl::QuickFix.3 \
		Padre::Document::Perl::QuickFix::IncludeModule.3 \
		Padre::Document::Perl::QuickFix::StrictWarnings.3 \
		Padre::File.3 \
		Padre::Help.3 \
		Padre::Locale.3 \
		Padre::Locker.3 \
		Padre::Logger.3 \
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
		Padre::Project::Temp.3 \
		Padre::QuickFix.3 \
		Padre::Search.3 \
		Padre::Service.3 \
		Padre::SlaveDriver.3 \
		Padre::Startup.3 \
		Padre::Task.3 \
		Padre::Task::HTTPClient.3 \
		Padre::Task::HTTPClient::LWP.3 \
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
		Padre::Util::FileBrowser.3 \
		Padre::Util::SVN.3 \
		Padre::Util::Template.3 \
		Padre::Util::Win32.3 \
		Padre::Wx.3 \
		Padre::Wx::Ack.3 \
		Padre::Wx::App.3 \
		Padre::Wx::CPAN.3 \
		Padre::Wx::Debugger.3 \
		Padre::Wx::Dialog.3 \
		Padre::Wx::Dialog::Advanced.3 \
		Padre::Wx::Dialog::DocStats.3 \
		Padre::Wx::Dialog::FilterTool.3 \
		Padre::Wx::Dialog::Find.3 \
		Padre::Wx::Dialog::Form.3 \
		Padre::Wx::Dialog::Goto.3 \
		Padre::Wx::Dialog::HelpSearch.3 \
		Padre::Wx::Dialog::KeyBindings.3 \
		Padre::Wx::Dialog::OpenResource.3 \
		Padre::Wx::Dialog::OpenURL.3 \
		Padre::Wx::Dialog::PluginManager.3 \
		Padre::Wx::Dialog::Preferences.3 \
		Padre::Wx::Dialog::Preferences::File.3 \
		Padre::Wx::Dialog::Preferences::PerlAutoComplete.3 \
		Padre::Wx::Dialog::QuickMenuAccess.3 \
		Padre::Wx::Dialog::RegexEditor.3 \
		Padre::Wx::Dialog::Replace.3 \
		Padre::Wx::Dialog::SessionManager.3 \
		Padre::Wx::Dialog::SessionSave.3 \
		Padre::Wx::Dialog::Shortcut.3 \
		Padre::Wx::Dialog::Warning.3 \
		Padre::Wx::Dialog::WindowList.3 \
		Padre::Wx::Display.3 \
		Padre::Wx::DocBrowser.3 \
		Padre::Wx::Editor.3 \
		Padre::Wx::FindResult.3 \
		Padre::Wx::HtmlWindow.3 \
		Padre::Wx::Main.3 \
		Padre::Wx::PodFrame.3 \
		Padre::Wx::Progress.3 \
		Padre::Wx::Role::MainChild.3 \
		Padre::Wx::Role::View.3 \
		Padre::Wx::StatusBar.3 \
		Wx::Perl::Dialog.3 \
		Wx::Perl::Dialog::Simple.3 \
		Wx::Perl::Dialog::SingleChoice.3

post-patch:
	${FIND} ${WRKSRC} -type f -name '*.orig' |${XARGS} ${RM} -f

.include <bsd.port.post.mk>
