# Created by: Erwin Lansing <erwin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Curses-UI
PORTVERSION=	0.9609
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Curses based OO user interface framework

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Curses>=0:${PORTSDIR}/devel/p5-Curses \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

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

.include <bsd.port.mk>
