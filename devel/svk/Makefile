# New ports collection makefile for:	devel/svk
# Date created:				Mar 15 2004
# Whom:					Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	svk
PORTVERSION=	0.17
PORTREVISION=	0
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/C/CL/CLKAO
DISTNAME=	SVK-${PORTVERSION}

MAINTAINER=	autrijus@autrijus.org
COMMENT=	A Distributed Version Control System

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/SVN/Core.pm:${PORTSDIR}/devel/subversion-perl \
		${SITE_PERL}/SVN/Mirror.pm:${PORTSDIR}/devel/p5-SVN-Mirror \
		${SITE_PERL}/Algorithm/Annotate.pm:${PORTSDIR}/devel/p5-Algorithm-Annotate \
		${SITE_PERL}/Algorithm/Diff.pm:${PORTSDIR}/devel/p5-Algorithm-Diff \
		${SITE_PERL}/${PERL_ARCH}/Clone.pm:${PORTSDIR}/devel/p5-Clone \
		${SITE_PERL}/Data/Hierarchy.pm:${PORTSDIR}/devel/p5-Data-Hierarchy \
		${SITE_PERL}/Locale/Maketext/Lexicon.pm:${PORTSDIR}/devel/p5-Locale-Maketext-Lexicon \
		${SITE_PERL}/Locale/Maketext/Simple.pm:${PORTSDIR}/devel/p5-Locale-Maketext-Simple \
		${SITE_PERL}/PerlIO/via/dynamic.pm:${PORTSDIR}/devel/p5-PerlIO-via-dynamic \
		${SITE_PERL}/Pod/Escapes.pm:${PORTSDIR}/textproc/p5-Pod-Escapes \
		${SITE_PERL}/Pod/Simple.pm:${PORTSDIR}/textproc/p5-Pod-Simple \
		${SITE_PERL}/Regexp/Shellish.pm:${PORTSDIR}/devel/p5-Regexp-Shellish \
		${SITE_PERL}/SVN/Simple/Edit.pm:${PORTSDIR}/devel/p5-SVN-Simple \
		${SITE_PERL}/Text/Diff.pm:${PORTSDIR}/textproc/p5-Text-Diff \
		${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS=	${BUILD_DEPENDS}

OPTIONS=	PPERL "Run svk with PPerl" off

USE_REINPLACE=	yes

PERL_CONFIGURE=	yes

MAN1=		svk.1
MAN3=		SVK.3 \
		SVK::Command.3 \
		SVK::Command::Add.3 \
		SVK::Command::Annotate.3 \
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
		SVK::Command::Proplist.3 \
		SVK::Command::Propset.3 \
		SVK::Command::Resolved.3 \
		SVK::Command::Revert.3 \
		SVK::Command::Smerge.3 \
		SVK::Command::Status.3 \
		SVK::Command::Switch.3 \
		SVK::Command::Sync.3 \
		SVK::Command::Update.3 \
		SVK::Command::Verify.3 \
		SVK::Editor::Combine.3 \
		SVK::Editor::Diff.3 \
		SVK::Editor::Merge.3 \
		SVK::Editor::Patch.3 \
		SVK::Editor::XD.3 \
		SVK::Merge.3 \
		SVK::Notify.3 \
		SVK::Patch.3 \
		SVK::Target.3 \
		SVK::XD.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		This program only support perl 5.8.0 or above
.endif

.if defined(WITH_PPERL)
RUN_DEPENDS+=	pperl:${PORTSDIR}/devel/p5-PPerl
PERL=		${LOCALBASE}/bin/pperl
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,%%PERL%%,${PERL}," ${WRKSRC}/bin/svk

.include <bsd.port.post.mk>
