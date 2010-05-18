# New ports collection makefile for:	devel/svk
# Date created:				Mar 15 2004
# Whom:					Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	svk
PORTVERSION=	2.2.3
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/C/CL/CLKAO
DISTNAME=	SVK-v${PORTVERSION}

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	A Distributed Version Control System

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/List/MoreUtils.pm:${PORTSDIR}/lang/p5-List-MoreUtils \
		${SITE_PERL}/${PERL_ARCH}/SVN/Core.pm:${PORTSDIR}/devel/p5-subversion \
		${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/Algorithm/Annotate.pm:${PORTSDIR}/devel/p5-Algorithm-Annotate \
		${SITE_PERL}/App/CLI.pm:${PORTSDIR}/devel/p5-App-CLI \
		${SITE_PERL}/Class/Accessor/Fast.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/Class/Data/Inheritable.pm:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		${SITE_PERL}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${SITE_PERL}/FreezeThaw.pm:${PORTSDIR}/devel/p5-FreezeThaw \
		${SITE_PERL}/IO/Digest.pm:${PORTSDIR}/devel/p5-IO-Digest \
		${SITE_PERL}/IO/Pager.pm:${PORTSDIR}/devel/p5-IO-Pager \
		${SITE_PERL}/Log/Log4perl.pm:${PORTSDIR}/devel/p5-Log-Log4perl \
		${SITE_PERL}/Pod/Escapes.pm:${PORTSDIR}/textproc/p5-Pod-Escapes \
		${SITE_PERL}/Pod/Simple.pm:${PORTSDIR}/textproc/p5-Pod-Simple \
		${SITE_PERL}/Regexp/Shellish.pm:${PORTSDIR}/devel/p5-Regexp-Shellish \
		${SITE_PERL}/SVN/Mirror.pm:${PORTSDIR}/devel/p5-SVN-Mirror \
		${SITE_PERL}/UNIVERSAL/require.pm:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		p5-Algorithm-Diff>=1.1901:${PORTSDIR}/devel/p5-Algorithm-Diff \
		p5-Class-Autouse>=1.15:${PORTSDIR}/devel/p5-Class-Autouse \
		p5-Data-Hierarchy>=0.30:${PORTSDIR}/devel/p5-Data-Hierarchy \
		p5-Locale-Maketext-Lexicon>=0.62:${PORTSDIR}/devel/p5-Locale-Maketext-Lexicon \
		p5-Locale-Maketext-Simple>=0.16:${PORTSDIR}/devel/p5-Locale-Maketext-Simple \
		p5-Path-Class>=0.16:${PORTSDIR}/devel/p5-Path-Class \
		p5-PerlIO-eol>=0.13:${PORTSDIR}/devel/p5-PerlIO-eol \
		p5-PerlIO-gzip>=0.18:${PORTSDIR}/archivers/p5-PerlIO-gzip \
		p5-PerlIO-via-Bzip2>=0.02:${PORTSDIR}/archivers/p5-PerlIO-via-Bzip2 \
		p5-PerlIO-via-dynamic>=0.11:${PORTSDIR}/devel/p5-PerlIO-via-dynamic \
		p5-PerlIO-via-symlink>=0.02:${PORTSDIR}/devel/p5-PerlIO-via-symlink \
		p5-SVN-Dump>=0.04:${PORTSDIR}/devel/p5-SVN-Dump \
		p5-SVN-Simple>=0.27:${PORTSDIR}/devel/p5-SVN-Simple \
		p5-SVN-Mirror>=0.71:${PORTSDIR}/devel/p5-SVN-Mirror \
		p5-Time-Progress>=0:${PORTSDIR}/devel/p5-Time-Progress \
		p5-YAML-Syck>=0.60:${PORTSDIR}/textproc/p5-YAML-Syck \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-version>=0.68:${PORTSDIR}/devel/p5-version
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN1=		svk.1
MAN3=		SVK.3 \
		SVK::Command.3 \
		SVK::Command::Add.3 \
		SVK::Command::Admin.3 \
		SVK::Command::Annotate.3 \
		SVK::Command::Branch.3 \
		SVK::Command::Cat.3 \
		SVK::Command::Checkout.3 \
		SVK::Command::Cleanup.3 \
		SVK::Command::Cmerge.3 \
		SVK::Command::Commit.3 \
		SVK::Command::Copy.3 \
		SVK::Command::Delete.3 \
		SVK::Command::Depotmap.3 \
		SVK::Command::Describe.3 \
		SVK::Command::Diff.3 \
		SVK::Command::Help.3 \
		SVK::Command::Ignore.3 \
		SVK::Command::Import.3 \
		SVK::Command::Info.3 \
		SVK::Command::List.3 \
		SVK::Command::Log.3 \
		SVK::Command::Merge.3 \
		SVK::Command::Mirror.3 \
		SVK::Command::Mkdir.3 \
		SVK::Command::Move.3 \
		SVK::Command::Patch.3 \
		SVK::Command::Propdel.3 \
		SVK::Command::Propedit.3 \
		SVK::Command::Propget.3 \
		SVK::Command::Proplist.3 \
		SVK::Command::Propset.3 \
		SVK::Command::Pull.3 \
		SVK::Command::Push.3 \
		SVK::Command::Resolved.3 \
		SVK::Command::Revert.3 \
		SVK::Command::Smerge.3 \
		SVK::Command::Status.3 \
		SVK::Command::Switch.3 \
		SVK::Command::Sync.3 \
		SVK::Command::Update.3 \
		SVK::Command::Verify.3 \
		SVK::Depot.3 \
		SVK::Editor::Checkout.3 \
		SVK::Editor::Combine.3 \
		SVK::Editor::Combiner.3 \
		SVK::Editor::Composite.3 \
		SVK::Editor::Copy.3 \
		SVK::Editor::CopyHandler.3 \
		SVK::Editor::Diff.3 \
		SVK::Editor::Merge.3 \
		SVK::Editor::Patch.3 \
		SVK::Editor::PropEol.3 \
		SVK::Editor::Rename.3 \
		SVK::Editor::SubTree.3 \
		SVK::Editor::Translate.3 \
		SVK::Editor::TxnCleanup.3 \
		SVK::Editor::XD.3 \
		SVK::Help::Environment.3 \
		SVK::Help::Index.3 \
		SVK::Help::Intro.3 \
		SVK::Help::View.3 \
		SVK::Help::zh_cn::Index.3 \
		SVK::Help::zh_tw::Index.3 \
		SVK::Inspector.3 \
		SVK::Log::ChangedPath.3 \
		SVK::Log::ChangedPaths.3 \
		SVK::Log::Filter.3 \
		SVK::Log::Filter::Author.3 \
		SVK::Log::Filter::Grep.3 \
		SVK::Log::Filter::Head.3 \
		SVK::Log::Filter::Output.3 \
		SVK::Log::Filter::Selection.3 \
		SVK::Log::Filter::Std.3 \
		SVK::Log::Filter::XML.3 \
		SVK::Log::FilterPipeline.3 \
		SVK::Logger.3 \
		SVK::Merge.3 \
		SVK::Merge::Info.3 \
		SVK::MimeDetect.3 \
		SVK::MimeDetect::FileLibMagic.3 \
		SVK::MimeDetect::FileMMagic.3 \
		SVK::MimeDetect::FileType.3 \
		SVK::MimeDetect::Internal.3 \
		SVK::Mirror.3 \
		SVK::Mirror::Backend::SVNRa.3 \
		SVK::Mirror::Backend::SVNRaPipe.3 \
		SVK::MirrorCatalog.3 \
		SVK::Notify.3 \
		SVK::Patch.3 \
		SVK::Patchset.3 \
		SVK::Path.3 \
		SVK::Path::Checkout.3 \
		SVK::Project.3 \
		SVK::Resolve.3 \
		SVK::Target::Universal.3 \
		SVK::Util.3 \
		SVK::Version.3 \
		SVK::XD.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500807
BUILD_DEPENDS+=	p5-Encode>=2.10:${PORTSDIR}/converters/p5-Encode
RUN_DEPENDS+=	p5-Encode>=2.10:${PORTSDIR}/converters/p5-Encode
.endif

.if ${PERL_LEVEL} < 500808
BUILD_DEPENDS+=	p5-Getopt-Long>=2.35:${PORTSDIR}/devel/p5-Getopt-Long
RUN_DEPENDS+=	p5-Getopt-Long>=2.35:${PORTSDIR}/devel/p5-Getopt-Long
.endif

.if ${PERL_LEVEL} < 500903
BUILD_DEPENDS+=	p5-Pod-Escapes>=0:${PORTSDIR}/textproc/p5-Pod-Escapes \
		p5-Pod-Simple>=0:${PORTSDIR}/textproc/p5-Pod-Escapes
RUN_DEPENDS+=	p5-Pod-Escapes>=0:${PORTSDIR}/textproc/p5-Pod-Escapes \
		p5-Pod-Simple>=0:${PORTSDIR}/textproc/p5-Pod-Escapes
.endif

pre-everything::
	@${ECHO} ""
	@${ECHO} "If you see some missing dependency, please update your"
	@${ECHO} "ports tree and upgrade it with 'portupgrade -R svk'."
	@${ECHO} ""

regression-test:
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.post.mk>
