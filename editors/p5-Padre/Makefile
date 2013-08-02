# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	Padre
PORTVERSION=	0.96
CATEGORIES=	editors perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} ${MASTER_SITE_PERL_CPAN:S/$/:wxsc/}
MASTER_SITE_SUBDIR=	${PORTNAME}/:DEFAULT Wx/:wxsc
PKGNAMEPREFIX=	p5-
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${WXSC_DISTFILE}:wxsc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl Application Development and Refactoring Environment

LICENSE=	ART10 GPLv2
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-JSON-XS>=2.29:${PORTSDIR}/converters/p5-JSON-XS \
		p5-DBD-SQLite>=1.35:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-DBI>=1.58:${PORTSDIR}/databases/p5-DBI \
		databases/p5-ORLite-Migrate>0:${PORTSDIR}/databases/p5-ORLite-Migrate \
		p5-Algorithm-Diff>=1.19:${PORTSDIR}/devel/p5-Algorithm-Diff \
		p5-App-cpanminus>=0.9923:${PORTSDIR}/devel/p5-App-cpanminus \
		p5-Capture-Tiny>0:${PORTSDIR}/devel/p5-Capture-Tiny \
		p5-Class-Adapter>=1.05:${PORTSDIR}/devel/p5-Class-Adapter \
		p5-Class-Inspector>=1.22:${PORTSDIR}/devel/p5-Class-Inspector \
		p5-Class-XSAccessor>=1.13:${PORTSDIR}/devel/p5-Class-XSAccessor \
		p5-Data-Dumper>=2.101:${PORTSDIR}/devel/p5-Data-Dumper \
		p5-Debug-Client>=0.20:${PORTSDIR}/devel/p5-Debug-Client \
		p5-Devel-Dumpvar>=0.04:${PORTSDIR}/devel/p5-Devel-Dumpvar \
		p5-Devel-Refactor>=0.05:${PORTSDIR}/devel/p5-Devel-Refactor \
		p5-File-Copy-Recursive>=0.37:${PORTSDIR}/devel/p5-File-Copy-Recursive \
		p5-File-Find-Rule>=0.30:${PORTSDIR}/devel/p5-File-Find-Rule \
		p5-File-HomeDir>=0.84:${PORTSDIR}/devel/p5-File-HomeDir \
		p5-File-Path>=2.08:${PORTSDIR}/devel/p5-File-Path \
		p5-File-ShareDir>=1.00:${PORTSDIR}/devel/p5-File-ShareDir \
		p5-IO-stringy>=2.110:${PORTSDIR}/devel/p5-IO-stringy \
		p5-IPC-Run>=0.83:${PORTSDIR}/devel/p5-IPC-Run \
		p5-List-MoreUtils>=0.22:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Locale-Msgfmt>=0.14:${PORTSDIR}/devel/p5-Locale-Msgfmt \
		p5-Module-Manifest>=0.07:${PORTSDIR}/devel/p5-Module-Manifest \
		p5-PPI>=1.213:${PORTSDIR}/textproc/p5-PPI \
		p5-Parse-ErrorString-Perl>=0.14:${PORTSDIR}/devel/p5-Parse-ErrorString-Perl \
		p5-Parse-ExuberantCTags>=1.00:${PORTSDIR}/devel/p5-Parse-ExuberantCTags \
		p5-Pod-Abstract>=0.16:${PORTSDIR}/textproc/p5-Pod-Abstract \
		p5-Sort-Versions>=1.5:${PORTSDIR}/devel/p5-Sort-Versions \
		p5-Test-Exception>=0.27:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-MockObject>=1.09:${PORTSDIR}/devel/p5-Test-MockObject \
		p5-Test-NoWarnings>=0.084:${PORTSDIR}/devel/p5-Test-NoWarnings \
		p5-Test-Script>=1.07:${PORTSDIR}/devel/p5-Test-Script \
		p5-version>=0.80:${PORTSDIR}/devel/p5-version \
		p5-URI>0:${PORTSDIR}/net/p5-URI \
		p5-Pod-POM>=0.17:${PORTSDIR}/textproc/p5-Pod-POM \
		p5-POD2-Base>=0.043:${PORTSDIR}/textproc/p5-POD2-Base \
		p5-PPIx-EditorTools>=0.13:${PORTSDIR}/textproc/p5-PPIx-EditorTools \
		p5-PPIx-Regexp>=0.011:${PORTSDIR}/textproc/p5-PPIx-Regexp \
		p5-Template-Tiny>=0.11:${PORTSDIR}/textproc/p5-Template-Tiny \
		p5-Text-Diff>=1.41:${PORTSDIR}/textproc/p5-Text-Diff \
		p5-Text-FindIndent>=0.10:${PORTSDIR}/textproc/p5-Text-FindIndent \
		p5-Text-Patch>=1.8:${PORTSDIR}/textproc/p5-Text-Patch \
		p5-YAML-Tiny>=1.32:${PORTSDIR}/textproc/p5-YAML-Tiny \
		p5-HTML-Parser>=3.58:${PORTSDIR}/www/p5-HTML-Parser \
		p5-libwww>=5.815:${PORTSDIR}/www/p5-libwww \
		p5-Wx>=0.97:${PORTSDIR}/x11-toolkits/p5-Wx \
		p5-Wx-Perl-ProcessStream>=0.25:${PORTSDIR}/x11-toolkits/p5-Wx-Perl-ProcessStream
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_WX=		2.8+
WX_COMPS=	wx contrib
WX_UNICODE=	yes
USE_DISPLAY=	yes
USES=		perl5 gettext
USE_PERL5=	configure
MAKE_JOBS_UNSAFE=	yes

