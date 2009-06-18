# New ports collection makefile for:	zim
# Date created:		2006-03-21
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	zim
PORTVERSION=	0.28
CATEGORIES=	editors perl5
MASTER_SITES=	http://www.zim-wiki.org/downloads/
DISTNAME=	Zim-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	WYSIWYG text editor written in Gtk2-Perl

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${SITE_PERL}/File/MimeInfo.pm:${PORTSDIR}/devel/p5-File-MimeInfo \
		${SITE_PERL}/File/DesktopEntry.pm:${PORTSDIR}/devel/p5-File-DesktopEntry
RUN_DEPENDS=	${BUILD_DEPENDS} \
		update-mime-database:${PORTSDIR}/misc/shared-mime-info \
		xdg-icon-resource:${PORTSDIR}/devel/xdg-utils

USE_GNOME=	gtk20 desktopfileutils
PERL_CONFIGURE=	yes
MAN1=		zim.1
MAN3=		Gtk2::Ex::DesktopEntryMenu.3 \
		Gtk2::Ex::HyperTextBuffer.3 \
		Gtk2::Ex::HyperTextView.3 \
		Gtk2::Ex::PathBar.3 \
		Zim.3 \
		Zim::Events.3 \
		Zim::FS.3 \
		Zim::FS::Bazaar.3 \
		Zim::FS::Subversion.3 \
		Zim::Formats.3 \
		Zim::Formats::Html.3 \
		Zim::Formats::Pod.3 \
		Zim::Formats::Txt2tags.3 \
		Zim::Formats::Wiki.3 \
		Zim::GUI.3 \
		Zim::GUI::Automount.3 \
		Zim::GUI::Calendar.3 \
		Zim::GUI::Component.3 \
		Zim::GUI::Daemon.3 \
		Zim::GUI::DiagramEditor.3 \
		Zim::GUI::EquationEditor.3 \
		Zim::GUI::ExportDialog.3 \
		Zim::GUI::FindReplaceDialog.3 \
		Zim::GUI::NotebookDialog.3 \
		Zim::GUI::PageView.3 \
		Zim::GUI::PathBar.3 \
		Zim::GUI::PreferencesDialog.3 \
		Zim::GUI::PropertiesDialog.3 \
		Zim::GUI::SearchDialog.3 \
		Zim::GUI::Spell.3 \
		Zim::GUI::TODOListDialog.3 \
		Zim::GUI::TrayIcon.3 \
		Zim::GUI::TreeView.3 \
		Zim::GUI::VersionsDialog.3 \
		Zim::History.3 \
		Zim::OS::Win32.3 \
		Zim::Page.3 \
		Zim::Selection.3 \
		Zim::Store.3 \
		Zim::Store::Cached.3 \
		Zim::Store::Files.3 \
		Zim::Store::Gjots.3 \
		Zim::Store::Man.3 \
		Zim::Template.3 \
		Zim::Utils.3

OPTIONS=	TRAYICON	"Support trayicon"	on \
		SPELL	"Support spell"	on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_TRAYICON)
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Gtk2/TrayIcon.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2-TrayIcon
.endif

.if !defined(WITHOUT_SPELL)
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Gtk2/Spell.pm:${PORTSDIR}/devel/p5-Gtk2-Spell
.endif

.include <bsd.port.post.mk>
