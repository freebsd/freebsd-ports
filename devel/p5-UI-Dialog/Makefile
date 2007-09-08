# New ports collection makefile for:    devel/p5-UI-Dialog
# Date created:                         22 May 2006
# Whom:                                 Dmitry Karasik <dmitry@karasik.eu.org>
#
# $FreeBSD$
#

PORTNAME=	UI-Dialog
PORTVERSION=	1.08
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/K/KC/KCK
PKGNAMEPREFIX=	p5-

MAINTAINER=	dmitry@karasik.eu.org
COMMENT=	Perl wrapper for the various dialog applications

RUN_DEPENDS=	cdialog:${PORTSDIR}/devel/cdialog

.if defined(WITH_X11)
RUN_DEPENDS+=	xdialog:${PORTSDIR}/x11/xdialog
.endif

.if defined(WITH_NEWT)
RUN_DEPENDS+=	whiptail:${PORTSDIR}/devel/newt
.endif

.if defined(WITH_KDE)
RUN_DEPENDS+=	kdialog:${PORTSDIR}/x11/kdebase3
.endif

.if defined(WITH_ZENITY)
RUN_DEPENDS+=	zenity:${PORTSDIR}/x11/zenity
.endif

PERL_CONFIGURE=	yes

MAN3=		UI::Dialog.3 UI::Dialog::Backend::XDialog.3 \
		UI::Dialog::Backend::KDialog.3 UI::Dialog::Backend::ASCII.3 \
		UI::Dialog::Backend::Zenity.3 UI::Dialog::KDE.3 \
		UI::Dialog::Backend.3 UI::Dialog::Gauged.3 \
		UI::Dialog::Console.3 UI::Dialog::Backend::Whiptail.3 \
		UI::Dialog::GNOME.3 UI::Dialog::Backend::CDialog.3 \
		UI::Dialog::Backend::Nautilus.3 UI::Dialog::Backend::GDialog.3 \
		UI::Dialog::Backend::XOSD.3

.include <bsd.port.mk>