PLIST_SUB=	WX_VERSION="${WX_VERSION}"

MAN3=		Padre.3 \
		Padre::Autosave.3 \
		Padre::Browser.3 \
		Padre::Browser::Document.3 \
		Padre::Cache.3 \
		Padre::Comment.3 \
		Padre::Config.3 \
		Padre::Config::Apply.3 \
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
		Padre::Delta.3 \
		Padre::Desktop.3 \
		Padre::Document.3 \
		Padre::Document::Perl.3 \
		Padre::Document::Perl::Beginner.3 \
		Padre::Document::Perl::Help.3 \
		Padre::Document::Perl::QuickFix.3 \
		Padre::Document::Perl::QuickFix::IncludeModule.3 \
		Padre::Document::Perl::QuickFix::StrictWarnings.3 \
		Padre::Document::Perl::Starter.3 \
		Padre::Feature.3 \
		Padre::File.3 \
		Padre::Help.3 \
		Padre::Locale.3 \
		Padre::Locale::T.3 \
		Padre::Locker.3 \
		Padre::Logger.3 \
		Padre::MIME.3 \
		Padre::Manual.3 \
		Padre::Manual::Hacking.3 \
		Padre::PPI::EndifyPod.3 \
		Padre::PPI::Transform.3 \
		Padre::PPI::UpdateCopyright.3 \
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
		Padre::Role::Task.3 \
		Padre::Search.3 \
		Padre::Startup.3 \
		Padre::Sync.3 \
		Padre::Task.3 \
		Padre::Task::Eval.3 \
		Padre::Task::File.3 \
		Padre::Task::FindUnmatchedBrace.3 \
		Padre::Task::FindVariableDeclaration.3 \
		Padre::Task::IntroduceTemporaryVariable.3 \
		Padre::Task::LWP.3 \
		Padre::Task::LexicalReplaceVariable.3 \
		Padre::Task::OpenResource.3 \
		Padre::Task::PPI.3 \
		Padre::TaskManager.3 \
		Padre::Transform.3 \
		Padre::Util.3 \
		Padre::Util::FileBrowser.3 \
		Padre::Util::SVN.3 \
		Padre::Util::Template.3 \
		Padre::Util::Win32.3 \
		Padre::Wx.3 \
		Padre::Wx::Action.3 \
		Padre::Wx::ActionQueue.3 \
		Padre::Wx::App.3 \
		Padre::Wx::Browser.3 \
		Padre::Wx::ComboBox::History.3 \
		Padre::Wx::Dialog::Advanced.3 \
		Padre::Wx::Dialog::FilterTool.3 \
		Padre::Wx::Dialog::Form.3 \
		Padre::Wx::Dialog::Goto.3 \
		Padre::Wx::Dialog::HelpSearch.3 \
		Padre::Wx::Dialog::OpenResource.3 \
		Padre::Wx::Dialog::OpenURL.3 \
		Padre::Wx::Dialog::Patch.3 \
		Padre::Wx::Dialog::PerlFilter.3 \
		Padre::Wx::Dialog::PluginManager.3 \
		Padre::Wx::Dialog::Positions.3 \
		Padre::Wx::Dialog::QuickMenuAccess.3 \
		Padre::Wx::Dialog::RegexEditor.3 \
		Padre::Wx::Dialog::SessionManager.3 \
		Padre::Wx::Dialog::SessionSave.3 \
		Padre::Wx::Dialog::Shortcut.3 \
		Padre::Wx::Dialog::Warning.3 \
		Padre::Wx::Dialog::WindowList.3 \
		Padre::Wx::Display.3 \
		Padre::Wx::Editor.3 \
		Padre::Wx::Frame::POD.3 \
		Padre::Wx::HtmlWindow.3 \
		Padre::Wx::Main.3 \
		Padre::Wx::Notebook.3 \
		Padre::Wx::Panel::Debugger.3 \
		Padre::Wx::Progress.3 \
		Padre::Wx::Role::Conduit.3 \
		Padre::Wx::Role::Config.3 \
		Padre::Wx::Role::Context.3 \
		Padre::Wx::Role::Dialog.3 \
		Padre::Wx::Role::Idle.3 \
		Padre::Wx::Role::Main.3 \
		Padre::Wx::Role::Timer.3 \
		Padre::Wx::Role::View.3 \
		Padre::Wx::ScrollLock.3 \
		Padre::Wx::StatusBar.3 \
		Padre::Wx::TreeCtrl.3 \
		Wx::Scintilla.3 \
		Wx::Scintilla::Constant.3 \
		Wx::Scintilla::Manual.3

