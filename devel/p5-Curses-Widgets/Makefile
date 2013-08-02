# New ports collection makefile for:	p5-Curses-Widgets
# Date created:				5 July 2001
# Whom:					petef@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	Curses-Widgets
PORTVERSION=	1.997
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	CursesWidgets-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses-based widgets and functions

BUILD_DEPENDS=	p5-Curses>=0:${PORTSDIR}/devel/p5-Curses
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Curses::Widgets::Label.3 \
	Curses::Widgets.3 \
	Curses::Widgets::TextMemo.3 \
	Curses::Widgets::ListBox.3 \
	Curses::Widgets::Menu.3 \
	Curses::Widgets::ButtonSet.3 \
	Curses::Widgets::ComboBox.3 \
	Curses::Widgets::TextField.3 \
	Curses::Widgets::Tutorial.3 \
	Curses::Widgets::Calendar.3 \
	Curses::Widgets::ProgressBar.3 \
	Curses::Widgets::ListBox::MultiColumn.3 \
	Curses::Widgets::Tutorial::Creation.3

.include <bsd.port.mk>
