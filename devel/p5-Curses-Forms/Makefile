# ex:ts=8
# Ports collection makefile for:	p5-Curses-Forms
# Date created:			Apr 3, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Curses-Forms
PORTVERSION=	1.997
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Curses
PKGNAMEPREFIX=	p5-
DISTNAME=	CursesForms-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provide high level APIs for rapid UI design on the console

BUILD_DEPENDS=	${SITE_PERL}/Curses/Widgets.pm:${PORTSDIR}/devel/p5-Curses-Widgets
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Curses::Forms.3 \
	Curses::Forms::Dialog.3 \
	Curses::Forms::Dialog::Input.3 \
	Curses::Forms::Dialog::Logon.3

.include <bsd.port.mk>
