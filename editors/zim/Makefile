# New ports collection makefile for:	zim
# Date created:		2006-03-21
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	zim
PORTVERSION=	0.15
CATEGORIES=	editors perl5
MASTER_SITES=	http://zoidberg.student.utwente.nl/downloads/Zim/ \
		ftp://zoidberg.student.utwente.nl/Zim/
DISTNAME=	Zim-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	WYSIWYG text editor written in Gtk2-Perl

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${SITE_PERL}/File/MimeInfo.pm:${PORTSDIR}/devel/p5-File-MimeInfo \
		${SITE_PERL}/File/DesktopEntry.pm:${PORTSDIR}/devel/p5-File-DesktopEntry
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GNOME=	gtk20
PERL_MODBUILD=	yes
MAN1=		zim.1
MAN3=		Gtk2::Ex::DesktopEntryMenu.3 \
		Gtk2::Ex::FormManager.3 \
		Gtk2::Ex::HyperTextBuffer.3 \
		Gtk2::Ex::HyperTextView.3 \
		Gtk2::Ex::PathBar.3 \
		Zim.3 \
		Zim::Components::Calendar.3 \
		Zim::Components::PageView.3 \
		Zim::Components::PathBar.3 \
		Zim::Components::SearchDialog.3 \
		Zim::Components::Spell.3 \
		Zim::Components::TrayIcon.3 \
		Zim::Components::TreeView.3 \
		Zim::File.3 \
		Zim::Formats::Html.3 \
		Zim::Formats::Pod.3 \
		Zim::Formats::Wiki.3 \
		Zim::Formats::XML.3 \
		Zim::History.3 \
		Zim::Page.3 \
		Zim::Page::Text.3 \
		Zim::Repository.3 \
		Zim::Repository::Base.3 \
		Zim::Repository::DBI.3 \
		Zim::Repository::Files.3 \
		Zim::Repository::Man.3 \
		Zim::Win32.3

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
