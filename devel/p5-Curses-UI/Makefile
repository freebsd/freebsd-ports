# New ports collection makefile for:	p5-Curses-UI
# Date Created:				April 19, 2004
# Whom:					Erwin Lansing <erwin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Curses-UI
PORTVERSION=	0.95
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Curses
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	A curses based OO user interface framework

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Curses.pm:${PORTSDIR}/devel/p5-Curses \
		${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/Test/Pod.pm:${PORTSDIR}/devel/p5-Test-Pod
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Curses::UI::Color.3 Curses::UI::Label.3 \
		Curses::UI::Dialog::Basic.3 Curses::UI::Dialog::Dirbrowser.3 \
		Curses::UI::Container.3 Curses::UI::Dialog::Filebrowser.3 \
		Curses::UI::Dialog::Question.3 Curses::UI::Dialog::Status.3 \
		Curses::UI::Widget.3 \
		Curses::UI::Buttonbox.3 Curses::UI::PasswordEntry.3 \
		Curses::UI::Listbox.3 Curses::UI::Checkbox.3 \
		Curses::UI::Dialog::Error.3 Curses::UI::Common.3 \
		Curses::UI::Popupmenu.3 Curses::UI::Menubar.3 \
		Curses::UI::Searchable.3 Curses::UI::Progressbar.3 \
		Curses::UI::TextEditor.3 Curses::UI.3 \
		Curses::UI::Radiobuttonbox.3 Curses::UI::Dialog::Progress.3 \
		Curses::UI::TextEntry.3 Curses::UI::TextViewer.3 \
		Curses::UI::Window.3 Curses::UI::Dialog::Calendar.3 \
		Curses::UI::Tutorial.3 Curses::UI::Calendar.3 \
		Curses::UI::Notebook.3

post-extract:
	${RM} ${WRKSRC}/lib/Curses/UI/TextEditor.pm.orig

.include <bsd.port.mk>