DESKTOP_ENTRIES="Padre" \
		"The Perl IDE" \
		"${SITE_PERL}/auto/share/dist/Padre/icons/padre/64x64/logo.png" \
		"padre" \
		"Development;Perl;IDE;" \
		""

WXSC_NAME=	Wx-Scintilla
WXSC_VERSION=	0.39
WXSC_DISTNAME=	${WXSC_NAME}-${WXSC_VERSION}
WXSC_DISTFILE=	${WXSC_DISTNAME}.tar.gz

.include <bsd.port.pre.mk>

.if exists(${PERL})
PERL_THREADS!=	${PERL} -V::usethreads
.if ${PERL_THREADS}!="'define';"
IGNORE=		needs a threaded Perl, build with WITH_THREADS=yes flag and try again
.endif
.else
IGNORE=		needs an existing installation of Perl built with WITH_THREADS=yes
.endif

WX_VERSION=	$$(${WX_CONFIG} --version)

post-extract:
	@cd ${WRKDIR} && ${GZCAT} ${DISTDIR}/${WXSC_DISTFILE} | ${TAR} -xf -

post-patch:
	@${REINPLACE_CMD} -e \
		'/my /s|wx-config|${WX_CONFIG}|' \
		${WRKDIR}/${WXSC_DISTNAME}/inc/Module/Build/Scintilla.pm
	@${REINPLACE_CMD} -e \
		's|-lgtk-x11-2.0.*-lpangoft2-1.0|-lm| ; \
		 /-lgobject-2.0/d ; \
		 /-lglib-2.0/d ; \
		 s|\\$$ORIGIN|${SITE_PERL}/mach/auto/Wx/Scintilla|' \
		${WRKDIR}/${WXSC_DISTNAME}/inc/Module/Build/Scintilla/GTK.pm
	@${FIND} ${WRKSRC} -type f -name '*.orig' -delete

pre-configure:
	@cd ${WRKDIR}/${WXSC_DISTNAME} && ${SETENV} ${CONFIGURE_ENV} \
		${PERL} Build.PL ${CONFIGURE_ARGS}

pre-build:
	@cd ${WRKDIR}/${WXSC_DISTNAME} && ./Build

pre-install:
	@cd ${WRKDIR}/${WXSC_DISTNAME} && ./Build install

.include <bsd.port.post.mk>
